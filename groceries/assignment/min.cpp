/*
 * min.cpp
 *
 *  Created on: 2014Äê12ÔÂ28ÈÕ
 *      Author: kohit
 */
/*
#include<iostream>
#include<cstdio>
#include<fstream>
#include "PriorityQueue.h"
using namespace std;

int main()
{
	char inbuf[100000];
	setvbuf( stdin, inbuf, _IOFBF, 100000 );
	priority_queue<int> Q;
	int n = 0, k = 0;
	//cin >> n >> k;
	fread( &n, sizeof(int), 1, stdin );
	fread( &k, sizeof(int), 1, stdin );
	for ( int i = 0; i < n; i++ ){
		int num = 0;
		//cin >> num;
		fread( &num, sizeof(int), 1, stdin );
		if ( i < k )
			Q.insert( num );
		else if ( num < Q.getMax() ){
			Q.delMax();
			Q.insert( num );
		}
	}
	for ( int i = 0; i < k; i++ )
		printf ( "%d\n", Q.delMax() );
	return 0;
}
*/
