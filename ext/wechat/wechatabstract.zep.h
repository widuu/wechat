
extern zend_class_entry *wechat_wechatabstract_ce;

ZEPHIR_INIT_CLASS(Wechat_Wechatabstract);

PHP_METHOD(Wechat_Wechatabstract, setLogPath);
PHP_METHOD(Wechat_Wechatabstract, getDebug);
PHP_METHOD(Wechat_Wechatabstract, setDebug);
PHP_METHOD(Wechat_Wechatabstract, getJsonBody);
PHP_METHOD(Wechat_Wechatabstract, getRawBody);
PHP_METHOD(Wechat_Wechatabstract, getInfo);
PHP_METHOD(Wechat_Wechatabstract, log);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechatabstract_setlogpath, 0, 0, 1)
	ZEND_ARG_INFO(0, logPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechatabstract_setdebug, 0, 0, 1)
	ZEND_ARG_INFO(0, debug)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechatabstract_getjsonbody, 0, 0, 0)
	ZEND_ARG_INFO(0, associative)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechatabstract_getinfo, 0, 0, 0)
	ZEND_ARG_INFO(0, associative)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechatabstract_log, 0, 0, 1)
	ZEND_ARG_INFO(0, info)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wechat_wechatabstract_method_entry) {
	PHP_ME(Wechat_Wechatabstract, setLogPath, arginfo_wechat_wechatabstract_setlogpath, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechatabstract, getDebug, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechatabstract, setDebug, arginfo_wechat_wechatabstract_setdebug, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechatabstract, getJsonBody, arginfo_wechat_wechatabstract_getjsonbody, ZEND_ACC_PROTECTED)
	PHP_ME(Wechat_Wechatabstract, getRawBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechatabstract, getInfo, arginfo_wechat_wechatabstract_getinfo, ZEND_ACC_PROTECTED)
	PHP_ME(Wechat_Wechatabstract, log, arginfo_wechat_wechatabstract_log, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
