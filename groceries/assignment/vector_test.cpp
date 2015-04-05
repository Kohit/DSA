/*
 * vector_test.cpp
 *
 *  Created on: 2014Äê12ÔÂ16ÈÕ
 *      Author: kohit
 */
/*
#include <iostream>
#include "Vector.h"
using namespace std;

struct edge{
	int v, w;
	edge(){}
	edge( int vv, int ww ){
		v = vv; w = ww;
	}
	bool operator< ( const edge & b ) const {
		if ( v == b.v )
			return w > b.w;
		return v < b.v;
	}
	bool operator== ( const edge & b ) const {
		return v == b.v && w == b.w;
	}
	void operator= ( const edge & b ){
		v = b.v; w = b.w;
	}
};

int main(){
	Vector<edge> a;
	a.push_back( edge( 1, 10 ) );
	a.push_back( edge( 5, 10 ) );
	a.push_back( edge( 1000, 20 ) );
	a.push_back( edge( 1, 9 ) );
	a.push_back( edge( 5, 11 ) );
	for ( int i = 0; i < a.size(); i++ )
		cout << a[i].v << endl;
	a.mergeSort();
	for ( int i = 0; i < a.size(); i++ )
		cout << a[i].v << " " << a[i].w << endl;
	return 0;
}
*/
