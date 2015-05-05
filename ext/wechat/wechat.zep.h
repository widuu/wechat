
extern zend_class_entry *wechat_wechat_ce;

ZEPHIR_INIT_CLASS(Wechat_Wechat);

PHP_METHOD(Wechat_Wechat, getTousername);
PHP_METHOD(Wechat_Wechat, setTousername);
PHP_METHOD(Wechat_Wechat, getFromusername);
PHP_METHOD(Wechat_Wechat, setFromusername);
PHP_METHOD(Wechat_Wechat, getMsgtype);
PHP_METHOD(Wechat_Wechat, setMsgtype);
PHP_METHOD(Wechat_Wechat, getEvent);
PHP_METHOD(Wechat_Wechat, setEvent);
PHP_METHOD(Wechat_Wechat, getCreatetime);
PHP_METHOD(Wechat_Wechat, setCreatetime);
PHP_METHOD(Wechat_Wechat, getContent);
PHP_METHOD(Wechat_Wechat, setContent);
PHP_METHOD(Wechat_Wechat, getMsgid);
PHP_METHOD(Wechat_Wechat, setMsgid);
PHP_METHOD(Wechat_Wechat, getPicurl);
PHP_METHOD(Wechat_Wechat, setPicurl);
PHP_METHOD(Wechat_Wechat, getMediaid);
PHP_METHOD(Wechat_Wechat, setMediaid);
PHP_METHOD(Wechat_Wechat, getFormat);
PHP_METHOD(Wechat_Wechat, setFormat);
PHP_METHOD(Wechat_Wechat, getThumbmediaid);
PHP_METHOD(Wechat_Wechat, setThumbmediaid);
PHP_METHOD(Wechat_Wechat, getLocation_x);
PHP_METHOD(Wechat_Wechat, setLocation_x);
PHP_METHOD(Wechat_Wechat, getLocation_y);
PHP_METHOD(Wechat_Wechat, setLocation_y);
PHP_METHOD(Wechat_Wechat, getScale);
PHP_METHOD(Wechat_Wechat, setScale);
PHP_METHOD(Wechat_Wechat, getLabel);
PHP_METHOD(Wechat_Wechat, setLabel);
PHP_METHOD(Wechat_Wechat, getTitle);
PHP_METHOD(Wechat_Wechat, setTitle);
PHP_METHOD(Wechat_Wechat, getDescription);
PHP_METHOD(Wechat_Wechat, setDescription);
PHP_METHOD(Wechat_Wechat, getUrl);
PHP_METHOD(Wechat_Wechat, setUrl);
PHP_METHOD(Wechat_Wechat, getRequest);
PHP_METHOD(Wechat_Wechat, response);
PHP_METHOD(Wechat_Wechat, subscribe);
PHP_METHOD(Wechat_Wechat, getToken);
PHP_METHOD(Wechat_Wechat, getUser);
PHP_METHOD(Wechat_Wechat, setRemark);
PHP_METHOD(Wechat_Wechat, Menu);
PHP_METHOD(Wechat_Wechat, _get);
PHP_METHOD(Wechat_Wechat, _set);
PHP_METHOD(Wechat_Wechat, getTpl);
PHP_METHOD(Wechat_Wechat, isPost);
PHP_METHOD(Wechat_Wechat, getNews);
PHP_METHOD(Wechat_Wechat, valid);
PHP_METHOD(Wechat_Wechat, setTimeout);
PHP_METHOD(Wechat_Wechat, httpGet);
PHP_METHOD(Wechat_Wechat, httpPost);

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_settousername, 0, 0, 1)
	ZEND_ARG_INFO(0, tousername)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_setfromusername, 0, 0, 1)
	ZEND_ARG_INFO(0, fromusername)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_setmsgtype, 0, 0, 1)
	ZEND_ARG_INFO(0, msgtype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_setevent, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_setcreatetime, 0, 0, 1)
	ZEND_ARG_INFO(0, createtime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_setmsgid, 0, 0, 1)
	ZEND_ARG_INFO(0, msgid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_setpicurl, 0, 0, 1)
	ZEND_ARG_INFO(0, picurl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_setmediaid, 0, 0, 1)
	ZEND_ARG_INFO(0, mediaid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_setformat, 0, 0, 1)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_setthumbmediaid, 0, 0, 1)
	ZEND_ARG_INFO(0, thumbmediaid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_setlocation_x, 0, 0, 1)
	ZEND_ARG_INFO(0, location_x)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_setlocation_y, 0, 0, 1)
	ZEND_ARG_INFO(0, location_y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_setscale, 0, 0, 1)
	ZEND_ARG_INFO(0, scale)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_setlabel, 0, 0, 1)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_settitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_setdescription, 0, 0, 1)
	ZEND_ARG_INFO(0, description)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_seturl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_response, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, info)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_subscribe, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, info)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_gettoken, 0, 0, 0)
	ZEND_ARG_INFO(0, appid)
	ZEND_ARG_INFO(0, secret)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_getuser, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, token)
	ZEND_ARG_INFO(0, openid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_setremark, 0, 0, 0)
	ZEND_ARG_INFO(0, token)
	ZEND_ARG_INFO(0, openid)
	ZEND_ARG_INFO(0, remarke)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_menu, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, token)
	ZEND_ARG_ARRAY_INFO(0, info, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat__get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat__set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_gettpl, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, info)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_getnews, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, info, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_valid, 0, 0, 0)
	ZEND_ARG_INFO(0, token)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_settimeout, 0, 0, 0)
	ZEND_ARG_INFO(0, timeout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_httpget, 0, 0, 0)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_wechat_wechat_httppost, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, info, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(wechat_wechat_method_entry) {
	PHP_ME(Wechat_Wechat, getTousername, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setTousername, arginfo_wechat_wechat_settousername, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getFromusername, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setFromusername, arginfo_wechat_wechat_setfromusername, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getMsgtype, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setMsgtype, arginfo_wechat_wechat_setmsgtype, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getEvent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setEvent, arginfo_wechat_wechat_setevent, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getCreatetime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setCreatetime, arginfo_wechat_wechat_setcreatetime, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setContent, arginfo_wechat_wechat_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getMsgid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setMsgid, arginfo_wechat_wechat_setmsgid, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getPicurl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setPicurl, arginfo_wechat_wechat_setpicurl, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getMediaid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setMediaid, arginfo_wechat_wechat_setmediaid, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getFormat, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setFormat, arginfo_wechat_wechat_setformat, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getThumbmediaid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setThumbmediaid, arginfo_wechat_wechat_setthumbmediaid, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getLocation_x, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setLocation_x, arginfo_wechat_wechat_setlocation_x, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getLocation_y, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setLocation_y, arginfo_wechat_wechat_setlocation_y, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getScale, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setScale, arginfo_wechat_wechat_setscale, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getLabel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setLabel, arginfo_wechat_wechat_setlabel, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getTitle, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setTitle, arginfo_wechat_wechat_settitle, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getDescription, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setDescription, arginfo_wechat_wechat_setdescription, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setUrl, arginfo_wechat_wechat_seturl, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, response, arginfo_wechat_wechat_response, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, subscribe, arginfo_wechat_wechat_subscribe, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getToken, arginfo_wechat_wechat_gettoken, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getUser, arginfo_wechat_wechat_getuser, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setRemark, arginfo_wechat_wechat_setremark, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, Menu, arginfo_wechat_wechat_menu, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, _get, arginfo_wechat_wechat__get, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, _set, arginfo_wechat_wechat__set, ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, getTpl, arginfo_wechat_wechat_gettpl, ZEND_ACC_PROTECTED)
	PHP_ME(Wechat_Wechat, isPost, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Wechat_Wechat, getNews, arginfo_wechat_wechat_getnews, ZEND_ACC_PRIVATE)
	PHP_ME(Wechat_Wechat, valid, arginfo_wechat_wechat_valid, ZEND_ACC_STATIC|ZEND_ACC_PUBLIC)
	PHP_ME(Wechat_Wechat, setTimeout, arginfo_wechat_wechat_settimeout, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Wechat_Wechat, httpGet, arginfo_wechat_wechat_httpget, ZEND_ACC_PROTECTED)
	PHP_ME(Wechat_Wechat, httpPost, arginfo_wechat_wechat_httppost, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
