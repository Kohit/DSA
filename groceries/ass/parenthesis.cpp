/*
 * parenthesis.cpp
 *
 *  Created on: 2014年10月28日
 *      Author: kohit
 */
/*
 * llist.cpp
 *
 *  Created on: 2014年10月8日
 *      Author: Administrator
 */
/*
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#define DEFAULT_CAPACITY 10007
using namespace std;

const int SZ = 1<<20;
struct fastio{
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;


typedef int Rank;
template < typename T >
class LinearList{
protected:
	Rank _size;
	int capacity;
	T* elem;
public:
	LinearList( int _capacity ){
		capacity = _capacity;
		_size = 0;
		elem = new T[ capacity ];
	}
	LinearList( ){
		capacity = DEFAULT_CAPACITY;
		_size = 0;
		elem = new T[ capacity ];
	}
	~LinearList(){
		delete [] elem;
	}
	T & operator[]( int i ){
		return elem[i];
	}
	void insert( T const & data, Rank index ){
		if ( index < 0 || _size == 0 )
			index = 0;
		if ( index >= _size ){
			elem[_size++] = data; return ;
		}
		for ( int i = _size; i > index; i-- )
			elem[i] = elem[i - 1];
		elem[index] = data;
		_size++;
	}
	void remove( Rank lo, Rank hi ){   // [ , )
		if ( lo >= hi || hi > _size ) return ;
		while( hi < _size ){
			elem[ lo++ ] = elem[ hi++ ];
		}
		_size = lo;
		return ;
	}
	T remove( Rank r ){
		if ( r < 0 || r >= _size ) return 0;
		T e = elem[r];
		remove( r, r + 1 );
		return e;
	}
	void showall(){
        std::ios::sync_with_stdio(false);
		for ( int i = 0; i < _size; i++ )
			printf ( "%d ", elem[i] );
		printf ( "\n" );
	}
	int size(){
		return _size;
	}
};

template< typename T >
class Stack: public LinearList< char >{
public:
	void push( T const & e ){ insert( e, size() ); }
	T pop(){ return remove( size() - 1 ); }
	T & top() { return ( *this )[ size() - 1 ]; }
	bool isempty(){ return size()? 0 : 1;}
};

const int MAX_N = 10007;

bool check( const char * str, int lo, int hi ){
	Stack< char > s;
	for ( int i = lo; i < hi; i++ ){
		switch( str[i] ){
		case '(': case '[': case '<': case '{': s.push( str[i] ); break;
		case ')':
			if ( s.isempty() || s.pop() != '(' ) return false; break;
		case ']':
			if ( s.isempty() || s.pop() != '[' ) return false; break;
		case '>':
			if ( s.isempty() || s.pop() != '<' ) return false; break;
		case '}':
			if ( s.isempty() || s.pop() != '{' ) return false; break;
		default: break;
		}
	}
	return s.isempty();
}


int main(){
   // std::ios::sync_with_stdio(false);
	//string parth;
	char parth[MAX_N];
	while( scanf ( "%s", parth ) != EOF ){
		if ( check( parth, 0, strlen( parth ) ) ) printf ( "YES\n" );//cout << "YES" << endl;
		else
			printf ( "NO\n" );//cout << "NO" << endl;
	}
	return 0;
}
*/
