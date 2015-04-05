/*
 * deque.h
 *
 *  Created on: 2014Äê11ÔÂ9ÈÕ
 *      Author: kohit
 */

#include "list.h"

template< typename T >
class Deque: public List<T>{
public:
	void insertFront( T const & e ){
		this->insertAsFirst( e );
	}
	void insertRear( T const & e ){
		this->insertAsLast( e );
	}
	T removeFront(){
		return this->remove( this->First() );
	}
	T removeRear(){
		return this->remove( this->Last() );
	}
	T & Front(){
		nodePosi(T) x = this->First();
		return x->value;
	}
	T & Rear(){
		nodePosi(T) x = this->Last();
		return x->value;
	}
	bool isempty(){ return this->_size ? 0: 1; }
};
