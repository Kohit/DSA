/*
 * test_queap.cpp
 *
 *  Created on: 2014Äê11ÔÂ21ÈÕ
 *      Author: kohit
 */
/*
#include <iostream>
#include "S_queap.h"
#include <cstdio>
using namespace std;

const int MAX_N = 1 << 20;

struct fio{
	char inbuf[MAX_N], outbuf[MAX_N];
	fio(){
		setvbuf( stdin, inbuf, _IOFBF, MAX_N );
		setvbuf( stdout, outbuf, _IOFBF, MAX_N );
	}
}io;

int main(){
	Queap Q;
	int n;
	scanf ( "%d", &n );
	while( n-- ){
		char e;
		scanf ( " %c", &e );
		if ( e == 'E' ){
			int x;
			scanf ( "%d", &x );
			Q.enqueap( x );
		}
		if ( e == 'D' ){
			printf ( "%d\n", Q.dequeap() );
		}
		if ( e == 'M' ){
			printf ( "%d\n", Q.min() );
		}
	}
	return 0;
}


*/
