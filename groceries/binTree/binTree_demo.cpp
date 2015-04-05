/*
 * bintree.cpp
 *
 *  Created on: 2014Äê11ÔÂ5ÈÕ
 *      Author: kohit
 */

#include <iostream>
using namespace std;
#include "binTree.h"

int main(){
	char seq[] = { 'D', 'B', 'E', 'A', 'C', 'G', 'F' };
	BinTree<char> binTree;

	cout << "building binary tree..." << endl;

	for ( int i = 0; i < 7; i++ ){
		cout << "insert " << seq[i] << endl;
		binTree.put( seq[i] );
		binTree.traverselevel();
		cout << endl;
	}

	cout << "testing traverse" << endl;
	cout << "test version of recursion" << endl;
	cout << "preorder:    ";
	binTree.traverPre_R();
	cout << endl << "inorder:     ";
	binTree.traverIn_R();
	cout << endl << "postorder:   ";
	binTree.traverPost_R();
	cout << endl;
	cout << "test version of iteration" << endl;
	cout << "preorder:    ";
	binTree.traverPre_I();
	cout << endl << "inorder:     ";
	binTree.traverIn_I();
	cout << endl << "postorder:   ";
	binTree.traverPost_I();
	cout << endl;

	cout << endl << "try find 'C' " << endl;
	bool x = binTree.find( 'C' );
	if ( x ) cout << "Success" << endl;
	else cout << "data no found" << endl;

	cout << endl << "try delete 'C' " << endl << "before delete:" << endl;
	binTree.traverselevel();
	binTree.remove( 'C' );
	cout << endl << "after delete:" << endl;
	binTree.traverselevel();
	return 0;
}
