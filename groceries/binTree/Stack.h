/*
 * Stack.h
 *
 *  Created on: 2014Äê11ÔÂ7ÈÕ
 *      Author: kohit
 */

#include "list.h"

template< typename T >
class Stack: public List<T>{
public:
	T top(){
		nodePosi(T) x = this->First();
		return x->value;
	}
	T pop(){
		return this->remove( this->First() );
	}
	void push( T const & e ){
		this->insertAsFirst( e );
	}
	bool isempty(){
		return this->_size ? 0 : 1;
	}
};
