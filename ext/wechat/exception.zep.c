
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Wechat_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Wechat, Exception, wechat, exception, zend_exception_get_default(TSRMLS_C), wechat_exception_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Wechat_Exception, __construct) {

	int code, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *code_param = NULL, *previous = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &message_param, &code_param, &previous);

	if (!message_param) {
		ZEPHIR_INIT_VAR(message);
		ZVAL_STRING(message, "", 1);
	} else {
	if (unlikely(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	}
	if (!code_param) {
		code = 0;
	} else {
		code = zephir_get_intval(code_param);
	}
	if (!previous) {
		previous = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, code);
	ZEPHIR_CALL_PARENT(NULL, wechat_exception_ce, this_ptr, "__construct", NULL, message, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

