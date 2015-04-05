
/*
 * looplist.h
 *
 *  Created on: 2014Äê10ÔÂ31ÈÕ
 *      Author: kohit
 */
#define iterator(T) Node<T>*

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
	Node<T> * header, * trailer, * last; // last: store the last node
public:
	List(){
		_size = 0;
		header = new Node<T>; trailer = new Node<T>;
		last = new Node<T>; last = NULL;
		header->pre = trailer; header->succ = trailer;
		trailer->pre = header; trailer->succ = header; // form the loop
	}
	Node<T> * First() const { return header->succ; }
	Node<T> * Last() const { return last; }
	Node<T> * begin() const { return header; } // ( , )
	Node<T> * end() const { return trailer; } // ( , )
	Node<T> * insertAsFirst( T const & e ){ _size++; return last = header->insertAsSucc( e ); }
	Node<T> * insertAsLast( T const & e ){ _size++; return trailer->insertAsPred( e ); }
	Node<T> * insertBefore( Node<T> * p, T const & e ){ _size++; return p->insertAsPred( e ); }
	Node<T> * insertBehind( Node<T> * p, T const & e ){ _size++; return p->insertAsSucc( e ); }
	Node<T> * insert( T const & e, int r ){  // first node must use insertAsFirst!
		_size++;
		Node<T> * p = Last();
		while( --r ){
			p = p->succ;
			if ( p == header || p == trailer ) r++;
		}
		return last = p->insertAsSucc( e );
	}
};
