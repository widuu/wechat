/*
 +------------------------------------------------------------------------+
 | Wechat Framework                                                       |
 +------------------------------------------------------------------------+
 | Copyright (c) 2016-2017   Widuu  (http://www.widuu.com)                |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to service@widuu.com so we can send you a copy immediately.            |
 +------------------------------------------------------------------------+
 | Authors: Widuu <admin@widuu.com>                                       |
 +------------------------------------------------------------------------+
 */

namespace Wechat\Core;

class FileCache implements Cache{

	private _cache_dir = null { get ,set };

	private _type      = "array"  { get ,set };

	private _prefix    = "widuu_" { get ,set };

	public function __construct( array config = [] ){

		if !isset config["cacheDir"] {
			let this->_cache_dir = realpath(dirname(_SERVER["SCRIPT_FILENAME"])).DIRECTORY_SEPARATOR."cache".DIRECTORY_SEPARATOR;
		}else{
			let this->_cache_dir = config["cacheDir"];
		}

		if isset config["type"] {
			let this->_type = config["type"];
		}

		if isset config["prefix"] {
			let this->_prefix = config["prefix"];
		}

	}

	public function setCache( string! key , var value){

		
		var data ,filename;

		let filename = this->_prefix.md5(key).".php";

		if !is_dir(this->_cache_dir) {
			mkdir( this->_cache_dir, 0777, true);
	    }

	    if this->_type == "array" {
	    	let data = "<?php\nreturn ".var_export(value, true).";\n?>";
	    }elseif( this->_type == "serialize" ){
	    	let data = serialize(data);
	    }

	    var status = file_put_contents( this->_cache_dir.filename , data );

	    if !status {
	    	return false;
	    }

	    return status;
	}

	public function getCache( string! key ){

		var data ,filename;

		let filename = this->_prefix.md5(key).".php";

		if !file_exists(this->_cache_dir.filename){
			return false;
		}

		if this->_type == "array" {
	    	let data = require( this->_cache_dir.filename );
	    }elseif this->_type == "serialize" {
	    	let data = unserialize(file_get_contents( this->_cache_dir.filename ));
	    }

	    return data;
	}

	public function delete(string! key) -> boolean {
		var filename;
		let filename = this->_prefix.md5(key).".php";
		if file_exists(this->_cache_dir.filename){
			return unlink(this->_cache_dir.filename); 
		}
		return true;
	}

	public function flush() -> boolean {
		
		var key ,cacheFile ,prefix , item;
		
		let prefix = this->_prefix;

		if !is_dir(this->_cache_dir){
			return true;
		}

		for item in iterator(new \DirectoryIterator(this->_cache_dir)) {
			if likely item->isFile() == true {
				let key = item->getFileName(),
					cacheFile = item->getPathName();
					if empty prefix || starts_with(key, prefix) {
						if !unlink(cacheFile) {
							return false;
						}
					}
			}
		}
		return true;
	}

}