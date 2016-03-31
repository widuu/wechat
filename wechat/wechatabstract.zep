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


abstract class WechatAbstract {

	protected _rowbody { set,get };

	/**
	 * List of registered services
	 */

	protected _services { set,get };

	/**
	 * AppId
	 */

	protected _app_id { set,get };

	/**
	 * AppSecret
	 */

	protected _app_secret { set,get };

	/**
	 * Token
	 */

	protected _token { set,get };

	/**
	 * EncodingAESKey
	 */

	protected _ase_key { set,get };

	/**
	 * 是否加密
	 */

	protected _aes = false { set,get };


}