/*
 * park.cpp
 *
 *  Created on: 2014年11月26日
 *      Author: kohit
 */

#include <iostream>
#include "stack.h"
#include "queue.h"
using namespace std;

const int MAX_N = 1 << 10;

struct car{
	int num, time;
	car(){}
	car( int nn, int tt ) : num(nn), time(tt) {}
};

int main(){
	Stack<car> P, TMP;
	Queue<car> Q;
	int n = 0, fee = 1;
	cout << "请输入车位数量" << endl;
	cin >> n;
	cout << "请输入单位时间费用" << endl;
	cin >> fee;
	cout << "请输入操作" << endl;
	while( true ){
		char op;
		int num, time;
		cin >> op >> num >> time;
		if ( op == 'A' ){
			if ( P.size() < n ){
				P.push( car( num, time ) );
				cout << "车号: " << num << " 进入停车场， 位置: " << P.size() << endl;
			}
			else{
				Q.enqueue( car( num, time ) );
				cout << "车号: " << num << " 进入便道，位置: " << Q.size() << endl;
			}
		}
		if ( op == 'D' ){
			while( P.top().num != num )
				TMP.push( P.pop() );
			cout << "车号: " << P.top().num << "  停留时间: " << time - P.top().time << \
					" 费用: " << fee * (time - P.top().time) << endl;
			P.pop();
			while( !TMP.isempty() )
				P.push( TMP.pop() );
			if ( !Q.isempty() ){
				car T = Q.dequeue();
				T.time = time;         // 假设车辆开出开入停车场不花时间
				P.push( T );
				cout << "车号: " << T.num << " 进入停车场， 位置: " << P.size() << endl;
			}
		}
		if ( op == 'E' ) break;
	}
	return 0;
}


