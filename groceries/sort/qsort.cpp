/*
 * qsort.cpp
 *
 *  Created on: 2014Äê12ÔÂ23ÈÕ
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 100007;
int a[maxn];
int n;

const int M = 1 << 20;
struct fastio{
	char inbuf[M], outbuf[M];
	fastio(){
		setvbuf( stdin, inbuf, _IOFBF, M );
		setvbuf( stdout, outbuf, _IOFBF, M );
	}
}io;

int patition( int * a, int lo, int hi ){  // [lo, hi]
	int pivot = a[lo];
	while( lo < hi ){
		while( lo < hi ){
			if ( pivot < a[hi] ) hi--;
			else {
				a[lo++] = a[hi];
				break;
			}
		}
		while( lo < hi ){
			if ( a[lo] < pivot ) lo++;
			else{
				a[hi--] = a[lo];
				break;
			}
		}
	}
	a[lo] = pivot;
	return lo;
}

int patition_( int * a, int lo, int hi ){
	int pivot = a[lo];
	while( lo < hi ){
		while( lo < hi && pivot <= a[hi] ) hi--;
		if ( lo < hi ) a[lo++] = a[hi];
		while( lo < hi && a[lo] <= pivot ) lo++;  // <=
		if ( lo < hi ) a[hi--] = a[lo];
	}
	a[lo] = pivot;
	return lo;
}


void qsort( int * a, int lo,int hi ){  // [lo , hi)
	if ( hi - lo < 2 ) return ;
	int mid = patition( a, lo, hi - 1 );
	for ( int i = 0; i < n - 1; i++ )
		printf ( "%d ", a[i] );
	printf ( "%d\n", a[n - 1] );
	qsort( a, lo, mid );
	qsort( a, mid + 1, hi );
}


int main(){
	scanf ( "%d", &n );
	for ( int i = 0; i < n; i++ )
		scanf ( "%d", &a[i] );
	qsort( a, 0, n );
	return 0;
}
*/

