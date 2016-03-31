
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_WECHAT_H
#define PHP_WECHAT_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_WECHAT_NAME        "wechat"
#define PHP_WECHAT_VERSION     "0.0.2"
#define PHP_WECHAT_EXTNAME     "wechat"
#define PHP_WECHAT_AUTHOR      "widuu<admin@widuu.com>"
#define PHP_WECHAT_ZEPVERSION  "0.9.2a-dev"
#define PHP_WECHAT_DESCRIPTION "The Wechat Collections Framework"



ZEND_BEGIN_MODULE_GLOBALS(wechat)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(wechat)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(wechat)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(wechat_globals_id, zend_wechat_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (wechat_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_wechat_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(wechat_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(wechat_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def wechat_globals
#define zend_zephir_globals_def zend_wechat_globals

extern zend_module_entry wechat_module_entry;
#define phpext_wechat_ptr &wechat_module_entry

#endif
