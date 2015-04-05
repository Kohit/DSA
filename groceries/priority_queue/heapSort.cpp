/*
 * heapSort.cpp
 *
 *  Created on: 2014Äê12ÔÂ2ÈÕ
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstdio>
#include "priority_queue.h"
using namespace std;

int const MAX_N = 100007;
int A[MAX_N];

#define parent(i) ( ( (i) - 1 ) >> 1 )
#define lc(i) ( ( (i) << 1 ) + 1 )
#define rc(i) ( ( (i) + 1 ) << 1 )

void swap( int & a, int & b ){
	int c = a; a = b; b = c;
}

int bigger( int n, int a, int b ){
	if ( a >= n ) return b < n ? b : -1;
	if ( b >= n ) return a;
	return A[a] > A[b] ? a : b;
}

int percolateDown( int n, int i ){
	int m = -1;
	while( ( m = bigger( n, lc(i), rc(i) ) ) != -1 && A[i] < A[m] ){
		swap( A[i], A[m] );
		i = m;
	}
	return i;
}



void heapSort( int lo, int hi ){
	for ( int i = hi / 2; i >= 0; i-- ){
		percolateDown( hi, i );
	}
	int n = hi;
	while( --hi ){
		swap( A[0], A[hi] );
		percolateDown( hi, 0 );
		for ( int i = 0; i < n; i++ )
			printf ( "%d ", A[i] );
		printf ( "\n" );
	}

}

int main(){
	int n;
	scanf ( "%d", &n );
	for ( int i = 0; i < n; i++ ){
		scanf ( "%d", &A[i] );
	}
	heapSort( 0, n );
	return 0;
}

*/
