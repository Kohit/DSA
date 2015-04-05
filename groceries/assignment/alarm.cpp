/*
 * alarm.cpp
 *
 *  Created on: 2014年11月19日
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 100007;

struct fio{
	char inbuf[MAX_N * 10], outbuf[MAX_N * 10];
	fio(){
		setvbuf( stdin, inbuf, _IOFBF, MAX_N * 10 );
		setvbuf( stdout, outbuf, _IOFBF, MAX_N * 10 );
	}
}io;

struct node{
	long long x, y;
	node(){}
	node( long long xx, long long yy ) : x(xx), y(yy) {}
	bool leftof( const node & b ){ // 判断点是否在线的左边，计算过程可能溢出，用long long
		return (x * y - ( x - b.x ) * ( y - b.y )) < 0 ? true : false;
	}
};

node area[MAX_N];

int binsearch( node & point, int n ){
	int lo = 0, hi = n;
	while( lo < hi ){
		int mid = ( lo + hi ) / 2;
		if ( point.leftof( area[mid] ) ) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

int main(){
	int n, m;
	scanf ( "%d%d", &n, &m );
	for ( int i = 0; i < n; i++ ){
		long long x, y;
		scanf ( "%lld%lld", &x, &y );
		area[i] = node( x, y );
	}
	for ( int i = 0; i < m; i++ ){
		node point;
		scanf ( "%lld%lld", &point.x, &point.y );
		printf ( "%d\n", binsearch( point, n ) );
	}
	return 0;
}
*/
