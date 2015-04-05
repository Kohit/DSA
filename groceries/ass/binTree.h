/*
 * binTree.h
 *
 *  Created on: 2014Äê11ÔÂ6ÈÕ
 *      Author: kohit
 */

#define binNodePosi(T) BinNode<T>*

template< typename T >
struct BinNode{
	T data;
	int _size, height;
	BinNode<T> * parent, * lchild, * rchild;
	BinNode(){
		parent = NULL; lchild = NULL; rchild = NULL; data = 0;
		height = 0; _size = 0;
	}
	BinNode( T const & _e, binNodePosi(T) p = NULL, int _s = 1 ){
		data = _e; parent = p; lchild = NULL; rchild = NULL;
		height = 0; _size = _s;
	}
	binNodePosi(T) insertAsLchild( T const & _e ){
		_size++; if ( !rchild ) height++;
		return lchild = new BinNode( _e, this );
	}
	binNodePosi(T) insertAsRchild( T const & _e ){
		_size++; if ( !rchild ) height++;
		return rchild = new BinNode( _e, this );
	}
	bool operator< ( const BinNode<T> & b ){
		return data < b.data;
	}
};

template< typename T >
class BinTree{
private:


	int height( binNodePosi(T) x ){
		if ( !x ) return 0;
		return x->height;
	}
	int size( binNodePosi(T) x ){
		if ( !x ) return 0;
		return x->_size;
	}

public:
	binNodePosi(T) _root;
	BinTree(){
		_root = NULL;
	}
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
	binNodePosi(T) root() {
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
	binNodePosi(T) attachL( binNodePosi(T) x, BinTree<T>* y ){
		if ( (x->lchild = y->_root) ) x->lchild->parent = x;
		y = NULL;
		return x;
	}
	binNodePosi(T) attachR( binNodePosi(T) x, BinTree<T>* y ){
		if ( (x->rchild = y->_root) ) x->rchild->parent = x;
		return x;
	}

	void traverIn_R(){
		traverIn_R( _root );
	}
	void traverIn_R( binNodePosi(T) x ){
		if ( !x ) return ;
		traverIn_R( x->lchild );
		//printf ( "%d ", x->data );
		std::cout << x->data << " ";
		traverIn_R( x->rchild );
	}
};
