/*
 * TSP_2.cpp
 *
 *  Created on: 2014Äê12ÔÂ15ÈÕ
 *      Author: kohit
 */
/*
#include <iostream>
#include "Stack.h"
#include <cstdio>
#include <cstring>
#include "Vector.h"

using namespace std;

const int MAX_N = 100007;
const int MAX_N_ = 1 << 20;
bool visit[MAX_N];


struct fastio{
	char inbuf[MAX_N_], outbuf[MAX_N_];
	fastio(){
		setvbuf( stdin, inbuf, _IOFBF, MAX_N_ );
		setvbuf( stdout, outbuf, _IOFBF, MAX_N_ );
	}
}io;


struct edge{
	int v, weight;
	edge(){}
	edge( int vv, int ww ){
		v = vv; weight = ww;
	}
	bool operator< ( const edge & b ) const {
		if ( v == b.v )
			return weight > b.weight;
		return v < b.v;
	}
	bool operator== ( const edge & b ) const {
		return v == b.v && weight == b.weight;
	}
	void operator= ( const edge & b ) {
		v = b.v; weight = b.weight;
	}
};

Vector<edge> adj[MAX_N]; // adjacency list, vertexes of vertex i may be repeat
Stack<int> V[MAX_N];     // V[i]: the maximal route start from vertex i
Stack<int> T;            // T : the topological sequence of vertexes
long MAX_P = 0;
int MAX_V = 0; // maximal price & vertex ( start point )
long price[MAX_N];        // maximal price starts from vertex i
int n, m;


void dfs( int v ){
	visit[v] = true;
	adj[v].mergeSort(); // follow the alphabet order
	for ( int i = 0; i < adj[v].size(); i++ ){
		int u = adj[v][i].v;
		if ( !visit[u] )
			dfs(u);
	}
	T.push( v );
	return ;
}

void t_sort(){
	for ( int i = 1; i <= n; i++ ){
		if ( !visit[i] ){
			dfs( i );
		}
	}
}


long DFS( int v ){
	visit[v] = true;
	if ( adj[v].size() == 0 ){ // end point
		V[v].push( v );
		return 0;
	}
	for ( int i = 0; i < adj[v].size(); i++ ){
		int u = adj[v][i].v;
		if ( visit[u] && price[u] + adj[v][i].weight > price[v] ){
			price[v] = price[u] + adj[v][i].weight; // update the price
			while( !V[v].isempty() ) V[v].pop();    // & the route
			for ( nodePosi(int) iteru = V[u].Last(); iteru != V[u].begin(); iteru = iteru->pre ){
				V[v].push( iteru->value );
			}
		}
	}
	V[v].push( v );
	return price[v];
}



int main(){
	scanf ( "%d%d", &n, &m );
	for ( int i = 0; i < m; i++ ){
		int a, b, p;
		scanf ( "%d%d%d", &a, &b, &p );
		adj[a].push_back(edge( b, p ));
	}

	t_sort(); // topology sort

	memset( visit, 0, sizeof(visit) );
	// visit by the backward of topological sequence
	for ( nodePosi(int) iter = T.Last(); iter != T.begin(); iter = iter->pre ){
		if ( !visit[iter->value] ){
			long p = DFS( iter->value );
			if ( p > MAX_P ){          // record the vertex of maximal route
				MAX_P = p; MAX_V = iter->value;
			}
		}
	}
	while( !V[MAX_V].isempty() ){
		printf ( "%d\t", V[MAX_V].pop() );
	}


	return 0;
}

*/
