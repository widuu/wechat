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

class Service {

	private static _services;

	private static _instance = null ;

	private function __construct(){
		let self::_services = [
			"request" : new \Wechat\Http\Request()
		];

	}

	public static function _getServices(){
		if self::_instance == null || typeof self::_instance != "object" {
			let self::_instance = new self();
		}
		return self::_services;
	}

	public static function _setServices(string! name = "" , var customObject = null ){
		let self::_services[name] = customObject;
	}

	public static function _delServices(string! name = "" ){
		let self::_services[name] = null;
	}
}