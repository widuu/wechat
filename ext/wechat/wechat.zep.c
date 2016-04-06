
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
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Wechat_Wechat) {

	ZEPHIR_REGISTER_CLASS_EX(Wechat, Wechat, wechat, wechat, wechat_wechatabstract_ce, wechat_wechat_method_entry, 0);

	return SUCCESS;

}

/**
 * 配置文件
 * @param  array configArray  配置信息
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, __construct) {

	zval *configArray_param = NULL, *customService = NULL, *_0$$5, *_1$$7, *_2$$9, *_3$$10;
	zval *configArray = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &configArray_param, &customService);

	if (!configArray_param) {
		ZEPHIR_INIT_VAR(configArray);
		array_init(configArray);
	} else {
	configArray = configArray_param;
	}
	if (!customService) {
		customService = ZEPHIR_GLOBAL(global_null);
	}


	if (1 != 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(wechat_exception_ce, "Wechat Class First Params Must Be Array", "wechat/wechat.zep", 37);
		return;
	}
	if (!(zephir_array_isset_string(configArray, SS("appid")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(wechat_exception_ce, "appid Must Be Required", "wechat/wechat.zep", 42);
		return;
	} else {
		zephir_array_fetch_string(&_0$$5, configArray, SL("appid"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 44 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_app_id"), _0$$5 TSRMLS_CC);
	}
	if (!(zephir_array_isset_string(configArray, SS("secret")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(wechat_exception_ce, "secret Must Be Required", "wechat/wechat.zep", 49);
		return;
	} else {
		zephir_array_fetch_string(&_1$$7, configArray, SL("secret"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 51 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_app_secret"), _1$$7 TSRMLS_CC);
	}
	if (!(zephir_array_isset_string(configArray, SS("token")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(wechat_exception_ce, "token Must Be Required", "wechat/wechat.zep", 56);
		return;
	} else {
		zephir_array_fetch_string(&_2$$9, configArray, SL("token"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 58 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_token"), _2$$9 TSRMLS_CC);
	}
	if (zephir_array_isset_string(configArray, SS("asekey"))) {
		zephir_array_fetch_string(&_3$$10, configArray, SL("asekey"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 63 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_ase_key"), _3$$10 TSRMLS_CC);
		if (1) {
			zephir_update_property_this(this_ptr, SL("_aes"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_aes"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 启动服务获取解析结果
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, server) {

	HashTable *_15$$4;
	HashPosition _14$$4;
	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_GET, *requestInfo = NULL, *requestObject = NULL, *_1, *_3 = NULL, *_2$$3, *_4$$4, *result$$4 = NULL, *k$$4 = NULL, *v$$4 = NULL, *_5$$4, **_16$$4, *encryptObject$$7 = NULL, *xmlObject$$7 = NULL, *_6$$7, *_7$$7, *_8$$7, *_9$$7, *_10$$7, *_11$$7, *_12$$7, *_13$$7;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);

	_0 = zephir_array_isset_string(_GET, SS("echostr"));
	if (_0) {
		zephir_array_fetch_string(&_1, _GET, SL("echostr"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 80 TSRMLS_CC);
		_0 = !(ZEPHIR_IS_EMPTY(_1));
	}
	if (_0) {
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "valid", NULL, 0, _2$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "ispost", NULL, 44);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		ZEPHIR_INIT_VAR(requestObject);
		object_init_ex(requestObject, wechat_http_request_ce);
		if (zephir_has_constructor(requestObject TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, requestObject, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&requestInfo, requestObject, "getrequest", NULL, 45);
		zephir_check_call_status();
		_4$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_aes"), PH_NOISY_CC);
		if (ZEPHIR_IS_FALSE(_4$$4)) {
			if (zephir_array_isset_string(requestInfo, SS("Encrypt"))) {
				if (1) {
					zephir_update_property_this(this_ptr, SL("_aes"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
				} else {
					zephir_update_property_this(this_ptr, SL("_aes"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				}
			}
		}
		_5$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_aes"), PH_NOISY_CC);
		if (ZEPHIR_IS_TRUE(_5$$4)) {
			ZEPHIR_INIT_VAR(encryptObject$$7);
			object_init_ex(encryptObject$$7, wechat_core_encryption_ce);
			_6$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
			_7$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_ase_key"), PH_NOISY_CC);
			_8$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_app_id"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, encryptObject$$7, "__construct", NULL, 46, _6$$7, _7$$7, _8$$7);
			zephir_check_call_status();
			zephir_array_fetch_string(&_9$$7, _GET, SL("msg_signature"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 105 TSRMLS_CC);
			zephir_array_fetch_string(&_10$$7, _GET, SL("timestamp"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 105 TSRMLS_CC);
			zephir_array_fetch_string(&_11$$7, _GET, SL("nonce"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 105 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&xmlObject$$7, encryptObject$$7, "decryptmsg", NULL, 47, _9$$7, _10$$7, _11$$7, requestInfo);
			zephir_check_call_status();
			zephir_array_fetch_string(&_12$$7, xmlObject$$7, SL("status"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 107 TSRMLS_CC);
			if (!ZEPHIR_IS_LONG(_12$$7, 0)) {
				RETURN_MM_BOOL(0);
			}
			zephir_array_fetch_string(&_13$$7, xmlObject$$7, SL("info"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 111 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&result$$4, requestObject, "xmltoarray", NULL, 48, _13$$7);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(result$$4, requestInfo);
		}
		zephir_is_iterable(result$$4, &_15$$4, &_14$$4, 0, 0, "wechat/wechat.zep", 120);
		for (
		  ; zephir_hash_get_current_data_ex(_15$$4, (void**) &_16$$4, &_14$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_15$$4, &_14$$4)
		) {
			ZEPHIR_GET_HMKEY(k$$4, _15$$4, _14$$4);
			ZEPHIR_GET_HVALUE(v$$4, _16$$4);
			zephir_update_property_zval_zval(this_ptr, k$$4, v$$4 TSRMLS_CC);
		}
		RETURN_CCTOR(result$$4);
	}
	RETURN_MM_BOOL(0);

}

/**
 * 微信js的签名算法
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, getSignPackage) {

	zval *sdkObject = NULL, *_0, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(sdkObject);
	object_init_ex(sdkObject, wechat_js_sdk_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_app_id"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_app_secret"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, sdkObject, "__construct", NULL, 49, _0, _1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(sdkObject, "getsignpackage", NULL, 50);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 微信验证
 * @param  string token 可以单独使用
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, valid) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *token = NULL, *_GET, *signature = NULL, *timestamp = NULL, *nonce = NULL, *tmpArr = NULL, *tmpStr = NULL, *echoStr = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	zephir_fetch_params(1, 0, 1, &token);

	if (!token) {
		ZEPHIR_CPY_WRT(token, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(token);
	}


	if (Z_TYPE_P(token) == IS_NULL) {
		ZEPHIR_OBS_NVAR(token);
		zephir_read_property_this(&token, this_ptr, SL("_token"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(signature);
	zephir_array_fetch_string(&signature, _GET, SL("signature"), PH_NOISY, "wechat/wechat.zep", 153 TSRMLS_CC);
	ZEPHIR_OBS_VAR(timestamp);
	zephir_array_fetch_string(&timestamp, _GET, SL("timestamp"), PH_NOISY, "wechat/wechat.zep", 154 TSRMLS_CC);
	ZEPHIR_OBS_VAR(nonce);
	zephir_array_fetch_string(&nonce, _GET, SL("nonce"), PH_NOISY, "wechat/wechat.zep", 155 TSRMLS_CC);
	ZEPHIR_OBS_VAR(echoStr);
	zephir_array_fetch_string(&echoStr, _GET, SL("echostr"), PH_NOISY, "wechat/wechat.zep", 156 TSRMLS_CC);
	ZEPHIR_INIT_VAR(tmpArr);
	zephir_create_array(tmpArr, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(tmpArr, token);
	zephir_array_fast_append(tmpArr, timestamp);
	zephir_array_fast_append(tmpArr, nonce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	ZEPHIR_MAKE_REF(tmpArr);
	ZEPHIR_CALL_FUNCTION(NULL, "sort", NULL, 19, tmpArr, _0);
	ZEPHIR_UNREF(tmpArr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(tmpStr);
	zephir_fast_join_str(tmpStr, SL(""), tmpArr TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "sha1", NULL, 20, tmpStr);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(tmpStr, _1);
	if (ZEPHIR_IS_EQUAL(tmpStr, signature)) {
		zend_print_zval(echoStr, 0);
	} else {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 判断请求方法
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, isPost) {

	zval *_SERVER, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);

	ZEPHIR_INIT_VAR(_0);
	zephir_array_fetch_string(&_1, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 175 TSRMLS_CC);
	zephir_fast_strtolower(_0, _1);
	if (ZEPHIR_IS_STRING(_0, "post")) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

