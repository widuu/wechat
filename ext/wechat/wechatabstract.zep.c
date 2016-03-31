
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


ZEPHIR_INIT_CLASS(Wechat_WechatAbstract) {

	ZEPHIR_REGISTER_CLASS(Wechat, WechatAbstract, wechat, wechatabstract, wechat_wechatabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(wechat_wechatabstract_ce, SL("_rowbody"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * List of registered services
	 */
	zend_declare_property_null(wechat_wechatabstract_ce, SL("_services"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * AppId
	 */
	zend_declare_property_null(wechat_wechatabstract_ce, SL("_app_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * AppSecret
	 */
	zend_declare_property_null(wechat_wechatabstract_ce, SL("_app_secret"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Token
	 */
	zend_declare_property_null(wechat_wechatabstract_ce, SL("_token"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * EncodingAESKey
	 */
	zend_declare_property_null(wechat_wechatabstract_ce, SL("_ase_key"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 是否加密
	 */
	zend_declare_property_bool(wechat_wechatabstract_ce, SL("_aes"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Wechat_WechatAbstract, setRowbody) {

	zval *rowbody;

	zephir_fetch_params(0, 1, 0, &rowbody);



	zephir_update_property_this(this_ptr, SL("_rowbody"), rowbody TSRMLS_CC);

}

PHP_METHOD(Wechat_WechatAbstract, getRowbody) {

	

	RETURN_MEMBER(this_ptr, "_rowbody");

}

/**
 * List of registered services
 */
PHP_METHOD(Wechat_WechatAbstract, setServices) {

	zval *services;

	zephir_fetch_params(0, 1, 0, &services);



	zephir_update_property_this(this_ptr, SL("_services"), services TSRMLS_CC);

}

/**
 * List of registered services
 */
PHP_METHOD(Wechat_WechatAbstract, getServices) {

	

	RETURN_MEMBER(this_ptr, "_services");

}

/**
 * AppId
 */
PHP_METHOD(Wechat_WechatAbstract, setAppId) {

	zval *app_id;

	zephir_fetch_params(0, 1, 0, &app_id);



	zephir_update_property_this(this_ptr, SL("_app_id"), app_id TSRMLS_CC);

}

/**
 * AppId
 */
PHP_METHOD(Wechat_WechatAbstract, getAppId) {

	

	RETURN_MEMBER(this_ptr, "_app_id");

}

/**
 * AppSecret
 */
PHP_METHOD(Wechat_WechatAbstract, setAppSecret) {

	zval *app_secret;

	zephir_fetch_params(0, 1, 0, &app_secret);



	zephir_update_property_this(this_ptr, SL("_app_secret"), app_secret TSRMLS_CC);

}

/**
 * AppSecret
 */
PHP_METHOD(Wechat_WechatAbstract, getAppSecret) {

	

	RETURN_MEMBER(this_ptr, "_app_secret");

}

/**
 * Token
 */
PHP_METHOD(Wechat_WechatAbstract, setToken) {

	zval *token;

	zephir_fetch_params(0, 1, 0, &token);



	zephir_update_property_this(this_ptr, SL("_token"), token TSRMLS_CC);

}

/**
 * Token
 */
PHP_METHOD(Wechat_WechatAbstract, getToken) {

	

	RETURN_MEMBER(this_ptr, "_token");

}

/**
 * EncodingAESKey
 */
PHP_METHOD(Wechat_WechatAbstract, setAseKey) {

	zval *ase_key;

	zephir_fetch_params(0, 1, 0, &ase_key);



	zephir_update_property_this(this_ptr, SL("_ase_key"), ase_key TSRMLS_CC);

}

/**
 * EncodingAESKey
 */
PHP_METHOD(Wechat_WechatAbstract, getAseKey) {

	

	RETURN_MEMBER(this_ptr, "_ase_key");

}

/**
 * 是否加密
 */
PHP_METHOD(Wechat_WechatAbstract, setAes) {

	zval *aes;

	zephir_fetch_params(0, 1, 0, &aes);



	zephir_update_property_this(this_ptr, SL("_aes"), aes TSRMLS_CC);

}

/**
 * 是否加密
 */
PHP_METHOD(Wechat_WechatAbstract, getAes) {

	

	RETURN_MEMBER(this_ptr, "_aes");

}

