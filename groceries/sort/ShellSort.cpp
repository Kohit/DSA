/*
 * ShellSort.cpp
 *
 *  Created on: 2014Äê12ÔÂ23ÈÕ
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 100005;
int a[maxn];
int H[21];

const int MAX_N = 1 << 20;
struct fastio{
	char inbuf[MAX_N], outbuf[MAX_N];
	fastio(){
		setvbuf( stdin, inbuf, _IOFBF, MAX_N );
		setvbuf( stdout, outbuf, _IOFBF, MAX_N );
	}
}io;


static void swap( int & a, int & b ){
	int t = a; a = b; b = t;
}

void ShellSort( int * a, int n, int s, int * H ){
	for ( int k = 0; k < s; k++ ){
		for ( int i = H[k]; i < n; i++ ){
			for ( int j = i; j >= H[k] && a[j] < a[j - H[k]]; j -= H[k] )
				swap( a[j], a[j - H[k]] );
		}
		for ( int i = 0; i < n - 1; i++ )
			printf ( "%d ", a[i] );
		printf ( "%d\n", a[n - 1] );
	}
}


int main(){
	int n, s;
	scanf ( "%d%d", &n, &s );
	for ( int i = 0; i < s; i++ ){
		scanf ( "%d", &H[i] );
	}
	for ( int i = 0; i < n; i++ ){
		scanf ( "%d", &a[i] );
	}
	ShellSort( a, n, s, H );
	return 0;
}

*/

