
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Wechat_Wechat) {

	ZEPHIR_REGISTER_CLASS_EX(Wechat, Wechat, wechat, wechat, wechat_wechatabstract_ce, wechat_wechat_method_entry, 0);

	/**
	 * 发送者id
	 */
	zend_declare_property_null(wechat_wechat_ce, SL("_tousername"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * wechat id
	 */
	zend_declare_property_null(wechat_wechat_ce, SL("_fromusername"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 事件类型
	 */
	zend_declare_property_null(wechat_wechat_ce, SL("_msgtype"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 事件
	 */
	zend_declare_property_null(wechat_wechat_ce, SL("_event"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 创建时间
	 */
	zend_declare_property_null(wechat_wechat_ce, SL("_createtime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 文本消息内容	
	 */
	zend_declare_property_null(wechat_wechat_ce, SL("_content"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 消息id
	 */
	zend_declare_property_null(wechat_wechat_ce, SL("_msgid"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 图片链接
	 */
	zend_declare_property_null(wechat_wechat_ce, SL("_picurl"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 媒体id
	 */
	zend_declare_property_null(wechat_wechat_ce, SL("_mediaid"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 语音格式
	 */
	zend_declare_property_null(wechat_wechat_ce, SL("_format"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 缩略图的媒体id
	 */
	zend_declare_property_null(wechat_wechat_ce, SL("_thumbmediaid"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 地理位置维度
	 */
	zend_declare_property_null(wechat_wechat_ce, SL("_location_x"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 地理位置经度
	 */
	zend_declare_property_null(wechat_wechat_ce, SL("_location_y"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 地图缩放大小
	 */
	zend_declare_property_null(wechat_wechat_ce, SL("_scale"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 地理位置信息
	 */
	zend_declare_property_null(wechat_wechat_ce, SL("_label"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 消息标题
	 */
	zend_declare_property_null(wechat_wechat_ce, SL("_title"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 消息描述
	 */
	zend_declare_property_null(wechat_wechat_ce, SL("_description"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 消息链接
	 */
	zend_declare_property_null(wechat_wechat_ce, SL("_url"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * TOKEN URL
	 */
	zend_declare_class_constant_string(wechat_wechat_ce, SL("TOKEN_URL"), "https://api.weixin.qq.com/cgi-bin/token?" TSRMLS_CC);

	/**
	 * User URL
	 */
	zend_declare_class_constant_string(wechat_wechat_ce, SL("USER_URL"), "https://api.weixin.qq.com/cgi-bin/user/" TSRMLS_CC);

	/**
	 * Menu URL
	 */
	zend_declare_class_constant_string(wechat_wechat_ce, SL("MENU_URL"), "https://api.weixin.qq.com/cgi-bin/menu/" TSRMLS_CC);

	return SUCCESS;

}

/**
 * 发送者id
 */
PHP_METHOD(Wechat_Wechat, getTousername) {


	RETURN_MEMBER(this_ptr, "_tousername");

}

/**
 * 发送者id
 */
PHP_METHOD(Wechat_Wechat, setTousername) {

	zval *tousername;

	zephir_fetch_params(0, 1, 0, &tousername);



	zephir_update_property_this(this_ptr, SL("_tousername"), tousername TSRMLS_CC);

}

/**
 * wechat id
 */
PHP_METHOD(Wechat_Wechat, getFromusername) {


	RETURN_MEMBER(this_ptr, "_fromusername");

}

/**
 * wechat id
 */
PHP_METHOD(Wechat_Wechat, setFromusername) {

	zval *fromusername;

	zephir_fetch_params(0, 1, 0, &fromusername);



	zephir_update_property_this(this_ptr, SL("_fromusername"), fromusername TSRMLS_CC);

}

/**
 * 事件类型
 */
PHP_METHOD(Wechat_Wechat, getMsgtype) {


	RETURN_MEMBER(this_ptr, "_msgtype");

}

/**
 * 事件类型
 */
PHP_METHOD(Wechat_Wechat, setMsgtype) {

	zval *msgtype;

	zephir_fetch_params(0, 1, 0, &msgtype);



	zephir_update_property_this(this_ptr, SL("_msgtype"), msgtype TSRMLS_CC);

}

/**
 * 事件
 */
PHP_METHOD(Wechat_Wechat, getEvent) {


	RETURN_MEMBER(this_ptr, "_event");

}

/**
 * 事件
 */
PHP_METHOD(Wechat_Wechat, setEvent) {

	zval *event;

	zephir_fetch_params(0, 1, 0, &event);



	zephir_update_property_this(this_ptr, SL("_event"), event TSRMLS_CC);

}

/**
 * 创建时间
 */
PHP_METHOD(Wechat_Wechat, getCreatetime) {


	RETURN_MEMBER(this_ptr, "_createtime");

}

/**
 * 创建时间
 */
PHP_METHOD(Wechat_Wechat, setCreatetime) {

	zval *createtime;

	zephir_fetch_params(0, 1, 0, &createtime);



	zephir_update_property_this(this_ptr, SL("_createtime"), createtime TSRMLS_CC);

}

/**
 * 文本消息内容	
 */
PHP_METHOD(Wechat_Wechat, getContent) {


	RETURN_MEMBER(this_ptr, "_content");

}

/**
 * 文本消息内容	
 */
PHP_METHOD(Wechat_Wechat, setContent) {

	zval *content;

	zephir_fetch_params(0, 1, 0, &content);



	zephir_update_property_this(this_ptr, SL("_content"), content TSRMLS_CC);

}

/**
 * 消息id
 */
PHP_METHOD(Wechat_Wechat, getMsgid) {


	RETURN_MEMBER(this_ptr, "_msgid");

}

/**
 * 消息id
 */
PHP_METHOD(Wechat_Wechat, setMsgid) {

	zval *msgid;

	zephir_fetch_params(0, 1, 0, &msgid);



	zephir_update_property_this(this_ptr, SL("_msgid"), msgid TSRMLS_CC);

}

/**
 * 图片链接
 */
PHP_METHOD(Wechat_Wechat, getPicurl) {


	RETURN_MEMBER(this_ptr, "_picurl");

}

/**
 * 图片链接
 */
PHP_METHOD(Wechat_Wechat, setPicurl) {

	zval *picurl;

	zephir_fetch_params(0, 1, 0, &picurl);



	zephir_update_property_this(this_ptr, SL("_picurl"), picurl TSRMLS_CC);

}

/**
 * 媒体id
 */
PHP_METHOD(Wechat_Wechat, getMediaid) {


	RETURN_MEMBER(this_ptr, "_mediaid");

}

/**
 * 媒体id
 */
PHP_METHOD(Wechat_Wechat, setMediaid) {

	zval *mediaid;

	zephir_fetch_params(0, 1, 0, &mediaid);



	zephir_update_property_this(this_ptr, SL("_mediaid"), mediaid TSRMLS_CC);

}

/**
 * 语音格式
 */
PHP_METHOD(Wechat_Wechat, getFormat) {


	RETURN_MEMBER(this_ptr, "_format");

}

/**
 * 语音格式
 */
PHP_METHOD(Wechat_Wechat, setFormat) {

	zval *format;

	zephir_fetch_params(0, 1, 0, &format);



	zephir_update_property_this(this_ptr, SL("_format"), format TSRMLS_CC);

}

/**
 * 缩略图的媒体id
 */
PHP_METHOD(Wechat_Wechat, getThumbmediaid) {


	RETURN_MEMBER(this_ptr, "_thumbmediaid");

}

/**
 * 缩略图的媒体id
 */
PHP_METHOD(Wechat_Wechat, setThumbmediaid) {

	zval *thumbmediaid;

	zephir_fetch_params(0, 1, 0, &thumbmediaid);



	zephir_update_property_this(this_ptr, SL("_thumbmediaid"), thumbmediaid TSRMLS_CC);

}

/**
 * 地理位置维度
 */
PHP_METHOD(Wechat_Wechat, getLocation_x) {


	RETURN_MEMBER(this_ptr, "_location_x");

}

/**
 * 地理位置维度
 */
PHP_METHOD(Wechat_Wechat, setLocation_x) {

	zval *location_x;

	zephir_fetch_params(0, 1, 0, &location_x);



	zephir_update_property_this(this_ptr, SL("_location_x"), location_x TSRMLS_CC);

}

/**
 * 地理位置经度
 */
PHP_METHOD(Wechat_Wechat, getLocation_y) {


	RETURN_MEMBER(this_ptr, "_location_y");

}

/**
 * 地理位置经度
 */
PHP_METHOD(Wechat_Wechat, setLocation_y) {

	zval *location_y;

	zephir_fetch_params(0, 1, 0, &location_y);



	zephir_update_property_this(this_ptr, SL("_location_y"), location_y TSRMLS_CC);

}

/**
 * 地图缩放大小
 */
PHP_METHOD(Wechat_Wechat, getScale) {


	RETURN_MEMBER(this_ptr, "_scale");

}

/**
 * 地图缩放大小
 */
PHP_METHOD(Wechat_Wechat, setScale) {

	zval *scale;

	zephir_fetch_params(0, 1, 0, &scale);



	zephir_update_property_this(this_ptr, SL("_scale"), scale TSRMLS_CC);

}

/**
 * 地理位置信息
 */
PHP_METHOD(Wechat_Wechat, getLabel) {


	RETURN_MEMBER(this_ptr, "_label");

}

/**
 * 地理位置信息
 */
PHP_METHOD(Wechat_Wechat, setLabel) {

	zval *label;

	zephir_fetch_params(0, 1, 0, &label);



	zephir_update_property_this(this_ptr, SL("_label"), label TSRMLS_CC);

}

/**
 * 消息标题
 */
PHP_METHOD(Wechat_Wechat, getTitle) {


	RETURN_MEMBER(this_ptr, "_title");

}

/**
 * 消息标题
 */
PHP_METHOD(Wechat_Wechat, setTitle) {

	zval *title;

	zephir_fetch_params(0, 1, 0, &title);



	zephir_update_property_this(this_ptr, SL("_title"), title TSRMLS_CC);

}

/**
 * 消息描述
 */
PHP_METHOD(Wechat_Wechat, getDescription) {


	RETURN_MEMBER(this_ptr, "_description");

}

/**
 * 消息描述
 */
PHP_METHOD(Wechat_Wechat, setDescription) {

	zval *description;

	zephir_fetch_params(0, 1, 0, &description);



	zephir_update_property_this(this_ptr, SL("_description"), description TSRMLS_CC);

}

/**
 * 消息链接
 */
PHP_METHOD(Wechat_Wechat, getUrl) {


	RETURN_MEMBER(this_ptr, "_url");

}

/**
 * 消息链接
 */
PHP_METHOD(Wechat_Wechat, setUrl) {

	zval *url;

	zephir_fetch_params(0, 1, 0, &url);



	zephir_update_property_this(this_ptr, SL("_url"), url TSRMLS_CC);

}

/**
 * 接收 POST 信息
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, getRequest) {

	HashTable *_11;
	HashPosition _10;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *key = NULL, *value = NULL, *_2 = NULL, *_3 = NULL, *_4, *_5, _6, *_7 = NULL, *_8 = NULL, *_9, **_12, *_13 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "ispost", &_1);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_3);
		ZVAL_BOOL(_3, 1);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getinfo", NULL, _3);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_request_data"), _2 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_debug"), PH_NOISY_CC);
		if (zephir_is_true(_4)) {
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("_request_data"), PH_NOISY_CC);
			if (ZEPHIR_IS_EMPTY(_5)) {
				ZEPHIR_INIT_NVAR(_3);
				zephir_time(_3);
				ZEPHIR_SINIT_VAR(_6);
				ZVAL_STRING(&_6, "Y-m-d H:i:s", 0);
				ZEPHIR_CALL_FUNCTION(&_7, "date", NULL, &_6, _3);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_8);
				ZEPHIR_CONCAT_SVS(_8, "[ERROR", _7, "] Request Data NULL\r\n");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, _8);
				zephir_check_call_status();
			}
		}
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_request_data"), PH_NOISY_CC);
		if (!(ZEPHIR_IS_EMPTY(_5))) {
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("_request_data"), PH_NOISY_CC);
			zephir_is_iterable(_9, &_11, &_10, 0, 0, "wechat/Wechat.zep", 154);
			for (
			  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
			  ; zephir_hash_move_forward_ex(_11, &_10)
			) {
				ZEPHIR_GET_HMKEY(key, _11, _10);
				ZEPHIR_GET_HVALUE(value, _12);
				ZEPHIR_INIT_NVAR(_13);
				zephir_fast_strtolower(_13, key);
				ZEPHIR_INIT_LNVAR(_8);
				ZEPHIR_CONCAT_SV(_8, "_", _13);
				ZEPHIR_CPY_WRT(key, _8);
				if (zephir_isset_property_zval(this_ptr, key TSRMLS_CC)) {
					zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
				}
			}
			RETURN_MM_MEMBER(this_ptr, "_request_data");
		}
	} else {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 返回消息方法
 * @param  string type
 * @param  (array|string) type
 * @return boolean
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, response) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *info, *_0, *tpl = NULL, *_1, *_2, _3, *_4 = NULL, *_5;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &type_param, &info);

	if (!type_param) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	} else {
	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_request_data"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&tpl, this_ptr, "gettpl", NULL, type, info);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_debug"), PH_NOISY_CC);
	if (zephir_is_true(_1)) {
		if (ZEPHIR_IS_EMPTY(tpl)) {
			ZEPHIR_INIT_VAR(_2);
			zephir_time(_2);
			ZEPHIR_SINIT_VAR(_3);
			ZVAL_STRING(&_3, "Y-m-d H:i:s", 0);
			ZEPHIR_CALL_FUNCTION(&_4, "date", NULL, &_3, _2);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_5);
			ZEPHIR_CONCAT_SVS(_5, "[ERROR", _4, "] Get Response XML Type Error\r\n");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, _5);
			zephir_check_call_status();
		}
	}
	zend_print_zval(tpl, 0);
	ZEPHIR_MM_RESTORE();

}

/**
 * 订阅事件
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, subscribe) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *info, *_0, *_1;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &type_param, &info);

	if (!type_param) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_STRING(type, "text", 1);
	} else {
	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_request_data"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		RETURN_MM_BOOL(0);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_event"), PH_NOISY_CC);
	if (ZEPHIR_IS_STRING(_1, "subscribe")) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "response", NULL, type, info);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取Token
 * @param string appid 
 * @param string secret
 * @return array
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, getToken) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *appid_param = NULL, *secret_param = NULL, *_1, *_2, *_3, *tokenUrl, *urlQurey, *result = NULL, *_5 = NULL;
	zval *appid = NULL, *secret = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &appid_param, &secret_param);

	if (!appid_param) {
		ZEPHIR_INIT_VAR(appid);
		ZVAL_STRING(appid, "", 1);
	} else {
	if (unlikely(Z_TYPE_P(appid_param) != IS_STRING && Z_TYPE_P(appid_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'appid' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(appid_param) == IS_STRING)) {
		zephir_get_strval(appid, appid_param);
	} else {
		ZEPHIR_INIT_VAR(appid);
		ZVAL_EMPTY_STRING(appid);
	}
	}
	if (!secret_param) {
		ZEPHIR_INIT_VAR(secret);
		ZVAL_STRING(secret, "", 1);
	} else {
	if (unlikely(Z_TYPE_P(secret_param) != IS_STRING && Z_TYPE_P(secret_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'secret' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(secret_param) == IS_STRING)) {
		zephir_get_strval(secret, secret_param);
	} else {
		ZEPHIR_INIT_VAR(secret);
		ZVAL_EMPTY_STRING(secret);
	}
	}


	_0 = ZEPHIR_IS_EMPTY(appid);
	if (!(_0)) {
		_0 = ZEPHIR_IS_EMPTY(secret);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, wechat_exception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "getToken Method Parameter does not allow nulls", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_LONG(_3, 4001);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_4, _2, _3);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "wechat/Wechat.zep", 211 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(urlQurey);
	zephir_create_array(urlQurey, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(urlQurey, SS("grant_type"), SL("client_credential"), 1);
	zephir_array_update_string(&urlQurey, SL("appid"), &appid, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&urlQurey, SL("secret"), &secret, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_5, "http_build_query", &_6, urlQurey);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(tokenUrl);
	ZEPHIR_CONCAT_SV(tokenUrl, "https://api.weixin.qq.com/cgi-bin/token?", _5);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "httpget", NULL, tokenUrl);
	zephir_check_call_status();
	zephir_json_decode(return_value, &(return_value), result, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
	RETURN_MM();

}

/**
 * 获取用户信息
 * @param string type 
 * @param string token
 * @param string openid
 * @return array
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, getUser) {

	zephir_fcall_cache_entry *_7 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *type_param = NULL, *token_param = NULL, *openid_param = NULL, *_1, *_2, *_3, *url = NULL, *param = NULL, *result = NULL, *_5 = NULL;
	zval *type = NULL, *token = NULL, *openid = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &type_param, &token_param, &openid_param);

	if (!type_param) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	} else {
	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
	}
	if (!token_param) {
		ZEPHIR_INIT_VAR(token);
		ZVAL_STRING(token, "", 1);
	} else {
	if (unlikely(Z_TYPE_P(token_param) != IS_STRING && Z_TYPE_P(token_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'token' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(token_param) == IS_STRING)) {
		zephir_get_strval(token, token_param);
	} else {
		ZEPHIR_INIT_VAR(token);
		ZVAL_EMPTY_STRING(token);
	}
	}
	if (!openid_param) {
		ZEPHIR_INIT_VAR(openid);
		ZVAL_STRING(openid, "", 1);
	} else {
		zephir_get_strval(openid, openid_param);
	}


	_0 = ZEPHIR_IS_EMPTY(token);
	if (!(_0)) {
		_0 = ZEPHIR_IS_EMPTY(type);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, wechat_exception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "Parameter does not allow nulls", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_LONG(_3, 4002);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_4, _2, _3);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "wechat/Wechat.zep", 231 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		if (ZEPHIR_IS_STRING(type, "userinfo")) {
			ZEPHIR_INIT_VAR(param);
			zephir_create_array(param, 3, 0 TSRMLS_CC);
			zephir_array_update_string(&param, SL("access_token"), &token, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&param, SL("openid"), &openid, PH_COPY | PH_SEPARATE);
			add_assoc_stringl_ex(param, SS("lang"), SL("zh_CN"), 1);
			ZEPHIR_CALL_FUNCTION(&_5, "http_build_query", &_6, param);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(url);
			ZEPHIR_CONCAT_SSV(url, "https://api.weixin.qq.com/cgi-bin/user/", "info?", _5);
			ZEPHIR_CALL_METHOD(&result, this_ptr, "httpget", &_7, url);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(type, "userlist")) {
			ZEPHIR_INIT_NVAR(param);
			zephir_create_array(param, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&param, SL("access_token"), &token, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&param, SL("next_openid"), &openid, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_5, "http_build_query", &_6, param);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(url);
			ZEPHIR_CONCAT_SSV(url, "https://api.weixin.qq.com/cgi-bin/user/", "get?", _5);
			ZEPHIR_CALL_METHOD(&result, this_ptr, "httpget", &_7, url);
			zephir_check_call_status();
			break;
		}
		RETURN_MM_BOOL(0);
	} while(0);

	zephir_json_decode(return_value, &(return_value), result, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
	RETURN_MM();

}

/**
 * 设置用户备注
 * @param string token 
 * @param string openid
 * @param string remarke
 * @return array
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, setRemark) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *token_param = NULL, *openid_param = NULL, *remarke_param = NULL, *remarkUrl = NULL, *postInfo, *result = NULL;
	zval *token = NULL, *openid = NULL, *remarke = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &token_param, &openid_param, &remarke_param);

	if (!token_param) {
		ZEPHIR_INIT_VAR(token);
		ZVAL_EMPTY_STRING(token);
	} else {
	if (unlikely(Z_TYPE_P(token_param) != IS_STRING && Z_TYPE_P(token_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'token' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(token_param) == IS_STRING)) {
		zephir_get_strval(token, token_param);
	} else {
		ZEPHIR_INIT_VAR(token);
		ZVAL_EMPTY_STRING(token);
	}
	}
	if (!openid_param) {
		ZEPHIR_INIT_VAR(openid);
		ZVAL_EMPTY_STRING(openid);
	} else {
	if (unlikely(Z_TYPE_P(openid_param) != IS_STRING && Z_TYPE_P(openid_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'openid' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(openid_param) == IS_STRING)) {
		zephir_get_strval(openid, openid_param);
	} else {
		ZEPHIR_INIT_VAR(openid);
		ZVAL_EMPTY_STRING(openid);
	}
	}
	if (!remarke_param) {
		ZEPHIR_INIT_VAR(remarke);
		ZVAL_EMPTY_STRING(remarke);
	} else {
	if (unlikely(Z_TYPE_P(remarke_param) != IS_STRING && Z_TYPE_P(remarke_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'remarke' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(remarke_param) == IS_STRING)) {
		zephir_get_strval(remarke, remarke_param);
	} else {
		ZEPHIR_INIT_VAR(remarke);
		ZVAL_EMPTY_STRING(remarke);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SSV(_0, "https://api.weixin.qq.com/cgi-bin/user/", "info/updateremark?access_token=", token);
	ZEPHIR_CPY_WRT(remarkUrl, _0);
	ZEPHIR_INIT_VAR(postInfo);
	zephir_create_array(postInfo, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&postInfo, SL("openid"), &openid, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&postInfo, SL("remark"), &remarke, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "httppost", NULL, remarkUrl, postInfo);
	zephir_check_call_status();
	if (!(zephir_is_true(result))) {
		RETURN_MM_BOOL(0);
	}
	zephir_json_decode(return_value, &(return_value), result, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
	RETURN_MM();

}

/**
 * 获取自定义菜单
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, Menu) {

	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	zend_bool _2;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *info = NULL;
	zval *type_param = NULL, *token_param = NULL, *info_param = NULL, *menu_url = NULL, *result = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL;
	zval *type = NULL, *token = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &type_param, &token_param, &info_param);

	if (!type_param) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	} else {
	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
	}
	if (!token_param) {
		ZEPHIR_INIT_VAR(token);
		ZVAL_EMPTY_STRING(token);
	} else {
	if (unlikely(Z_TYPE_P(token_param) != IS_STRING && Z_TYPE_P(token_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'token' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(token_param) == IS_STRING)) {
		zephir_get_strval(token, token_param);
	} else {
		ZEPHIR_INIT_VAR(token);
		ZVAL_EMPTY_STRING(token);
	}
	}
	if (!info_param) {
	ZEPHIR_INIT_VAR(info);
	array_init(info);
	} else {
		zephir_get_arrval(info, info_param);
	}


	do {
		if (ZEPHIR_IS_STRING(type, "get")) {
			ZEPHIR_INIT_VAR(_0);
			ZEPHIR_CONCAT_SSV(_0, "https://api.weixin.qq.com/cgi-bin/menu/", "get?access_token=", token);
			ZEPHIR_CPY_WRT(menu_url, _0);
			ZEPHIR_CALL_METHOD(&result, this_ptr, "httpget", &_1, menu_url);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(type, "delete")) {
			ZEPHIR_INIT_LNVAR(_0);
			ZEPHIR_CONCAT_SSV(_0, "https://api.weixin.qq.com/cgi-bin/menu/", "delete?access_token=", token);
			ZEPHIR_CPY_WRT(menu_url, _0);
			ZEPHIR_CALL_METHOD(&result, this_ptr, "httpget", &_1, menu_url);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(type, "create")) {
			_2 = 1 != 1;
			if (!(_2)) {
				_2 = ZEPHIR_IS_EMPTY(info);
			}
			if (_2) {
				ZEPHIR_INIT_VAR(_3);
				object_init_ex(_3, wechat_exception_ce);
				ZEPHIR_INIT_VAR(_4);
				ZVAL_STRING(_4, "create param error", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_INIT_VAR(_5);
				ZVAL_LONG(_5, 4005);
				ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_6, _4, _5);
				zephir_check_temp_parameter(_4);
				zephir_check_call_status();
				zephir_throw_exception_debug(_3, "wechat/Wechat.zep", 290 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_LNVAR(_0);
			ZEPHIR_CONCAT_SSV(_0, "https://api.weixin.qq.com/cgi-bin/menu/", "create?access_token=", token);
			ZEPHIR_CPY_WRT(menu_url, _0);
			ZEPHIR_CALL_METHOD(&result, this_ptr, "httppost", NULL, menu_url, info);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	} while(0);

	if (!(ZEPHIR_IS_EMPTY(result))) {
		zephir_json_decode(return_value, &(return_value), result, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
		RETURN_MM();
	} else {
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, wechat_exception_ce);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "Response Error", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_LONG(_5, 4003);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_6, _4, _5);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "wechat/Wechat.zep", 301 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

}

/**
 * 获取变量的方法
 * @param  string name
 * @return boolean | string
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, _get) {

	zval *name_param = NULL, *_1;
	zval *name = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "_", name);
	ZEPHIR_CPY_WRT(name, _0);
	if (zephir_isset_property_zval(this_ptr, name TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property_zval(&_1, this_ptr, name, PH_NOISY_CC);
		RETURN_CCTOR(_1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * 设置变量的方法
 * @param string   name
 * @param 		   value
 * @return boolean 
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, _set) {

	zval *name_param = NULL, *value;
	zval *name = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "_", name);
	ZEPHIR_CPY_WRT(name, _0);
	if (zephir_isset_property_zval(this_ptr, name TSRMLS_CC)) {
		zephir_update_property_zval_zval(this_ptr, name, value TSRMLS_CC);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * 设置变量的方法
 * @param string   name
 * @param 		   value
 * @return boolean 
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, getTpl) {

	zephir_nts_static zephir_fcall_cache_entry *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *info, *tpl, *_0, *_1, *_2, *_3 = NULL, *_4, *_5, *_6, *_7, *_8, *num = NULL, *_9 = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &type_param, &info);

	if (!type_param) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	} else {
	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_fromusername"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_tousername"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_time(_2);
	ZEPHIR_INIT_VAR(tpl);
	ZEPHIR_CONCAT_SVSVSVSVS(tpl, "<xml><ToUserName><![CDATA[", _0, "]]></ToUserName><FromUserName><![CDATA[", _1, "]]></FromUserName><CreateTime>", _2, "</CreateTime><MsgType><![CDATA[", type, "]]></MsgType>");
	do {
		if (ZEPHIR_IS_STRING(type, "text")) {
			ZEPHIR_INIT_VAR(_3);
			ZEPHIR_CONCAT_SVS(_3, "<Content><![CDATA[", info, "]]></Content>");
			zephir_concat_self(&tpl, _3 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(type, "image")) {
			ZEPHIR_INIT_LNVAR(_3);
			ZEPHIR_CONCAT_SVS(_3, "<Image><MediaId><![CDATA[", info, "]]></MediaId></Image>");
			zephir_concat_self(&tpl, _3 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(type, "voice")) {
			ZEPHIR_INIT_LNVAR(_3);
			ZEPHIR_CONCAT_SVS(_3, "<Voice><MediaId><![CDATA[", info, "]]></MediaId></Voice>");
			zephir_concat_self(&tpl, _3 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(type, "video")) {
			ZEPHIR_INIT_LNVAR(_3);
			ZEPHIR_CONCAT_SVS(_3, "<Video><MediaId><![CDATA[", info, "]]></MediaId><Title><![CDATA[title]]></Title><Description><![CDATA[description]]></Description></Video> ");
			zephir_concat_self(&tpl, _3 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(type, "music")) {
			if (Z_TYPE_P(info) != IS_ARRAY) {
				RETURN_MM_BOOL(0);
			}
			zephir_array_fetch_string(&_4, info, SL("title"), PH_NOISY | PH_READONLY, "wechat/Wechat.zep", 366 TSRMLS_CC);
			zephir_array_fetch_string(&_5, info, SL("description"), PH_NOISY | PH_READONLY, "wechat/Wechat.zep", 366 TSRMLS_CC);
			zephir_array_fetch_string(&_6, info, SL("musicurl"), PH_NOISY | PH_READONLY, "wechat/Wechat.zep", 366 TSRMLS_CC);
			zephir_array_fetch_string(&_7, info, SL("hqmusicurl"), PH_NOISY | PH_READONLY, "wechat/Wechat.zep", 366 TSRMLS_CC);
			zephir_array_fetch_string(&_8, info, SL("mediaid"), PH_NOISY | PH_READONLY, "wechat/Wechat.zep", 366 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_3);
			ZEPHIR_CONCAT_SVSVSVSVSVS(_3, "<Music><Title><![CDATA[", _4, "]]></Title><Description><![CDATA[", _5, "]]></Description><MusicUrl><![CDATA[", _6, "]]></MusicUrl><HQMusicUrl><![CDATA[", _7, "]]></HQMusicUrl><ThumbMediaId><![CDATA[", _8, "]]></ThumbMediaId></Music>");
			zephir_concat_self(&tpl, _3 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(type, "news")) {
			if (Z_TYPE_P(info) != IS_ARRAY) {
				RETURN_MM_BOOL(0);
			}
			if (zephir_array_isset_string(info, SS("title"))) {
				ZEPHIR_INIT_VAR(num);
				ZVAL_LONG(num, 1);
			} else {
				ZEPHIR_INIT_NVAR(num);
				ZVAL_LONG(num, zephir_fast_count_int(info TSRMLS_CC));
			}
			ZEPHIR_CALL_METHOD(&_9, this_ptr, "getnews", &_10, info);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_3);
			ZEPHIR_CONCAT_SVSVS(_3, "<ArticleCount>", num, "</ArticleCount><Articles>", _9, "</Articles>");
			zephir_concat_self(&tpl, _3 TSRMLS_CC);
			break;
		}
		RETURN_MM_BOOL(0);
	} while(0);

	zephir_concat_self_str(&tpl, SL("</xml>") TSRMLS_CC);
	RETURN_CCTOR(tpl);

}

/**
 * 判断请求方法
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, isPost) {

	zval *_0, *_SERVER, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_array_fetch_string(&_1, _SERVER, SL("REQUEST_METHOD"), PH_NOISY | PH_READONLY, "wechat/Wechat.zep", 395 TSRMLS_CC);
	zephir_fast_strtolower(_0, _1);
	if (ZEPHIR_IS_STRING(_0, "post")) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * 获取新闻
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, getNews) {

	HashTable *_7;
	HashPosition _6;
	zval *info_param = NULL, *value = NULL, *tpl, *_0, *_1, *_2, *_3, *_4 = NULL, *_5 = NULL, **_8;
	zval *info = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &info_param);

	info = info_param;

	ZEPHIR_INIT_VAR(tpl);
	ZVAL_STRING(tpl, "", 1);


	if (zephir_array_isset_string(info, SS("title"))) {
		zephir_array_fetch_string(&_0, info, SL("title"), PH_NOISY | PH_READONLY, "wechat/Wechat.zep", 409 TSRMLS_CC);
		zephir_array_fetch_string(&_1, info, SL("description"), PH_NOISY | PH_READONLY, "wechat/Wechat.zep", 409 TSRMLS_CC);
		zephir_array_fetch_string(&_2, info, SL("picurl"), PH_NOISY | PH_READONLY, "wechat/Wechat.zep", 409 TSRMLS_CC);
		zephir_array_fetch_string(&_3, info, SL("url"), PH_NOISY | PH_READONLY, "wechat/Wechat.zep", 409 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SVSVSVSVS(_4, "<item><Title><![CDATA[", _0, "]]></Title><Description><![CDATA[", _1, "]]></Description><PicUrl><![CDATA[", _2, "]]></PicUrl><Url><![CDATA[", _3, "]]></Url></item>");
		zephir_concat_self(&tpl, _4 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_5);
		zephir_is_iterable(info, &_7, &_6, 0, 0, "wechat/Wechat.zep", 414);
		for (
		  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7, &_6)
		) {
			ZEPHIR_GET_HMKEY(_5, _7, _6);
			ZEPHIR_GET_HVALUE(value, _8);
			zephir_array_fetch_string(&_0, value, SL("title"), PH_NOISY | PH_READONLY, "wechat/Wechat.zep", 412 TSRMLS_CC);
			zephir_array_fetch_string(&_1, value, SL("description"), PH_NOISY | PH_READONLY, "wechat/Wechat.zep", 412 TSRMLS_CC);
			zephir_array_fetch_string(&_2, value, SL("picurl"), PH_NOISY | PH_READONLY, "wechat/Wechat.zep", 412 TSRMLS_CC);
			zephir_array_fetch_string(&_3, value, SL("url"), PH_NOISY | PH_READONLY, "wechat/Wechat.zep", 412 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SVSVSVSVS(_4, "<item><Title><![CDATA[", _0, "]]></Title><Description><![CDATA[", _1, "]]></Description><PicUrl><![CDATA[", _2, "]]></PicUrl><Url><![CDATA[", _3, "]]></Url></item>");
			zephir_concat_self(&tpl, _4 TSRMLS_CC);
		}
	}
	RETURN_CCTOR(tpl);

}

/**
 * 微信验证
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, valid) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL;
	zval *token_param = NULL, *signature, *timestamp, *nonce, *tmpArr, *tmpStr = NULL, *echoStr, *_GET, *_0, *_2 = NULL;
	zval *token = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &token_param);

	if (!token_param) {
		ZEPHIR_INIT_VAR(token);
		ZVAL_EMPTY_STRING(token);
	} else {
	if (unlikely(Z_TYPE_P(token_param) != IS_STRING && Z_TYPE_P(token_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'token' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(token_param) == IS_STRING)) {
		zephir_get_strval(token, token_param);
	} else {
		ZEPHIR_INIT_VAR(token);
		ZVAL_EMPTY_STRING(token);
	}
	}


	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	ZEPHIR_OBS_VAR(signature);
	zephir_array_fetch_string(&signature, _GET, SL("signature"), PH_NOISY, "wechat/Wechat.zep", 425 TSRMLS_CC);
	ZEPHIR_OBS_VAR(timestamp);
	zephir_array_fetch_string(&timestamp, _GET, SL("timestamp"), PH_NOISY, "wechat/Wechat.zep", 426 TSRMLS_CC);
	ZEPHIR_OBS_VAR(nonce);
	zephir_array_fetch_string(&nonce, _GET, SL("nonce"), PH_NOISY, "wechat/Wechat.zep", 427 TSRMLS_CC);
	ZEPHIR_OBS_VAR(echoStr);
	zephir_array_fetch_string(&echoStr, _GET, SL("echostr"), PH_NOISY, "wechat/Wechat.zep", 428 TSRMLS_CC);
	ZEPHIR_INIT_VAR(tmpArr);
	zephir_create_array(tmpArr, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(tmpArr, token);
	zephir_array_fast_append(tmpArr, timestamp);
	zephir_array_fast_append(tmpArr, nonce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	Z_SET_ISREF_P(tmpArr);
	ZEPHIR_CALL_FUNCTION(NULL, "sort", &_1, tmpArr, _0);
	Z_UNSET_ISREF_P(tmpArr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(tmpStr);
	zephir_fast_join_str(tmpStr, SL(""), tmpArr TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "sha1", &_3, tmpStr);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(tmpStr, _2);
	if (ZEPHIR_IS_EQUAL(tmpStr, signature)) {
		zend_print_zval(echoStr, 0);
	} else {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置URL过期时间
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, setTimeout) {

	zval *timeout_param = NULL, _0;
	int timeout;

	zephir_fetch_params(0, 0, 1, &timeout_param);

	if (!timeout_param) {
		timeout = 1;
	} else {
	if (unlikely(Z_TYPE_P(timeout_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'timeout' must be a long/integer") TSRMLS_CC);
		RETURN_NULL();
	}

	timeout = Z_LVAL_P(timeout_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, timeout);
	RETURN_BOOL(1);

}

/**
 * HTTP GET 方法
 * @param  string url 
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, httpGet) {

	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *curlHandle = NULL, *content = NULL, *timeout, _0 = zval_used_for_init, _2;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &url_param);

	if (!url_param) {
		ZEPHIR_INIT_VAR(url);
		ZVAL_STRING(url, "", 1);
	} else {
	if (unlikely(Z_TYPE_P(url_param) != IS_STRING && Z_TYPE_P(url_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'url' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(url_param) == IS_STRING)) {
		zephir_get_strval(url, url_param);
	} else {
		ZEPHIR_INIT_VAR(url);
		ZVAL_EMPTY_STRING(url);
	}
	}


	ZEPHIR_INIT_VAR(timeout);
	ZVAL_LONG(timeout, ZEPHIR_GLOBAL(curl_timeout));
	ZEPHIR_CALL_FUNCTION(&curlHandle, "curl_init", NULL);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 10002);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_1, curlHandle, &_0, url);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 19913);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_1, curlHandle, &_0, &_2);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 64);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_1, curlHandle, &_0, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 81);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_1, curlHandle, &_0, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 13);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_1, curlHandle, &_0, timeout);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&content, "curl_exec", NULL, curlHandle);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, curlHandle);
	zephir_check_call_status();
	RETURN_CCTOR(content);

}

/**
 * HTTP POST 方法
 * @param  string url 
 * @param  array  info
 * @author widuu <admin@widuu.com>
 */
PHP_METHOD(Wechat_Wechat, httpPost) {

	zephir_fcall_cache_entry *_6 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *info = NULL;
	zval *url_param = NULL, *info_param = NULL, *curlHandle = NULL, *content = NULL, *timeout, *_0 = NULL, *_1, *_2, _4 = zval_used_for_init, _5 = zval_used_for_init;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &url_param, &info_param);

	zephir_get_arrval(info, info_param);
	if (!url_param) {
		ZEPHIR_INIT_VAR(url);
		ZVAL_EMPTY_STRING(url);
	} else {
	if (unlikely(Z_TYPE_P(url_param) != IS_STRING && Z_TYPE_P(url_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'url' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(url_param) == IS_STRING)) {
		zephir_get_strval(url, url_param);
	} else {
		ZEPHIR_INIT_VAR(url);
		ZVAL_EMPTY_STRING(url);
	}
	}


	if (1 != 1) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, wechat_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "infomation must be type array", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, 4004);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_3, _1, _2);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "wechat/Wechat.zep", 481 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(timeout);
	ZVAL_LONG(timeout, ZEPHIR_GLOBAL(curl_timeout));
	ZEPHIR_CALL_FUNCTION(&curlHandle, "curl_init", NULL, url);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 42);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, curlHandle, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 19913);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, curlHandle, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 47);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, curlHandle, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 256);
	zephir_json_encode(_0, &(_0), info, zephir_get_intval(&_4)  TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 10015);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, curlHandle, &_5, _0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 64);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, curlHandle, &_5, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 81);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, curlHandle, &_5, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 13);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_6, curlHandle, &_5, timeout);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&content, "curl_exec", NULL, curlHandle);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, curlHandle);
	zephir_check_call_status();
	RETURN_CCTOR(content);

}

