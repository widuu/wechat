
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Wechat_Http_Http) {

	ZEPHIR_REGISTER_CLASS(Wechat\\Http, Http, wechat, http_http, wechat_http_http_method_entry, 0);

	/**
	 * 超时时间
	 */
	zend_declare_property_long(wechat_http_http_ce, SL("_timeout"), 10, ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * 超时时间
 */
PHP_METHOD(Wechat_Http_Http, setTimeout) {

	zval *timeout;

	zephir_fetch_params(0, 1, 0, &timeout);



	zephir_update_property_this(this_ptr, SL("_timeout"), timeout TSRMLS_CC);

}

/**
 * 超时时间
 */
PHP_METHOD(Wechat_Http_Http, getTimeout) {

	

	RETURN_MEMBER(this_ptr, "_timeout");

}

/**
 * Http 请求方法
 *
 * @param  string type   值可选<get|post>方法
 * @param  string url    必填请求url
 * @param  string|array  字符串或数组,get方法下,直接拼接url.post方法下，如果info不为空params是url否则是post数据
 * @param  string|array  可选仅POST情况下使用，并且POST的params参数作为URL使用
 * @return string|boolean
 *
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Http_Http, request) {

	zend_bool _0, _3$$5, _10$$8;
	zephir_fcall_cache_entry *_16 = NULL, *_25 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *url_param = NULL, *params = NULL, *info = NULL, *curlHandle = NULL, *content = NULL, *paramUrl = NULL, *postData = NULL, _15 = zval_used_for_init, _17, *_18, *_19 = NULL, *_20, *_1$$5 = NULL, *_2$$5, *_4$$6 = NULL, *_5$$6, _6$$6, *_7$$6, *_8$$8 = NULL, *_9$$8, *_11$$9 = NULL, *_12$$9, _13$$9, *_14$$9, _21$$11 = zval_used_for_init, _22$$11, *_23$$12 = NULL, *_24$$12;
	zval *type = NULL, *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &type_param, &url_param, &params, &info);

	if (!type_param) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_STRING(type, "", 1);
	} else {
	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
	}
	if (!url_param) {
		ZEPHIR_INIT_VAR(url);
		ZVAL_STRING(url, "", 1);
	} else {
	if (unlikely(Z_TYPE_P(url_param) != IS_STRING && Z_TYPE_P(url_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'url' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(url_param) == IS_STRING)) {
		zephir_get_strval(url, url_param);
	} else {
		ZEPHIR_INIT_VAR(url);
		ZVAL_EMPTY_STRING(url);
	}
	}
	if (!params) {
		params = ZEPHIR_GLOBAL(global_null);
	}
	if (!info) {
		info = ZEPHIR_GLOBAL(global_null);
	}


	if (ZEPHIR_IS_EMPTY(type)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(wechat_http_exception_ce, "type must be required ", "wechat/http/http.zep", 28);
		return;
	}
	if (ZEPHIR_IS_EMPTY(url)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(wechat_http_exception_ce, "url must be required", "wechat/http/http.zep", 33);
		return;
	}
	_0 = Z_TYPE_P(params) == IS_ARRAY;
	if (_0) {
		_0 = zephir_fast_count_int(params TSRMLS_CC) != 0;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_2$$5);
		zephir_fast_strtolower(_2$$5, type);
		_3$$5 = ZEPHIR_IS_STRING(_2$$5, "get");
		if (!(_3$$5)) {
			_3$$5 = !(ZEPHIR_IS_EMPTY(info));
		}
		if (_3$$5) {
			ZEPHIR_CALL_FUNCTION(&paramUrl, "http_build_query", NULL, 22, params);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_5$$6);
			ZEPHIR_SINIT_VAR(_6$$6);
			ZVAL_STRING(&_6$$6, "?", 0);
			zephir_fast_trim(_5$$6, url, &_6$$6, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_INIT_VAR(_7$$6);
			ZEPHIR_CONCAT_VSV(_7$$6, _5$$6, "?", paramUrl);
			zephir_get_strval(url, _7$$6);
			ZEPHIR_CPY_WRT(postData, info);
		} else {
			ZEPHIR_CPY_WRT(postData, params);
		}
	} else {
		ZEPHIR_INIT_VAR(_9$$8);
		zephir_fast_strtolower(_9$$8, type);
		_10$$8 = ZEPHIR_IS_STRING(_9$$8, "get");
		if (!(_10$$8)) {
			_10$$8 = !(ZEPHIR_IS_EMPTY(info));
		}
		if (_10$$8) {
			ZEPHIR_INIT_VAR(_12$$9);
			ZEPHIR_SINIT_VAR(_13$$9);
			ZVAL_STRING(&_13$$9, "?", 0);
			zephir_fast_trim(_12$$9, url, &_13$$9, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_INIT_VAR(_14$$9);
			ZEPHIR_CONCAT_VSV(_14$$9, _12$$9, "?", params);
			zephir_get_strval(url, _14$$9);
			ZEPHIR_CPY_WRT(postData, info);
		} else {
			ZEPHIR_CPY_WRT(postData, params);
		}
	}
	ZEPHIR_CALL_FUNCTION(&curlHandle, "curl_init", NULL, 23);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_15);
	ZVAL_LONG(&_15, 10002);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_16, 24, curlHandle, &_15, url);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_15);
	ZVAL_LONG(&_15, 19913);
	ZEPHIR_SINIT_VAR(_17);
	ZVAL_LONG(&_17, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_16, 24, curlHandle, &_15, &_17);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_15);
	ZVAL_LONG(&_15, 64);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_16, 24, curlHandle, &_15, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_15);
	ZVAL_LONG(&_15, 81);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_16, 24, curlHandle, &_15, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	_18 = zephir_fetch_nproperty_this(this_ptr, SL("_timeout"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_15);
	ZVAL_LONG(&_15, 13);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_16, 24, curlHandle, &_15, _18);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_20);
	zephir_fast_strtolower(_20, type);
	if (ZEPHIR_IS_STRING(_20, "post")) {
		ZEPHIR_SINIT_VAR(_21$$11);
		ZVAL_LONG(&_21$$11, 47);
		ZEPHIR_SINIT_VAR(_22$$11);
		ZVAL_LONG(&_22$$11, 1);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_16, 24, curlHandle, &_21$$11, &_22$$11);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_21$$11);
		ZVAL_LONG(&_21$$11, 10015);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_16, 24, curlHandle, &_21$$11, postData);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&content, "curl_exec", NULL, 25, curlHandle);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(content)) {
		ZEPHIR_CALL_FUNCTION(&_23$$12, "curl_error", NULL, 26, curlHandle);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_24$$12);
		ZEPHIR_CONCAT_SV(_24$$12, "Curl error: ", _23$$12);
		zend_print_zval(_24$$12, 0);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_close", &_25, 27, curlHandle);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", &_25, 27, curlHandle);
	zephir_check_call_status();
	RETURN_CCTOR(content);

}

/**
 * Get 请求方法
 *
 * @param  string url    必填请求url
 * @param  string|array  可选拼接url的字符串或者数组
 * @return string|boolean
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Http_Http, httpGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *params = NULL, *_0;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &url_param, &params);

	if (!url_param) {
		ZEPHIR_INIT_VAR(url);
		ZVAL_STRING(url, "", 1);
	} else {
	if (unlikely(Z_TYPE_P(url_param) != IS_STRING && Z_TYPE_P(url_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'url' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(url_param) == IS_STRING)) {
		zephir_get_strval(url, url_param);
	} else {
		ZEPHIR_INIT_VAR(url);
		ZVAL_EMPTY_STRING(url);
	}
	}
	if (!params) {
		params = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "get", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "request", NULL, 0, _0, url, params);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Post 请求方法
 *
 * @param  string url    必填请求url
 * @param  string|array  当info为空时，是POST的数据，否则为url拼接参数
 * @param  string|array  可选POST的数据
 * @return string|boolean
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Http_Http, httpPost) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *params = NULL, *info = NULL, *_0;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &url_param, &params, &info);

	if (!url_param) {
		ZEPHIR_INIT_VAR(url);
		ZVAL_STRING(url, "", 1);
	} else {
	if (unlikely(Z_TYPE_P(url_param) != IS_STRING && Z_TYPE_P(url_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'url' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(url_param) == IS_STRING)) {
		zephir_get_strval(url, url_param);
	} else {
		ZEPHIR_INIT_VAR(url);
		ZVAL_EMPTY_STRING(url);
	}
	}
	if (!params) {
		params = ZEPHIR_GLOBAL(global_null);
	}
	if (!info) {
		info = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "post", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "request", NULL, 0, _0, url, params, info);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

