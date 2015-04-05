/*
 * PriorityQueue.h
 *
 *  Created on: 2014Äê12ÔÂ24ÈÕ
 *      Author: kohit
 */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include "Vector.h"

template< typename T >
class priority_queue{
private:
	Vector<T> Heap;
protected:
	void swap( T & a, T & b ){
		T t = a; a = b; b = t;
	}
	void percolateDown( int r ){
		int n = Heap.size() - 1;
		while( r * 2 <= n ){
			int c = r * 2;
			if ( c < n && Heap[c] < Heap[c + 1] ) c++;
			if ( Heap[c] <= Heap[r] ) break;
			swap( Heap[r], Heap[c] );
			r = c;
		}
	}
	void percolateUp( int r ){
		while( r / 2 >= 1 ){
			int p = r / 2;
			if ( Heap[r] <= Heap[p] ) break;
			swap( Heap[p], Heap[r] );
			r = p;
		}
	}
public:
	priority_queue(){
		Heap.push_back( 0 );
	}
	priority_queue( T * e, int n ){
		Heap.push_back( 0 );
		for ( int i = 0; i < n; i++ )
			Heap.push_back( e[i] );
		for ( int i = n / 2; i >= 1; i-- )
			percolateDown( i );
	}
	T getMax(){
		return Heap[1];
	}
	T delMax(){
		T t = Heap[1];
		Heap[1] = Heap[Heap.size() - 1];
		Heap.remove( Heap.size() - 1 );
		percolateDown( 1 );
		return t;
	}
	void insert( T e ){
		Heap.push_back( e );
		percolateUp( Heap.size() -  1 );
	}
};

#endif /* PRIORITYQUEUE_H_ */
