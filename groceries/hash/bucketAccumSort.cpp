/*
 * bucketAccumSort.cpp
 *
 *  Created on: 2014Äê11ÔÂ30ÈÕ
 *      Author: kohit
 */


#include <iostream>
#include <string>
using namespace std;

string baSort( const string & s ){
	int count[27];
	for ( int i = 0; i < 26; i++ )
		count[i] = 0;
	for ( size_t i = 0; i < s.length(); i++ )
		count[s[i] - 'A']++;
	char ch = 'A';
	string str;
	for ( int i = 0; i < 26; i++ ){
		for ( int j = 0; j < count[i]; j++ )
			str += ch;
		ch++;
	}
	return str;
}

int test(){

	string s;
	while( cin >> s ){
		string ss = baSort( s );
		cout << ss << endl;
	}

	return 0;
}

