
extern zend_class_entry *wechat_core_config_ce;

ZEPHIR_INIT_CLASS(Wechat_Core_Config);

PHP_METHOD(Wechat_Core_Config, __construct);
PHP_METHOD(Wechat_Core_Config, set);
PHP_METHOD(Wechat_Core_Config, get);
PHP_METHOD(Wechat_Core_Config, isExists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_config___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, configArray, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_config_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_config_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_config_isexists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wechat_core_config_method_entry) {
	PHP_ME(Wechat_Core_Config, __construct, arginfo_wechat_core_config___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Wechat_Core_Config, set, arginfo_wechat_core_config_set, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_Config, get, arginfo_wechat_core_config_get, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_Config, isExists, arginfo_wechat_core_config_isexists, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
