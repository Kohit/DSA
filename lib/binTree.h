/*
 * binTree.h
 *
 *  Created on: 2014年11月6日
 *      Author: kohit
 */

#define binNodePosi(T) BinNode<T>*

#include "queue.h"
#include "Stack.h"

template< typename T >
struct BinNode{
	T data;
	int _size, height, posi; // posi use for formated output
	BinNode<T> * parent, * lchild, * rchild;
	BinNode(){
		parent = NULL; lchild = NULL; rchild = NULL; data = 0;
		height = 0; posi = 0; _size = 0;
	}
	BinNode( T const & _e, binNodePosi(T) p = NULL, int _s = 1 ){
		data = _e; parent = p; lchild = NULL; rchild = NULL;
		height = 0; posi = 0; _size = _s;
	}
	binNodePosi(T) insertAsLchild( T const & _e ){
		_size++; if ( !rchild ) height++;
		return lchild = new BinNode( _e, this );
	}
	binNodePosi(T) insertAsRchild( T const & _e ){
		_size++; if ( !rchild ) height++;
		return rchild = new BinNode( _e, this );
	}
};

template< typename T >
class BinTree{
private:
	binNodePosi(T) _root;

	int height( binNodePosi(T) x ){
		if ( !x ) return 0;
		return x->height;
	}
	int size( binNodePosi(T) x ){
		if ( !x ) return 0;
		return x->_size;
	}
	binNodePosi(T) leftmost( binNodePosi(T) x ){
		if ( !x ) return NULL;
		if ( !x->lchild ) return x;
		return leftmost( x->lchild );
	}
	binNodePosi(T) removeLeftMost( binNodePosi(T) x ){
		if ( !x->lchild ) return x->rchild;
		x->lchild = removeLeftMost( x->lchild );
		x->_size = size( x->lchild ) + size( x->rchild ) + 1;
		x->height = max( height( x->lchild ), height( x->rchild ) ) + 1;
		return x;
	}
	int depth( binNodePosi(T) x ){
		int count = 0;
		binNodePosi(T) p = _root;
		while( p ){
			if ( p->data < x->data ) p = p->rchild;
			else if ( p->data > x->data ) p = p->lchild;
			else break;
			count++;
		}
		return count;
	}

public:

	BinTree(){
		_root = NULL;
	}
	/*
	~BinTree(){     // low efficiency
		while( _root ){
			_root = remove( _root, _root->data );
		}
	}
	*/
	~BinTree(){
		destroy( _root );
	}
	void destroy( binNodePosi(T) x ){
		if ( !x ) return ;
		destroy( x->lchild );
		destroy( x->rchild );
		delete x;
	}
	int size(){
		return size( _root );
	}
	int height(){
		return height( _root );
	}
	binNodePosi(T) & root() {
		return _root;
	};

	binNodePosi(T) insertAsRoot( T const & e ){
		return _root = new BinNode<T>( e );
	}
	binNodePosi(T) insertAsLchild( binNodePosi(T) x, T const & e ){
		return x->insertAsLchild( e );
	}
	binNodePosi(T) insertAsRchild( binNodePosi(T) x, T const & e ){
		return x->insertAsRchild( e );
	}

	void put( T e ){
		_root = put( _root, e );                  // to keep _root stable
	}
	binNodePosi(T) put( binNodePosi(T) x, T e ){
		if ( !x ) return new BinNode<T>( e );
		if ( e < x->data ) {
			x->lchild = put( x->lchild, e );
			x->lchild->parent = x;
		}
		else {
			x->rchild = put( x->rchild, e );
			x->rchild->parent = x;
		}
		x->_size = size( x->lchild ) + size( x->rchild ) + 1; // update size & height
		x->height = max( height( x->lchild ), height( x->rchild ) ) + 1;
		return x;
	}

	bool find( T e ){
		return search( _root, e ) ? true : false;
	}
	binNodePosi(T) search( binNodePosi(T) x, T e ){
		if ( !x ) return NULL;
		else if ( x->data == e ) return x;
		else if ( e < x->data ) return search( x->lchild, e );
		else return search( x->rchild, e );
	}

	void remove( T e ){
		_root = remove( _root, e );
	}
	binNodePosi(T) remove( binNodePosi(T) x, T e ){
		if ( !x ) return NULL;
		else if ( e < x->data ) x->lchild = remove( x->lchild, e );
		else if ( x->data < e ) x->rchild = remove( x->rchild, e );
		else{                                      // x is the target
			if ( !x->rchild ) {                    // if x don't have right child
				if ( x->lchild )                   // then use its left child to
					x->lchild->parent = x->parent; // replace its position
				binNodePosi(T) t = x->lchild;
				delete x;
				return t;
			}
			if ( !x->lchild ) {                    // vice versa
				if ( x->rchild )
					x->rchild->parent = x->parent;
				binNodePosi(T) t = x->rchild;
				delete x;
				return t;
			}
			binNodePosi(T) t = x;                   // if x have both child then
			x = leftmost( t->rchild );              // use its right child's
			x->rchild = removeLeftMost( t->rchild );// leftmost child to
			x->lchild = t->lchild;                  // replace its position
			x->parent = t->parent;
			if ( x->rchild ) x->rchild->parent = x;
			if ( x->lchild ) x->lchild->parent = x;
			delete t;
		}
		x->_size = size( x->lchild ) + size( x->rchild ) + 1;
		x->height = max( height( x->lchild ), height( x->rchild ) ) + 1;
		return x;
	}

	void traverselevel(){
		binNodePosi(T) x = _root;
		_root->posi = size( _root->lchild );
		Queue<binNodePosi(T)> Q;
		Q.enqueue( x );
		int d = 0, posi = 0;           // d: current depth, posi: current position
		while( !Q.isempty() ){
			x = Q.dequeue();
			// visit x, for formatted output
			if ( d == depth(x) - 1 ) { // newline
				d++; posi = 0; cout << endl;
			}
			if ( x->parent && x->parent->lchild == x ){
				x->posi = x->parent->posi - size( x->rchild ) - 1;
			}
			else if ( x->parent && x->parent->rchild == x ){
				x->posi = x->parent->posi + size( x->lchild ) + 1;
			}
			for ( ; posi < x->posi; posi++ ) cout << " ";
			cout << x->data;
			posi++;

			if ( x->lchild ) Q.enqueue( x->lchild );
			if ( x->rchild ) Q.enqueue( x->rchild );
		}
	}

	// preorder
	void traverPre_R(){                     // recursion
		traverPre_R( _root );
	}
	void traverPre_R( binNodePosi(T) x ){
		if ( !x ) return ;
		cout << x->data;
		traverPre_R( x->lchild );
		traverPre_R( x->rchild );
	}
	void traverPre_I(){                    // iteration, and so on
		traverPre_I( _root );
	}
	void traverPre_I( binNodePosi(T) x ){
		Stack<binNodePosi(T)> S;
		while( true ){
			while( x ){                   // visit along left branch
				cout << x->data;
				S.push( x->rchild );
				x = x->lchild;
			}
			if ( S.isempty() ) break;
			x = S.pop();
		}
	}

	// inorder
	void traverIn_R(){
		traverIn_R( _root );
	}
	void traverIn_R( binNodePosi(T) x ){
		if ( !x ) return ;
		traverIn_R( x->lchild );
		printf ( "%d ", x->data );
		//cout << x->data << " ";
		traverIn_R( x->rchild );
	}
	void traverIn_I(){
		traverIn_I( _root );
	}
	void traverIn_I( binNodePosi(T) x ){
		Stack<binNodePosi(T)> S;
		while( true ){
			while( x ){                  // go along left branch
				S.push( x );
				x = x->lchild;
			}
			if ( S.isempty() ) break;
			x = S.pop();
			printf ( "%d ", x->data );
			//cout << x->data;
			x = x->rchild;
		}
	}

	// postorder
	void traverPost_R(){
		traverPost_R( _root );
	}
	void traverPost_R( binNodePosi(T) x ){
		if ( !x ) return ;
		traverPost_R( x->lchild );
		traverPost_R( x->rchild );
		cout << x->data;
	}
	void traverPost_I(){
		traverPost_I( _root );
	}
	void traverPost_I( binNodePosi(T) x ){
		Stack<binNodePosi(T)> S;
		if ( x ) S.push( x );
		while( !S.isempty() ){
			if ( S.top() != x->parent ){                     // sibling
				while( binNodePosi(T) p = S.top() ){         // find HLVFL
					if ( p && p->lchild ){
						if ( p->rchild ) S.push( p->rchild );
						S.push( p->lchild );
					}else
						S.push( p->rchild );
				}
				S.pop();
			}
			x = S.pop();
			cout << x->data;
		}
	}
};
