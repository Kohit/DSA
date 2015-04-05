/*
 * lighthouse.cpp
 *
 *  Created on: 2014��10��10��
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
/*
const int MAX_N = 5000000;
const int MAX_SIZE = MAX_N * 15;

void stackoverflow(){    // �˹�����ջ���
	while(1)
		stackoverflow();
}

struct Point{
	int x, y;
	Point( int _x, int _y ){
		x = _x; y = _y;
	}
	Point(){}
};
Point point[MAX_N];

char buf[MAX_SIZE];
int numbers[8000000];

void analyse( char * buf, int len ){
	// ���ַ����н������֣��ο� https://www.byvoid.com/blog/fast-readfile�������޸�
	int i = 0;
	numbers[ 0 ] = 0;
	for ( char *p = buf; *p && ( p - buf < len ); p++ ){
		if ( *p == ' ' || *p == '\n')
			numbers[++i] = 0;
		else if ( *p == '\r' ) continue;
		else
			numbers[i] = numbers[i] * 10 + *p - '0';
	}
}

void read(){
	// �ο� https://www.byvoid.com/blog/fast-readfile ʹ��fread���и���������ٶ�
	int len = fread( buf, 1, MAX_SIZE, stdin );
	buf[len] = '\0';
	analyse( buf, len );
}

void merge( int lo, int mid, int hi ){
	// A, B, C, i, j, k, lb, lc
	int lb = mid - lo; // B���Ͻ�
	int lc = hi - mid; // C���Ͻ�
	Point * A = point + lo;    // A[lo, hi)
	Point * B = new Point[ lb ]; // B[lo, mid)
	Point * C = point + mid;   // C[mid, hi)
	for ( int i = 0; i < lb; B[i] = A[i++] );
	for ( int i = 0, j = 0, k = 0;  j < lb ; ){ // ��j��k��Խ��ʱ����
		if (  ( lc <= k ) || ( B[j].x <= C[k].x )  ) A[i++] = B[j++];
		// lc <= k������kԽ��ʱ����C[k]Ϊ����󣬴�ʱB[j]һ��С��C[k]
		if ( ( k < lc ) && (  C[k].x < B[j].x  ) ) A[i++] = C[k++];
	}
	delete [] B;
}


void mergesort( int lo, int hi ){
	if ( hi - lo < 2 ) return ; // ֱ������Ϊ1
	int mid = ( lo + hi ) >> 1;
	mergesort( lo, mid );    // T(n/2)
	mergesort( mid, hi );    // T(n/2)
	merge( lo, mid, hi );    // O(n)
}


long mergeY( int lo, int mid, int hi ){
	// A, B, C, i, j, k, lb, lc, sucessions
	long suces = 0;
	int lb = mid - lo; // B���Ͻ�
	int lc = hi - mid; // C���Ͻ�
	Point * A = point + lo;    // A[lo, hi)
	Point * B = new Point[ lb ]; // B[lo, mid)
	Point * C = point + mid;   // C[mid, hi)
	for ( int i = 0; i < lb; B[i] = A[i++] );
	for ( int i = 0, j = 0, k = 0; j < lb ; ){ // ��j��k��Խ��ʱ����
		if (  ( lc <= k ) || ( B[j].y <= C[k].y  ) ) {
			suces += ( lc - k );
			A[i++] = B[j++];
		}
		// lc <= k������kԽ��ʱ����C[k]Ϊ����󣬴�ʱB[j]һ��С��C[k]
		if ( ( k < lc ) && ( C[k].y < B[j].y  ) )A[i++] = C[k++];
	}
	delete [] B;
	return suces;
}


long mergesortY( int lo, int hi ){
	if ( hi - lo < 2 ) return 0; // ֱ������Ϊ1
	int mid = ( lo + hi ) >> 1;
	long x = mergesortY( lo, mid );    // T(n/2)
	long y = mergesortY( mid, hi );    // T(n/2)
	long z = mergeY( lo, mid, hi );    // O(n)
	return x + y + z;
}



int main(){
	read();
	int index = 1;
	int n = numbers[0];
	for ( int i = 0; i < n; i++ ){
		point[i].x = numbers[index++];
		point[i].y = numbers[index++];
	}
	// �໥�յ���һ�Ե�����Ҫ����˳���
	mergesort( 0, n ); // ��x��������
	long sucessions = mergesortY( 0, n ); // ��y�������򣬲�����˳�����
	printf ( "%ld\n", sucessions );
	return 0;
}
*/
