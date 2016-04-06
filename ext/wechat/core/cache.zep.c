
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Wechat_Core_Cache) {

	ZEPHIR_REGISTER_INTERFACE(Wechat\\Core, Cache, wechat, core_cache, wechat_core_cache_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Wechat_Core_Cache, setCache);

ZEPHIR_DOC_METHOD(Wechat_Core_Cache, getCache);

ZEPHIR_DOC_METHOD(Wechat_Core_Cache, delete);

ZEPHIR_DOC_METHOD(Wechat_Core_Cache, flush);

