
extern zend_class_entry *wechat_core_encryption_ce;

ZEPHIR_INIT_CLASS(Wechat_Core_Encryption);

PHP_METHOD(Wechat_Core_Encryption, setToken);
PHP_METHOD(Wechat_Core_Encryption, getToken);
PHP_METHOD(Wechat_Core_Encryption, setEncodingAesKey);
PHP_METHOD(Wechat_Core_Encryption, getEncodingAesKey);
PHP_METHOD(Wechat_Core_Encryption, setAppId);
PHP_METHOD(Wechat_Core_Encryption, getAppId);
PHP_METHOD(Wechat_Core_Encryption, __construct);
PHP_METHOD(Wechat_Core_Encryption, decryptMsg);
PHP_METHOD(Wechat_Core_Encryption, encryptMsg);
PHP_METHOD(Wechat_Core_Encryption, encrypt);
PHP_METHOD(Wechat_Core_Encryption, decrypt);
PHP_METHOD(Wechat_Core_Encryption, getRandomStr);
PHP_METHOD(Wechat_Core_Encryption, getKey);
PHP_METHOD(Wechat_Core_Encryption, decode);
PHP_METHOD(Wechat_Core_Encryption, encode);
PHP_METHOD(Wechat_Core_Encryption, getSha1);
PHP_METHOD(Wechat_Core_Encryption, generate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_encryption_settoken, 0, 0, 1)
	ZEND_ARG_INFO(0, token)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_encryption_setencodingaeskey, 0, 0, 1)
	ZEND_ARG_INFO(0, encoding_aes_key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_encryption_setappid, 0, 0, 1)
	ZEND_ARG_INFO(0, app_id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_encryption___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, token)
	ZEND_ARG_INFO(0, encodingAesKey)
	ZEND_ARG_INFO(0, appId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_encryption_decryptmsg, 0, 0, 0)
	ZEND_ARG_INFO(0, msgSignature)
	ZEND_ARG_INFO(0, timestamp)
	ZEND_ARG_INFO(0, nonce)
	ZEND_ARG_INFO(0, postData)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_encryption_encryptmsg, 0, 0, 0)
	ZEND_ARG_INFO(0, replyMsg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_encryption_encrypt, 0, 0, 0)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, appid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_encryption_decrypt, 0, 0, 0)
	ZEND_ARG_INFO(0, encrypted)
	ZEND_ARG_INFO(0, appid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_encryption_getkey, 0, 0, 0)
	ZEND_ARG_INFO(0, k)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_encryption_decode, 0, 0, 0)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_encryption_encode, 0, 0, 0)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_encryption_getsha1, 0, 0, 0)
	ZEND_ARG_INFO(0, token)
	ZEND_ARG_INFO(0, timestamp)
	ZEND_ARG_INFO(0, nonce)
	ZEND_ARG_INFO(0, encrypt_msg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_core_encryption_generate, 0, 0, 0)
	ZEND_ARG_INFO(0, encrypt)
	ZEND_ARG_INFO(0, signature)
	ZEND_ARG_INFO(0, timestamp)
	ZEND_ARG_INFO(0, nonce)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wechat_core_encryption_method_entry) {
	PHP_ME(Wechat_Core_Encryption, setToken, arginfo_wechat_core_encryption_settoken, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_Encryption, getToken, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_Encryption, setEncodingAesKey, arginfo_wechat_core_encryption_setencodingaeskey, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_Encryption, getEncodingAesKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_Encryption, setAppId, arginfo_wechat_core_encryption_setappid, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_Encryption, getAppId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_Encryption, __construct, arginfo_wechat_core_encryption___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Wechat_Core_Encryption, decryptMsg, arginfo_wechat_core_encryption_decryptmsg, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_Encryption, encryptMsg, arginfo_wechat_core_encryption_encryptmsg, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_Encryption, encrypt, arginfo_wechat_core_encryption_encrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_Encryption, decrypt, arginfo_wechat_core_encryption_decrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_Encryption, getRandomStr, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_Encryption, getKey, arginfo_wechat_core_encryption_getkey, ZEND_ACC_PRIVATE)
	PHP_ME(Wechat_Core_Encryption, decode, arginfo_wechat_core_encryption_decode, ZEND_ACC_PRIVATE)
	PHP_ME(Wechat_Core_Encryption, encode, arginfo_wechat_core_encryption_encode, ZEND_ACC_PRIVATE)
	PHP_ME(Wechat_Core_Encryption, getSha1, arginfo_wechat_core_encryption_getsha1, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Core_Encryption, generate, arginfo_wechat_core_encryption_generate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
