
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/time.h"
#include "kernel/concat.h"
#include "kernel/math.h"


/**
 * 微信加密解密类库
 */
ZEPHIR_INIT_CLASS(Wechat_Core_Encryption) {

	ZEPHIR_REGISTER_CLASS(Wechat\\Core, Encryption, wechat, core_encryption, wechat_core_encryption_method_entry, 0);

	/**
	 * Token
	 */
	zend_declare_property_null(wechat_core_encryption_ce, SL("_token"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * encodingAesKey
	 */
	zend_declare_property_null(wechat_core_encryption_ce, SL("_encoding_aes_key"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * appId
	 */
	zend_declare_property_null(wechat_core_encryption_ce, SL("_app_id"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * key
	 */
	zend_declare_property_null(wechat_core_encryption_ce, SL("_key"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_long(wechat_core_encryption_ce, SL("block_size"), 32, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Token
 */
PHP_METHOD(Wechat_Core_Encryption, setToken) {

	zval *token;

	zephir_fetch_params(0, 1, 0, &token);



	zephir_update_property_this(this_ptr, SL("_token"), token TSRMLS_CC);

}

/**
 * Token
 */
PHP_METHOD(Wechat_Core_Encryption, getToken) {

	

	RETURN_MEMBER(this_ptr, "_token");

}

/**
 * encodingAesKey
 */
PHP_METHOD(Wechat_Core_Encryption, setEncodingAesKey) {

	zval *encoding_aes_key;

	zephir_fetch_params(0, 1, 0, &encoding_aes_key);



	zephir_update_property_this(this_ptr, SL("_encoding_aes_key"), encoding_aes_key TSRMLS_CC);

}

/**
 * encodingAesKey
 */
PHP_METHOD(Wechat_Core_Encryption, getEncodingAesKey) {

	

	RETURN_MEMBER(this_ptr, "_encoding_aes_key");

}

/**
 * appId
 */
PHP_METHOD(Wechat_Core_Encryption, setAppId) {

	zval *app_id;

	zephir_fetch_params(0, 1, 0, &app_id);



	zephir_update_property_this(this_ptr, SL("_app_id"), app_id TSRMLS_CC);

}

/**
 * appId
 */
PHP_METHOD(Wechat_Core_Encryption, getAppId) {

	

	RETURN_MEMBER(this_ptr, "_app_id");

}

/**
 * 实例化加密类
 * 
 * @param string token  微信的token
 * @param string encodingAesKey  微信的encodingAesKey
 * @param string appid 微信的appId
 *
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Core_Encryption, __construct) {

	zval *token_param = NULL, *encodingAesKey_param = NULL, *appId_param = NULL;
	zval *token = NULL, *encodingAesKey = NULL, *appId = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &token_param, &encodingAesKey_param, &appId_param);

	if (!token_param) {
		ZEPHIR_INIT_VAR(token);
		ZVAL_STRING(token, "", 1);
	} else {
		zephir_get_strval(token, token_param);
	}
	if (!encodingAesKey_param) {
		ZEPHIR_INIT_VAR(encodingAesKey);
		ZVAL_STRING(encodingAesKey, "", 1);
	} else {
		zephir_get_strval(encodingAesKey, encodingAesKey_param);
	}
	if (!appId_param) {
		ZEPHIR_INIT_VAR(appId);
		ZVAL_STRING(appId, "", 1);
	} else {
		zephir_get_strval(appId, appId_param);
	}


	if (ZEPHIR_IS_EMPTY(token)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Token Must Be Required", "wechat/core/encryption.zep", 67);
		return;
	}
	if (ZEPHIR_IS_EMPTY(encodingAesKey)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "encodingAesKey Must Be Required", "wechat/core/encryption.zep", 71);
		return;
	}
	if (ZEPHIR_IS_EMPTY(appId)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "appId Must Be Required", "wechat/core/encryption.zep", 75);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_token"), token TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_encoding_aes_key"), encodingAesKey TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_app_id"), appId TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 检验消息的真实性，并且获取解密后的明文.
 *
 * @param  string msgSignature  签名串，对应URL参数的msg_signature
 * @param  string timestamp  时间戳 对应URL参数的timestamp
 * @param  string nonce  随机串，对应URL参数的nonce
 * @param  array|string  postData  密文，对应POST请求的数据
 * @return array  返回错误码和错误信息|成功返回0，和解析后的xml
 *
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Core_Encryption, decryptMsg) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *msgSignature_param = NULL, *timestamp_param = NULL, *nonce_param = NULL, *postData = NULL, *_0, *_1, *encrypt = NULL, *enArray = NULL, *_2, *_3, *signature = NULL, *result = NULL, *_5, *_6, *_8, *_4$$7, *_7$$9;
	zval *msgSignature = NULL, *timestamp = NULL, *nonce = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &msgSignature_param, &timestamp_param, &nonce_param, &postData);

	if (!msgSignature_param) {
		ZEPHIR_INIT_VAR(msgSignature);
		ZVAL_STRING(msgSignature, "", 1);
	} else {
		zephir_get_strval(msgSignature, msgSignature_param);
	}
	if (!timestamp_param) {
		ZEPHIR_INIT_VAR(timestamp);
		ZVAL_STRING(timestamp, "", 1);
	} else {
		zephir_get_strval(timestamp, timestamp_param);
	}
	if (!nonce_param) {
		ZEPHIR_INIT_VAR(nonce);
		ZVAL_STRING(nonce, "", 1);
	} else {
		zephir_get_strval(nonce, nonce_param);
	}
	if (!postData) {
		postData = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_encoding_aes_key"), PH_NOISY_CC);
	if (zephir_fast_strlen_ev(_0) != 43) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		add_assoc_long_ex(return_value, SS("status"), -40004);
		add_assoc_stringl_ex(return_value, SS("info"), SL("encodingAesKey 非法"), 1);
		RETURN_MM();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_encoding_aes_key"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "getkey", NULL, 3, _1);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(timestamp)) {
		ZEPHIR_INIT_NVAR(timestamp);
		zephir_time(timestamp);
	}
	if (Z_TYPE_P(postData) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(encrypt);
		zephir_array_fetch_string(&encrypt, postData, SL("Encrypt"), PH_NOISY, "wechat/core/encryption.zep", 115 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(encrypt, postData);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&enArray, this_ptr, "getsha1", NULL, 0, _2, timestamp, nonce, encrypt);
	zephir_check_call_status();
	zephir_array_fetch_string(&_3, enArray, SL("status"), PH_NOISY | PH_READONLY, "wechat/core/encryption.zep", 124 TSRMLS_CC);
	if (!ZEPHIR_IS_LONG(_3, 0)) {
		zephir_array_fetch_string(&_4$$7, enArray, SL("info"), PH_NOISY | PH_READONLY, "wechat/core/encryption.zep", 125 TSRMLS_CC);
		RETURN_CTOR(_4$$7);
	}
	ZEPHIR_OBS_VAR(signature);
	zephir_array_fetch_string(&signature, enArray, SL("info"), PH_NOISY, "wechat/core/encryption.zep", 128 TSRMLS_CC);
	if (!ZEPHIR_IS_EQUAL(signature, msgSignature)) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		add_assoc_long_ex(return_value, SS("status"), -40001);
		add_assoc_stringl_ex(return_value, SS("info"), SL("签名验证错误"), 1);
		RETURN_MM();
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_app_id"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "decrypt", NULL, 0, encrypt, _5);
	zephir_check_call_status();
	zephir_array_fetch_string(&_6, result, SL("status"), PH_NOISY | PH_READONLY, "wechat/core/encryption.zep", 136 TSRMLS_CC);
	if (!ZEPHIR_IS_LONG(_6, 0)) {
		zephir_array_fetch_string(&_7$$9, result, SL("info"), PH_NOISY | PH_READONLY, "wechat/core/encryption.zep", 137 TSRMLS_CC);
		RETURN_CTOR(_7$$9);
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	add_assoc_long_ex(return_value, SS("status"), 0);
	ZEPHIR_OBS_VAR(_8);
	zephir_array_fetch_string(&_8, result, SL("info"), PH_NOISY, "wechat/core/encryption.zep", 139 TSRMLS_CC);
	zephir_array_update_string(&return_value, SL("info"), &_8, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * 将公众平台回复用户的消息加密打包.
 *
 * @param string replyMsg  公众平台待回复用户的消息，xml格式的字符串
 * @return array 成功array(0,加密后的xml), 错误返回(errCode,错误信息)
 *
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Core_Encryption, encryptMsg) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *replyMsg_param = NULL, *_0, *enArray = NULL, *_1, *_2, *timeStamp = NULL, *nonce = NULL, *encrypt = NULL, *result = NULL, *_3, *_4, *signature = NULL, *encryptMsg = NULL, *_5$$4;
	zval *replyMsg = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &replyMsg_param);

	if (!replyMsg_param) {
		ZEPHIR_INIT_VAR(replyMsg);
		ZVAL_STRING(replyMsg, "", 1);
	} else {
		zephir_get_strval(replyMsg, replyMsg_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_encoding_aes_key"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "getkey", NULL, 3, _0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_app_id"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&enArray, this_ptr, "encrypt", NULL, 0, replyMsg, _1);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, enArray, SL("status"), PH_NOISY | PH_READONLY, "wechat/core/encryption.zep", 159 TSRMLS_CC);
	if (!ZEPHIR_IS_LONG(_2, 0)) {
		RETURN_CCTOR(enArray);
	}
	ZEPHIR_INIT_VAR(timeStamp);
	zephir_time(timeStamp);
	ZEPHIR_CALL_METHOD(&nonce, this_ptr, "getrandomstr", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(encrypt);
	zephir_array_fetch_string(&encrypt, enArray, SL("info"), PH_NOISY, "wechat/core/encryption.zep", 167 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "getsha1", NULL, 0, _3, timeStamp, nonce, encrypt);
	zephir_check_call_status();
	zephir_array_fetch_string(&_4, result, SL("status"), PH_NOISY | PH_READONLY, "wechat/core/encryption.zep", 171 TSRMLS_CC);
	if (!ZEPHIR_IS_LONG(_4, 0)) {
		zephir_array_fetch_string(&_5$$4, result, SL("info"), PH_NOISY | PH_READONLY, "wechat/core/encryption.zep", 172 TSRMLS_CC);
		RETURN_CTOR(_5$$4);
	}
	ZEPHIR_OBS_VAR(signature);
	zephir_array_fetch_string(&signature, result, SL("info"), PH_NOISY, "wechat/core/encryption.zep", 175 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&encryptMsg, this_ptr, "generate", NULL, 0, encrypt, signature, timeStamp, nonce);
	zephir_check_call_status();
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	add_assoc_long_ex(return_value, SS("status"), 0);
	zephir_array_update_string(&return_value, SL("info"), &encryptMsg, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * 对明文进行加密
 *
 * @param  string text 需要加密的明文
 * @return array  成功返回数组status 0 和info,错误返回错误码和错误信息info
 *
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Core_Encryption, encrypt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *text = NULL, *appid = NULL, *random$$3 = NULL, _0$$3 = zval_used_for_init, _1$$3 = zval_used_for_init, *_2$$3 = NULL, *_3$$3, *size$$3 = NULL, *module$$3 = NULL, _4$$3, _5$$3, *iv$$3 = NULL, *_6$$3, *_7$$3 = NULL, *_8$$3, *encrypted$$3 = NULL, *_9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &text, &appid);

	if (!text) {
		ZEPHIR_CPY_WRT(text, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(text);
	}
	if (!appid) {
		appid = ZEPHIR_GLOBAL(global_null);
	}



	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&random$$3, this_ptr, "getrandomstr", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, "N", 0);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, zephir_fast_strlen_ev(text));
		ZEPHIR_CALL_FUNCTION(&_2$$3, "pack", NULL, 4, &_0$$3, &_1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_VVVV(_3$$3, random$$3, _2$$3, text, appid);
		ZEPHIR_CPY_WRT(text, _3$$3);
		ZEPHIR_SINIT_NVAR(_0$$3);
		ZVAL_STRING(&_0$$3, "rijndael-128", 0);
		ZEPHIR_SINIT_NVAR(_1$$3);
		ZVAL_STRING(&_1$$3, "cbc", 0);
		ZEPHIR_CALL_FUNCTION(&size$$3, "mcrypt_get_block_size", NULL, 5, &_0$$3, &_1$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_SINIT_NVAR(_0$$3);
		ZVAL_STRING(&_0$$3, "rijndael-128", 0);
		ZEPHIR_SINIT_NVAR(_1$$3);
		ZVAL_STRING(&_1$$3, "", 0);
		ZEPHIR_SINIT_VAR(_4$$3);
		ZVAL_STRING(&_4$$3, "cbc", 0);
		ZEPHIR_SINIT_VAR(_5$$3);
		ZVAL_STRING(&_5$$3, "", 0);
		ZEPHIR_CALL_FUNCTION(&module$$3, "mcrypt_module_open", NULL, 6, &_0$$3, &_1$$3, &_4$$3, &_5$$3);
		zephir_check_call_status_or_jump(try_end_1);
		_6$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_key"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_0$$3);
		ZVAL_LONG(&_0$$3, 0);
		ZEPHIR_SINIT_NVAR(_1$$3);
		ZVAL_LONG(&_1$$3, 16);
		ZEPHIR_INIT_VAR(iv$$3);
		zephir_substr(iv$$3, _6$$3, 0 , 16 , 0);
		ZEPHIR_CALL_METHOD(&_7$$3, this_ptr, "encode", NULL, 7, text);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CPY_WRT(text, _7$$3);
		_8$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_key"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "mcrypt_generic_init", NULL, 8, module$$3, _8$$3, iv$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_FUNCTION(&encrypted$$3, "mcrypt_generic", NULL, 9, module$$3, text);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_FUNCTION(NULL, "mcrypt_generic_deinit", NULL, 10, module$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_FUNCTION(NULL, "mcrypt_module_close", NULL, 11, module$$3);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		add_assoc_long_ex(return_value, SS("status"), 0);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "base64_encode", NULL, 12, encrypted$$3);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_array_update_string(&return_value, SL("info"), &_7$$3, PH_COPY | PH_SEPARATE);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(_9);
		ZEPHIR_CPY_WRT(_9, EG(exception));
		if (zephir_instance_of_ev(_9, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			zephir_create_array(return_value, 2, 0 TSRMLS_CC);
			add_assoc_long_ex(return_value, SS("status"), -40006);
			add_assoc_stringl_ex(return_value, SS("info"), SL("aes 加密失败"), 1);
			RETURN_MM();
		}
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * 对密文进行解密
 *
 * @param  string encrypted  需要解密的密文
 * @param  string appid  	 微信的appId
 * @return array  返回错误码和错误信息|成功返回0，和解析后的xml
 *
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Core_Encryption, decrypt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *encrypted = NULL, *appid = NULL, *ciphertext_dec = NULL, *module = NULL, *iv = NULL, *decrypted = NULL, *_6 = NULL, *from_appid = NULL, *xml_content = NULL, _0$$3 = zval_used_for_init, _1$$3 = zval_used_for_init, _2$$3, _3$$3, *_4$$3, *_5$$3, *result$$5 = NULL, *content$$5 = NULL, _7$$5, _8$$5, *len_list$$5 = NULL, _9$$5, _10$$5, *_11$$5, _12$$5 = zval_used_for_init, *xml_len$$5 = NULL, _13$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &encrypted, &appid);

	if (!encrypted) {
		encrypted = ZEPHIR_GLOBAL(global_null);
	}
	if (!appid) {
		appid = ZEPHIR_GLOBAL(global_null);
	}



	/* try_start_1: */

		ZEPHIR_CALL_FUNCTION(&ciphertext_dec, "base64_decode", NULL, 13, encrypted);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, "rijndael-128", 0);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_STRING(&_1$$3, "", 0);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "cbc", 0);
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_STRING(&_3$$3, "", 0);
		ZEPHIR_CALL_FUNCTION(&module, "mcrypt_module_open", NULL, 6, &_0$$3, &_1$$3, &_2$$3, &_3$$3);
		zephir_check_call_status_or_jump(try_end_1);
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_key"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_0$$3);
		ZVAL_LONG(&_0$$3, 0);
		ZEPHIR_SINIT_NVAR(_1$$3);
		ZVAL_LONG(&_1$$3, 16);
		ZEPHIR_INIT_VAR(iv);
		zephir_substr(iv, _4$$3, 0 , 16 , 0);
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_key"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "mcrypt_generic_init", NULL, 8, module, _5$$3, iv);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_FUNCTION(&decrypted, "mdecrypt_generic", NULL, 14, module, ciphertext_dec);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_FUNCTION(NULL, "mcrypt_generic_deinit", NULL, 10, module);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_FUNCTION(NULL, "mcrypt_module_close", NULL, 11, module);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_CPY_WRT(_6, EG(exception));
		if (zephir_instance_of_ev(_6, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			zephir_create_array(return_value, 2, 0 TSRMLS_CC);
			add_assoc_long_ex(return_value, SS("status"), -40007);
			add_assoc_stringl_ex(return_value, SS("info"), SL("aes 解密失败"), 1);
			RETURN_MM();
		}
	}

	/* try_start_2: */

		ZEPHIR_CALL_METHOD(&result$$5, this_ptr, "decode", NULL, 15, decrypted);
		zephir_check_call_status_or_jump(try_end_1);
		if (zephir_fast_strlen_ev(result$$5) < 16) {
			array_init(return_value);
			RETURN_MM();
		}
		ZEPHIR_SINIT_VAR(_7$$5);
		ZVAL_LONG(&_7$$5, 16);
		ZEPHIR_SINIT_VAR(_8$$5);
		ZVAL_LONG(&_8$$5, zephir_fast_strlen_ev(result$$5));
		ZEPHIR_INIT_VAR(content$$5);
		zephir_substr(content$$5, result$$5, 16 , zephir_get_intval(&_8$$5), 0);
		ZEPHIR_SINIT_VAR(_9$$5);
		ZVAL_LONG(&_9$$5, 0);
		ZEPHIR_SINIT_VAR(_10$$5);
		ZVAL_LONG(&_10$$5, 4);
		ZEPHIR_INIT_VAR(_11$$5);
		zephir_substr(_11$$5, content$$5, 0 , 4 , 0);
		ZEPHIR_SINIT_VAR(_12$$5);
		ZVAL_STRING(&_12$$5, "N", 0);
		ZEPHIR_CALL_FUNCTION(&len_list$$5, "unpack", NULL, 16, &_12$$5, _11$$5);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_OBS_VAR(xml_len$$5);
		zephir_array_fetch_long(&xml_len$$5, len_list$$5, 1, PH_NOISY, "wechat/core/encryption.zep", 267 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_12$$5);
		ZVAL_LONG(&_12$$5, 4);
		ZEPHIR_INIT_VAR(xml_content);
		zephir_substr(xml_content, content$$5, 4 , zephir_get_intval(xml_len$$5), 0);
		ZEPHIR_SINIT_VAR(_13$$5);
		ZVAL_LONG(&_13$$5, (zephir_get_numberval(xml_len$$5) + 4));
		ZEPHIR_INIT_VAR(from_appid);
		zephir_substr(from_appid, content$$5, zephir_get_intval(&_13$$5), 0, ZEPHIR_SUBSTR_NO_LENGTH);

	try_end_2:

	if (EG(exception)) {
		ZEPHIR_INIT_NVAR(_6);
		ZEPHIR_CPY_WRT(_6, EG(exception));
		if (zephir_instance_of_ev(_6, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			zephir_create_array(return_value, 2, 0 TSRMLS_CC);
			add_assoc_long_ex(return_value, SS("status"), -40004);
			add_assoc_stringl_ex(return_value, SS("info"), SL("encodingAesKey 非法"), 1);
			RETURN_MM();
		}
	}
	if (!ZEPHIR_IS_EQUAL(from_appid, appid)) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		add_assoc_long_ex(return_value, SS("status"), -40001);
		add_assoc_stringl_ex(return_value, SS("info"), SL("签名验证错误"), 1);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	add_assoc_long_ex(return_value, SS("status"), 0);
	zephir_array_update_string(&return_value, SL("info"), &xml_content, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * 随机生成16位字符串
 *
 * @return string 生成的字符串
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Core_Encryption, getRandomStr) {

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
		zephir_array_fetch_long(&_1$$3, strPol, zephir_mt_rand(zephir_get_intval(&_2$$3), zephir_get_intval(max) TSRMLS_CC), PH_NOISY | PH_READONLY, "wechat/core/encryption.zep", 301 TSRMLS_CC);
		zephir_concat_self(&str, _1$$3 TSRMLS_CC);
		n++;
	}
	RETURN_CCTOR(str);

}

PHP_METHOD(Wechat_Core_Encryption, getKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *k_param = NULL, *_1 = NULL;
	zval *k = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &k_param);

	if (!k_param) {
		ZEPHIR_INIT_VAR(k);
		ZVAL_STRING(k, "", 1);
	} else {
		zephir_get_strval(k, k_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_VS(_0, k, "=");
	ZEPHIR_CALL_FUNCTION(&_1, "base64_decode", NULL, 13, _0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_key"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 对解密后的明文进行补位删除
 *
 * @param decrypted 解密后的明文
 * @return 删除填充补位后的明文
 *
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Core_Encryption, decode) {

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *text = NULL, *pad = NULL, _0, *_1, _3, _4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &text);

	if (!text) {
		ZEPHIR_INIT_VAR(text);
		ZVAL_STRING(text, "", 1);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, -1);
	ZEPHIR_INIT_VAR(_1);
	zephir_substr(_1, text, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_CALL_FUNCTION(&pad, "ord", NULL, 17, _1);
	zephir_check_call_status();
	_2 = ZEPHIR_LT_LONG(pad, 1);
	if (!(_2)) {
		_2 = ZEPHIR_GT_LONG(pad, 32);
	}
	if (_2) {
		ZEPHIR_INIT_NVAR(pad);
		ZVAL_LONG(pad, 0);
	}
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, ((zephir_fast_strlen_ev(text) - zephir_get_numberval(pad))));
	zephir_substr(return_value, text, 0 , zephir_get_intval(&_4), 0);
	RETURN_MM();

}

/**
 * 对需要加密的明文进行填充补位
 *
 * @param text 需要进行填充补位操作的明文
 * @return 补齐明文字符串
 *
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Core_Encryption, encode) {

	int ZEPHIR_LAST_CALL_STATUS, index;
	zval *text = NULL, *text_length = NULL, *amount_to_pad = NULL, *_0, *_1, *_2, *pad_chr = NULL, *tmp = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &text);

	if (!text) {
		ZEPHIR_INIT_VAR(text);
		ZVAL_STRING(text, "", 1);
	}


	ZEPHIR_INIT_VAR(text_length);
	ZVAL_LONG(text_length, zephir_fast_strlen_ev(text));
	_0 = zephir_fetch_static_property_ce(wechat_core_encryption_ce, SL("block_size") TSRMLS_CC);
	_1 = zephir_fetch_static_property_ce(wechat_core_encryption_ce, SL("block_size") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	mod_function(_2, text_length, _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(amount_to_pad);
	zephir_sub_function(amount_to_pad, _0, _2);
	if (ZEPHIR_IS_LONG(amount_to_pad, 0)) {
		ZEPHIR_OBS_NVAR(amount_to_pad);
		zephir_read_static_property_ce(&amount_to_pad, wechat_core_encryption_ce, SL("block_size") TSRMLS_CC);
	}
	ZEPHIR_CALL_FUNCTION(&pad_chr, "chr", NULL, 18, amount_to_pad);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(tmp);
	ZVAL_STRING(tmp, "", 1);
	index = 0;
	while (1) {
		if (ZEPHIR_IS_LONG(amount_to_pad, index)) {
			break;
		}
		zephir_concat_self(&tmp, pad_chr TSRMLS_CC);
		index++;
	}
	ZEPHIR_CONCAT_VV(return_value, text, tmp);
	RETURN_MM();

}

/**
 * 用SHA1算法生成安全签名
 *
 * @return array 成功返回数组status为0，错误返回错误信息
 *
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Core_Encryption, getSha1) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *token_param = NULL, *timestamp_param = NULL, *nonce_param = NULL, *encrypt_msg_param = NULL, *sortArray$$3 = NULL, *_0$$3, *str$$3 = NULL, *_1$$3 = NULL, *_2 = NULL;
	zval *token = NULL, *timestamp = NULL, *nonce = NULL, *encrypt_msg = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &token_param, &timestamp_param, &nonce_param, &encrypt_msg_param);

	if (!token_param) {
		ZEPHIR_INIT_VAR(token);
		ZVAL_STRING(token, "", 1);
	} else {
		zephir_get_strval(token, token_param);
	}
	if (!timestamp_param) {
		ZEPHIR_INIT_VAR(timestamp);
		ZVAL_STRING(timestamp, "", 1);
	} else {
		zephir_get_strval(timestamp, timestamp_param);
	}
	if (!nonce_param) {
		ZEPHIR_INIT_VAR(nonce);
		ZVAL_STRING(nonce, "", 1);
	} else {
		zephir_get_strval(nonce, nonce_param);
	}
	if (!encrypt_msg_param) {
		ZEPHIR_INIT_VAR(encrypt_msg);
		ZVAL_STRING(encrypt_msg, "", 1);
	} else {
		zephir_get_strval(encrypt_msg, encrypt_msg_param);
	}



	/* try_start_1: */

		ZEPHIR_INIT_VAR(sortArray$$3);
		zephir_create_array(sortArray$$3, 4, 0 TSRMLS_CC);
		zephir_array_fast_append(sortArray$$3, encrypt_msg);
		zephir_array_fast_append(sortArray$$3, token);
		zephir_array_fast_append(sortArray$$3, timestamp);
		zephir_array_fast_append(sortArray$$3, nonce);
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_LONG(_0$$3, 2);
		ZEPHIR_MAKE_REF(sortArray$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "sort", NULL, 19, sortArray$$3, _0$$3);
		ZEPHIR_UNREF(sortArray$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(str$$3);
		zephir_fast_join_str(str$$3, SL(""), sortArray$$3 TSRMLS_CC);
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		add_assoc_long_ex(return_value, SS("status"), 0);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "sha1", NULL, 20, str$$3);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_array_update_string(&return_value, SL("info"), &_1$$3, PH_COPY | PH_SEPARATE);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CPY_WRT(_2, EG(exception));
		if (zephir_instance_of_ev(_2, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			zephir_create_array(return_value, 2, 0 TSRMLS_CC);
			add_assoc_long_ex(return_value, SS("status"), -40003);
			add_assoc_stringl_ex(return_value, SS("info"), SL("sha加密生成签名失败"), 1);
			RETURN_MM();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 生成xml消息
 *
 * @param string $encrypt 加密后的消息密文
 * @param string $signature 安全签名
 * @param string $timestamp 时间戳
 * @param string $nonce 随机字符串
 *
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Core_Encryption, generate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *encrypt = NULL, *signature = NULL, *timestamp = NULL, *nonce = NULL, *format = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &encrypt, &signature, &timestamp, &nonce);

	if (!encrypt) {
		encrypt = ZEPHIR_GLOBAL(global_null);
	}
	if (!signature) {
		signature = ZEPHIR_GLOBAL(global_null);
	}
	if (!timestamp) {
		timestamp = ZEPHIR_GLOBAL(global_null);
	}
	if (!nonce) {
		nonce = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(format);
	ZVAL_STRING(format, "<xml>\n<Encrypt><![CDATA[%s]]></Encrypt>\n<MsgSignature><![CDATA[%s]]></MsgSignature>\n<TimeStamp>%s</TimeStamp>\n<Nonce><![CDATA[%s]]></Nonce>\n</xml>", 1);
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 21, format, encrypt, signature, timestamp, nonce);
	zephir_check_call_status();
	RETURN_MM();

}

