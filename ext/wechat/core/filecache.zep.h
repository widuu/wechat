
extern zend_class_entry *wechat_core_filecache_ce;

ZEPHIR_INIT_CLASS(Wechat_Core_FileCache);

PHP_METHOD(Wechat_Core_FileCache, getCacheDir);
PHP_METHOD(Wechat_Core_FileCache, setCacheDir);
PHP_METHOD(Wechat_Core_FileCache, getType);
PHP_METHOD(Wechat_Core_FileCache, setType);
PHP_METHOD(Wechat_Core_FileCache, getPrefix);
PHP_METHOD(Wechat_Core_FileCache, setPrefix);
PHP_METHOD(Wechat_Core_FileCache, __construct);
PHP_METHOD(Wechat_Core_FileCache, setCache);
PHP_METHOD(Wechat_Core_FileCache, getCache);
PHP_METHOD(Wechat_Core_FileCache, delete);
PHP_METHOD(Wechat_Core_FileCache, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_filecache_setcachedir, 0, 0, 1)
	ZEND_ARG_INFO(0, cache_dir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_filecache_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_filecache_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_filecache___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, config, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_filecache_setcache, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_filecache_getcache, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_filecache_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wechat_core_filecache_method_entry) {
	PHP_ME(Wechat_Core_FileCache, getCacheDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_FileCache, setCacheDir, arginfo_wechat_core_filecache_setcachedir, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_FileCache, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_FileCache, setType, arginfo_wechat_core_filecache_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_FileCache, getPrefix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_FileCache, setPrefix, arginfo_wechat_core_filecache_setprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_FileCache, __construct, arginfo_wechat_core_filecache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Wechat_Core_FileCache, setCache, arginfo_wechat_core_filecache_setcache, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_FileCache, getCache, arginfo_wechat_core_filecache_getcache, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_FileCache, delete, arginfo_wechat_core_filecache_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_FileCache, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
