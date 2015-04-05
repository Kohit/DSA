/*
 * S_queap.h
 *
 *  Created on: 2014��11��21��
 *      Author: kohit
 */

#include "l_stack.h"

class Queap{
private:
	struct node{          // ��ֵ�ظ��ǳ��࣬�ü������������ظ�ֵ�����ٽ���ջ����
		int e, count;
		node(){
			e = 0; count = 0;
		}
		node( int ee, int cc ): e(ee), count(cc){}
	};
	Stack<int> S1, S2;     // ��������
	Stack<node> SM1, SM2;  // ������ֵ
public:
	Queap(){}
	void enqueap( int e ){
		S1.push( e );
		int count = 1;
		while( !SM1.empty() && SM1.top().e > e ){ // ջ����ֵ��e����
			count+= SM1.pop().count;              // ջ��ֵӦ�ø�Ϊe��ʹ��
		}                                         // ջ�ӵ͵����ɵ�������
		SM1.push( node( e, count ) );
	}
	int dequeap(){
		while( !SM1.empty() ){                    // ����ʱӦ����ֵջջ��Ԫ�ص�
			SM2.push( SM1.pop() );                // ��������1��ֱ����Ϊ0ʱ����
		}
		if ( --(SM2.top().count) == 0 ) SM2.pop();
		while( !SM2.empty() ){
			SM1.push( SM2.pop() );
		}
		if ( S2.empty() )                         // ��S2Ϊ��ʱ�ŵ���S1��ֵ
			while( !S1.empty() ){                 // ʹ��S2��ֵ�ܱ�S1�Ƚ���
				S2.push( S1.pop() );
			}
		return S2.pop();
	}
	int min(){
		while( !SM1.empty() ){                    // SM1�ײ���ֵΪ��Сֵ
			SM2.push( SM1.pop() );
		}
		int e = SM2.top().e;

		while( !SM2.empty() ){
			SM1.push( SM2.pop() );
		}
		return e;
	}
};
