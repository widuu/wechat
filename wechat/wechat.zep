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

namespace Wechat;

use Wechat\Js\Sdk;
use Wechat\Http\Request;
use Wechat\Core\Encryption;

class Wechat extends WechatAbstract {


	/**
	 * 配置文件
	 * @param  array configArray  配置信息
	 * @author widuu <admin@widuu.com>
	 */


	public function __construct(Array! configArray = null , <Service> customService = null ){
		// 类型检测
		if typeof configArray != "array" {
			throw new Exception("Wechat Class First Params Must Be Array");
		}

		// 检测 AppId
		if !isset( configArray["appid"] ){
			throw new Exception("appid Must Be Required");
		}else{
			let this->_app_id = configArray["appid"];
		}

		// 检测 AppSecret
		if !isset( configArray["secret"] ){
			throw new Exception("secret Must Be Required");
		}else{
			let this->_app_secret = configArray["secret"];
		}

		// 检测 Token
		if !isset( configArray["token"] ){
			throw new Exception("token Must Be Required");
		}else{
			let this->_token = configArray["token"];
		}

		// 检测 EncodingAESKey，消息使用加密传输
		if isset( configArray["asekey"] ){
			let this->_ase_key = configArray["asekey"],
				this->_aes = true;
		}

	}


	/**
	 * 启动服务获取解析结果
	 * @author widuu <admin@widuu.com>
	 */

	public function server()-> array | boolean {

		var requestInfo, requestObject;

		// 判断是否是微信认证
		if isset _GET["echostr"] && !empty _GET["echostr"] {
			this->valid(this->_token);
			return true;
		}

		if this->isPost(){
			// 获取POST参数并转化为数组
			let requestObject = new Request(),
				requestInfo   = requestObject->getRequest();

			// 判断是否使用了 加密传输
			if this->_aes == false {
				if isset requestInfo["Encrypt"] {
					let this->_aes = true;
				}
			}

			var result ,k ,v;

			if this->_aes == true {
				
				var encryptObject, xmlObject;
				// 加密类
				let encryptObject = new Encryption( this->_token , this->_ase_key , this->_app_id );
				// 解析XML
				let xmlObject = encryptObject->decryptMsg( _GET["msg_signature"] , _GET["timestamp"], _GET["nonce"], requestInfo );
				// 如果状态不为0 返回错误
				if  xmlObject["status"] != 0 {
					return false;
				}

				let result    = requestObject->xmlToArray( xmlObject["info"] );
			}else{
				let result =  requestInfo;
			}
			
			for k,v in result {
				let this->{k} = v;
			}

			return result;
		}

		// 如果不是POST 提交直接false
		return false;
	}


	/**
	 * 微信js的签名算法
	 * @author widuu <admin@widuu.com>
	 */

	public function getSignPackage(){
		var sdkObject;
		let sdkObject = new Sdk(this->_app_id,this->_app_secret);
		return sdkObject->getSignPackage();
	}


	/**
	 * 微信验证
	 * @param  string token 可以单独使用
	 * @author widuu <admin@widuu.com>
	 */

	public function valid(var token = null){
		
		if token == null {
			let token = this->_token;
		}

		var signature,timestamp,nonce,tmpArr,tmpStr,echoStr;
		let signature = _GET["signature"],
			timestamp = _GET["timestamp"],
       		nonce 	  = _GET["nonce"],
        	echoStr   = _GET["echostr"], 
			tmpArr    = [ token, timestamp, nonce ];
        sort(tmpArr, SORT_STRING);
		let tmpStr = implode( "", tmpArr );
		let tmpStr = sha1( tmpStr );
		
		if  tmpStr == signature {
			echo echoStr;
		}else{
			return false;
		}
	}

	/**
	 * 判断请求方法
	 * @author widuu <admin@widuu.com>
	 */

	private function isPost() -> boolean {
		if strtolower(_SERVER["REQUEST_METHOD"]) == "post" {
			return  true;
		}
		return false;
	}

}