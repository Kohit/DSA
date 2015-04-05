/*
 * llist.cpp
 *
 *  Created on: 2014Äê10ÔÂ8ÈÕ
 *      Author: Administrator
 */
/*
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#define DEFAULT_CAPACITY 10000
using namespace std;


typedef int Rank;
template < typename T >
class LinearList{
private:
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
	T & operator[] ( Rank r ) const {
		return elem[r];
	}
	void remove( Rank lo, Rank hi ){   // [ , )
		if ( lo >= hi || hi > _size ) return ;
		while( hi < _size ){
			elem[ lo++ ] = elem[ hi++ ];
		}
		_size = lo;
		return ;
	}
	void remove( Rank r ){
		if ( r < 0 || r >= _size ) return;
		remove( r, r + 1 );
		return ;
	}
	void showall(){
		std::ios::sync_with_stdio(false);
		for ( int i = 0; i < _size; i++ )
			cout << elem[i] << " ";
		cout << endl;
	}
	int size(){
		return _size;
	}
};

int main(){
	LinearList< int > linearList;
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	n--;
	string COM;
	cin >> COM;
	for ( int i = 0; i < n; i++ ){
		cin >> COM;
		if ( COM == "PRINT" ){
			linearList.showall();
		}else if ( COM == "ADD" ){
			int val = 0, x = 0;
			cin >> x >> val;
			linearList.insert( val, x - 1 );
		}else if ( COM == "DELETE" ){
			int rank = 0;
			cin >> rank;
			linearList.remove( rank - 1);
		}else if ( COM == "LENGTH" ){
			cout << linearList.size() << endl;
		}
	}
	return 0;
}*/
