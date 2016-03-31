
extern zend_class_entry *wechat_http_request_ce;

ZEPHIR_INIT_CLASS(Wechat_Http_Request);

PHP_METHOD(Wechat_Http_Request, getRequest);
PHP_METHOD(Wechat_Http_Request, xmlToArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_http_request_xmltoarray, 0, 0, 0)
	ZEND_ARG_INFO(0, xmlStr)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wechat_http_request_method_entry) {
	PHP_ME(Wechat_Http_Request, getRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Http_Request, xmlToArray, arginfo_wechat_http_request_xmltoarray, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
