/*
 * l_stack.h
 *
 *  Created on: 2014年11月21日
 *      Author: kohit
 */

#include "list.h"

template<typename T>
class Stack{
private:
	List<T> S;
public:
	Stack(){}
	void push( T e ){
		S.insertAsFirst( e );
	}
	T pop(){
		return S.remove( S.First() );
	}
	T & top(){
		return S.First()->value;
	}
	bool empty(){
		return S.size() > 0 ? false : true;
	}
};
