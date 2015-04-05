/*
 * rebuild.cpp
 *
 *  Created on: 2014Äê11ÔÂ10ÈÕ
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstdio>
using namespace std;
#include "binTree.h"

const int MAX_N = 1 << 22;
struct fio{
	char inbuf[ MAX_N ], outbuf[ MAX_N ];
	fio(){
		setvbuf( stdin, inbuf, _IOFBF, MAX_N );
		setvbuf( stdout, outbuf, _IOFBF, MAX_N );
	}
}io;


int pre[ MAX_N ], post[ MAX_N ];
int n;
BinTree<int> proTree;

binNodePosi(int) rebuild( int prelo, int prehi, int postlo, int posthi ){
	if ( prelo > prehi || postlo > posthi ) return NULL;
	binNodePosi(int) p = new BinNode<int>( pre[prelo] );
	if ( prelo == prehi || postlo == posthi ) return p;
	int pomi = postlo;
	//while( pre[prelo + 1] != post[pomi] ) pomi++;
	int prmi = prehi;
	while( pre[prmi] != post[posthi - 1] ) prmi--;
	pomi = posthi - 2 - ( prehi - prmi );
	p->lchild = rebuild( prelo + 1, prmi - 1, postlo, pomi );
	p->rchild = rebuild( prmi, prehi, pomi + 1, posthi - 1 );
	return p;
}

int main(){
	scanf ( "%d", &n );
	for ( int i = 0; i < n; i++ )
		scanf ( "%d", &pre[i] );
	for ( int i = 0; i < n; i++ )
		scanf ( "%d", &post[i] );
	proTree.root() = rebuild( 0, n - 1, 0, n - 1 );
	proTree.traverIn_I();
	return 0;
}
*/

