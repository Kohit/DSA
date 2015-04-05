/*
 * strcmp.cpp
 *
 *  Created on: 2014Äê10ÔÂ28ÈÕ
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAX_N = 10007;
const int SZ = 100000;
struct fastio{
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;

int main(){
	//std::ios::sync_with_stdio(false);
	int n;
	scanf ( "%d", &n );
	//cin >> n;
	char a[MAX_N], b[MAX_N];
	//string a, b;
	while ( n-- ){
		scanf ( "%s%s", a, b );
		//cin >> a >> b;
		int i = 0, j = 0;
		int len1 = strlen( a );
		int len2 = strlen( b );
		while( true ){
			int tmp = i;
			while( j < len2 && i < len1 && a[i] == b[j] ){
				i++;
				j++;
			}
			if ( j == len2 ) {
				//cout << "yes" << endl;
				printf ( "yes\n" ); break; }
			if ( i == len1 ) {
				//cout << "no" << endl;
				printf ( "no\n" ); break; }
			i = tmp + 1;
			j = 0;
		}
	}
	return 0;
}


*/
