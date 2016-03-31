
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(wechat_exception_ce, "Wechat Class First Params Must Be Array", "wechat/wechat.zep", 36);
		return;
	}
	if (!(zephir_array_isset_string(configArray, SS("appid")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(wechat_exception_ce, "appid Must Be Required", "wechat/wechat.zep", 41);
		return;
	} else {
		zephir_array_fetch_string(&_0$$5, configArray, SL("appid"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 43 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_app_id"), _0$$5 TSRMLS_CC);
	}
	if (!(zephir_array_isset_string(configArray, SS("secret")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(wechat_exception_ce, "secret Must Be Required", "wechat/wechat.zep", 48);
		return;
	} else {
		zephir_array_fetch_string(&_1$$7, configArray, SL("secret"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 50 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_app_secret"), _1$$7 TSRMLS_CC);
	}
	if (!(zephir_array_isset_string(configArray, SS("token")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(wechat_exception_ce, "token Must Be Required", "wechat/wechat.zep", 55);
		return;
	} else {
		zephir_array_fetch_string(&_2$$9, configArray, SL("token"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 57 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_token"), _2$$9 TSRMLS_CC);
	}
	if (zephir_array_isset_string(configArray, SS("asekey"))) {
		zephir_array_fetch_string(&_3$$10, configArray, SL("asekey"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 62 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_ase_key"), _3$$10 TSRMLS_CC);
		if (1) {
			zephir_update_property_this(this_ptr, SL("_aes"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("_aes"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Wechat_Wechat, server) {

	HashTable *_14;
	HashPosition _13;
	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_GET, *requestInfo = NULL, *requestObject = NULL, *_1, *_3, *result = NULL, *k = NULL, *v = NULL, *_4, **_15, *_2$$3, *encryptObject$$6 = NULL, *xmlObject$$6 = NULL, *_5$$6, *_6$$6, *_7$$6, *_8$$6, *_9$$6, *_10$$6, *_11$$6, *_12$$6;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);

	_0 = zephir_array_isset_string(_GET, SS("echostr"));
	if (_0) {
		zephir_array_fetch_string(&_1, _GET, SL("echostr"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 74 TSRMLS_CC);
		_0 = !(ZEPHIR_IS_EMPTY(_1));
	}
	if (_0) {
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "valid", NULL, 0, _2$$3);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(requestObject);
	object_init_ex(requestObject, wechat_http_request_ce);
	if (zephir_has_constructor(requestObject TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, requestObject, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&requestInfo, requestObject, "getrequest", NULL, 1);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_aes"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE(_3)) {
		if (zephir_array_isset_string(requestInfo, SS("Encrypt"))) {
			if (1) {
				zephir_update_property_this(this_ptr, SL("_aes"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
			} else {
				zephir_update_property_this(this_ptr, SL("_aes"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			}
		}
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_aes"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE(_4)) {
		ZEPHIR_INIT_VAR(encryptObject$$6);
		object_init_ex(encryptObject$$6, wechat_core_encryption_ce);
		_5$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
		_6$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_ase_key"), PH_NOISY_CC);
		_7$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_app_id"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, encryptObject$$6, "__construct", NULL, 2, _5$$6, _6$$6, _7$$6);
		zephir_check_call_status();
		zephir_array_fetch_string(&_8$$6, _GET, SL("msg_signature"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 97 TSRMLS_CC);
		zephir_array_fetch_string(&_9$$6, _GET, SL("timestamp"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 97 TSRMLS_CC);
		zephir_array_fetch_string(&_10$$6, _GET, SL("nonce"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 97 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&xmlObject$$6, encryptObject$$6, "decryptmsg", NULL, 3, _8$$6, _9$$6, _10$$6, requestInfo);
		zephir_check_call_status();
		zephir_array_fetch_string(&_11$$6, xmlObject$$6, SL("status"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 99 TSRMLS_CC);
		if (!ZEPHIR_IS_LONG(_11$$6, 0)) {
			RETURN_MM_BOOL(0);
		}
		zephir_array_fetch_string(&_12$$6, xmlObject$$6, SL("info"), PH_NOISY | PH_READONLY, "wechat/wechat.zep", 103 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&result, requestObject, "xmltoarray", NULL, 4, _12$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(result, requestInfo);
	}
	zephir_is_iterable(result, &_14, &_13, 0, 0, "wechat/wechat.zep", 112);
	for (
	  ; zephir_hash_get_current_data_ex(_14, (void**) &_15, &_13) == SUCCESS
	  ; zephir_hash_move_forward_ex(_14, &_13)
	) {
		ZEPHIR_GET_HMKEY(k, _14, _13);
		ZEPHIR_GET_HVALUE(v, _15);
		zephir_update_property_zval_zval(this_ptr, k, v TSRMLS_CC);
	}
	RETURN_CCTOR(result);

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
	zephir_array_fetch_string(&signature, _GET, SL("signature"), PH_NOISY, "wechat/wechat.zep", 128 TSRMLS_CC);
	ZEPHIR_OBS_VAR(timestamp);
	zephir_array_fetch_string(&timestamp, _GET, SL("timestamp"), PH_NOISY, "wechat/wechat.zep", 129 TSRMLS_CC);
	ZEPHIR_OBS_VAR(nonce);
	zephir_array_fetch_string(&nonce, _GET, SL("nonce"), PH_NOISY, "wechat/wechat.zep", 130 TSRMLS_CC);
	ZEPHIR_OBS_VAR(echoStr);
	zephir_array_fetch_string(&echoStr, _GET, SL("echostr"), PH_NOISY, "wechat/wechat.zep", 131 TSRMLS_CC);
	ZEPHIR_INIT_VAR(tmpArr);
	zephir_create_array(tmpArr, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(tmpArr, token);
	zephir_array_fast_append(tmpArr, timestamp);
	zephir_array_fast_append(tmpArr, nonce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	ZEPHIR_MAKE_REF(tmpArr);
	ZEPHIR_CALL_FUNCTION(NULL, "sort", NULL, 5, tmpArr, _0);
	ZEPHIR_UNREF(tmpArr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(tmpStr);
	zephir_fast_join_str(tmpStr, SL(""), tmpArr TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "sha1", NULL, 6, tmpStr);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(tmpStr, _1);
	if (ZEPHIR_IS_EQUAL(tmpStr, signature)) {
		zend_print_zval(echoStr, 0);
	} else {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_MM_RESTORE();

}

