
extern zend_class_entry *wechat_wechat_ce;

ZEPHIR_INIT_CLASS(Wechat_Wechat);

PHP_METHOD(Wechat_Wechat, __construct);
PHP_METHOD(Wechat_Wechat, server);
PHP_METHOD(Wechat_Wechat, valid);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, configArray, 1)
	ZEND_ARG_OBJ_INFO(0, customService, Wechat\\Service, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_valid, 0, 0, 0)
	ZEND_ARG_INFO(0, token)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wechat_wechat_method_entry) {
	PHP_ME(Wechat_Wechat, __construct, arginfo_wechat_wechat___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Wechat_Wechat, server, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, valid, arginfo_wechat_wechat_valid, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
