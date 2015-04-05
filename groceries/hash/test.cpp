/*
 * test.cpp
 *
 *  Created on: 2015年1月11日
 *  Revised on: 2015年4月4日
 *      Author: kohit
 */

#include <iostream>
#include "hash.h"
using namespace std;

int main(){

	HashTable<int> foo;           // size = 37

	foo[ "abc" ] = 1;
	cout << foo["abc"] << endl;

	foo[ "abc" ] = 10;
	cout << foo[ "abc" ] << endl;

	cout << foo[ "bca" ] << endl;  // risk, might cough stack overflow
	foo[ "bca" ]++;
	cout << foo[ "bca" ] << endl;

	HashTable<char *> fooo( 213 ); // set size to 213

	string demo = "abc";
	fooo[ demo ] = "bca";
	cout << fooo[ demo ]; cout << endl;

	fooo[ demo ] = "cba";
	cout << fooo[ demo ]; cout << endl;

	demo = "Bob";
	cout << "hashcode ( " << demo << " ) : " << fooo.hashcode( demo.c_str() ) << endl;
	int key = fooo.prob( demo.c_str() );
	if ( fooo.key( key ) == demo )
		fooo.Value( key ) = "2";
	else {
		fooo.key( key ) = demo;
		fooo.Value( key ) = "213";
	}
	cout << demo << " -> " << fooo.Value( key ) << endl;

	demo = "Alice";
	cout << "hashcode ( " << demo << " ) : " << fooo.hashcode( demo.c_str() ) << endl;
	key = fooo.prob( demo.c_str() );
	if ( fooo.key( key ) == demo.c_str() )
		fooo.Value( key ) = "213";
	else{
		fooo.key( key ) = demo;
		fooo.Value( key ) = "23333";
	}
	cout << demo << " -> " << fooo.Value( key ) << endl;

	return 0;
}
