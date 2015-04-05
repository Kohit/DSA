/*
 * queue.h
 *
 *  Created on: 2014年11月5日
 *      Author: kohit
 */

#include "list.h"

template< typename T >
class Queue: public List<T>{
public:
	~Queue(){
		while( !isempty() ){
			dequeue();
		}
	}
	void enqueue( T const & e ){ this->insertAsLast( e ); }
	T front(){
		nodePosi(T) x = this->First();
		return x->value;
	}
	T dequeue(){ return this->remove( this->First() ); }
	bool isempty(){ return this->_size ? 0: 1; }
};
