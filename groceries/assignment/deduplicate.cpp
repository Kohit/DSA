/*
 * deduplicate.cpp
 *
 *  Created on: 2014Äê12ÔÂ17ÈÕ
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include "bitmap_v2.h"
using namespace std;

const int MAX_N = 1 << 20;
struct fastio{
	char inbuf[MAX_N], outbuf[MAX_N];
	fastio(){
		setvbuf( stdin, inbuf, _IOFBF, MAX_N );
		setvbuf( stdout, outbuf, _IOFBF, MAX_N );
	}
}io;

int M = 40000 + 3;

int hash( char s[] ){
	int h = 0;
	for ( int n = strlen(s), i = 0; i < n; i++ ){
		h = ( h * 37 + s[i] ) % M;
	}
	return h;
}

int prob2( char s[], string * & ht ){
	int r = hash(s);
	while( !ht[r].empty() && ht[r] != s )
		r = ( r + 1 ) % M;
	return r;
}


int prob( char s[], string * & ht ){
	int r = hash( s );
	int h = r;
	int p = 1;
	bool neg = false;
	int i = 0;
	while( !ht[r].empty() && ( ht[r] != s ) ){
		if ( neg ){
			r = ( h - p * p ) % M;
			if ( r < 0 ) r = -r;
			neg = false;
		}
		else{
			r = ( h + p * p ) % M;
			neg = true;
		}
		i++;
		if ( i % 2 == 0 ) p++;
	}
	return r;
}

int main(){
	int n;
	scanf ( "%d", &n );
	M = 1200611;
	char s[41];
	string * ht = new string[ M + 7 ];
	Bitmap bm( M + 7 );
	for ( int i = 0; i < n; i++ ){
		scanf ( "%s", s );
		int r = prob( s, ht );
		if ( ht[r] == s && !bm.test(r) ){
			printf ( "%s\n", s );
			bm.set( r );
		}
		else if ( ht[r].empty() ){
			ht[r] = s;
		}
	}
	delete [] ht;
	return 0;
}
*/
