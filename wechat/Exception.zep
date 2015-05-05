namespace Wechat;

class Exception extends \Exception{

	public function __construct(string! message = "",int code=0,<Exception> previous = null){
		parent::__construct(message,code);
		
	}
}