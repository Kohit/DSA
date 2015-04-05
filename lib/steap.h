/*
 * steap.h
 *
 *  Created on: 2014Äê11ÔÂ9ÈÕ
 *      Author: kohit
 */

#include "Stack.h"

template< typename T >
class Steap{
private:
	Stack<T> S, P;
public:
	void push( T const & e ){
		S.push( e );
		P.push( max( e, P.top() ) );
		//P.top < e ? P.push( e ), P.top().counter = 1 : P.top().counter++;
	}
	T & top(){
		return S.top();
	}
	T pop(){
		P.pop();
		return S.pop();
	}
	T getMax(){
		return P.top();
	}
};

