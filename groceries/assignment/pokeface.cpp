/*
 * pokeface.cpp
 *
 *  Created on: 2014��12��18��
 *      Author: kohit
 *
 *      �ο�NotOnlySuccess�Ĳ��ġ���ȫ���߶�����
 *      �Լ�MetalSeed���߶�������
 *      http://blog.csdn.net/metalseed/article/details/8039326
 *      lazy lag�ġ�Ƿ����˼������ xuyuan ͬѧ
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
int lou[maxn << 2];      // lazy lag�� ����ʱ��������ȫ���ǣ���������䲢���Ƿ������ѯʱǷ�����������䣬ͬʱ������Ҳ�̳�Ƿ��
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
	if ( lou[ p ] % 2 == 1 ){              // ��Ƿ�������������䣨����������������һ�Σ�ż������
		neg[ p << 1 ] = size[p << 1] - neg[p << 1]; // ���ڵ�����Ƿ��ʱ��Ȼ�������䶼�����ǣ����������Ҳ����ȫ���ǣ���״̬ȡ��
		lou[ p << 1 ] += 1;                // ������Ҳ����Ƿ��
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
	if ( L <= l && r <= R ){              // ��Ȼ������ȫ���ǣ���
		neg[p] = size[p] - neg[p];        // �����״̬��Ȼȡ��
		lou[p] += 1; // += 1              // ���Ƿ��
		return ;
	}
	PushDown(p);                          // ����δ��ȫ���ǣ���������Ƿ������Ҫ�Ȼ��������䣬�ٵݹ�
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
