/*
 * hotname.cpp
 *
 *  Created on: 2014Äê12ÔÂ18ÈÕ
 *      Author: kohit
 */
/*

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int M = 20123;                  // size
int count[20125];
string ht[20125];

struct fastio{
	char inbuf[1 << 20], outbuf[1 << 20];
	fastio(){
		setvbuf( stdin, inbuf, _IOFBF, 1 << 20 );
		setvbuf( stdout, outbuf, _IOFBF, 1 << 20 );
	}
}io;

int hash( char s[] ){
	int h = 0;
	for ( int n = strlen(s), i = 0; i < n; i++ ){
		h = ( h * 37 + s[i] ) % M;
	}
	return h;
}

int prob( char s[] ){
	int r = hash( s );
	int h = r;
	int p = 1;
	bool neg = false;
	int i = 0;
	while( !ht[r].empty() && ( ht[r] != s ) ){
		if ( neg ){
			r = ( h - p * p ) % M;
			if ( r < 0 ) r = - r;     // in case the r might be negative
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
	int maxn = 0, maxr = 0;
	while( n-- ){
		char s[10];
		scanf ( "%s", s );
		int r = prob( s );
		if ( ht[r] == s ){
			count[r]++;
			if ( count[r] > maxn ){
				maxn = count[r];
				maxr = r;
			}
		}
		else{
			ht[r] = s;
			count[r]++;
			if ( count[r] > maxn ){
				maxn = count[r];
				maxr = r;
			}

		}
	}
	printf ( "%s %d\n", ht[maxr].c_str(), maxn );
	return 0;
}
*/
