/*
 * priority_queue.h
 *
 *  Created on: 2014Äê12ÔÂ2ÈÕ
 *      Author: kohit
 */

#include "Vector.h"

template< typename T >
struct PQ{
	virtual void enqueue( T ) = 0;
	virtual T front() = 0;
	virtual T dequeue() = 0;
};

#define parent(i) ( ( (i) - 1 ) >> 1 )
#define lc(i) ( ( (i) << 1 ) + 1 )
#define rc(i) ( ( (i) + 1 ) << 1 )

template< typename T >
static bool lessThan( T * a, T * b ){ return lessThan( *a, *b ); }

template< typename T >
static bool lessThan( T & a, T & b ){ return a < b; }

template< typename T >
static void swap( T & a, T & b ){ T e = a; a = b; b = e; }

template< typename T >
class priority_queue : public PQ<T>, public Vector<T>{
protected:
	int percolateUp( int i ){
		while( i > 0 ){
			int j = parent(i);
			if ( lessThan( this->elem[i], this->elem[j] ) ) break;
			swap( this->elem[i], this->elem[j] );
			i = j;
		}
		return i;
	}
	int percolateDown( int n, int i ){
		int m = -1;
		while( ( m = bigger( n, lc(i), rc(i) ) ) != -1 && this->elem[i] < this->elem[m] ){
			swap( this->elem[i], this->elem[m] );
			i = m;
		}
		return i;
	}
	int bigger( int n, int a, int b ){
		if ( a >= n ) return b < n ? b : -1;
		if ( b >= n ) return a;
		return this->elem[a] > this->elem[b] ? a : b;
	}
	void heapify( int n ){
		for ( int i = n - 1; i >= 0; i-- ){
			percolateDown( n, i );
		}
	}
public:
	priority_queue(){}
	priority_queue( T * A, int n ){
		copyFrom( A, 0, n );
		heapify( n );
	}
	void enqueue( T e ){
		this->elem[this->_size ++] = e;
		percolateUp( this->_size - 1 );
	}
	T dequeue(){
		T e = this->elem[0];
		this->elem[0] = this->elem[-- this->_size];
		percolateDown( this->_size, 0 );
		return e;
	}
	T front(){
		return this->elem[0];
	}
	bool isempty(){
		return this->_size > 0 ? false : true;
	}
};

