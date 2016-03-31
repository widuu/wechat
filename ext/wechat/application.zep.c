
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


ZEPHIR_INIT_CLASS(Wechat_Application) {

	ZEPHIR_REGISTER_CLASS_EX(Wechat, Application, wechat, application, wechat_wechat_ce, wechat_application_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Wechat_Application, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *Config = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &Config);

	if (!Config) {
		Config = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_PARENT(NULL, wechat_application_ce, this_ptr, "__construct", &_0, 2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

