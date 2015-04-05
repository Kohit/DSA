/*
 *
 *  Created on: 2014年10月8日
 *      Author: kohit
 *
 *
 *      unionfind + kruskal
 * 
 *
 *   test case
 *
 * 5
 * 4 5 2
 * 3 4 3
 * 1 4 5
 * 1 3 6
 * 1 2 7
 * 2 4 8
 * 2 5 8
 * 3 5 9
 * 1 5 12
 * 2 3 14
 * -1 -1 -1
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1 << 31;
const int MAX_N = 1 << 10;
class unionFind{
	int * par,* size;
public:
	unionFind( const int & n  ){
		par = new int [n + 1];
		size = new int [n + 1];
		for ( int i = 0; i <= n; i++ ){
			par[i] = i;
			size[i] = 1;
		}
	}
	int find( int a ){
		while( a != par[a] ){
			par[a] = par[ par[a] ];
			a = par[a];
		}
		return a;
	}
	bool same( const int & a, const int & b ){
		int pa = find( a );
		int pb = find( b );
		return pa == pb;
	}
	void unit( const int & a, const int & b ){
		int x = find( a );
		int y = find( b );
		if ( x == y ) return ;
		if ( size[x] < size[y] ){
			par[x] = y;
			size[y] += size[x];
		}else{
			par[y] = x;
			size[x] += size[y];
		}
	}
};

struct edge{
	int u, v, weigh;
	edge( int uu, int vv, int ww ) : u( uu ), v( vv ), weigh( ww ){}
	edge(){}
	bool operator< ( const edge & e ) const {
		return weigh < e.weigh;
	}
};
edge es[MAX_N];

int main(){
	int n;
	cout << "请输入顶点数" << endl;
	scanf ( "%d", &n );
	unionFind unionfind( n );
	int u, v, w, E = 0;
	cout << "请输入每条边，格式为u v weigh，输入-1 -1 -1终止" << endl;
	while( scanf ( "%d%d%d", &u, &v, &w ) != EOF ){
		if ( u == -1 && v == -1 && w == -1 )
			break;
		es[E++] = edge( u, v, w );
	}
	sort( es, es + E );
	int res = 0, SE = 0;
	edge spanTree[E];
	for ( int i = 0; i < E; i++ ){
		edge e = es[i];
		if ( !unionfind.same( e.u, e.v ) ){
			unionfind.unit( e.u, e.v );
			res += e.weigh;
			spanTree[SE++] = edge( e.u, e.v, e.weigh );
		}
	}
	cout << "最小生成树的权值为： "  << res << endl;
	cout << "最小生成树的每条边为： " << endl;
	for ( int i = 0; i < SE; i++ )
		cout << spanTree[i].u << " --> " << spanTree[i].v << " ; " << spanTree[i].weigh << endl;
	return 0;
}


