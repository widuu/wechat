
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Wechat_Core_Service) {

	ZEPHIR_REGISTER_CLASS(Wechat\\Core, Service, wechat, core_service, wechat_core_service_method_entry, 0);

	zend_declare_property_null(wechat_core_service_ce, SL("_services"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(wechat_core_service_ce, SL("_instance"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Wechat_Core_Service, __construct) {

	zval *_1;
	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, wechat_http_request_ce);
	if (zephir_has_constructor(_1 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_array_update_string(&_0, SL("request"), &_1, PH_COPY | PH_SEPARATE);
	zephir_update_static_property_ce(wechat_core_service_ce, SL("_services"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Wechat_Core_Service, _getServices) {

	zend_bool _1;
	zval *_0, *_2, *_4, *_3$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(wechat_core_service_ce, SL("_instance") TSRMLS_CC);
	_1 = Z_TYPE_P(_0) == IS_NULL;
	if (!(_1)) {
		ZEPHIR_OBS_VAR(_2);
		zephir_read_static_property_ce(&_2, wechat_core_service_ce, SL("_instance") TSRMLS_CC);
		_1 = Z_TYPE_P(_2) != IS_OBJECT;
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_3$$3);
		object_init_ex(_3$$3, wechat_core_service_ce);
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "__construct", NULL, 28);
		zephir_check_call_status();
		zephir_update_static_property_ce(wechat_core_service_ce, SL("_instance"), &_3$$3 TSRMLS_CC);
	}
	_4 = zephir_fetch_static_property_ce(wechat_core_service_ce, SL("_services") TSRMLS_CC);
	RETURN_CTOR(_4);

}

PHP_METHOD(Wechat_Core_Service, _setServices) {

	zval *name_param = NULL, *customObject = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name_param, &customObject);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_STRING(name, "", 1);
	} else {
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	}
	if (!customObject) {
		customObject = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_static_property_array_multi_ce(wechat_core_service_ce, SL("_services"), &customObject TSRMLS_CC, SL("z"), 1, name);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Wechat_Core_Service, _delServices) {

	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_STRING(name, "", 1);
	} else {
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	}


	zephir_update_static_property_array_multi_ce(wechat_core_service_ce, SL("_services"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("z"), 1, name);
	ZEPHIR_MM_RESTORE();

}

