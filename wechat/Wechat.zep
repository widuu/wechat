namespace Wechat;

class Wechat extends Wechatabstract{


	/**
 	 * 发送者id
	 */

	protected _tousername { get,set };

	/**
	 * wechat id
	 */

	protected _fromusername { get,set };

	/**
	 * 事件类型
	 */

	protected _msgtype { get,set };

	/**
	 * 事件
	 */

	protected _event { get,set };

	/**
	 * 创建时间
	 */

	protected _createtime { get,set };

	/**
	 * 文本消息内容	
	 */

	protected _content { get,set };

	/**
	 * 消息id
	 */

	protected _msgid { get,set };

	/**
	 * 图片链接
	 */

	protected _picurl { get,set };

	/**
	 * 媒体id
	 */

	protected _mediaid { get,set };

	/**
	 * 语音格式
	 */

	protected _format { get,set };

	/**
	 * 缩略图的媒体id
	 */

	protected _thumbmediaid { get,set };

	/**
	 * 地理位置维度
	 */

	protected _location_x { get,set };

	/**
	 * 地理位置经度
	 */

	protected _location_y { get,set };

	/**
	 * 地图缩放大小
	 */

	protected _scale { get,set };

	/**
	 * 地理位置信息
	 */

	protected _label { get,set };

	/**
	 * 消息标题
	 */

	protected _title { get,set };

	/**
	 * 消息描述
	 */

	protected _description { get,set };

	/**
	 * 消息链接
	 */

	protected _url { get,set };

	/**
 	 * TOKEN URL
	 */

	const TOKEN_URL = "https://api.weixin.qq.com/cgi-bin/token?";

	/**
	 * User URL
	 */

	const USER_URL = "https://api.weixin.qq.com/cgi-bin/user/";

	/**
	 * Menu URL
	 */

	const MENU_URL = "https://api.weixin.qq.com/cgi-bin/menu/";

	/**
	 * 接收 POST 信息
	 * @author widuu <admin@widuu.com>
	 */

	public function getRequest(){
		if this->isPost() {
			var key,value;
			let this->_request_data = this->getInfo(true);
			if this->_debug {
				if empty this->_request_data{
					this->log("[ERROR".date("Y-m-d H:i:s",time())."] Request Data NULL\r\n");		
				}
			};
			if !empty this->_request_data{
				for key,value in this->_request_data {
					let key = "_".strtolower(key);
					if isset this->{key} {
						let this->{key} = value;
					}
					
				}
				return this->_request_data;
			}
			
		}else{
			return false;
		}
		
	}

	/**
     * 返回消息方法
     * @param  string type
     * @param  (array|string) type
     * @return boolean
     * @author widuu <admin@widuu.com>
	 */

	public function response(string! type=null,info){
		if empty this->_request_data {
			return false;
		}
		var  tpl;
		let  tpl = this->getTpl(type,info);
		if this->_debug {
			if empty tpl{
				this->log("[ERROR".date("Y-m-d H:i:s",time())."] Get Response XML Type Error\r\n");		
			}
		};
		echo tpl;
	}

	/**
	 * 订阅事件
	 * @author widuu <admin@widuu.com>
	 */
 
	public function subscribe(string! type="text", info){
		if empty this->_request_data {
			return false;
		}

		if(this->_event == "subscribe"){
			this->response(type,info);
			return;
		}
	}

	/**
	 * 获取Token
	 * @param string appid 
	 * @param string secret
	 * @return array
	 * @author widuu <admin@widuu.com>
	 */

	public function getToken(string! appid="",string! secret=""){
		if (empty appid || empty secret) {
			throw new Exception("getToken Method Parameter does not allow nulls",4001);
		};
		var tokenUrl,urlQurey,result;
		let urlQurey = ["grant_type":"client_credential","appid":appid,"secret":secret];
		let tokenUrl = Wechat::TOKEN_URL.http_build_query(urlQurey);
		let result   = this->httpGet(tokenUrl);
		return json_decode(result,true);
	}

	/**
	 * 获取用户信息
	 * @param string type 
	 * @param string token
	 * @param string openid
	 * @return array
	 * @author widuu <admin@widuu.com>
	 */

	public function getUser(string! type=null,string! token="",string openid=""){
		if empty token || empty type {
			throw new Exception("Parameter does not allow nulls",4002);
		}
		var url,param,result;
		switch(type){
			case "userinfo" :
				let param  = ["access_token":token,"openid":openid,"lang":"zh_CN"];
				let url    = Wechat::USER_URL."info?".http_build_query(param);
				let result = this->httpGet(url);
				break;
			case "userlist" :
				let param  = ["access_token":token,"next_openid":openid];
				let url    = Wechat::USER_URL."get?".http_build_query(param);
				let result = this->httpGet(url);
				break;
			default:
				return false;
		}

		return json_decode(result,true);
	}

	/**
	 * 设置用户备注
	 * @param string token 
	 * @param string openid
	 * @param string remarke
	 * @return array
	 * @author widuu <admin@widuu.com>
	 */

	public function setRemark(string! token=null,string! openid=null,string! remarke=null)->boolean{
		var remarkUrl,postInfo,result;
		let remarkUrl = Wechat::USER_URL."info/updateremark?access_token=".token;
		let postInfo  = ["openid":openid,"remark":remarke];
		let result    = this->httpPost(remarkUrl,postInfo);
		if  !result {
			return false;
		}
		return  json_decode(result,true);
	}

	/**
     * 获取自定义菜单
     * @author widuu <admin@widuu.com>
     */

	public function Menu(string!type = null,string! token =null,array info = null){
		var menu_url,result;
		switch(type){
			case "get":
				let menu_url = Wechat::MENU_URL."get?access_token=".token;
				let result   = this->httpGet(menu_url);
				break;
			case "delete":
				let menu_url = Wechat::MENU_URL."delete?access_token=".token;
				let result   = this->httpGet(menu_url);
				break;
			case "create":
				if typeof info != "array" || empty info {
					throw new Exception("create param error",4005);
				}
				let menu_url = Wechat::MENU_URL."create?access_token=".token;
				let result   = this->httpPost(menu_url,info);
			  default :
				return false;
		}
		
		if !empty result{
			return json_decode(result,true);
		}else{
			throw new Exception("Response Error",4003);
		}
	}

	/**
	 * 获取变量的方法
	 * @param  string name
	 * @return boolean | string
	 * @author widuu <admin@widuu.com>
	 */

	public function _get(string! name){
		let name = "_".name;
		if isset this->{name} {
			return this->{name};
		}
		return false;
	}

	/**
	 * 设置变量的方法
	 * @param string   name
	 * @param 		   value
	 * @return boolean 
	 * @author widuu <admin@widuu.com>
	 */

	public function _set(string! name,value) ->boolean{
		let name = "_".name;
		if isset this->{name} {
			let this->{name} = value;
			return true;
		}
		return false;
	}

	/**
	 * 设置变量的方法
	 * @param string   name
	 * @param 		   value
	 * @return boolean 
	 * @author widuu <admin@widuu.com>
	 */

	protected function getTpl(string! type=null,info){
		//组织 xml
		var tpl;
		let tpl = "<xml><ToUserName><![CDATA[".this->_fromusername."]]></ToUserName><FromUserName><![CDATA[".this->_tousername."]]></FromUserName><CreateTime>".time()."</CreateTime><MsgType><![CDATA[".type."]]></MsgType>";
		switch (type){
			case "text":
				let tpl .= "<Content><![CDATA[".info."]]></Content>";
				break;
			case "image":
				let tpl .= "<Image><MediaId><![CDATA[".info."]]></MediaId></Image>";
				break;
			case "voice":
				let tpl .= "<Voice><MediaId><![CDATA[".info."]]></MediaId></Voice>";
				break;
			case "video":
				let tpl .= "<Video><MediaId><![CDATA[".info."]]></MediaId><Title><![CDATA[title]]></Title><Description><![CDATA[description]]></Description></Video> ";
				break;
			case "music":
				if typeof info != "array"{
					return false;
				}
				let tpl .= "<Music><Title><![CDATA[".info["title"]."]]></Title><Description><![CDATA[".info["description"]."]]></Description><MusicUrl><![CDATA[".info["musicurl"]."]]></MusicUrl><HQMusicUrl><![CDATA[".info["hqmusicurl"]."]]></HQMusicUrl><ThumbMediaId><![CDATA[".info["mediaid"]."]]></ThumbMediaId></Music>";
				break;
			case "news" :
				if typeof info != "array"{
					return false;
				}
				var num;
				if  isset info["title"] {
					let num = 1;
				}else{
					let num = count(info);
				}	
				let tpl .= "<ArticleCount>".num."</ArticleCount><Articles>".this->getNews(info)."</Articles>";
				break;
			default :
				return false;
		}

		let tpl.= "</xml>";
		return tpl;

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

	/**
     * 获取新闻
     * @author widuu <admin@widuu.com>
	 */

	private function getNews(array! info){
		var value,tpl = "";
		if  isset info["title"] {
			let tpl.="<item><Title><![CDATA[".info["title"]."]]></Title><Description><![CDATA[".info["description"]."]]></Description><PicUrl><![CDATA[".info["picurl"]."]]></PicUrl><Url><![CDATA[".info["url"]."]]></Url></item>";
		}else{
			for _,value in info {
				let tpl.="<item><Title><![CDATA[".value["title"]."]]></Title><Description><![CDATA[".value["description"]."]]></Description><PicUrl><![CDATA[".value["picurl"]."]]></PicUrl><Url><![CDATA[".value["url"]."]]></Url></item>";
			}
		}
		return tpl;
	}

	/**
     * 微信验证
	 * @author widuu <admin@widuu.com>
	 */

	static public function valid(string! token = null){
		var signature,timestamp,nonce,tmpArr,tmpStr,echoStr;
		let signature = _GET["signature"];
       	let timestamp = _GET["timestamp"];
       	let nonce 	  = _GET["nonce"];
        let echoStr   = _GET["echostr"]; 
		let tmpArr    = [ token, timestamp, nonce ];
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
	 * 设置URL过期时间
	 * @author widuu <admin@widuu.com>
	 */

	public static function setTimeout(int! timeout = 1){
		 globals_set("curl_timeout", timeout);
		 return true;
	}

	/**
     * HTTP GET 方法
     * @param  string url 
	 * @author widuu <admin@widuu.com>
	 */

	protected function httpGet(string! url="") { 
		var curlHandle, content,timeout ;
		let timeout    = globals_get("curl_timeout");
		let curlHandle = curl_init(); 
		curl_setopt( curlHandle , CURLOPT_URL, url ); 
		curl_setopt( curlHandle , CURLOPT_RETURNTRANSFER, 1 ); 
		curl_setopt( curlHandle , CURLOPT_SSL_VERIFYPEER, false);
        curl_setopt( curlHandle , CURLOPT_SSL_VERIFYHOST, false);
		curl_setopt( curlHandle , CURLOPT_TIMEOUT, timeout ); 
		let content = curl_exec( curlHandle );
		curl_close( curlHandle ); 
		return content; 
	}

	/**
	 * HTTP POST 方法
	 * @param  string url 
	 * @param  array  info
	 * @author widuu <admin@widuu.com>
	 */ 

	protected function httpPost(string! url=null ,array info){
		var curlHandle, content,timeout ;
		if typeof info != "array"{
			throw new Exception("infomation must be type array",4004);
		}
		let timeout    = globals_get("curl_timeout");
		let curlHandle = curl_init( url );    
        curl_setopt(curlHandle, CURLOPT_HEADER, 0);    
        curl_setopt(curlHandle, CURLOPT_RETURNTRANSFER, 1);    
        curl_setopt(curlHandle, CURLOPT_POST, 1);    
        curl_setopt(curlHandle, CURLOPT_POSTFIELDS, json_encode(info,JSON_UNESCAPED_UNICODE));  
        curl_setopt(curlHandle, CURLOPT_SSL_VERIFYPEER, false);
        curl_setopt(curlHandle, CURLOPT_SSL_VERIFYHOST, false);
        curl_setopt(curlHandle ,CURLOPT_TIMEOUT, timeout ); 
        let content = curl_exec( curlHandle );    
        curl_close( curlHandle ); 
		return content; 
	}
}