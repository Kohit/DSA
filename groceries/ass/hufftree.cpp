/*
 * hufftree.cpp
 *
 *  Created on: 2014Äê11ÔÂ11ÈÕ
 *      Author: kohit
 */
/*
#include <iostream>
using namespace std;
#include "list.h"
#include "binTree.h"
typedef List<BinTree<int>* > HuffForest;

HuffForest forest;


BinTree<int>* minweight( HuffForest * forest ){
	nodePosi(BinTree<int>*) p = forest->First();
	nodePosi(BinTree<int>*) less = p;
	while( p && p != forest->end() ){
		if ( less->value->root()->data > p->value->root()->data )
			less = p;
		p = p->succ;
	}
	return forest->remove( less );
}


BinTree<int>* generate( HuffForest * forest ){
	while( 1 < forest->size() ){
		BinTree<int> * T1 = minweight( forest );
		BinTree<int> * T2 = minweight( forest );
		BinTree<int> * x = new BinTree<int>;
		x->insertAsRoot( T1->root()->data + T2->root()->data );
		x->attachL( x->root(), T1 );
		x->attachR( x->root(), T2 );
		forest->insertAsLast( x );
	}
	return forest->First()->value;
}

int main(){
	int n;
	cin >> n;
	for ( int i = 0; i < n; i++ ){
		int w = 0;
		cin >> w;
		BinTree<int>* p = new BinTree<int>;
		p->insertAsRoot( w );
		forest.insertAsLast( p );
	}
	BinTree<int> * r = generate( & forest );
	cout << r->weight() << endl;
	r->traverPre_R();
	return 0;
}

*/
