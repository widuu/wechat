
extern zend_class_entry *wechat_exception_ce;

ZEPHIR_INIT_CLASS(Wechat_Exception);

PHP_METHOD(Wechat_Exception, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_exception___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_OBJ_INFO(0, previous, Wechat\\Exception, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wechat_exception_method_entry) {
	PHP_ME(Wechat_Exception, __construct, arginfo_wechat_exception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
