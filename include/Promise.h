#ifndef PROMISE_H
#define PROMISE_H
#ifdef ARDUINO
	#include <ArxSmartPtr.h>
#else
	#include <memory>
#endif
	
namespace promise{

	template<typename InValue, typename RetValue>
	class Promise {
	public:
		template<typename NewRetValue>
		Promise<RetValue, NewRetValue> then(void(*cb)(RetValue, void(*resolve)(NewRetValue), void(*error)(int))){
			this->cb = cb;
			Promise<RetValue, NewRetValue> newP;
			return newP;
		}
		
	private:
		void(*cb)(RetValue, void(*resolve)(NewRetValue), void(*error)(int));
	};

}
#endif
