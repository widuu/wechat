namespace Wechat\Http;

class Http{

	/**
	 * 超时时间
	 */

	private _timeout = 10 { set,get};

	/**
	 * Http 请求方法
	 *
	 * @param  string type   值可选<get|post>方法
	 * @param  string url    必填请求url
	 * @param  string|array  字符串或数组,get方法下,直接拼接url.post方法下，如果info不为空params是url否则是post数据
	 * @param  string|array  可选仅POST情况下使用，并且POST的params参数作为URL使用
	 * @return string|boolean
	 *
	 * @author widuu <admin@widuu.com>
	 */

	public function request( string! type = "", string! url="" , params=null , info = null) -> string | boolean {

		var curlHandle, content, paramUrl, postData;

		if empty type {
			throw new Exception("type must be required ");
		}


		if empty url {
			throw new Exception("url must be required");
		}

		if typeof params == "array" && count(params) != 0 {
			if type->lower() == "get" || !empty info {
				let paramUrl = http_build_query(params),
					url = url->trimright("?")."?".paramUrl,
					postData = info;
			}else{
				let postData = params;
			}
		}else{
			if type->lower() == "get" || !empty info {
				let url = url->trimright("?")."?".params,
					postData = info;
			}else{
				let postData = params;
			}
		}

		
		let curlHandle = curl_init(); 
		curl_setopt( curlHandle , CURLOPT_URL, url ); 
		curl_setopt( curlHandle , CURLOPT_RETURNTRANSFER, 1 ); 
		curl_setopt( curlHandle , CURLOPT_SSL_VERIFYPEER, false);
        curl_setopt( curlHandle , CURLOPT_SSL_VERIFYHOST, false);
		curl_setopt( curlHandle , CURLOPT_TIMEOUT, this->_timeout ); 

		if type->lower() == "post" {      
        	curl_setopt(curlHandle, CURLOPT_POST, 1); 
        	curl_setopt(curlHandle, CURLOPT_POSTFIELDS, postData);  
		}
		
		let content = curl_exec( curlHandle );  

		if content === false {
		    echo "Curl error: ". curl_error( curlHandle );
		    curl_close( curlHandle );
		    return false;
		}
		 
		curl_close( curlHandle ); 
		return content;
	}

	/**
	 * Get 请求方法
	 *
	 * @param  string url    必填请求url
	 * @param  string|array  可选拼接url的字符串或者数组
	 * @return string|boolean
	 * @author widuu <admin@widuu.com>
	 */

	public function httpGet( string! url="" ,  params = null ) -> string | boolean {
		return this->request( "get" , url , params );
	}


	/**
	 * Post 请求方法
	 *
	 * @param  string url    必填请求url
	 * @param  string|array  当info为空时，是POST的数据，否则为url拼接参数
	 * @param  string|array  可选POST的数据
	 * @return string|boolean
	 * @author widuu <admin@widuu.com>
	 */

	public function httpPost( string! url="" ,  params = null , info = null) -> string | boolean {
		return this->request( "post" , url , params , info );
	}
}

