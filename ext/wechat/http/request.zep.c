
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
#include "kernel/file.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * 请求处理类库
 */
ZEPHIR_INIT_CLASS(Wechat_Http_Request) {

	ZEPHIR_REGISTER_CLASS(Wechat\\Http, Request, wechat, http_request, wechat_http_request_method_entry, 0);

	return SUCCESS;

}

/**
 * 接收POST的XML数据 并返回解析后的数组
 * @return array|boolean 返回解析后的数组或者解释失败返回false
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Http_Request, getRequest) {

	zval *postData = NULL, _0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "php://input", 0);
	ZEPHIR_INIT_VAR(postData);
	zephir_file_get_contents(postData, &_0 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "xmltoarray", NULL, 0, postData);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 将XML数据转换成数组
 * @return array|boolean 返回解析后的数组或者解释失败返回false
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Http_Request, xmlToArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *xmlStr_param = NULL, *requestInfo = NULL, *xmlData = NULL, _0$$3, _1$$3;
	zval *xmlStr = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &xmlStr_param);

	if (!xmlStr_param) {
		ZEPHIR_INIT_VAR(xmlStr);
		ZVAL_STRING(xmlStr, "", 1);
	} else {
	if (unlikely(Z_TYPE_P(xmlStr_param) != IS_STRING && Z_TYPE_P(xmlStr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'xmlStr' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(xmlStr_param) == IS_STRING)) {
		zephir_get_strval(xmlStr, xmlStr_param);
	} else {
		ZEPHIR_INIT_VAR(xmlStr);
		ZVAL_EMPTY_STRING(xmlStr);
	}
	}


	if (!(ZEPHIR_IS_EMPTY(xmlStr))) {
		ZEPHIR_CALL_FUNCTION(NULL, "libxml_disable_entity_loader", NULL, 29, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, "SimpleXMLElement", 0);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, 16384);
		ZEPHIR_CALL_FUNCTION(&xmlData, "simplexml_load_string", NULL, 30, xmlStr, &_0$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&requestInfo, "get_object_vars", NULL, 31, xmlData);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(requestInfo);
		ZVAL_BOOL(requestInfo, 0);
	}
	RETURN_CCTOR(requestInfo);

}

