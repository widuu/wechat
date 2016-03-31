
extern zend_class_entry *wechat_core_service_ce;

ZEPHIR_INIT_CLASS(Wechat_Core_Service);

PHP_METHOD(Wechat_Core_Service, __construct);
PHP_METHOD(Wechat_Core_Service, _getServices);
PHP_METHOD(Wechat_Core_Service, _setServices);
PHP_METHOD(Wechat_Core_Service, _delServices);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_service__setservices, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, customObject)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_service__delservices, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wechat_core_service_method_entry) {
	PHP_ME(Wechat_Core_Service, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Wechat_Core_Service, _getServices, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Wechat_Core_Service, _setServices, arginfo_wechat_core_service__setservices, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Wechat_Core_Service, _delServices, arginfo_wechat_core_service__delservices, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
