/*
 * hospital.cpp
 *
 *  Created on: 2014��11��1��
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
	long long res = 0;   // ��ֹ�������
	for ( int i = 0; i < MAX_N; i++ ){
		res += vili[ i ] * abs( pos - i ); // û�д����ȨֵΪ0������Խ������Ӱ��
	}
	return res;
}

int search( int lo, int hi ){
	while( lo < hi ){
		int mid = ( lo + hi ) >> 1;
		// ����ҽԺ������ߵ�����
		long long le = Cal( (mid - 1) >= 0 ? mid - 1: mid ); // ע�⵱midΪ1��0�����
		long long ri = Cal( mid + 1 ); // �ұ�
		long long mi = Cal( mid ); // �м�
		if ( le <= mi ) hi = mid; // �����ߵĽ����С����ô�𰸿϶�����ߣ��Դ�����
		else if ( ri < mi ) lo = mid;
		else return mid;
	}
	return lo; // ȷ��
}

int main(){
	int n;
	scanf ( "%d", &n );
	memset( vili, 0, sizeof( vili ) );
	for ( int i = 0; i < n; i++ ){  // n�ķ�Χ���ڴ������꣬��˴�������ظ�������Ȩֵ��Ҫ�ۼӣ�
		int wi = 0, xi = 0;
		scanf ( "%d%d", &xi, &wi );
		vili[ xi ] += wi;           // vili����ҪΪlong long����ֹ�������
	}
	// �ö��ֲ��ԣ�������������ҳ����ŵ�����
	int pos = search( 0, MAX_N - 5000 ); // ���䷶Χ��[0,32767]�����ٲ���Ҫ�ļ��㣬������ʵ���µ��»����...
	printf ( "%d\n%lld\n", pos, Cal( pos ) );
	return 0;
}
*/
