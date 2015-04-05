/*
 * sort.cpp
 *
 *  Created on: 2014Äê12ÔÂ10ÈÕ
 *      Author: kohit
 */
/*
#include <iostream>
using namespace std;

int E[] = { 213, 111, 222, 77, 400, 300, 987, 1024, 632, 555 };

void static swap( int & a, int & b ){
	int c = a; a = b; b = c;
}

void selectionSort( int a[], int n ){
	while( n ){
		int MAXI = 0, MAX = a[0];
		for ( int i = 1; i < n; i++ ){
			if ( a[i] > MAX ){
				MAX = a[i];
				MAXI = i;
			}
		}
		swap( a[MAXI], a[--n] );
	}
}

void bubbleSort( int a[], int n ){
	bool sorted = false;
	while( !sorted ){
		sorted = true;
		for ( int i = 1; i < n; i++ ){
			if ( a[i] < a[i - 1] ){
				swap( a[i], a[i - 1] );
				sorted = false;
			}
		}
		n--;
	}
}

void insertionSort( int a[], int n ){
	for ( int i = 1; i < n; i++  ){
		for ( int j = i; j > 0 && a[j] < a[j - 1]; j--  ){
			swap( a[j], a[j - 1] );
		}
	}
}

void merge( int a[], int lo, int mid, int hi ){
	int lb = mid - lo, rb = hi - mid;
	int * A = a + lo;
	int * B = new int[lb];
	int * C = a + mid;
	for ( int i = 0; i < lb; B[i] = A[i++] );
	for ( int i = 0, j = 0, k = 0; j < lb || k < rb;  ){
		if ( j < lb && ( k >= rb || B[j] <= C[k] ) ) A[i++] = B[j++];
		if ( k < rb && ( j >= lb || C[k] < B[j] ) ) A[i++] = C[k++];
	}
	delete []B;
}

void mergeSort( int a[], int lo, int hi ){
	if ( hi - lo < 2 ) return ;
	int mid = ( lo + hi ) >> 1;
	mergeSort( a, lo, mid );
	mergeSort( a, mid, hi );
	merge( a, lo, mid, hi );
}

void mergeSort( int a[], int n ){
	mergeSort( a, 0, n );
}


int main(){
	const int n = 10;
	int A[10];

	// test merge sort
	for ( int i = 0; i < n; i++ )
		A[i] = E[i];
	cout << "original sequence:" << endl;
	for ( int i = 0; i < n; i++ )
		cout << A[i] << " ";
	cout << endl;
	mergeSort( A, n );
	cout << "after merge sort:" << endl;
	for ( int i = 0; i < n; i++ )
		cout << A[i] << " ";
	cout << endl;

	// test bubble sort
	for ( int i = 0; i < n; i++ )
		A[i] = E[i];
	cout << "original sequence:" << endl;
	for ( int i = 0; i < n; i++ )
		cout << A[i] << " ";
	cout << endl;
	bubbleSort( A, n );
	cout << "after bubble sort:" << endl;
	for ( int i = 0; i < n; i++ )
		cout << A[i] << " ";
	cout << endl;

	// test insertion sort
	for ( int i = 0; i < n; i++ )
		A[i] = E[i];
	cout << "original sequence:" << endl;
	for ( int i = 0; i < n; i++ )
		cout << A[i] << " ";
	cout << endl;
	insertionSort( A, n );
	cout << "after insertion sort:" << endl;
	for ( int i = 0; i < n; i++ )
		cout << A[i] << " ";
	cout << endl;

	// test selection sort
	for ( int i = 0; i < n; i++ )
		A[i] = E[i];
	cout << "original sequence:" << endl;
	for ( int i = 0; i < n; i++ )
		cout << A[i] << " ";
	cout << endl;
	selectionSort( A, n );
	cout << "after selection sort:" << endl;
	for ( int i = 0; i < n; i++ )
		cout << A[i] << " ";
	cout << endl;

	return 0;
}
*/
