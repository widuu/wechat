
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "wechat.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *wechat_wechatabstract_ce;
zend_class_entry *wechat_exception_ce;
zend_class_entry *wechat_wechat_ce;

ZEND_DECLARE_MODULE_GLOBALS(wechat)

static PHP_MINIT_FUNCTION(wechat)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	ZEPHIR_INIT(Wechat_Wechatabstract);
	ZEPHIR_INIT(Wechat_Exception);
	ZEPHIR_INIT(Wechat_Wechat);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(wechat)
{

	zephir_deinitialize_memory(TSRMLS_C);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_wechat_globals *zephir_globals TSRMLS_DC)
{
	zephir_globals->initialized = 0;

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	zephir_globals->cache_enabled = 1;

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;

	zephir_globals->curl_timeout = 1;

}

static PHP_RINIT_FUNCTION(wechat)
{

	zend_wechat_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zephir_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(zephir_globals_ptr TSRMLS_CC);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(wechat)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(wechat)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_WECHAT_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_WECHAT_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_WECHAT_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_WECHAT_VERSION);
	php_info_print_table_end();


}

static PHP_GINIT_FUNCTION(wechat)
{
	php_zephir_init_globals(wechat_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(wechat)
{

}


zend_function_entry php_wechat_functions[] = {
ZEND_FE_END

};

zend_module_entry wechat_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_WECHAT_EXTNAME,
	php_wechat_functions,
	PHP_MINIT(wechat),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(wechat),
#else
	NULL,
#endif
	PHP_RINIT(wechat),
	PHP_RSHUTDOWN(wechat),
	PHP_MINFO(wechat),
	PHP_WECHAT_VERSION,
	ZEND_MODULE_GLOBALS(wechat),
	PHP_GINIT(wechat),
	PHP_GSHUTDOWN(wechat),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_WECHAT
ZEND_GET_MODULE(wechat)
#endif
