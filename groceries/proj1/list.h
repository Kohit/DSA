/*
 * list.h
 *
 *  Created on: 2014Äê10ÔÂ31ÈÕ
 *      Author: kohit
 */

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
private:
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
	Node<T> * begin() const { return header->succ; }
	Node<T> * end() const { return trailer; }
	Node<T> * insertAsFirst( T const & e ){ _size++; return header->insertAsSucc( e ); }
	Node<T> * insertAsLast( T const & e ){ _size++; return trailer->insertAsPred( e ); }
	Node<T> * insertBefore( Node<T> * p, T const & e ){ _size++; return p->insertAsPred( e ); }
	Node<T> * insertBehind( Node<T> * p, T const & e ){ _size++; return p->insertAsSucc( e ); }
	Node<T> * find( T const & e ){
		Node<T> * p = header;
		while( ( p = p->succ ) != trailer ){
			if ( p->value == e )
				return p;
		}
		return NULL;
	}
	Node<T> remove( Node<T> * p ){
		Node<T> e = p->value;
		p->pre->succ = p->succ;
		p->succ->pre = p->pre;
		delete p; _size--;
		return e;
	}
	int size(){ return _size; }
	template< typename VST >
	void traverse( VST & visit ){
		for ( Node<T> * p = header->succ; p != trailer; p = p->succ )
			visit( p->data );
	}
};
