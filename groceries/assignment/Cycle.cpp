/*
 * Cycle.cpp
 *
 *  Created on: 2014Äê12ÔÂ26ÈÕ
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10007;
char inbuf[1000000], outbuf[1000000];
int main(){
	setvbuf( stdin, inbuf, _IOFBF, 1000000 );
	setvbuf( stdout, outbuf, _IOFBF, 1000000 );
	char s1[maxn], s2[maxn];
	while( scanf ( "%s", s1 ) != EOF ){
		scanf ( "%s", s2 );
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		if ( len1 != len2 )
			printf ( "NO\n" );
		else{
			int w1 = 0, w2 = 0;
			for ( int i = 0; i < len1; i++ ){
				w1 += (int)s1[i];
				w2 += (int)s2[i];
			}
			if ( w1 != w2 )
				printf ( "NO\n" );
			else{
				for ( int i = 0; i < len1; i++ ){
					while( i < len1 && s1[i] != s2[0] ) i++;
					if ( i >= len1 ){
						printf ( "NO\n" );
						break;
					}
					int j = i, k = 0, count = 0;
					while( count < len1 && s1[j] == s2[k] ){
						j = ( j + 1 ) % len1;
						k++;
						count++;
					}
					if ( count > len1 ){
						printf ( "NO\n" );
						break;
					}
					if ( k == len1 ){
						printf ( "YES\n" );
						break;
					}
				}
			}
		}
	}
	return 0;
}
*/
