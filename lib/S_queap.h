/*
 * S_queap.h
 *
 *  Created on: 2014年11月21日
 *      Author: kohit
 */

#include "l_stack.h"

class Queap{
private:
	struct node{          // 最值重复非常多，用计数器来保存重复值，减少进出栈次数
		int e, count;
		node(){
			e = 0; count = 0;
		}
		node( int ee, int cc ): e(ee), count(cc){}
	};
	Stack<int> S1, S2;     // 保存数据
	Stack<node> SM1, SM2;  // 保存最值
public:
	Queap(){}
	void enqueap( int e ){
		S1.push( e );
		int count = 1;
		while( !SM1.empty() && SM1.top().e > e ){ // 栈顶的值比e大，则
			count+= SM1.pop().count;              // 栈顶值应该改为e，使得
		}                                         // 栈从低到顶成递增序列
		SM1.push( node( e, count ) );
	}
	int dequeap(){
		while( !SM1.empty() ){                    // 出队时应将最值栈栈底元素的
			SM2.push( SM1.pop() );                // 计数器减1，直到其为0时弹出
		}
		if ( --(SM2.top().count) == 0 ) SM2.pop();
		while( !SM2.empty() ){
			SM1.push( SM2.pop() );
		}
		if ( S2.empty() )                         // 当S2为空时才倒置S1的值
			while( !S1.empty() ){                 // 使得S2的值总比S1先进队
				S2.push( S1.pop() );
			}
		return S2.pop();
	}
	int min(){
		while( !SM1.empty() ){                    // SM1底部的值为最小值
			SM2.push( SM1.pop() );
		}
		int e = SM2.top().e;

		while( !SM2.empty() ){
			SM1.push( SM2.pop() );
		}
		return e;
	}
};
