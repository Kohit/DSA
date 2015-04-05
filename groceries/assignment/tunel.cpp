/*
 * tunel.cpp
 *
 *  Created on: 2014年11月9日
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstdio>
#include "queap.h"
using namespace std;

const int MAX_N = 1 << 20;
struct read{
	char bufi[ MAX_N ], bufo[ MAX_N ];
	read(){
		setvbuf( stdin, bufi, _IOFBF, MAX_N );
		setvbuf( stdout, bufo, _IOFBF, MAX_N );
	}
}io;


struct car{
	int height, num;
	car( int h = 0, int n = 0 ): height(h), num(n) {}
	bool operator< ( const car & e ){
		return height < e.height;
	}
	bool operator== ( const car & e ){
		return height == e.height;
	}
};


int main(){
	int n;
	scanf ( "%d", &n );
	Queap<car> Q;           // 参考习题[10-19]
	while( n-- ){
		char op;
		scanf( " %c", &op );
		if ( op == 'E' ){
			int h = 0;
			scanf ( "%d", &h );
			Q.enqueue( h );
		}
		if ( op == 'M' ){
			printf ( "%d\n", Q.getMAX().height );
		}
		if ( op == 'D' ){
			printf ( "%d\n", Q.dequeue().height );
		}
	}
	return 0;
}



*/
