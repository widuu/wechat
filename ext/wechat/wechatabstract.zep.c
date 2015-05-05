
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "kernel/file.h"


/**
 *  Interface for Wechat
 *
 */
ZEPHIR_INIT_CLASS(Wechat_Wechatabstract) {

	ZEPHIR_REGISTER_CLASS(Wechat, Wechatabstract, wechat, wechatabstract, wechat_wechatabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(wechat_wechatabstract_ce, SL("_rawBody"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wechat_wechatabstract_ce, SL("_request_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(wechat_wechatabstract_ce, SL("_logPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(wechat_wechatabstract_ce, SL("_debug"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Wechat_Wechatabstract, setLogPath) {

	zval *logPath;

	zephir_fetch_params(0, 1, 0, &logPath);



	zephir_update_property_this(this_ptr, SL("_logPath"), logPath TSRMLS_CC);

}

PHP_METHOD(Wechat_Wechatabstract, getDebug) {


	RETURN_MEMBER(this_ptr, "_debug");

}

PHP_METHOD(Wechat_Wechatabstract, setDebug) {

	zval *debug;

	zephir_fetch_params(0, 1, 0, &debug);



	zephir_update_property_this(this_ptr, SL("_debug"), debug TSRMLS_CC);

}

PHP_METHOD(Wechat_Wechatabstract, getJsonBody) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *associative_param = NULL, *_0, *_1, *_2, *_3, _4, *_5 = NULL, *_6;
	zend_bool associative;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &associative_param);

	if (!associative_param) {
		associative = 0;
	} else {
		associative = zephir_get_boolval(associative_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_rawBody"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "getrawbody", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_rawBody"), PH_NOISY_CC);
	if (Z_TYPE_P(_1) == IS_STRING) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_rawBody"), PH_NOISY_CC);
		zephir_json_decode(return_value, &(return_value), _2, zephir_get_intval((associative ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)))  TSRMLS_CC);
		RETURN_MM();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_debug"), PH_NOISY_CC);
	if (zephir_is_true(_2)) {
		ZEPHIR_INIT_VAR(_3);
		zephir_time(_3);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "Y-m-d H:i:s", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "date", NULL, &_4, _3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_CONCAT_SVS(_6, "[ERROR", _5, "] Request Data NULL\r\n");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, _6);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Wechat_Wechatabstract, getRawBody) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, _1, *_2, *_3, *_4, _5, *_6 = NULL, *_7;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "php://input", 0);
	zephir_file_get_contents(_0, &_1 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_rawBody"), _0 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_debug"), PH_NOISY_CC);
	if (zephir_is_true(_2)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_rawBody"), PH_NOISY_CC);
		if (ZEPHIR_IS_EMPTY(_3)) {
			ZEPHIR_INIT_VAR(_4);
			zephir_time(_4);
			ZEPHIR_SINIT_VAR(_5);
			ZVAL_STRING(&_5, "Y-m-d H:i:s", 0);
			ZEPHIR_CALL_FUNCTION(&_6, "date", NULL, &_5, _4);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_7);
			ZEPHIR_CONCAT_SVS(_7, "[ERROR", _6, "] POST Data NULL\r\n");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, _7);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 对wechat 信息进行解析,当返回false 解析失败
 * @param  boolean true 解析 array false 为 object
 * @return object | array | false 
 */
PHP_METHOD(Wechat_Wechatabstract, getInfo) {

	zephir_nts_static zephir_fcall_cache_entry *_13 = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *associative_param = NULL, *content = NULL, *info_object = NULL, *_0 = NULL, *_2, *_3, _4 = zval_used_for_init, *_5 = NULL, *_7 = NULL, _9, *_10 = NULL, *_11, *_12 = NULL;
	zend_bool associative, _1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &associative_param);

	if (!associative_param) {
		associative = 0;
	} else {
		associative = zephir_get_boolval(associative_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 0);
	ZEPHIR_CALL_METHOD(&content, this_ptr, "getjsonbody", NULL, _0);
	zephir_check_call_status();
	_1 = zephir_isset_property(content, SS("body") TSRMLS_CC);
	if (_1) {
		_1 = !ZEPHIR_IS_FALSE(content);
	}
	if (_1) {
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property(&_2, content, SL("body"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(content, _2);
	} else {
		ZEPHIR_OBS_NVAR(content);
		zephir_read_property_this(&content, this_ptr, SL("_rawBody"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(content) != IS_STRING) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_debug"), PH_NOISY_CC);
		if (zephir_is_true(_3)) {
			ZEPHIR_INIT_NVAR(_0);
			zephir_time(_0);
			ZEPHIR_SINIT_VAR(_4);
			ZVAL_STRING(&_4, "Y-m-d H:i:s", 0);
			ZEPHIR_CALL_FUNCTION(&_5, "date", &_6, &_4, _0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_7);
			ZEPHIR_CONCAT_SVS(_7, "[ERROR", _5, "] Analysis XML Type Not String\r\n");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", &_8, _7);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_STRING(&_4, "SimpleXMLElement", 0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, 16384);
	ZEPHIR_CALL_FUNCTION(&info_object, "simplexml_load_string", NULL, content, &_4, &_9);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_debug"), PH_NOISY_CC);
	if (zephir_is_true(_3)) {
		if (!(zephir_isset_property(info_object, SS("ToUserName") TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_10);
			zephir_time(_10);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_STRING(&_4, "Y-m-d H:i:s", 0);
			ZEPHIR_CALL_FUNCTION(&_5, "date", &_6, &_4, _10);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_7);
			ZEPHIR_CONCAT_SVS(_7, "[ERROR", _5, "] Analysis XML Error \r\n");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", &_8, _7);
			zephir_check_call_status();
		}
	}
	if (Z_TYPE_P(info_object) == IS_OBJECT) {
		if (associative) {
			ZEPHIR_INIT_NVAR(_10);
			zephir_time(_10);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_STRING(&_4, "Y-m-d H:i:s", 0);
			ZEPHIR_CALL_FUNCTION(&_5, "date", &_6, &_4, _10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_11);
			ZEPHIR_CALL_FUNCTION(&_12, "get_object_vars", &_13, info_object);
			zephir_check_call_status();
			zephir_fast_join_str(_11, SL(":"), _12 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_7);
			ZEPHIR_CONCAT_SVSVS(_7, "[INFO", _5, "] Request ", _11, "\r\n");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", &_8, _7);
			zephir_check_call_status();
			ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", &_13, info_object);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_CCTOR(info_object);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_debug"), PH_NOISY_CC);
	if (zephir_is_true(_3)) {
		ZEPHIR_INIT_NVAR(_10);
		zephir_time(_10);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "Y-m-d H:i:s", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "date", &_6, &_4, _10);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_7);
		ZEPHIR_CONCAT_SVS(_7, "[ERROR ", _5, "] The wrong data type \r\n");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", &_8, _7);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(0);

}

/**
 * 写日志
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechatabstract, log) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *info, *_0, _1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &info);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_logPath"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 8);
	ZEPHIR_CALL_FUNCTION(NULL, "file_put_contents", &_2, _0, info, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

