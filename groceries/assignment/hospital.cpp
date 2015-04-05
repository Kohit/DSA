/*
 * hospital.cpp
 *
 *  Created on: 2014年11月1日
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_N = 40000;

long long vili[ MAX_N ];

int abs( int a ){
	return ( a > 0 ) ? a : -a;
}

long long Cal( int pos ){
	long long res = 0;   // 防止数据溢出
	for ( int i = 0; i < MAX_N; i++ ){
		res += vili[ i ] * abs( pos - i ); // 没有村落的权值为0，不会对结果产生影响
	}
	return res;
}

int search( int lo, int hi ){
	while( lo < hi ){
		int mid = ( lo + hi ) >> 1;
		// 计算医院放在左边的坐标
		long long le = Cal( (mid - 1) >= 0 ? mid - 1: mid ); // 注意当mid为1与0的情况
		long long ri = Cal( mid + 1 ); // 右边
		long long mi = Cal( mid ); // 中间
		if ( le <= mi ) hi = mid; // 如果左边的结果更小，那么答案肯定在左边，以此类推
		else if ( ri < mi ) lo = mid;
		else return mid;
	}
	return lo; // 确保
}

int main(){
	int n;
	scanf ( "%d", &n );
	memset( vili, 0, sizeof( vili ) );
	for ( int i = 0; i < n; i++ ){  // n的范围大于村落坐标，因此村落可能重复，但是权值需要累加，
		int wi = 0, xi = 0;
		scanf ( "%d%d", &xi, &wi );
		vili[ xi ] += wi;           // vili数组要为long long，防止数据溢出
	}
	// 用二分策略，在整个区间查找出最优的坐标
	int pos = search( 0, MAX_N - 5000 ); // 村落范围在[0,32767]，减少不必要的计算，呃，其实是怕等下会溢出...
	printf ( "%d\n%lld\n", pos, Cal( pos ) );
	return 0;
}
*/
