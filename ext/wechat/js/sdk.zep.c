
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "kernel/string.h"
#include "kernel/math.h"


ZEPHIR_INIT_CLASS(Wechat_Js_Sdk) {

	ZEPHIR_REGISTER_CLASS(Wechat\\Js, Sdk, wechat, js_sdk, wechat_js_sdk_method_entry, 0);

	/**
	 * AppId
	 */
	zend_declare_property_null(wechat_js_sdk_ce, SL("_app_id"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * AppSecret
	 */
	zend_declare_property_null(wechat_js_sdk_ce, SL("_app_secret"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 获取的ACCESS_TOKEN
	 */
	zend_declare_property_null(wechat_js_sdk_ce, SL("_token"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 获取的JS_TICKET
	 */
	zend_declare_property_null(wechat_js_sdk_ce, SL("_js_ticket"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * http 类库
	 */
	zend_declare_property_null(wechat_js_sdk_ce, SL("_http"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 缓存类库
	 */
	zend_declare_property_null(wechat_js_sdk_ce, SL("_cache"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * ticket URL
	 */
	zend_declare_class_constant_string(wechat_js_sdk_ce, SL("TICKET_URL"), "https://api.weixin.qq.com/cgi-bin/ticket/getticket" TSRMLS_CC);

	/**
	 * access_token URL
	 */
	zend_declare_class_constant_string(wechat_js_sdk_ce, SL("TOKEN_URL"), "https://api.weixin.qq.com/cgi-bin/token" TSRMLS_CC);

	return SUCCESS;

}

/**
 * AppId
 */
PHP_METHOD(Wechat_Js_Sdk, getAppId) {

	

	RETURN_MEMBER(this_ptr, "_app_id");

}

/**
 * AppSecret
 */
PHP_METHOD(Wechat_Js_Sdk, getAppSecret) {

	

	RETURN_MEMBER(this_ptr, "_app_secret");

}

/**
 * 获取的ACCESS_TOKEN
 */
PHP_METHOD(Wechat_Js_Sdk, setToken) {

	zval *token;

	zephir_fetch_params(0, 1, 0, &token);



	zephir_update_property_this(this_ptr, SL("_token"), token TSRMLS_CC);

}

/**
 * 获取的ACCESS_TOKEN
 */
PHP_METHOD(Wechat_Js_Sdk, getToken) {

	

	RETURN_MEMBER(this_ptr, "_token");

}

/**
 * 获取的JS_TICKET
 */
PHP_METHOD(Wechat_Js_Sdk, setJsTicket) {

	zval *js_ticket;

	zephir_fetch_params(0, 1, 0, &js_ticket);



	zephir_update_property_this(this_ptr, SL("_js_ticket"), js_ticket TSRMLS_CC);

}

/**
 * 获取的JS_TICKET
 */
PHP_METHOD(Wechat_Js_Sdk, getJsTicket) {

	

	RETURN_MEMBER(this_ptr, "_js_ticket");

}

/**
 * 配置文件
 * @param  string appId  
 * @param  string appSecret 
 * @param  string Token  	自己手动填写的access_token
 * @param  string jsTicket  自己手动填写的js_ticket
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Js_Sdk, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *appId_param = NULL, *appSecret_param = NULL, *token = NULL, *jsTicket = NULL, *_0, *_1, *_2$$4 = NULL, *_3$$6 = NULL;
	zval *appId = NULL, *appSecret = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &appId_param, &appSecret_param, &token, &jsTicket);

	if (unlikely(Z_TYPE_P(appId_param) != IS_STRING && Z_TYPE_P(appId_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'appId' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(appId_param) == IS_STRING)) {
		zephir_get_strval(appId, appId_param);
	} else {
		ZEPHIR_INIT_VAR(appId);
		ZVAL_EMPTY_STRING(appId);
	}
	if (unlikely(Z_TYPE_P(appSecret_param) != IS_STRING && Z_TYPE_P(appSecret_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'appSecret' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(appSecret_param) == IS_STRING)) {
		zephir_get_strval(appSecret, appSecret_param);
	} else {
		ZEPHIR_INIT_VAR(appSecret);
		ZVAL_EMPTY_STRING(appSecret);
	}
	if (!token) {
		ZEPHIR_INIT_VAR(token);
		ZVAL_STRING(token, "", 1);
	}
	if (!jsTicket) {
		ZEPHIR_INIT_VAR(jsTicket);
		ZVAL_STRING(jsTicket, "", 1);
	}


	zephir_update_property_this(this_ptr, SL("_app_id"), appId TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_app_secret"), appSecret TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, wechat_http_http_ce);
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_http"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, wechat_core_filecache_ce);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 40);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_cache"), _1 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(token))) {
		zephir_update_property_this(this_ptr, SL("_token"), token TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getaccesstoken", NULL, 41);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_token"), _2$$4 TSRMLS_CC);
	}
	if (!(ZEPHIR_IS_EMPTY(jsTicket))) {
		zephir_update_property_this(this_ptr, SL("_js_ticket"), jsTicket TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&_3$$6, this_ptr, "getjsapiticket", NULL, 42);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_js_ticket"), _3$$6 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取JS加密参数方法
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Js_Sdk, getSignPackage) {

	zend_bool _0, _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_SERVER, *protocol = NULL, *url = NULL, *timestamp = NULL, *nonceStr = NULL, *ticketStr = NULL, *ticketArray = NULL, *signature = NULL, *signPackage = NULL, *_1, *_3, *_4, *_5, *_6 = NULL, *_7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	_0 = zephir_array_isset_string(_SERVER, SS("HTTPS"));
	if (_0) {
		zephir_array_fetch_string(&_1, _SERVER, SL("HTTPS"), PH_NOISY | PH_READONLY, "wechat/js/sdk.zep", 113 TSRMLS_CC);
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(_1, "off");
	}
	_2 = _0;
	if (!(_2)) {
		zephir_array_fetch_string(&_3, _SERVER, SL("SERVER_PORT"), PH_NOISY | PH_READONLY, "wechat/js/sdk.zep", 113 TSRMLS_CC);
		_2 = ZEPHIR_IS_LONG(_3, 443);
	}
	ZEPHIR_INIT_VAR(protocol);
	if (_2) {
		ZVAL_STRING(protocol, "https://", 1);
	} else {
		ZVAL_STRING(protocol, "http://", 1);
	}
	zephir_array_fetch_string(&_4, _SERVER, SL("HTTP_HOST"), PH_NOISY | PH_READONLY, "wechat/js/sdk.zep", 119 TSRMLS_CC);
	zephir_array_fetch_string(&_5, _SERVER, SL("REQUEST_URI"), PH_NOISY | PH_READONLY, "wechat/js/sdk.zep", 119 TSRMLS_CC);
	ZEPHIR_INIT_VAR(url);
	ZEPHIR_CONCAT_VVV(url, protocol, _4, _5);
	ZEPHIR_INIT_VAR(timestamp);
	zephir_time(timestamp);
	ZEPHIR_CALL_METHOD(&nonceStr, this_ptr, "getrandomstr", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(ticketArray);
	zephir_create_array(ticketArray, 4, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property_this(&_6, this_ptr, SL("_js_ticket"), PH_NOISY_CC);
	zephir_array_update_string(&ticketArray, SL("jsapi_ticket"), &_6, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&ticketArray, SL("noncestr"), &nonceStr, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&ticketArray, SL("timestamp"), &timestamp, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&ticketArray, SL("url"), &url, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_7, "http_build_query", NULL, 30, ticketArray);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&ticketStr, "urldecode", NULL, 43, _7);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&signature, "sha1", NULL, 20, ticketStr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(signPackage);
	zephir_create_array(signPackage, 6, 0 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_6);
	zephir_read_property_this(&_6, this_ptr, SL("_app_id"), PH_NOISY_CC);
	zephir_array_update_string(&signPackage, SL("appId"), &_6, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&signPackage, SL("nonceStr"), &nonceStr, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&signPackage, SL("timestamp"), &timestamp, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&signPackage, SL("url"), &url, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&signPackage, SL("signature"), &signature, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&signPackage, SL("rawString"), &ticketStr, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(signPackage);

}

/**
 * 获取ACCESS_TOKEN 方法
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Js_Sdk, getAccessToken) {

	zend_bool _3;
	zval *cacheToken = NULL, *url = NULL, *urlParam = NULL, *result = NULL, *tokenData = NULL, *cacheArray = NULL, *AccessToken = NULL, *_0, *_1, *_2, *_4, *_5, *_6$$3 = NULL, *_7$$3, *_8$$3, *_9$$4, *_10$$4, *_11$$4, *_12$$4, *_13$$4;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cache"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_app_id"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "access_token", _1);
	ZEPHIR_CALL_METHOD(&cacheToken, _0, "getcache", NULL, 0, _2);
	zephir_check_call_status();
	_3 = !zephir_is_true(cacheToken);
	if (!(_3)) {
		zephir_array_fetch_string(&_4, cacheToken, SL("expire_time"), PH_NOISY | PH_READONLY, "wechat/js/sdk.zep", 150 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5);
		zephir_time(_5);
		_3 = ZEPHIR_LT(_4, _5);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(url);
		ZVAL_STRING(url, "https://api.weixin.qq.com/cgi-bin/token", 1);
		ZEPHIR_INIT_VAR(urlParam);
		zephir_create_array(urlParam, 3, 0 TSRMLS_CC);
		add_assoc_stringl_ex(urlParam, SS("grant_type"), SL("client_credential"), 1);
		ZEPHIR_OBS_VAR(_6$$3);
		zephir_read_property_this(&_6$$3, this_ptr, SL("_app_id"), PH_NOISY_CC);
		zephir_array_update_string(&urlParam, SL("appid"), &_6$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_6$$3);
		zephir_read_property_this(&_6$$3, this_ptr, SL("_app_secret"), PH_NOISY_CC);
		zephir_array_update_string(&urlParam, SL("secret"), &_6$$3, PH_COPY | PH_SEPARATE);
		_7$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_http"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&result, _7$$3, "httpget", NULL, 0, url, urlParam);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(tokenData);
		zephir_json_decode(tokenData, &(tokenData), result, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
		zephir_array_fetch_string(&_8$$3, tokenData, SL("access_token"), PH_NOISY | PH_READONLY, "wechat/js/sdk.zep", 157 TSRMLS_CC);
		if (!(ZEPHIR_IS_EMPTY(_8$$3))) {
			ZEPHIR_OBS_VAR(AccessToken);
			zephir_array_fetch_string(&AccessToken, tokenData, SL("access_token"), PH_NOISY, "wechat/js/sdk.zep", 159 TSRMLS_CC);
			ZEPHIR_INIT_VAR(cacheArray);
			zephir_create_array(cacheArray, 2, 0 TSRMLS_CC);
			ZEPHIR_OBS_VAR(_9$$4);
			zephir_array_fetch_string(&_9$$4, tokenData, SL("access_token"), PH_NOISY, "wechat/js/sdk.zep", 160 TSRMLS_CC);
			zephir_array_update_string(&cacheArray, SL("access_token"), &_9$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(_10$$4);
			zephir_time(_10$$4);
			add_assoc_long_ex(cacheArray, SS("expire_time"), (zephir_get_numberval(_10$$4) + 7000));
			_11$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_cache"), PH_NOISY_CC);
			_12$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_app_id"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_13$$4);
			ZEPHIR_CONCAT_SV(_13$$4, "access_token", _12$$4);
			ZEPHIR_CALL_METHOD(NULL, _11$$4, "setcache", NULL, 0, _13$$4, cacheArray);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_OBS_NVAR(AccessToken);
		zephir_array_fetch_string(&AccessToken, cacheToken, SL("access_token"), PH_NOISY, "wechat/js/sdk.zep", 166 TSRMLS_CC);
	}
	RETURN_CCTOR(AccessToken);

}

/**
 * 获取JS_TICKET 方法
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Js_Sdk, getJsApiTicket) {

	zend_bool _3;
	zval *cacheToken = NULL, *url = NULL, *urlParam = NULL, *result = NULL, *tokenData = NULL, *cacheArray = NULL, *jsToken = NULL, *_0, *_1, *_2, *_4, *_5, *_6$$3, *_7$$3, *_8$$3, *_9$$4, *_10$$4, *_11$$4, *_12$$4, *_13$$4;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cache"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_app_id"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "jsapi_ticket", _1);
	ZEPHIR_CALL_METHOD(&cacheToken, _0, "getcache", NULL, 0, _2);
	zephir_check_call_status();
	_3 = !zephir_is_true(cacheToken);
	if (!(_3)) {
		zephir_array_fetch_string(&_4, cacheToken, SL("expire_time"), PH_NOISY | PH_READONLY, "wechat/js/sdk.zep", 183 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5);
		zephir_time(_5);
		_3 = ZEPHIR_LT(_4, _5);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(url);
		ZVAL_STRING(url, "https://api.weixin.qq.com/cgi-bin/ticket/getticket", 1);
		ZEPHIR_INIT_VAR(urlParam);
		zephir_create_array(urlParam, 2, 0 TSRMLS_CC);
		add_assoc_stringl_ex(urlParam, SS("type"), SL("jsapi"), 1);
		ZEPHIR_OBS_VAR(_6$$3);
		zephir_read_property_this(&_6$$3, this_ptr, SL("_token"), PH_NOISY_CC);
		zephir_array_update_string(&urlParam, SL("access_token"), &_6$$3, PH_COPY | PH_SEPARATE);
		_7$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_http"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&result, _7$$3, "httpget", NULL, 0, url, urlParam);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(tokenData);
		zephir_json_decode(tokenData, &(tokenData), result, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
		zephir_array_fetch_string(&_8$$3, tokenData, SL("ticket"), PH_NOISY | PH_READONLY, "wechat/js/sdk.zep", 190 TSRMLS_CC);
		if (!(ZEPHIR_IS_EMPTY(_8$$3))) {
			ZEPHIR_OBS_VAR(jsToken);
			zephir_array_fetch_string(&jsToken, tokenData, SL("ticket"), PH_NOISY, "wechat/js/sdk.zep", 192 TSRMLS_CC);
			ZEPHIR_INIT_VAR(cacheArray);
			zephir_create_array(cacheArray, 2, 0 TSRMLS_CC);
			ZEPHIR_OBS_VAR(_9$$4);
			zephir_array_fetch_string(&_9$$4, tokenData, SL("ticket"), PH_NOISY, "wechat/js/sdk.zep", 193 TSRMLS_CC);
			zephir_array_update_string(&cacheArray, SL("ticket"), &_9$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(_10$$4);
			zephir_time(_10$$4);
			add_assoc_long_ex(cacheArray, SS("expire_time"), (zephir_get_numberval(_10$$4) + 7000));
			_11$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_cache"), PH_NOISY_CC);
			_12$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_app_id"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_13$$4);
			ZEPHIR_CONCAT_SV(_13$$4, "jsapi_ticket", _12$$4);
			ZEPHIR_CALL_METHOD(NULL, _11$$4, "setcache", NULL, 0, _13$$4, cacheArray);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_OBS_NVAR(jsToken);
		zephir_array_fetch_string(&jsToken, cacheToken, SL("ticket"), PH_NOISY, "wechat/js/sdk.zep", 199 TSRMLS_CC);
	}
	RETURN_CCTOR(jsToken);

}

/**
 * 随机生成16位字符串
 *
 * @return string 生成的字符串
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Js_Sdk, getRandomStr) {

	int n = 0;
	zval *str = NULL, *strPol = NULL, *max = NULL, *_0 = NULL, *_1$$3, _2$$3 = zval_used_for_init;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(str);
	ZVAL_STRING(str, "", 1);
	ZEPHIR_INIT_VAR(strPol);
	zephir_create_array(strPol, 62, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "A", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "B", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "C", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "D", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "E", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "F", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "G", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "H", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "I", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "J", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "K", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "L", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "M", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "N", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "O", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "P", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Q", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "R", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "S", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "T", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "U", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "V", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "W", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "X", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Y", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Z", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 0);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 2);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 3);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 4);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 5);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 6);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 7);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 8);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 9);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "a", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "b", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "c", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "d", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "e", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "f", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "g", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "h", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "i", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "j", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "k", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "l", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "m", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "n", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "o", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "p", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "q", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "r", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "s", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "t", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "u", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "v", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "w", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "x", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "y", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "z", 1);
	zephir_array_fast_append(strPol, _0);
	ZEPHIR_INIT_VAR(max);
	ZVAL_LONG(max, (zephir_fast_count_int(strPol TSRMLS_CC) - 1));
	n = 0;
	while (1) {
		if (n == 16) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_2$$3);
		ZVAL_LONG(&_2$$3, 0);
		zephir_array_fetch_long(&_1$$3, strPol, zephir_mt_rand(zephir_get_intval(&_2$$3), zephir_get_intval(max) TSRMLS_CC), PH_NOISY | PH_READONLY, "wechat/js/sdk.zep", 222 TSRMLS_CC);
		zephir_concat_self(&str, _1$$3 TSRMLS_CC);
		n++;
	}
	RETURN_CCTOR(str);

}

