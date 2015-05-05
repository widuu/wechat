namespace Wechat;

/**
 *  Interface for Wechat
 *
 */

abstract class Wechatabstract {

	protected _rawBody;

	protected _request_data;
	
	protected _logPath { set };

	protected _debug = false { get,set };

	protected function getJsonBody(boolean associative = false) -> <\stdclass> | array | boolean
	{
		if empty this->_rawBody {
			this->getRawBody();
		}

		if typeof this->_rawBody == "string" {
			return json_decode(this->_rawBody,associative);
		}

		if this->_debug {
			this->log("[ERROR".date("Y-m-d H:i:s",time())."] Request Data NULL\r\n");		
		};
		return false;
	}

	public function getRawBody(){
		let this->_rawBody = file_get_contents("php://input");
		if this->_debug {
			if empty this->_rawBody {
				this->log("[ERROR".date("Y-m-d H:i:s",time())."] POST Data NULL\r\n");	
			}	
		};
	}

	/**
	 * 对wechat 信息进行解析,当返回false 解析失败
	 * @param  boolean true 解析 array false 为 object
	 * @return object | array | false 
	 */

	protected function getInfo(boolean associative = false) -> <\stdclass> | array | boolean | string {
		var content,info_object;
		// 获取 json 的 object 信息
		let content = this->getJsonBody(false);
		//判断传输中是否有 Body 信息
		if isset content->body && content != false {
			let content = content -> body;
		}else{
			let content = this->_rawBody;
		}
		// string bug
		if typeof content != "string" {
			if this->_debug {
				this->log("[ERROR".date("Y-m-d H:i:s",time())."] Analysis XML Type Not String\r\n");		
			};
			return false;
		}
		
		// 解析XML文件
		let info_object = simplexml_load_string(content, "SimpleXMLElement", LIBXML_NOCDATA);

		if this->_debug {
			if !isset info_object->ToUserName  {
				this->log("[ERROR".date("Y-m-d H:i:s",time())."] Analysis XML Error \r\n");		
			}
		};

		// 返回数据类型判断
		if typeof info_object == "object" {
			if  associative {
				this->log("[INFO".date("Y-m-d H:i:s",time())."] Request ".implode(":", get_object_vars(info_object))."\r\n");
				return get_object_vars(info_object);
			}
			return info_object;
		}

		if this->_debug {
			this->log("[ERROR ".date("Y-m-d H:i:s",time())."] The wrong data type \r\n");		
		};

		return false;
	}

	/**
	 * 写日志
	 * @author widuu <admin@widuu.com>
	 */

	protected function log( info ){
		file_put_contents(this->_logPath,info,FILE_APPEND);
	}
}