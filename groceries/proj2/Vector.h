/*
 * Vector.h
 *
 *  Created on: 2014Äê10ÔÂ8ÈÕ
 *      Author: kohit
 */

#define DEFAULT_CAPACITY 50
using namespace std;

typedef int Rank;
template < typename T >
class Vector{
private:
	Rank _size;
	int capacity;
	T* elem;
public:
	Vector( int _capacity ){
		capacity = _capacity;
		_size = 0;
		elem = new T[ capacity ];
	}
	Vector(){
		capacity = DEFAULT_CAPACITY;
		_size = 0;
		elem = new T[ capacity ];
	}
	~Vector(){
		delete [] elem;
	}
	void expand(){
		capacity *= 2;
		T * e = new T[capacity];
		for ( int i = 0; i < _size; i++ ){
			e[i] = elem[i];
		}
		delete [] elem;
		elem = e;
	}
	void push_back( T const & data ){
		if ( _size >= capacity ){
			expand();
		}
		elem[_size++] = data;
	}
	T & operator[] ( Rank r ){
		return elem[r];
	}
	void remove( Rank lo, Rank hi ){   // [ , )
		if ( lo >= hi || hi > _size ) return ;
		while( hi < _size ){
			elem[ lo++ ] = elem[ hi++ ];
		}
		_size = lo;
	}
	void remove( Rank r ){
		if ( r < 0 || r > _size ) return ;
		remove( r, r + 1 );
	}
	int size(){
		return _size;
	}
};





