/*
 * HeapSort.cpp
 *
 *  Created on: 2014Äê12ÔÂ23ÈÕ
 *      Author: kohit
 */

#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 100007;
const int M = 1 << 20;
struct fastio{
	char inbuf[M], outbuf[M];
	fastio(){
		setvbuf( stdin, inbuf, _IOFBF, M );
		setvbuf( stdout, outbuf, _IOFBF, M );
	}
}io;

static void swap( int & a, int & b ){
	int t = a; a = b; b = t;
}

int a[maxn];

void sink( int * a, int k, int n ){
	while( k * 2 <= n ){
		int j = 2 * k;
		if ( j < n && a[j] < a[j + 1] ) j++;
		if ( a[k] >= a[j] ) break;
		swap( a[k], a[j] );
		k = j;
	}
}


void HeapSort( int * a, int n ){
	int N = n;
	for ( int k = n / 2; k >= 1; k-- )
		sink( a, k, n );
	while( n > 1 ){
		swap( a[1], a[n] );
		n--;
		sink( a, 1, n );
		for ( int i = 1; i < N; i++ )
			printf ( "%d ", a[i] );
		printf ( "%d\n", a[N] );
	}
}

int main(){
	int n;
	scanf ( "%d", &n );
	for ( int i = 1; i <= n; i++ )
		scanf ( "%d", &a[i] );
	HeapSort( a, n );
	return 0;
}


