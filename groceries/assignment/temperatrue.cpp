/*
 * temperatrue.cpp
 *
 *  Created on: 2014年12月19日
 *      Author: kohit
 */
/*

#include <iostream>
#include <cstdio>
#include "Vector.h"
#include "temperature.h"
using namespace std;

struct point{
	int x, y;
	long long temp;
	point(){}
	point( int xx, int yy, long long t ) : x(xx), y(yy), temp(t) {}
	bool operator< ( const point & b ) const {
		if ( x == b.x ) return y < b.y;
		return x < b.x;
	}
	bool operator== ( const point & b ) const {
		return x == b.x && y == b.y;
	}
};

struct ans{
	long long temp;
	int size;
	ans(){
		temp = 0; size = 0;
	}
	ans( long long tt, int ss ) : temp(tt), size(ss) {}
	ans operator + ( const ans & a ){
		return ans( temp + a.temp, size + a.size );
	}
};

static int binsearch( int data, Vector<point> & p ){
	int lo = 0, hi = p.size();
	while( lo < hi ){
		int mid = ( lo + hi ) / 2;
		if ( data < p[mid].y ) hi = mid;
		else lo = mid + 1;
	}
	return --lo;      // 返回不大于data的最右边的元素
}

struct Less{
	bool operator() ( const point & a, const point & b ) {
		if ( a.y == b.y ) return a.x < b.x;
		return a.y < b.y;
	}
};

struct BinNode{
	point data;
	long long temp;
	Vector<point> * node;
	BinNode * parent, * lchild, * rchild;
	int lo, hi;
	BinNode(){
		data = point( 0, 0, 0 );parent = NULL; lchild = NULL; rchild = NULL;
		temp = 0; node = NULL; lo = hi = 0;
	}
	BinNode( const point & _e, Vector<point> * & e, int l, int h ){
		data = _e; parent = NULL; lchild = NULL; rchild = NULL;
		temp = 0; node = e; lo = l; hi = h;
	}
	bool operator< ( const BinNode & b ){
		return data < b.data;
	}
};


class Range_Tree{
private:
	BinNode * _root, * _hot;
	Vector<point> * elem;
	int _size;
public:
	Range_Tree( int n ){
		_root = NULL;	_hot = NULL; _size = n;
		elem = new Vector<point>;
	}
	~Range_Tree(){
		destroy( _root );
	}
	void destroy( BinNode * x ){
		if ( !x ) return ;
		destroy( x->lchild );
		destroy( x->rchild );
		delete x->node;
		delete x;
	}
	void push_back( point e ){
		elem->push_back( e );
	}
	void build(){
		elem->mergeSort();
		_root = build( 1, _size );
	}

	BinNode * build( int lo, int hi ){
		BinNode * p;
		Vector<point> * v = new Vector<point>;
		int l = (*elem)[lo - 1].x;
		int r = (*elem)[hi - 1].x;
		if ( hi == lo ){
			v->push_back( (*elem)[lo - 1] );
			p = new BinNode( (*elem)[lo - 1], v, l, r );
			p->temp = (*elem)[lo - 1].temp;
			return p;
		}
		int mid = ( lo + hi ) >> 1;     // [lo   ,mid   hi]
		long long t = 0;
		for ( int j = lo - 1; j < hi; j++ ){ // [mid, hi]
			t += (*elem)[j].temp;
			(*v).push_back( (*elem)[j] );
		}
		Less less;
		v->mergeSort( less );
	//	cout << "l = " << l << " r =" << r << endl;
		p = new BinNode( (*elem)[mid], v, l, r );
		//for ( int i = 0; i  )
		p->temp = t;
		p->lchild = build( lo, mid );
		p->rchild = build( mid + 1, hi );
		if ( p->lchild ) p->lchild->parent = p;
		if ( p->rchild ) p->rchild->parent = p;
		return p;
	}
	ans search( int x1, int y1, int x2, int y2 ){
		return search( _root, x1, y1, x2, y2 );
	}
	ans search( BinNode * p, int x1, int y1, int x2, int y2 ){
		if ( !p ) return ans( 0, 0 );
		ans tmp( 0, 0 );
		Vector<point> * v = p->node;
		if ( x1 <= p->lo && p->hi <= x2 ){
			if ( y1 <= (*v)[0].y && (*v)[v->size() - 1].y <= y2 ){
			//	for ( int i = 0; i < v->size(); i++ ){
				//	cout << (*v)[i].x << " " << (*v)[i].y << endl;
			//	}
				return ans( p->temp, v->size() );
			}
			int lo = binsearch( y1, (*v) );
			//lo++;
			if ( lo < 0 ) lo = 0;
			int i = lo - 1;
			while( i >= 0 && (*v)[i].y >= y1 && (*v)[i].y <= y2 ){
				//cout << (*v)[i].x << " " << (*v)[i].y << endl;
				tmp.temp += (*v)[i--].temp;
				tmp.size++;
			}
			if ( (*v)[lo].y < y1 ) lo++;
			while( lo < v->size() && (*v)[lo].y <= y2 ){
			//	cout << (*v)[lo].x << " " << (*v)[lo].y << endl;
				tmp.temp += (*v)[lo++].temp;
				tmp.size++;
			}
			return tmp;
		}
		if ( p->lchild && x1 <= p->lchild->hi && p->lchild->lo <= x2 )
			tmp = tmp + search( p->lchild, x1, y1, x2, y2 );
		if ( p->rchild && p->rchild->lo <= x2 && p->rchild->hi >= x1 )
			tmp = tmp + search( p->rchild, x1, y1, x2, y2 );
		return tmp;
	}
};



int main(){
	int n;
	n = GetNumOfStation();
	Range_Tree rt( n );
	for ( int i = 0; i < n; i++ ){
		int x, y, temp;
		GetStationInfo( i, &x, &y, &temp );
		//printf ( "%d %d %d\n", x, y, temp );
		rt.push_back( point( x, y, temp ) );
	}
	rt.build();
	int state = 1;
	int x1, y1, x2, y2;
	while( state = GetQuery( &x1, &y1, &x2, &y2 ) ){
		ans res =  rt.search( x1, y1, x2, y2 );
		//printf ( "%lld %d\n", res.temp, res.size );
		Response( res.size == 0 ? 0 : res.temp / res.size );
	}

	return 0;
}
*/
