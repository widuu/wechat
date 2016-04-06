PHP_ARG_ENABLE(wechat, whether to enable wechat, [ --enable-wechat   Enable Wechat])

if test "$PHP_WECHAT" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, WECHAT_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_WECHAT, 1, [Whether you have Wechat])
	wechat_sources="wechat.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c wechat/core/cache.zep.c
	wechat/wechatabstract.zep.c
	wechat/core/config.zep.c
	wechat/core/encryption.zep.c
	wechat/core/filecache.zep.c
	wechat/core/http.zep.c
	wechat/core/service.zep.c
	wechat/exception.zep.c
	wechat/http/exception.zep.c
	wechat/http/http.zep.c
	wechat/http/request.zep.c
	wechat/js/sdk.zep.c
	wechat/wechat.zep.c "
	PHP_NEW_EXTENSION(wechat, $wechat_sources, $ext_shared,, )
	PHP_SUBST(WECHAT_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([wechat], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([wechat], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/wechat], [php_WECHAT.h])

fi
