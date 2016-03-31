
extern zend_class_entry *wechat_application_ce;

ZEPHIR_INIT_CLASS(Wechat_Application);

PHP_METHOD(Wechat_Application, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_application___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, Config, Wechat\\Config, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wechat_application_method_entry) {
	PHP_ME(Wechat_Application, __construct, arginfo_wechat_application___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
