/*
 * sieve.cpp
 *
 *  Created on: 2014Äê12ÔÂ9ÈÕ
 *      Author: kohit
 */



#include <iostream>
#include <string>
#include "bitmap_v2.h"
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;

//const int MAX_N = 10000007;
//int prime[ MAX_N + 1 ];
Bitmap is_prime( 10001000000 );

void sieve( long long n ){
	//is_prime[ 0 ] = is_prime[ 1 ] = false;
	for ( long long i = 2; i < n; i++ ) is_prime.set( i );    //is_prime[ i ] = true;
	int p = 0;
	for ( long long i = 2; i <= n; i++ ){
		if ( is_prime.test(i) ){
			if ( i > 10000000000 )
				cout << i << endl;
				//prime[ p++ ] = i;
			for ( long long j = 2 * i; j <= n; j += i )
				is_prime.clear( j );
				//is_prime[ j ] = false;
		}
	}
}

int main()
{
	sieve( 10000100000);
	cout << (double)clock() / CLOCKS_PER_SEC << endl;
	/*
	int j = 20;
	for ( int i = 0; i < 100000000 && j > 0; i++ ){
		if ( prime[i] > 1000000000 ){
			cout << prime[i] << endl;
			j--;
		}
	}
	*/
	return 0;
}



