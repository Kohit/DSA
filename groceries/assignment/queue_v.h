/*
 * queue_v.h
 *
 *  Created on: 2014Äê12ÔÂ28ÈÕ
 *      Author: kohit
 */


template< typename T >
class Queue{
private:
	T * elem;
	int fore, rear;
public:
	Queue(int n){
		fore = 0; rear = 0;
		elem = new T[n];
	}
	void reset(){
		fore = rear = 0;
	}
	void enqueue( T const & e ){
		elem[rear++] = e;
	}
	T front(){
		return elem[fore];
	}
	T dequeue(){ return elem[fore++]; }
	bool isempty(){ return rear == fore; }
};
