
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
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Wechat_Core_Config) {

	ZEPHIR_REGISTER_CLASS(Wechat\\Core, Config, wechat, core_config, wechat_core_config_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Wechat_Core_Config, __construct) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *configArray_param = NULL, *key = NULL, *val = NULL, **_2;
	zval *configArray = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &configArray_param);

	if (!configArray_param) {
		ZEPHIR_INIT_VAR(configArray);
		array_init(configArray);
	} else {
	configArray = configArray_param;
	}


	zephir_is_iterable(configArray, &_1, &_0, 0, 0, "wechat/core/config.zep", 29);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(val, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, 0, key, val);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Wechat_Core_Config, set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *val, *_0 = NULL, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &val);

	ZEPHIR_SEPARATE_PARAM(key);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 7, key);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(key, _0);
	if (Z_TYPE_P(val) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, wechat_core_config_ce);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 8, val);
		zephir_check_call_status();
		zephir_update_property_zval_zval(this_ptr, key, _1$$3 TSRMLS_CC);
	} else {
		zephir_update_property_zval_zval(this_ptr, key, val TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Wechat_Core_Config, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *_0 = NULL, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);

	ZEPHIR_SEPARATE_PARAM(key);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 7, key);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(key, _0);
	if (zephir_isset_property_zval(this_ptr, key TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_1$$3);
		zephir_read_property_zval(&_1$$3, this_ptr, key, PH_NOISY_CC);
		RETURN_CCTOR(_1$$3);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Wechat_Core_Config, isExists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);

	ZEPHIR_SEPARATE_PARAM(key);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 7, key);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(key, _0);
	RETURN_MM_BOOL(zephir_isset_property_zval(this_ptr, key TSRMLS_CC));

}

