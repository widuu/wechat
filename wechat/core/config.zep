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


class Config{

	public function __construct( array! configArray = null ){
		var key , val ;
		for key , val in configArray {
			this->set(key,val);
		}
	}

	public function set(var key, var val){
		let key = strval(key);
		if typeof val === "array" {
			let this->{key} = new self(val);
		}else{
			let this->{key} = val;
		}
	}

	public function get(var key) -> string | boolean {
		let key = strval(key);
		if isset this->{key} {
			return this->{key};
		}
		return false;
	}

	public function isExists( var key ) -> boolean {
		let key = strval(key);
		return isset this->{key};
	}
}