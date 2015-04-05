/*
 * queue.cpp
 *
 *  Created on: 2014年10月28日
 *      Author: kohit
 */
/*
 * list.h
 *
 *  Created on: 2014年10月16日
 *      Author: kohit
 */

/*
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;


struct Node{
	char value;
	Node * pre, * succ;
	Node(){}
	Node( char e, Node * p = NULL, Node * s = NULL ): value( e ), pre( p ), succ( s ){}

};

class List{
private:
	int _size;
	Node * header, * trailer;
public:
	List(){
		_size = 0;
		header = new Node;
		trailer = new Node;
		header->pre = NULL; header->succ = trailer;
		trailer->pre = header; trailer->succ = NULL;
		header->value = 0;
		trailer->value = 0;
	}
	Node * First() const {
		return header->succ;
	}
	void insertAsFirst( char e ){
		Node * p = header;
		Node * x = new Node( e, p, p->succ );
		p->succ->pre = x;
		p->succ = x;
		_size++;
	}
	void insertAsLast( char e ){
		Node *p = trailer;
		Node * x = new Node( e, p->pre, p );
		p->pre->succ = x;
		p->pre = x;
		_size++;
	}
	void insert( int r, char e ){
		Node * p = header->succ;
		int i = 0;
		while( p->succ && i++ < r ){
			p = p->succ;
		}
		Node * x = new Node( e, p->pre, p );
		p->pre->succ = x;
		p->pre = x;
		_size++;
	}
	char remove( Node * p ){
		char e = p->value;
		p->pre->succ = p->succ;
		p->succ->pre = p->pre;
		delete p;
		_size--;
		return e;
	}
	int size(){
		return _size;
	}
	void traverse( ){
		std::ios::sync_with_stdio(false);
		Node * p = header;
		if ( header->succ == trailer ){
			cout << endl;
			return ;
		}
		p = p->succ;
		cout << p->value;
		while( (p = p->succ) != trailer ){
			cout << " " << p->value;
		}
		cout << endl;
		return ;
	}
};

class Queue: public List{
public:
	bool isempty(){ return size()? 0 : 1; }
	void enqueue( const char & e ){ insertAsLast( e ); }
	char dequeue( ){ return remove( First() ); }
	char & front(){ return First()->value; }
};

int main(){
	std::ios::sync_with_stdio(false);
	Queue Q;
	int n;
	cin >> n;
	string com;
	cin >> com;
	n--;
	char e;
	while( n-- ){
		cin >> com;
		if ( com == "ENTER" ){ cin >> e; Q.enqueue( e ); }
		else if ( com == "LENGTH" ) cout<< Q.size() << endl;
		else if ( com == "OUT" ) { if ( !Q.isempty() ) Q.dequeue(); }
		else if ( com == "PRINT" ) Q.traverse();
	}
	return 0;
}

*/
