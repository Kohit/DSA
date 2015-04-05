/*
 * pokeface.cpp
 *
 *  Created on: 2014年12月18日
 *      Author: kohit
 *
 *      参考NotOnlySuccess的博文“完全版线段树”
 *      以及MetalSeed的线段树博文
 *      http://blog.csdn.net/metalseed/article/details/8039326
 *      lazy lag的“欠条”思想来自 xuyuan 同学
 *
 */
/*

#include <iostream>
#include <cstdio>
using namespace std;

#define lson l , m , p << 1
#define rson m + 1 , r , p << 1 | 1
#define root 1 , N , 1

const int maxn = 1 << 20;
int lou[maxn << 2];      // lazy lag， 更新时若区间完全覆盖，则更新区间并标记欠条，查询时欠条还给子区间，同时子区间也继承欠条
int neg[maxn << 2];                  // the number of negative leafs in node i
int size[maxn << 2];                 // the number of leafs in node i

struct fastio{
	char inbuf[maxn], outbuf[maxn];
	fastio(){
		setvbuf( stdin, inbuf, _IOFBF, maxn );
		setvbuf( stdout, outbuf, _IOFBF, maxn );
	}
}io;


void PushDown( int p ){
	if ( lou[ p ] % 2 == 1 ){              // 还欠条给左右子区间（非子树），奇数改一次，偶数不改
		neg[ p << 1 ] = size[p << 1] - neg[p << 1]; // 父节点留下欠条时必然整个区间都被覆盖，因此子区间也是完全覆盖，即状态取反
		lou[ p << 1 ] += 1;                // 子区间也有了欠条
		neg[ p << 1 | 1 ] = size[p << 1 | 1] - neg[p << 1 | 1];
		lou[ p << 1 | 1 ] += 1;
		lou[ p ]--;
	}
}

int build( int l, int r, int p ){
	if ( l == r )
		return size[p] = 1;
	int m = ( l + r ) >> 1;
	size[p] = build( lson ) + build( rson );
	return size[p];
}

void update( int L, int R, int l, int r, int p ){
	if ( L <= l && r <= R ){              // 既然区间完全覆盖，则
		neg[p] = size[p] - neg[p];        // 区间的状态必然取反
		lou[p] += 1; // += 1              // 标记欠条
		return ;
	}
	PushDown(p);                          // 区间未完全覆盖，可能留有欠条，需要先还给子区间，再递归
	int m = ( l + r ) >> 1;
	if ( L <= m ) update( L, R, lson );
	if ( m < R ) update( L, R, rson );
	neg[p] = neg[p << 1] + neg[p << 1 | 1];
}

int query( int L, int R, int l, int r, int p ){
	if ( L <= l && r <= R ){
		return size[p] -  neg[p];
	}
	int m = ( l + r ) >> 1;
	PushDown( p );                         // the same as above
	int res = 0;
	if ( L <= m )	res += query( L, R, lson );
	if ( m < R )	res += query( L, R, rson );
	return res;
}

int main(){
	int N, M;
	scanf ( "%d%d", &N, &M );
	build( root );                       // section 1 to N, 1 is root, [N, 2N) is leaf
	for ( int i = 0; i < M; i++ ){
		char ch;
		int l, r;
		scanf ( " %c%d%d", &ch, &l, &r );
		if ( ch == 'H' )
			update( l, r, root );
		if ( ch == 'Q' ) {
			int res = query( l, r, root );
			printf ( "%d\n", res );
		}
	}
	return 0;
}
*/
