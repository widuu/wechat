
extern zend_class_entry *wechat_core_http_ce;

ZEPHIR_INIT_CLASS(Wechat_Core_Http);

PHP_METHOD(Wechat_Core_Http, setTimeout);
PHP_METHOD(Wechat_Core_Http, getTimeout);
PHP_METHOD(Wechat_Core_Http, request);
PHP_METHOD(Wechat_Core_Http, httpGet);
PHP_METHOD(Wechat_Core_Http, httpPost);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_http_settimeout, 0, 0, 1)
	ZEND_ARG_INFO(0, timeout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_http_request, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, info)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_http_httpget, 0, 0, 0)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_http_httppost, 0, 0, 0)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, info)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wechat_core_http_method_entry) {
	PHP_ME(Wechat_Core_Http, setTimeout, arginfo_wechat_core_http_settimeout, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_Http, getTimeout, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_Http, request, arginfo_wechat_core_http_request, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_Http, httpGet, arginfo_wechat_core_http_httpget, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_Http, httpPost, arginfo_wechat_core_http_httppost, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
