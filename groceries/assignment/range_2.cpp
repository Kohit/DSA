/*
 * range_2.cpp
 *
 *  Created on: 2014Äê10ÔÂ3ÈÕ
 *      Author: kohit
 */
/*

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
/*
int cmp( const void * a, const void * b ){
	return *( int * )a - *( int * )b;
}
*/
/*
const int Max = 10000007;
int point[Max];
int backup[Max];

int main(){
	int n, m;
	scanf ( "%d%d", &n, &m );
	for ( int i = 0; i < n; i++ ){
		int index = 0;
		scanf ( "%d", &index );
		point[index] = 1;
		backup[index] = 1;
	}
	int count = 0;
	for ( int i = 0; i < 10000007; i++ ){
		if ( point[i] != 0 ){
			point[i] = ++count;
		}
		else
			point[i] = count;
	}
	int a = 0, b = 0;
	for ( int i = 0; i < m; i++ ){
		scanf ( "%d%d", &a, &b );
		int hi = point[b];
		int lo = point[a];
		int res = hi - lo;
		if ( backup[a] == 1 ) res++;
//		cout << hi << " " << lo << endl;
		if ( a == b && backup[a] == 1 ) printf ( "1\n" );
		else printf ( "%d\n", res );
	}
	return 0;
}



*/
