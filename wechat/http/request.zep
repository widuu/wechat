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

namespace Wechat\Http;

/**
 * 请求处理类库
 */

class Request {
	
	/**
	 * 接收POST的XML数据 并返回解析后的数组
	 * @return array|boolean 返回解析后的数组或者解释失败返回false
	 * @author widuu <admin@widuu.com>
	 */

	public function getRequest() -> array | boolean {

		// 解析POST来的数据
 		var postData = file_get_contents("php://input");

 		// 返回转换的数组
 		return this->xmlToArray( postData );
	}

	/**
	 * 将XML数据转换成数组
	 * @return array|boolean 返回解析后的数组或者解释失败返回false
	 * @author widuu <admin@widuu.com>
	 */

	public function xmlToArray( string! xmlStr = "" ) -> array | boolean {
		var requestInfo,xmlData;
		// 将数据解析成
        if  !empty xmlStr {
        	// 安全过滤
            libxml_disable_entity_loader(true);
            // 生成xml对象
            let xmlData = simplexml_load_string(xmlStr, "SimpleXMLElement", LIBXML_NOCDATA),
            	//转换成数组
            	requestInfo = get_object_vars(xmlData);
		}else{
			// 如果PostData为空
			let requestInfo = false;
		}

		return requestInfo;
	}

}