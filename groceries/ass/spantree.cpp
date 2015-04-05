/*
 * spantree.cpp
 *
 *  Created on: 2014Äê11ÔÂ19ÈÕ
 *      Author: kohit
 */
/*

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 101;
const int INF = 1 << 30;
int es[MAX_N][MAX_N];
int cost[MAX_N];           // minimal cost from set x to vertex i
bool x[MAX_N];             // set of span tree

int prime( int n ){
	for ( int i = 0; i < n; i++ ){
		cost[i] = INF;
		x[i] = false;
	}
	cost[0] = 0;           // start from vertex 0
	int res = 0;
	while( true ){
		int v = -1;
		for ( int i = 0; i < n; i++ ){
			if ( !x[i] && ( v == -1 || cost[i] < cost[v] ) )
				v = i;
		}
		if ( v == -1 ) break;  // if all vertex were been visited
		x[v] = true;       // add v into set x
		res += cost[v];
		for ( int i = 0; i < n; i++ )                // update new minimal cost
			cost[i] = min( cost[i], es[v][i] );      // from set x to vertex i
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			scanf ( "%d", &es[i][j] );
	int res = prime( n );
	cout << res << endl;
	return 0;
}
*/
