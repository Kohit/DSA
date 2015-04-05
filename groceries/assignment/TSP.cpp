/*
 * TSP.cpp
 *
 *  Created on: 2014Äê12ÔÂ15ÈÕ
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstdio>
#include "list.h"
using namespace std;

const int MAX_N = 1 << 20;

struct fastio{
	char inbuf[MAX_N], outbuf[MAX_N];
	fastio(){
		setvbuf( stdin, inbuf, _IOFBF, MAX_N );
		setvbuf( stdout, outbuf, _IOFBF, MAX_N );
	}
}io;

List<int> adj[MAX_N];
bool visit[MAX_N];
int hight[MAX_N];


int dfs( int v ){
	visit[v] = true;
	nodePosi(int) iter;
	for ( iter = adj[v].First(); iter != adj[v].end(); iter = iter->succ ){
		int u = iter->value;
		if ( !visit[u] ){
			hight[v] = max( hight[v], dfs( u ) + 1 );
		}else {
			hight[v] = max( hight[v], hight[u] + 1 );
		}
	}
	return hight[v];
}


int main(){
	int n, m;
	scanf ( "%d%d", &n, &m );

	for ( int i = 0; i < m; i++ ){
		int u, v;
		scanf ( "%d%d", &u, &v );
		adj[u].insertAsLast( v );
	}

	int MAX = 0;
	for ( int i = 1; i <= n; i++ )
		if ( !visit[i] )
			MAX = max( MAX, dfs(i) );

	printf ( "%d\n", MAX + 1 );

	return 0;
}
*/
