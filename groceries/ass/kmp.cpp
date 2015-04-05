/*
 * kmp.cpp
 *
 *  Created on: 2014Äê12ÔÂ27ÈÕ
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int mn = 1 << 20;
struct fastio{
	char inbuf[mn], outbuf[mn];
	fastio(){
		setvbuf( stdin, inbuf, _IOFBF, mn );
		setvbuf( stdout, outbuf, _IOFBF, mn );
	}
}io;

const int maxn = 10007;

int * build( char * s2 ){
	int len = strlen( s2 );
	int j = 0;
	int * n = new int[len];
	n[0] = -1;
	int t = -1;
	while( j < len - 1 ){
		if ( t < 0 || s2[j] == s2[t] ){
			j++; t++;
			n[j] = ( s2[j] != s2[t] ? t : n[t] );
		}
		else
			t = n[t];      // miss
	}
	return n;
}

int kmp_match( char * s1, char * s2 ){
	int * next = build( s2 );
	int len1 = strlen( s1 );
	int len2 = strlen( s2 );
	int i = 0, j = 0;
	while( j < len2 && i < len1 ){
		if ( j < 0 || s1[i] == s2[j] ){
			i++; j++;
		}
		else
			j = next[j];
	}
	delete [] next;
	return i - j;
}

int main(){
	int n;
	scanf ( "%d", &n );
	char s1[maxn], s2[maxn];
	while( n-- ){
		scanf ( "%s%s", s1, s2 );
		int len1 = strlen( s1 );
		int len2 = strlen( s2 );
		int res = kmp_match( s1, s2 );
		if ( res <= len1 - len2 )
			printf ( "yes\n" );
		else
			printf ( "no\n" );
	}
	return 0;
}


*/
