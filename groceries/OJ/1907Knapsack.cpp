/*
 * 1907Knapsack.cpp
 *
 *  Created on: 2014Äê4ÔÂ6ÈÕ
 *      Author: KoHit
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#define INF -100000
using namespace std;

int value[ 101 ];
int weight[ 1001 ];
int dp[ 102 ][ 1002 ];

int max ( int x, int y ){
	return (x - y >= 0) ? x : y;
}

int knapsack ( int n, int c ){
	if ( c < 0 )
		return INF;
	if ( n == 0 )
		return 0;
	if ( dp[ n ][ c ] )
		return dp[ n ][ c ];
	return dp[ n ][ c ] = max ( knapsack( n - 1, c ), knapsack( n - 1, c - weight[ n ] ) + value[ n ] );
}

int main(){
	int t;
	scanf( "%d", &t );

	while ( t-- ) {
		memset( value, 0, sizeof(value) );
		memset( weight, 0, sizeof(weight) );
		memset( dp, 0, sizeof(dp) );
		int N, C;
		scanf ( "%d%d", &N, &C );
		for ( int i = 1; i <= N; i++ ){
			scanf ( "%d%d", &weight[ i ], &value[ i ] );
		}
		int result = 0;
		result = knapsack( N, C );
		cout << result << endl;
	}
	return 0;
}
