/*
 * train.cpp
 *
 *  Created on: 2014年11月8日
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstdio>
#include "Stack.h"
using namespace std;

const int MAX_N = 2000000;
int res[ MAX_N ];                  // 出栈的值

int main(){
	int n, m;
	cin >> n >> m;
	for ( int i = 0; i < n; i++ )
		scanf ( "%d", &res[i] );
	Stack<int> S;
	S.push( 0 );                      // 哨兵
	int j = 0;
	bool able = true;
	for ( int i = 0; i < n; i++ ){
		if ( res[i] < S.top() ){     // 由于进栈序列非递减，则出栈的值一定大于或等于栈顶的值
			able = false;
			break;
		}
		while( S.top() < res[i] && S.size() <= m ){ // 大于的话继续进栈，直到遇到该值或者栈满
			S.push( ++j );
		}
		if ( S.top() != res[i] ){ // 爆栈
			able = false;
			break;
		}
		S.pop();
	}
	if ( able == false )
		printf ( "No\n" );
	else
		printf ( "Yes\n" );
	return 0;
}
*/
