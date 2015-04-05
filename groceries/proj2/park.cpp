/*
 * park.cpp
 *
 *  Created on: 2014��11��26��
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
	cout << "�����복λ����" << endl;
	cin >> n;
	cout << "�����뵥λʱ�����" << endl;
	cin >> fee;
	cout << "���������" << endl;
	while( true ){
		char op;
		int num, time;
		cin >> op >> num >> time;
		if ( op == 'A' ){
			if ( P.size() < n ){
				P.push( car( num, time ) );
				cout << "����: " << num << " ����ͣ������ λ��: " << P.size() << endl;
			}
			else{
				Q.enqueue( car( num, time ) );
				cout << "����: " << num << " ��������λ��: " << Q.size() << endl;
			}
		}
		if ( op == 'D' ){
			while( P.top().num != num )
				TMP.push( P.pop() );
			cout << "����: " << P.top().num << "  ͣ��ʱ��: " << time - P.top().time << \
					" ����: " << fee * (time - P.top().time) << endl;
			P.pop();
			while( !TMP.isempty() )
				P.push( TMP.pop() );
			if ( !Q.isempty() ){
				car T = Q.dequeue();
				T.time = time;         // ���賵����������ͣ��������ʱ��
				P.push( T );
				cout << "����: " << T.num << " ����ͣ������ λ��: " << P.size() << endl;
			}
		}
		if ( op == 'E' ) break;
	}
	return 0;
}


