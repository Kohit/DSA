/*
 * Karp-Rabin.cpp
 *
 *  Created on: 2014Äê12ÔÂ30ÈÕ
 *      Author: kohit
 */

#include <iostream>
#include <cstring>
#include <cstdio>
//#include "pow.h"
using namespace std;


const int mn = 1 << 20;
struct fastio{
	char inbuf[mn], outbuf[mn];
	fastio(){
		setvbuf( stdin, inbuf, _IOFBF, mn );
		setvbuf( stdout, outbuf, _IOFBF, mn );
	}
}io;

#define M 100000007
#define R 128
typedef long long hashCode;
bool check1by1( char* P, char* T, size_t i ){
	for ( size_t m = strlen( P ), j = 0; j < m; j++, i++ ){
		if ( P[j] != T[i] ) return false;
	}
	return true;
}
void updateHash( hashCode& hashT, char* T, size_t m, size_t k, hashCode Dm ){
	hashT = ( hashT - T[k - 1] * Dm ) % M;
	hashT = ( hashT * R + T[k + m - 1] ) % M;
	if ( hashT < 0 ) hashT += M;
}

long long pow( long long x, int n ){  // x ^ n
	long long res = 1;
	while( n ){
		if ( n & 1 ) res = ( res * x ) % M;
		x = ( x * x ) % M;
		n >>= 1;
	}
	return res;
}

int match( char* P, char* T ){
	size_t m = strlen( P ), n = strlen( T );
	hashCode Dm = pow( R, m - 1 ), hashP = 0, hashT = 0;
	for ( size_t i = 0; i < m; i++ ){
		hashP = ( hashP * R + P[i] ) % M;
		hashT = ( hashT * R + T[i] ) % M;
	}
	size_t k = 0;
	while( true ){
		if ( hashP == hashT )
			if ( check1by1( P, T, k ) ) return k;
		if ( ++k > n - m ) break;
		else updateHash( hashT, T, m, k, Dm );
	}
	return -1;
}

const int maxn = 10007;



int main(){
	int n;
	scanf ( "%d", &n );
	char s1[maxn], s2[maxn];
	while( n-- ){
		scanf ( "%s%s", s1, s2 );
		int res = match( s2, s1 );
		if ( res != -1 )
			printf ( "yes\n" );
		else
			printf ( "no\n" );
	}
	return 0;
}


