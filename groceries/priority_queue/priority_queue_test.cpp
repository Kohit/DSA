/*
 * priority_queue_test.cpp
 *
 *  Created on: 2014Äê12ÔÂ24ÈÕ
 *      Author: kohit
 */
#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main(){
	int a[] = { 9, 8, 1, 0, 3, -1, 7, 10, 11 };
	priority_queue<int> Q( a, 9 );
	Q.insert( 80 );
	for ( int i = 0; i < 10; i++ ){
		cout << Q.delMax() << endl;
	}
	return 0;
}


