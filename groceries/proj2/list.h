/*
 * list.h
 *
 *  Created on: 2014Äê11ÔÂ26ÈÕ
 *      Author: Administrator
 */

#define nodePosi(T) Node<T>*

template< typename T >
struct Node{
	T value;
	Node<T> * pre, * succ;
	Node(){}
	Node( T e, Node<T> * p = NULL, Node<T> * s = NULL ): value( e ), pre( p ), succ( s ){}
	Node<T>* insertAsPred( T const & e ){
		Node<T> * x = new Node( e, pre, this );
		pre->succ = x; pre = x;
		return x;
	}
	Node<T>* insertAsSucc( T const & e ){
		Node<T> * x = new Node( e, this, succ );
		succ->pre = x; succ = x;
		return x;
	}
};

template< typename T >
class List{
protected:
	int _size;
	Node<T> * header, * trailer;
public:
	List(){
		_size = 0;
		header = new Node<T>; trailer = new Node<T>;
		header->pre = NULL; header->succ = trailer;
		trailer->pre = header; trailer->succ = NULL;
	}
	Node<T> * First() const { return header->succ; }
	Node<T> * Last() const { return trailer->pre; }
	Node<T> * insertAsFirst( T const & e ){ _size++; return header->insertAsSucc( e ); }
	Node<T> * insertAsLast( T const & e ){ _size++; return trailer->insertAsPred( e ); }
	T remove( Node<T> * p ){
		T e = p->value;
		p->pre->succ = p->succ;
		p->succ->pre = p->pre;
		delete p; _size--;
		return e;
	}
	int size(){ return _size; }
};

