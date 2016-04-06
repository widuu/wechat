
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/variables.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/require.h"
#include "kernel/iterator.h"
#include "ext/spl/spl_directory.h"


ZEPHIR_INIT_CLASS(Wechat_Core_FileCache) {

	ZEPHIR_REGISTER_CLASS(Wechat\\Core, FileCache, wechat, core_filecache, wechat_core_filecache_method_entry, 0);

	zend_declare_property_null(wechat_core_filecache_ce, SL("_cache_dir"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(wechat_core_filecache_ce, SL("_type"), "array", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(wechat_core_filecache_ce, SL("_prefix"), "widuu_", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(wechat_core_filecache_ce TSRMLS_CC, 1, wechat_core_cache_ce);
	return SUCCESS;

}

PHP_METHOD(Wechat_Core_FileCache, getCacheDir) {

	

	RETURN_MEMBER(this_ptr, "_cache_dir");

}

PHP_METHOD(Wechat_Core_FileCache, setCacheDir) {

	zval *cache_dir;

	zephir_fetch_params(0, 1, 0, &cache_dir);



	zephir_update_property_this(this_ptr, SL("_cache_dir"), cache_dir TSRMLS_CC);

}

PHP_METHOD(Wechat_Core_FileCache, getType) {

	

	RETURN_MEMBER(this_ptr, "_type");

}

PHP_METHOD(Wechat_Core_FileCache, setType) {

	zval *type;

	zephir_fetch_params(0, 1, 0, &type);



	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);

}

PHP_METHOD(Wechat_Core_FileCache, getPrefix) {

	

	RETURN_MEMBER(this_ptr, "_prefix");

}

PHP_METHOD(Wechat_Core_FileCache, setPrefix) {

	zval *prefix;

	zephir_fetch_params(0, 1, 0, &prefix);



	zephir_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);

}

PHP_METHOD(Wechat_Core_FileCache, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *config_param = NULL, *_SERVER, *_0$$3, *_1$$3 = NULL, *_2$$3 = NULL, *_3$$3, *_4$$4, *_5$$5, *_6$$6;
	zval *config = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 0, 1, &config_param);

	if (!config_param) {
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	} else {
		zephir_get_arrval(config, config_param);
	}


	if (!(zephir_array_isset_string(config, SS("cacheDir")))) {
		zephir_array_fetch_string(&_0$$3, _SERVER, SL("SCRIPT_FILENAME"), PH_NOISY | PH_READONLY, "wechat/core/filecache.zep", 31 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "dirname", NULL, 22, _0$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_2$$3, "realpath", NULL, 23, _1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_VSSS(_3$$3, _2$$3, "/", "cache", "/");
		zephir_update_property_this(this_ptr, SL("_cache_dir"), _3$$3 TSRMLS_CC);
	} else {
		zephir_array_fetch_string(&_4$$4, config, SL("cacheDir"), PH_NOISY | PH_READONLY, "wechat/core/filecache.zep", 33 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_cache_dir"), _4$$4 TSRMLS_CC);
	}
	if (zephir_array_isset_string(config, SS("type"))) {
		zephir_array_fetch_string(&_5$$5, config, SL("type"), PH_NOISY | PH_READONLY, "wechat/core/filecache.zep", 37 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_type"), _5$$5 TSRMLS_CC);
	}
	if (zephir_array_isset_string(config, SS("prefix"))) {
		zephir_array_fetch_string(&_6$$6, config, SL("prefix"), PH_NOISY | PH_READONLY, "wechat/core/filecache.zep", 41 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_prefix"), _6$$6 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Wechat_Core_FileCache, setCache) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, *data = NULL, *filename = NULL, *_0, *_1, *_2, *_3 = NULL, *_6, *_7, *status = NULL, *_10, *_11, *_4$$3, _5$$3, *_8$$4 = NULL, *_9$$5 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_md5(_1, key);
	ZEPHIR_INIT_VAR(filename);
	ZEPHIR_CONCAT_VVS(filename, _0, _1, ".php");
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_cache_dir"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "is_dir", NULL, 24, _2);
	zephir_check_call_status();
	if (!(zephir_is_true(_3))) {
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_cache_dir"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_5$$3);
		ZVAL_LONG(&_5$$3, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 25, _4$$3, &_5$$3, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	if (ZEPHIR_IS_STRING(_6, "array")) {
		ZEPHIR_INIT_VAR(_8$$4);
		ZEPHIR_INIT_NVAR(_8$$4);
		zephir_var_export_ex(_8$$4, &value TSRMLS_CC);
		ZEPHIR_INIT_VAR(data);
		ZEPHIR_CONCAT_SVS(data, "<?php\nreturn ", _8$$4, ";\n?>");
	} else if (ZEPHIR_IS_STRING(_7, "serialize")) {
		ZEPHIR_CALL_FUNCTION(&_9$$5, "serialize", NULL, 26, data);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(data, _9$$5);
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("_cache_dir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_11);
	ZEPHIR_CONCAT_VV(_11, _10, filename);
	ZEPHIR_INIT_VAR(status);
	zephir_file_put_contents(status, _11, data TSRMLS_CC);
	if (!(zephir_is_true(status))) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CCTOR(status);

}

PHP_METHOD(Wechat_Core_FileCache, getCache) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *data = NULL, *filename = NULL, *_0, *_1, *_2, *_3, *_4, *_5, *_6$$4, *_7$$4, *_8$$4 = NULL, *_9$$5, *_10$$5, *_11$$5;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_md5(_1, key);
	ZEPHIR_INIT_VAR(filename);
	ZEPHIR_CONCAT_VVS(filename, _0, _1, ".php");
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_cache_dir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, filename);
	if (!((zephir_file_exists(_3 TSRMLS_CC) == SUCCESS))) {
		RETURN_MM_BOOL(0);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	if (ZEPHIR_IS_STRING(_4, "array")) {
		_6$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_cache_dir"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_7$$4);
		ZEPHIR_CONCAT_VV(_7$$4, _6$$4, filename);
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_8$$4);
		if (zephir_require_zval_ret(&_8$$4, _7$$4 TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		ZEPHIR_CPY_WRT(data, _8$$4);
	} else if (ZEPHIR_IS_STRING(_5, "serialize")) {
		ZEPHIR_INIT_VAR(_9$$5);
		_10$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_cache_dir"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_11$$5);
		ZEPHIR_CONCAT_VV(_11$$5, _10$$5, filename);
		zephir_file_get_contents(_9$$5, _11$$5 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&data, "unserialize", NULL, 27, _9$$5);
		zephir_check_call_status();
	}
	RETURN_CCTOR(data);

}

PHP_METHOD(Wechat_Core_FileCache, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *filename = NULL, *_0, *_1, *_2, *_3, *_4$$3, *_5$$3;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_md5(_1, key);
	ZEPHIR_INIT_VAR(filename);
	ZEPHIR_CONCAT_VVS(filename, _0, _1, ".php");
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_cache_dir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, filename);
	if ((zephir_file_exists(_3 TSRMLS_CC) == SUCCESS)) {
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_cache_dir"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_5$$3);
		ZEPHIR_CONCAT_VV(_5$$3, _4$$3, filename);
		ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 28, _5$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Wechat_Core_FileCache, flush) {

	zend_bool _6$$5;
	zend_object_iterator *_2;
	zval *key = NULL, *cacheFile = NULL, *prefix = NULL, *item = NULL, *_0, *_1 = NULL, *_3, *_4, *_5$$4 = NULL, *_7$$6 = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(prefix);
	zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cache_dir"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "is_dir", NULL, 24, _0);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(_3);
	object_init_ex(_3, spl_ce_DirectoryIterator);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_cache_dir"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 29, _4);
	zephir_check_call_status();
	_2 = zephir_get_iterator(_3 TSRMLS_CC);
	_2->funcs->rewind(_2 TSRMLS_CC);
	for (;_2->funcs->valid(_2 TSRMLS_CC) == SUCCESS && !EG(exception); _2->funcs->move_forward(_2 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_2->funcs->get_current_data(_2, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(item, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		ZEPHIR_CALL_METHOD(&_5$$4, item, "isfile", NULL, 0);
		zephir_check_call_status();
		if (likely(ZEPHIR_IS_TRUE(_5$$4))) {
			ZEPHIR_CALL_METHOD(&key, item, "getfilename", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&cacheFile, item, "getpathname", NULL, 0);
			zephir_check_call_status();
			_6$$5 = ZEPHIR_IS_EMPTY(prefix);
			if (!(_6$$5)) {
				_6$$5 = zephir_start_with(key, prefix, NULL);
			}
			if (_6$$5) {
				ZEPHIR_CALL_FUNCTION(&_7$$6, "unlink", &_8, 28, cacheFile);
				zephir_check_call_status();
				if (!(zephir_is_true(_7$$6))) {
					RETURN_MM_BOOL(0);
				}
			}
		}
	}
	_2->funcs->dtor(_2 TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

