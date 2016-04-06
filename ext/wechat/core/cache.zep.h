
extern zend_class_entry *wechat_core_cache_ce;

ZEPHIR_INIT_CLASS(Wechat_Core_Cache);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_cache_setcache, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_cache_getcache, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_cache_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wechat_core_cache_method_entry) {
	PHP_ABSTRACT_ME(Wechat_Core_Cache, setCache, arginfo_wechat_core_cache_setcache)
	PHP_ABSTRACT_ME(Wechat_Core_Cache, getCache, arginfo_wechat_core_cache_getcache)
	PHP_ABSTRACT_ME(Wechat_Core_Cache, delete, arginfo_wechat_core_cache_delete)
	PHP_ABSTRACT_ME(Wechat_Core_Cache, flush, NULL)
	PHP_FE_END
};
