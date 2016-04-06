
extern zend_class_entry *wechat_js_sdk_ce;

ZEPHIR_INIT_CLASS(Wechat_Js_Sdk);

PHP_METHOD(Wechat_Js_Sdk, getAppId);
PHP_METHOD(Wechat_Js_Sdk, getAppSecret);
PHP_METHOD(Wechat_Js_Sdk, setToken);
PHP_METHOD(Wechat_Js_Sdk, getToken);
PHP_METHOD(Wechat_Js_Sdk, setJsTicket);
PHP_METHOD(Wechat_Js_Sdk, getJsTicket);
PHP_METHOD(Wechat_Js_Sdk, __construct);
PHP_METHOD(Wechat_Js_Sdk, getSignPackage);
PHP_METHOD(Wechat_Js_Sdk, getAccessToken);
PHP_METHOD(Wechat_Js_Sdk, getJsApiTicket);
PHP_METHOD(Wechat_Js_Sdk, getRandomStr);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_js_sdk_settoken, 0, 0, 1)
	ZEND_ARG_INFO(0, token)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_js_sdk_setjsticket, 0, 0, 1)
	ZEND_ARG_INFO(0, js_ticket)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_js_sdk___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, appId)
	ZEND_ARG_INFO(0, appSecret)
	ZEND_ARG_INFO(0, token)
	ZEND_ARG_INFO(0, jsTicket)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wechat_js_sdk_method_entry) {
	PHP_ME(Wechat_Js_Sdk, getAppId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Js_Sdk, getAppSecret, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Js_Sdk, setToken, arginfo_wechat_js_sdk_settoken, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Js_Sdk, getToken, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Js_Sdk, setJsTicket, arginfo_wechat_js_sdk_setjsticket, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Js_Sdk, getJsTicket, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Js_Sdk, __construct, arginfo_wechat_js_sdk___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Wechat_Js_Sdk, getSignPackage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Js_Sdk, getAccessToken, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Wechat_Js_Sdk, getJsApiTicket, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Wechat_Js_Sdk, getRandomStr, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
