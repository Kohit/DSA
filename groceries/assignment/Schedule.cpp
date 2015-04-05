/*
 * Schedule.cpp
 *
 *  Created on: 2014Äê12ÔÂ24ÈÕ
 *      Author: kohit
 */

/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include "PriorityQueue.h"
using namespace std;

const int maxn = 1 << 20;
long long INF = (long long)1 << 32;

struct fastio{
	char inbuf[maxn], outbuf[maxn];
	fastio(){
		setvbuf( stdin, inbuf, _IOFBF, maxn );
		setvbuf( stdout, outbuf, _IOFBF, maxn );
	}
}io;

struct scheme{
	long long p;
	char name[10]; // don't use string !
	scheme(){
		p = 0;
	}
	scheme( long long pp ){
		p = pp;
	}
	scheme( long long pp, char * ss ){
		p = pp;
		strcpy( name, ss );
	}
	bool operator<= ( const scheme & e ){
		if ( p == e.p ) return  strcmp( name, e.name ) > 0;
		return p > e.p;
	}
	bool operator< ( const scheme & e ){
		if ( p == e.p ) return strcmp( name, e.name ) > 0;
		return p > e.p;
	}
};

int main(){
	int n, m;
	scanf ( "%d%d", &n, &m );
	priority_queue<scheme> Q;
	for ( int i = 0; i < n; i++ ){
		long long p;
		char str[10];
		scanf ( "%lld%s", &p, str );
		Q.push_back( scheme( p, str ) );
	}
	if ( n == 0 || m == 0 ) return 0;
	Q.heapify();
	while( m-- ){
		if ( Q.isempty() ) break;
		scheme e = Q.delMax();
		printf ( "%s\n", e.name );
		e.p *= 2;
		if ( e.p < INF )    // less than
		Q.insert( e );
	}
	return 0;
}

*/
