/*
 * hash.h
 *
 *  Created on: 2015年1月11日
 *  Revised on: 2015年4月4日
 *      Author: kohit
 */

#ifndef HASH_H_
#define HASH_H_

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <assert.h>
using namespace std;

/*
 * keys[i] -> values[i]
 * API:
 * Value( int i ): return value[i]
 * key( int i ): return key[i]
 * hashcode( const char s[] ), return hashcode of s, hashcode might not be the right index
 * prob( const char s[] ), prob true index r, which keys[r] -> value[r]
 *
 */


template< typename T >
class HashTable{
private:
	int M;             // size, use a prime would be better
	string * keys;
	T * values;
public:
	HashTable(){
		M = 37;
		keys = new string [ M + 1 ];
		values = new T [ M + 1 ];
	}
	HashTable( int size ){
		M = size;
		keys = new string [ M + 1 ];
		values = new T [ M + 1 ];
	}

	T & Value( int key ){
		return values[key];
	}

	string & key( int rank ){
		return keys[ rank ];
	}

	T & operator[] ( const char s[] ){
		int r = prob( s );
		if ( keys[r] == s ) return values[r];
		else keys[r] = s;
		return values[r];
	}
	T & operator[] ( string s ){
		int r = prob( s.c_str() );
		if ( keys[r] == s ) return values[r];
		else keys[r] = s;
		return values[r];
	}

	int hashcode( const char s[] ){
		int h = 0;
		for ( int n = strlen(s), i = 0; i < n; i++ ){
			h = ( h * 37 + s[i] ) % M;
		}
		return h;
	}

	int prob( const char s[] ){
		int rank = hashcode( s );
		int hi = rank;
		int pow = 1;
		bool neg = false;
		int i = 0;
		while( !keys[rank].empty() && ( keys[rank] != s ) ){
			if ( neg ){
				rank = ( hi - pow * pow ) % M;
				if ( rank < 0 ) rank = - rank;
				neg = false;
			}
			else{
				rank = ( hi + pow * pow ) % M;
				neg = true;
			}
			i++;
			if ( i % 2 == 0 ) pow++;
		}
		return rank;
	}
};


#endif /* HASH_H_ */
