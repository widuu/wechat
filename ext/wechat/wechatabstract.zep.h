
extern zend_class_entry *wechat_wechatabstract_ce;

ZEPHIR_INIT_CLASS(Wechat_WechatAbstract);

PHP_METHOD(Wechat_WechatAbstract, setRowbody);
PHP_METHOD(Wechat_WechatAbstract, getRowbody);
PHP_METHOD(Wechat_WechatAbstract, setServices);
PHP_METHOD(Wechat_WechatAbstract, getServices);
PHP_METHOD(Wechat_WechatAbstract, setAppId);
PHP_METHOD(Wechat_WechatAbstract, getAppId);
PHP_METHOD(Wechat_WechatAbstract, setAppSecret);
PHP_METHOD(Wechat_WechatAbstract, getAppSecret);
PHP_METHOD(Wechat_WechatAbstract, setToken);
PHP_METHOD(Wechat_WechatAbstract, getToken);
PHP_METHOD(Wechat_WechatAbstract, setAseKey);
PHP_METHOD(Wechat_WechatAbstract, getAseKey);
PHP_METHOD(Wechat_WechatAbstract, setAes);
PHP_METHOD(Wechat_WechatAbstract, getAes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechatabstract_setrowbody, 0, 0, 1)
	ZEND_ARG_INFO(0, rowbody)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechatabstract_setservices, 0, 0, 1)
	ZEND_ARG_INFO(0, services)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechatabstract_setappid, 0, 0, 1)
	ZEND_ARG_INFO(0, app_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechatabstract_setappsecret, 0, 0, 1)
	ZEND_ARG_INFO(0, app_secret)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechatabstract_settoken, 0, 0, 1)
	ZEND_ARG_INFO(0, token)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechatabstract_setasekey, 0, 0, 1)
	ZEND_ARG_INFO(0, ase_key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechatabstract_setaes, 0, 0, 1)
	ZEND_ARG_INFO(0, aes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wechat_wechatabstract_method_entry) {
	PHP_ME(Wechat_WechatAbstract, setRowbody, arginfo_wechat_wechatabstract_setrowbody, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_WechatAbstract, getRowbody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_WechatAbstract, setServices, arginfo_wechat_wechatabstract_setservices, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_WechatAbstract, getServices, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_WechatAbstract, setAppId, arginfo_wechat_wechatabstract_setappid, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_WechatAbstract, getAppId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_WechatAbstract, setAppSecret, arginfo_wechat_wechatabstract_setappsecret, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_WechatAbstract, getAppSecret, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_WechatAbstract, setToken, arginfo_wechat_wechatabstract_settoken, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_WechatAbstract, getToken, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_WechatAbstract, setAseKey, arginfo_wechat_wechatabstract_setasekey, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_WechatAbstract, getAseKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_WechatAbstract, setAes, arginfo_wechat_wechatabstract_setaes, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_WechatAbstract, getAes, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
