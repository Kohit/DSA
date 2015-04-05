/*
 * 2d_tree.cpp
 *
 *  Created on: 2014Äê12ÔÂ17ÈÕ
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct point{
	int x, y;
	point(){}
	point( int xx, int yy ) : x(xx), y(yy) {}
	bool operator< ( const point & b ) const {
		if ( x == b.x ) return y < b.y;
		return x < b.x;
	}
};

bool Less ( const point & a, const point & b ) {
		if ( a.y == b.y ) return a.x < b.y;
		return a.y < b.y;
}

struct BinNode{
	point data;
	int deep, size;
	BinNode * parent, * lchild, * rchild;
	BinNode(){
		parent = NULL; lchild = NULL; rchild = NULL; data = point( 0, 0 );
		deep = 0; size = 0;
	}
	BinNode( const point & _e, int _d = 0, int s = 1 ){
		data = _e; parent = NULL; lchild = NULL; rchild = NULL;
		deep = _d; size = s;
	}
	bool operator< ( const BinNode & b ){
		return data < b.data;
	}
};


class TwoD_Tree{
private:
	BinNode * _root, * _hot;
	vector<point> elem;
	int size( BinNode * p ){
		if ( p ) return p->size;
		return 0;
	}
public:
	TwoD_Tree(){
		_root = NULL;	_hot = NULL;
	}
	~TwoD_Tree(){
		destroy( _root );
	}
	void destroy( BinNode * x ){
		if ( !x ) return ;
		destroy( x->lchild );
		destroy( x->rchild );
		delete x;
	}
	void push_back( point e ){
		elem.push_back( e );
	}
	void build(){

		for ( int i = 0; i < elem.size(); i++ )
			cout << elem[i].x << " " << elem[i].y << endl;

		_root = build( 0, elem.size(), 0 );
	}

	int midX( int lo, int hi ){
		sort( elem.begin() + lo, elem.begin() + hi );

		cout << "after x" << endl;
		for ( int i = 0; i < elem.size(); i++ )
			cout << elem[i].x << " " << elem[i].y << endl;

		return ( hi + lo ) / 2;
	}
	int midY( int lo, int hi ){
		sort( elem.begin() + lo, elem.begin() + hi, Less );

		cout << "after y" << endl;
		for ( int i = 0; i < elem.size(); i++ )
			cout << elem[i].x << " " << elem[i].y << endl;

		return ( hi + lo ) / 2;
	}

	BinNode * build( int lo, int hi, int deep ){
		if ( hi - lo < 1 ) return NULL;
		BinNode * p;
		if ( deep % 2 == 0 ){
			int mid = midX( lo, hi );
			cout << "|" << elem[mid].x << " " << elem[mid].y << endl;
			p = new BinNode( elem[mid], deep );
			p->lchild = build( lo, mid, deep + 1 );
			if ( p->lchild ) p->lchild->parent = p;
			p->rchild = build( mid + 1, hi, deep + 1 );
			if ( p->rchild ) p->rchild->parent = p;
		}
		else{
			int mid = midY( lo, hi );
			cout << "---" << elem[mid].x << " " << elem[mid].y << endl;
			p = new BinNode( elem[mid], deep );
			p->lchild = build( lo, mid, deep + 1 );
			if ( p->lchild ) p->lchild->parent = p;
			p->rchild = build( mid + 1, hi, deep + 1 );
			if ( p->rchild ) p->rchild->parent = p;
		}
		p->size = size(p->lchild) + size(p->rchild) + 1;

		return p;
	}
	void trav(){
		trav( _root );
	}
	void trav( BinNode * p ){
		if ( !p ) return ;
		trav( p->lchild );
		cout << p->data.x << " " << p->data.y << " " << p->deep << endl;
		trav( p->rchild );
	}
};




int main(){
	int n, m;
	scanf ( "%d", &n );
	TwoD_Tree T;
	for ( int i = 0; i < n; i++ ){
		int x, y;
		scanf ( "%d%d", &x, &y );
		T.push_back( point( x, y ) );
	}
	T.build();
	T.trav();

	scanf ( "%d", &m );
	for ( int i = 0; i < m; i++ ){
		int x1, y1, x2, y2;
		scanf ( "%d%d%d%d", &x1, &y1, &x2, &y2 );

	}

	return 0;
}
*/
