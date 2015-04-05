/*
 * range.cpp
 *
 *  Created on: 2014年10月3日
 *      Author: kohit
 */
// bin search + mergesort
/*
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
const int MAX_SIZE = 1000000;

int point[MAX_SIZE];
int n, m;
int binsearch( int data ){
	int lo = 0, hi = n;
	while( lo < hi ){
		int mid = ( lo + hi ) / 2;
		if ( data < point[mid] ) hi = mid;
		else lo = mid + 1;
	}
	return --lo;      // 返回不大于data的最右边的元素
}

int comp( const void * a, const void * b ){
	return *( int *)a - *( int *)b;
}
/* not correct
int search( int data ){
	int lo = 0, hi = n - 1;
	while( lo < hi ){
		int mid = ( int ) (lo + ( hi - lo ) * ( data - point[lo] ) / ( point[hi] - point[lo] ) + 0.5 );
		//cout << mid << endl;
//		double mm = (double)( hi - lo ) * ( data - point[lo] ) / ( point[hi] - point[lo] );
	//	int mid = lo + mm;
		//cout << mm << " mid = " << mid << " ; lo = " << lo << " ; hi = " << hi << endl;
		if ( mid < lo ) return --lo;
		if ( data < point[mid] ) hi = mid;
		else
			lo = mid + 1;
	}
	return --lo;
}
*/
/*
 * void merge( int lo, int mid, int hi ){
	// A, B, C, i, j, k, lb, lc
	int lb = mid - lo; // B的上界
	int lc = hi - mid; // C的上界
	int * A = point + lo;    // A[lo, hi)
	int * B = new int[ lb ]; // B[lo, mid)
	int * C = point + mid;   // C[mid, hi)
	for ( int i = 0; i < lb; B[i] = A[i++] );
	for ( int i = 0, j = 0, k = 0; ( j < lb ) || ( k < lc ); ){ // 当j与k都越界时结束
		if ( ( j < lb ) && ( ( lc <= k ) || ( B[j] <= C[k] ) ) ) A[i++] = B[j++];
		// lc <= k，即当k越界时，视C[k]为无穷大，此时B[j]一定小于C[k]
		if ( ( k < lc ) && ( ( lb <= j ) || ( C[k] < B[j] ) ) ) A[i++] = C[k++];
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
 * */
/*
int merge( int lo, int mid, int hi ){
	// A, B, C, i, j, k, lb, lc, inversions
	int invers = 0;
	int lb = mid - lo; // B的上界
	int lc = hi - mid; // C的上界
	int * A = point + lo;    // A[lo, hi)
	int * B = new int[ lb ]; // B[lo, mid)
	int * C = point + mid;   // C[mid, hi)
	for ( int i = 0; i < lb; B[i] = A[i++] );
	for ( int i = 0, j = 0, k = 0; ( j < lb ) || ( k < lc ); ){ // 当j与k都越界时结束
		if ( ( j < lb ) && ( ( lc <= k ) || ( B[j] <= C[k] ) ) ) A[i++] = B[j++];
		// lc <= k，即当k越界时，视C[k]为无穷大，此时B[j]一定小于C[k]
		if ( ( k < lc ) && ( ( lb <= j ) || ( C[k] < B[j] ) ) ){
			invers += (lb - j);
			A[i++] = C[k++];}
	}
	delete [] B;
	return invers;
}


int mergesort( int lo, int hi ){
	if ( hi - lo < 2 ) return 0; // 直到区间为1
	int mid = ( lo + hi ) >> 1;

	int x = mergesort( lo, mid );    // T(n/2)
	int y = mergesort( mid, hi );    // T(n/2)
	int z = merge( lo, mid, hi );    // O(n)
	return x + y + z;
}



int main(){
	scanf( "%d%d", &n, &m );
	for ( int i = 0; i < n; i++ )
		scanf( "%d", &point[i] );
	//qsort( point, n, sizeof(int), comp );
	int inversions = mergesort( 0, n );
	cout << "inversions :" << inversions << endl;
	int a, b;
	for ( int i = 0; i < m; i++ ){
		scanf ( "%d%d", &a, &b );
		int hb = binsearch( b );
		int lo = binsearch( a );
		int res = hb -lo;
		if ( lo >= 0 && point[lo] == a ) res++;
		printf( "%d\n", res );
	}
	return 0;
}
*/
