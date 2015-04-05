/*
 * queap.h
 *
 *  Created on: 2014Äê11ÔÂ9ÈÕ
 *      Author: kohit
 */

#include "deque.h"

template< typename T >
class Queap{
private:
	Deque<T> Q, P;
public:
	void enqueue( T const & e ){
		Q.insertRear( e );
		P.insertRear( e );
		for ( nodePosi(T) x = P.Last(); x && (x->value < e || x->value == e ); x = x->pre )
			x->value = e;
	}
	T dequeue(){
		P.removeFront();
		return Q.removeFront();
	}
	T & front(){
		return Q.Front();
	}
	T getMAX(){
		return P.Front();
	}
};
