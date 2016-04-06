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

namespace Wechat\Js;

use Wechat\Http\Http; 
use Wechat\Core\FileCache;

class Sdk {

	/**
	 * AppId
	 */

	private _app_id { get };
	
	/**
	 * AppSecret
	 */

	private _app_secret { get };

	/**
	 * 获取的ACCESS_TOKEN
	 */

	private _token { set,get };

	/**
	 * 获取的JS_TICKET
	 */

	private _js_ticket { set,get };

	/**
	 * http 类库
	 */

	private _http;

	/**
	 * 缓存类库
	 */

	private _cache;

	/**
	 * ticket URL
	 */

	const TICKET_URL = "https://api.weixin.qq.com/cgi-bin/ticket/getticket";
	
	/**
	 * access_token URL
	 */

	const TOKEN_URL  = "https://api.weixin.qq.com/cgi-bin/token";


	/**
	 * 配置文件
	 * @param  string appId  
	 * @param  string appSecret 
	 * @param  string Token  	自己手动填写的access_token
	 * @param  string jsTicket  自己手动填写的js_ticket
	 * @author widuu <admin@widuu.com>
	 */

	public function __construct( string! appId , string! appSecret ,var token ="",var jsTicket = "" ){
		
		let this->_app_id = appId,
			this->_app_secret = appSecret,
			this->_http  = new Http(),
			this->_cache = new FileCache();

		if !empty token {
			let this->_token = token;
		}else{
			let this->_token = this->getAccessToken();
		}

		if !empty jsTicket {
			let this->_js_ticket = jsTicket;
		}else{
			let this->_js_ticket = this->getJsApiTicket();
		}

	}

	/**
	 * 获取JS加密参数方法
	 * @author widuu <admin@widuu.com>
	 */

	public function getSignPackage() {

		var protocol,url,timestamp,nonceStr,ticketStr,ticketArray,signature,signPackage;

    	if isset _SERVER["HTTPS"] && _SERVER["HTTPS"] !== "off" || _SERVER["SERVER_PORT"] == 443 {
    		let protocol = "https://";
    	}else{
    		let protocol = "http://";
    	}

    	let url = protocol._SERVER["HTTP_HOST"]._SERVER["REQUEST_URI"],
			timestamp = time(),
			nonceStr  = this->getRandomStr(),
			ticketArray = ["jsapi_ticket":this->_js_ticket,"noncestr":nonceStr,"timestamp":timestamp,"url":url],
			ticketStr   = urldecode(http_build_query(ticketArray));

		let signature = sha1(ticketStr);

    	let signPackage = [
		      "appId"     : this->_app_id,
		      "nonceStr"  : nonceStr,
		      "timestamp" : timestamp,
		      "url"       : url,
		      "signature" : signature,
		      "rawString" : ticketStr
    	];

    	return signPackage; 
  	}

  	/**
	 * 获取ACCESS_TOKEN 方法
	 * @author widuu <admin@widuu.com>
	 */

	private function getAccessToken(){

		var cacheToken,url,urlParam,result,tokenData,cacheArray,AccessToken;

		let cacheToken = this->_cache->getCache("access_token".this->_app_id);

		if !cacheToken || cacheToken["expire_time"] < time() {
			let url = self::TOKEN_URL,
				urlParam = [ "grant_type":"client_credential","appid": this->_app_id,"secret": this->_app_secret];
			
			let result = this->_http->httpGet( url, urlParam),
				tokenData = json_decode(result,true);

			if !empty tokenData["access_token"] {
				
				let AccessToken = tokenData["access_token"],
					cacheArray  = ["access_token":tokenData["access_token"],"expire_time":time() + 7000];
				
				this->_cache->setCache("access_token".this->_app_id,cacheArray);
			}

		}else{
			let AccessToken = cacheToken["access_token"];
		}

    	return AccessToken;
	}

	/**
	 * 获取JS_TICKET 方法
	 * @author widuu <admin@widuu.com>
	 */

	private function getJsApiTicket(){

		var cacheToken,url,urlParam,result,tokenData,cacheArray,jsToken;

		let cacheToken = this->_cache->getCache("jsapi_ticket".this->_app_id);

		if !cacheToken || cacheToken["expire_time"] < time() {
			let url = self::TICKET_URL,
				urlParam = [ "type":"jsapi","access_token": this->_token];
			
			let result = this->_http->httpGet( url, urlParam),
				tokenData = json_decode(result,true);

			if !empty tokenData["ticket"] {
				
				let jsToken = tokenData["ticket"],
					cacheArray  = ["ticket":tokenData["ticket"],"expire_time":time() + 7000];
				
				this->_cache->setCache("jsapi_ticket".this->_app_id,cacheArray);
			}

		}else{
			let jsToken = cacheToken["ticket"];
		}

    	return jsToken;
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
	
}