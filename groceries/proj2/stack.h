/*
 * stack.h
 *
 *  Created on: 2014Äê11ÔÂ26ÈÕ
 *      Author: kohit
 */

#include "Vector.h"

template< typename T >
class Stack: public Vector<T>{
public:
	void push( T const & e ){
		this->push_back( e );
	}
	T pop(){
		T e = (*this)[this->size() - 1];
		this->remove( this->size() - 1 );
		return e;
	}
	T top(){
		return (*this)[this->size() - 1];
	}
	bool isempty(){
		return this->size() > 0 ? false : true;
	}
};
