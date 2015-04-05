/*
 * LightHousePro.cpp
 *
 *  Created on: 2014年12月21日
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstdio>
#include "Vector.h"
using namespace std;

const int INF = 1 << 30;

const int maxn = 1 << 20;
struct fastio{
	char inbuf[maxn], outbuf[maxn];
	fastio(){
		setvbuf( stdin, inbuf, _IOFBF, maxn );
		setvbuf( stdout, outbuf, _IOFBF, maxn );
	}
}io;

struct point{
	int x, y;
	point(){
		x = y = 0;
	}
	point( int xx, int yy ) : x(xx), y(yy) {}
	bool operator< ( const point & b ) const {
		if ( x == b.x ) return y < b.y;
		return x < b.x;
	}
	bool operator== ( const point & b ) const {
		return x == b.x && y == b.y;
	}
};

struct Less{
	bool operator() ( const point & a, const point & b ) {
		if ( a.y == b.y ) return a.x < b.x;
		return a.y < b.y;
	}
};

struct BinNode{
	int data;
	BinNode * parent, * lchild, * rchild, * root;
	int lo, hi;
	BinNode(){
		data = 0; parent = NULL; lchild = NULL; rchild = NULL;
		lo = hi = 0; root = NULL;
	}
	BinNode( int l, int h ){
		data = 0; parent = NULL; lchild = NULL; rchild = NULL;
		lo = l; hi = h; root = NULL;
	}
	bool operator< ( const BinNode & b ){
		return data < b.data;
	}
};


class Segment_Tree{
private:
	BinNode * _root, * _hot;
	Vector<point> * elem;
	int _size;
public:
	Segment_Tree( int n ){
		_root = NULL;	_hot = NULL; _size = n;
		elem = new Vector<point>(n + 7);
	}
	~Segment_Tree(){
		destroy( _root );
	}
	void destroy( BinNode * x ){
		if ( !x ) return ;
		destroy( x->lchild );
		destroy( x->rchild );
		delete x;
	}
	void push_back( point e ){
		elem->push_back( e );
	}
	void build(){
		elem->mergeSort();
		_root = build( 1, elem->size() );
	}

	BinNode * build( int lo, int hi ){
		BinNode * p;
		Vector<point> * v = new Vector<point>( hi - lo + 7 );
		int l = (*elem)[lo - 1].x;
		int r = (*elem)[hi - 1].x;
		if ( hi == lo ){
			p = new BinNode( l, r );
			p->root = new BinNode( (*elem)[lo - 1].y, (*elem)[lo - 1].y );
			p->root->data = 1;
			p->data = 1;
			return p;
		}
		int mid = ( lo + hi ) >> 1;     // [lo   mid,   hi]
		for ( int j = lo - 1; j < hi; j++ ){ // [mid, hi]
			(*v).push_back( (*elem)[j] );
		}
		Less less;
		v->mergeSort( less );         // log n * log log n          // y坐标无需保持全序，只需划分成局部有序？
		p = new BinNode( l, r );
		p->data = v->size();
		p->root = build( v, 1, v->size() ); // log n
		p->lchild = build( lo, mid );
		p->rchild = build( mid + 1, hi );
		delete v;
		return p;
	} // n * log n * log long n

	BinNode * build( Vector<point> * v, int lo, int hi ){

		int l = (*v)[lo - 1].y;
		int r = (*v)[hi - 1].y;
		BinNode * p = new BinNode( l, r );    /////////////////////
		if ( hi == lo ){
			p->data = 1;
			return p;
		}
		int mid = ( lo + hi ) >> 1;
		p->lchild = build( v, lo, mid );
		p->rchild = build( v, mid + 1, hi );
		if ( p->lchild ) p->data += p->lchild->data;
		if ( p->rchild ) p->data += p->rchild->data;
		return p;
	}

	int search( int x1, int y1, int x2, int y2 ){
		return search( _root, x1, y1, x2, y2 );
	}
	int search( BinNode * p, int x1, int y1, int x2, int y2 ){
		if ( !p ) return 0;
		int count = 0;
		if ( x1 <= p->lo && p->hi <= x2 ){
			if ( y1 <= p->root->lo && p->root->hi <= y2 )
				return p->root->data;
			count = search( p->root, y1, y2 );
			return count;
		}
		if ( p->lchild && p->lchild->lo <= x2 )
			count += search( p->lchild, x1, y1, x2, y2 );
		if ( p->rchild && p->rchild->hi >= x1 )
			count += search( p->rchild, x1, y1, x2, y2 );
		return count;
	}
	int search( BinNode * p, int y1, int y2 ){
		if ( !p ) return 0;
		if ( y1 <= p->lo && p->hi <= y2 )
			return p->data;
		int count = 0;
		if ( p->lchild && p->lchild->lo <= y2 )
			count += search( p->lchild, y1, y2 );
		if ( p->rchild && p->rchild->hi >= y1 )
			count += search( p->rchild, y1, y2 );
		return count;
	}

};


int main(){
	int n;
	scanf ( "%d", &n );
	Segment_Tree rt( n );
	while( n-- ){
		int x, y;
		scanf ( "%d%d", &x, &y );
		rt.push_back( point( x, y ) );
	}
	rt.build();
	int m;
	scanf ( "%d", &m );
	while( m-- ){
		int x1, y1, x2, y2;
		scanf ( "%d%d%d%d", &x1, &y1, &x2, &y2 );
		int res = rt.search( 0, 0, x1, y1 );
		res += rt.search( x2, y2, INF, INF );
		if ( x1 == x2 && y1 == y2 && res > 0 ) res--;
		printf ( "%d\n", res );
	}
	return 0;
}
*/
