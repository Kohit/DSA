/*
 * lighthouse.cpp
 *
 *  Created on: 2014年10月10日
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

void stackoverflow(){    // 人工制造栈溢出
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
	// 从字符串中解析数字，参考 https://www.byvoid.com/blog/fast-readfile，略有修改
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
	// 参考 https://www.byvoid.com/blog/fast-readfile 使用fread会有更快的输入速度
	int len = fread( buf, 1, MAX_SIZE, stdin );
	buf[len] = '\0';
	analyse( buf, len );
}

void merge( int lo, int mid, int hi ){
	// A, B, C, i, j, k, lb, lc
	int lb = mid - lo; // B的上界
	int lc = hi - mid; // C的上界
	Point * A = point + lo;    // A[lo, hi)
	Point * B = new Point[ lb ]; // B[lo, mid)
	Point * C = point + mid;   // C[mid, hi)
	for ( int i = 0; i < lb; B[i] = A[i++] );
	for ( int i = 0, j = 0, k = 0;  j < lb ; ){ // 当j与k都越界时结束
		if (  ( lc <= k ) || ( B[j].x <= C[k].x )  ) A[i++] = B[j++];
		// lc <= k，即当k越界时，视C[k]为无穷大，此时B[j]一定小于C[k]
		if ( ( k < lc ) && (  C[k].x < B[j].x  ) ) A[i++] = C[k++];
	}
	delete [] B;
}


void mergesort( int lo, int hi ){
	if ( hi - lo < 2 ) return ; // 直到区间为1
	int mid = ( lo + hi ) >> 1;
	mergesort( lo, mid );    // T(n/2)
	mergesort( mid, hi );    // T(n/2)
	merge( lo, mid, hi );    // O(n)
}


long mergeY( int lo, int mid, int hi ){
	// A, B, C, i, j, k, lb, lc, sucessions
	long suces = 0;
	int lb = mid - lo; // B的上界
	int lc = hi - mid; // C的上界
	Point * A = point + lo;    // A[lo, hi)
	Point * B = new Point[ lb ]; // B[lo, mid)
	Point * C = point + mid;   // C[mid, hi)
	for ( int i = 0; i < lb; B[i] = A[i++] );
	for ( int i = 0, j = 0, k = 0; j < lb ; ){ // 当j与k都越界时结束
		if (  ( lc <= k ) || ( B[j].y <= C[k].y  ) ) {
			suces += ( lc - k );
			A[i++] = B[j++];
		}
		// lc <= k，即当k越界时，视C[k]为无穷大，此时B[j]一定小于C[k]
		if ( ( k < lc ) && ( C[k].y < B[j].y  ) )A[i++] = C[k++];
	}
	delete [] B;
	return suces;
}


long mergesortY( int lo, int hi ){
	if ( hi - lo < 2 ) return 0; // 直到区间为1
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
	// 相互照到的一对灯塔需要构成顺序对
	mergesort( 0, n ); // 对x坐标排序
	long sucessions = mergesortY( 0, n ); // 对y坐标排序，并计算顺序对数
	printf ( "%ld\n", sucessions );
	return 0;
}
*/
