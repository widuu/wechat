/*
 +------------------------------------------------------------------------+
 | Wechat Framework                                                       |
 +------------------------------------------------------------------------+
 | Copyright (c) 2016-2017   Widuu  (http://www.widuu.com)                |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to service@widuu.com so we can send you a copy immediately.            |
 +------------------------------------------------------------------------+
 | Authors: Widuu <admin@widuu.com>                                       |
 +------------------------------------------------------------------------+
 */

namespace Wechat\Core;

/**
 * 微信加密解密类库
 */

class Encryption {

	/**
	 * Token
	 */

	private _token { set,get };
	
	/**
	 * encodingAesKey
	 */

	private _encoding_aes_key { set,get };

	/**
	 * appId
	 */
	
	private _app_id { set,get };

	/**
	 * key
	 */

	private _key;


	public static block_size = 32;

	/**
	 * 实例化加密类
	 * 
	 * @param string token  微信的token
	 * @param string encodingAesKey  微信的encodingAesKey
	 * @param string appid 微信的appId
	 *
	 * @author widuu <admin@widuu.com>
	 */

	public function __construct( string token = "", string encodingAesKey ="" ,string appId="" ){
		
		// 检测必须参数
		if empty token {
			throw new \Exception("Token Must Be Required");
		}

		if empty encodingAesKey {
			throw new \Exception("encodingAesKey Must Be Required");
		}

		if empty appId {
			throw new \Exception("appId Must Be Required");
		}

		let this->_token = token,
			this->_encoding_aes_key = encodingAesKey,
			this->_app_id = appId;

	}

	/**
	 * 检验消息的真实性，并且获取解密后的明文.
	 *
	 * @param  string msgSignature  签名串，对应URL参数的msg_signature
	 * @param  string timestamp  时间戳 对应URL参数的timestamp
	 * @param  string nonce  随机串，对应URL参数的nonce
	 * @param  array|string  postData  密文，对应POST请求的数据
	 * @return array  返回错误码和错误信息|成功返回0，和解析后的xml
	 *
	 * @author widuu <admin@widuu.com>
	 */

	public function decryptMsg( string msgSignature="" , string timestamp = "" , string nonce ="", var postData=null ) {

		//检测参数的非法性

		if strlen(this->_encoding_aes_key) != 43 {
			return [ "status":-40004 ,"info":"encodingAesKey 非法" ];
		}

		// 获取key
		this->getKey(this->_encoding_aes_key);

		if empty timestamp  {
			let timestamp = time();
		}

		var encrypt;
		//判断密文是数组还是字符串

		if typeof postData == "array" {
			let encrypt = postData["Encrypt"];
		}else{
			let encrypt = postData;
		}
	
		//验证安全签名

		var enArray = this->getSha1(this->_token, timestamp, nonce, encrypt);

		if enArray["status"] != 0 {
			return enArray["info"];
		}

		var signature = enArray["info"];

		if signature != msgSignature {
			return ["status":-40001 , "info":"签名验证错误"];
		}

		var result = this->decrypt(encrypt, this->_app_id);

		if result["status"] != 0 {
			return result["info"];
		}
		return ["status":0 , "info":result["info"] ];
	}

	/**
	 * 将公众平台回复用户的消息加密打包.
	 *
	 * @param string replyMsg  公众平台待回复用户的消息，xml格式的字符串
	 * @return array 成功array(0,加密后的xml), 错误返回(errCode,错误信息)
	 *
	 * @author widuu <admin@widuu.com>
	 */

	public function encryptMsg( string replyMsg = "") -> array {

		// 获取key
		this->getKey(this->_encoding_aes_key);
		
		//加密
		var enArray = this->encrypt( replyMsg, this->_app_id );

		if enArray["status"] != 0 {
			return enArray;
		}
		
		var timeStamp = time();

		var nonce = this->getRandomStr();

		var encrypt = enArray["info"];

		var result = this->getSha1(this->_token, timeStamp, nonce, encrypt);

		if result["status"] != 0 {
			return result["info"];
		}

		var signature = result["info"];

		//生成发送的xml
		var encryptMsg = this->generate( encrypt, signature, timeStamp, nonce );
		
		return ["status":0,"info":encryptMsg];
	}

	/**
	 * 对明文进行加密
	 *
	 * @param  string text 需要加密的明文
	 * @return array  成功返回数组status 0 和info,错误返回错误码和错误信息info
	 *
	 * @author widuu <admin@widuu.com>
	 */

	public function encrypt(var text = null,var appid = null ) -> array {

		try {
			//获得16位随机字符串，填充到明文之前
			var random =  this->getRandomStr();
			let text   = random . pack("N", strlen( text )) . text . appid;
			// 网络字节序
			var size   = mcrypt_get_block_size(MCRYPT_RIJNDAEL_128, MCRYPT_MODE_CBC);
			var module = mcrypt_module_open(MCRYPT_RIJNDAEL_128, "", MCRYPT_MODE_CBC, "");
			var iv = substr( this->_key, 0, 16 );
			//使用自定义的填充方式对明文进行补位填充
			let text = this->encode( text );
			mcrypt_generic_init( module, this->_key, iv );
			//加密
			var encrypted = mcrypt_generic( module, text );
			mcrypt_generic_deinit( module );
			mcrypt_module_close( module );

			return ["status":0 , "info":base64_encode(encrypted) ];
		
		} catch \Exception  {

			return ["status":-40006 , "info":"aes 加密失败"];
		}

		return [];
	}



	/**
	 * 对密文进行解密
	 *
	 * @param  string encrypted  需要解密的密文
	 * @param  string appid  	 微信的appId
	 * @return array  返回错误码和错误信息|成功返回0，和解析后的xml
	 *
	 * @author widuu <admin@widuu.com>
	 */

	public function decrypt( var encrypted = null, var appid = null ) -> array {
		// 申明变量
		var ciphertext_dec,module,iv,decrypted;
		
		try {

			//使用BASE64对需要解密的字符串进行解码
			let ciphertext_dec = base64_decode( encrypted ),
				module = mcrypt_module_open( MCRYPT_RIJNDAEL_128, "", MCRYPT_MODE_CBC, ""),
				iv = substr( this->_key, 0, 16);

			mcrypt_generic_init( module, this->_key, iv );

			//解密
			let decrypted = mdecrypt_generic( module, ciphertext_dec);
			mcrypt_generic_deinit( module );
			mcrypt_module_close( module );

		} catch \Exception {
			return [ "status":-40007 , "info":"aes 解密失败" ];
		}

		var from_appid,xml_content;

		try {

			//去除补位字符
			var result = this->decode( decrypted );
			//去除16位随机字符串,网络字节序和AppId
			if ( strlen( result) < 16 ){
				return [];
			}

			var content  = substr( result, 16, strlen( result ) );
			var len_list = unpack( "N", substr( content, 0, 4 ) );
			var xml_len  =  len_list[1];
			let xml_content = substr( content, 4, xml_len ),
				from_appid  = substr( content,  xml_len + 4 );

		} catch \Exception  {
			return ["status":-40004 , "info":"encodingAesKey 非法" ];
		}

		if  from_appid != appid {
			return ["status":-40001 , "info":"签名验证错误" ];
		}
			
		return [ "status":0, "info":xml_content ];

	}


	/**
	 * 随机生成16位字符串
	 *
	 * @return string 生成的字符串
	 * @author widuu <admin@widuu.com>
	 */
	
	public function getRandomStr() -> string {
		var str , strPol , max , n ;
		let str = "",
			strPol = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"],
			max = count(strPol) - 1,
			n = 0;
		
		// 生成字符串
		loop {
			if n == 16 { break; }
			let str .= strPol[mt_rand(0,max)];
			let n++;
		}

		// 返回字符串
		return str;
	}

	private function getKey(string k = ""){
		let this->_key = base64_decode(k . "=");
	}

	/**
	 * 对解密后的明文进行补位删除
	 *
	 * @param decrypted 解密后的明文
	 * @return 删除填充补位后的明文
	 *
	 * @author widuu <admin@widuu.com>
	 */

	private function decode(var text = "" ) -> string {
		var pad;
		let pad = ord( substr( text, -1 ) );
		if  pad < 1 || pad > 32 {
			let pad = 0;
		}
		return substr( text, 0, ( strlen( text) -  pad ) );
	}

	/**
	 * 对需要加密的明文进行填充补位
	 *
	 * @param text 需要进行填充补位操作的明文
	 * @return 补齐明文字符串
	 *
	 * @author widuu <admin@widuu.com>
	 */

	private function encode(var text = "") -> string {
		var text_length = strlen( text );
		//计算需要填充的位数
		var amount_to_pad;
		let amount_to_pad = self::block_size - ( text_length % self::block_size );
		if  amount_to_pad == 0 {
			let amount_to_pad = self::block_size;
		}
		//获得补位所用的字符
		var pad_chr = chr( amount_to_pad );
		var tmp = "" , index = 0;
		// 生成字符串
		loop {
			if index  == amount_to_pad { break; }
			let tmp .= pad_chr;
			let index ++;
		}

		return text . tmp;
	}

	/**
	 * 用SHA1算法生成安全签名
	 *
	 * @return array 成功返回数组status为0，错误返回错误信息
	 *
	 * @author widuu <admin@widuu.com>
	 */

	public function getSha1(string token = "", string timestamp = "", string nonce="", string encrypt_msg="") {
		//排序
		try {
			var sortArray = [ encrypt_msg, token, timestamp, nonce ];
			sort( sortArray, SORT_STRING);
			var str = implode( "" ,sortArray );
			return ["status":0,"info": sha1( str ) ];
		} catch \Exception  {
			return ["status":-40003 , "info":"sha加密生成签名失败"];
		}
	}

	/**
	 * 生成xml消息
	 *
	 * @param string $encrypt 加密后的消息密文
	 * @param string $signature 安全签名
	 * @param string $timestamp 时间戳
	 * @param string $nonce 随机字符串
	 *
	 * @author widuu <admin@widuu.com>
	 */

	public function generate(var encrypt = null, var signature = null, var timestamp = null, var nonce = null) -> string {
		var format = "<xml>
<Encrypt><![CDATA[%s]]></Encrypt>
<MsgSignature><![CDATA[%s]]></MsgSignature>
<TimeStamp>%s</TimeStamp>
<Nonce><![CDATA[%s]]></Nonce>
</xml>";
		return sprintf( format, encrypt, signature, timestamp, nonce);
	}

}