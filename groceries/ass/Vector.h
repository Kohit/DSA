/*
 * Vector.h
 *
 *  Created on: 2014Äê10ÔÂ8ÈÕ
 *      Author: kohit
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#define DEFAULT_CAPACITY 50

typedef int Rank;
template < typename T >
class Vector{
protected:
	Rank _size;
	int capacity;
	T* elem;
public:
	Vector( int _capacity ){
		capacity = _capacity;
		_size = 0;
		elem = new T[ capacity ];
	}
	Vector(){
		capacity = DEFAULT_CAPACITY;
		_size = 0;
		elem = new T[ capacity ];
	}
	~Vector(){
		delete [] elem;
	}
	void copyFrom( T const * A, Rank lo, Rank hi ){
		elem = new T[ capacity = 2 * (hi - lo) ];
		_size = 0;
		while( lo < hi ){
			elem[_size++] = A[lo++];
		}
	}
	void expand(){
		capacity *= 2;
		T * e = new T[capacity];
		for ( int i = 0; i < _size; i++ ){
			e[i] = elem[i];
		}
		delete [] elem;
		elem = e;
	}
	void push_back( T const & data ){
		if ( _size >= 2 * capacity ){
			expand();
		}
		elem[_size++] = data;
	}
	T & operator[] ( Rank r ){
		return elem[r];
	}
	int size(){
		return _size;
	}
};

#endif /* VECTOR_H_ */
