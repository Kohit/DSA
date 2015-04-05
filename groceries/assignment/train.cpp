/*
 * train.cpp
 *
 *  Created on: 2014��11��8��
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstdio>
#include "Stack.h"
using namespace std;

const int MAX_N = 2000000;
int res[ MAX_N ];                  // ��ջ��ֵ

int main(){
	int n, m;
	cin >> n >> m;
	for ( int i = 0; i < n; i++ )
		scanf ( "%d", &res[i] );
	Stack<int> S;
	S.push( 0 );                      // �ڱ�
	int j = 0;
	bool able = true;
	for ( int i = 0; i < n; i++ ){
		if ( res[i] < S.top() ){     // ���ڽ�ջ���зǵݼ������ջ��ֵһ�����ڻ����ջ����ֵ
			able = false;
			break;
		}
		while( S.top() < res[i] && S.size() <= m ){ // ���ڵĻ�������ջ��ֱ��������ֵ����ջ��
			S.push( ++j );
		}
		if ( S.top() != res[i] ){ // ��ջ
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
