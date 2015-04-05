/*
 * linear.cpp
 *
 *  Created on: 2014年10月7日
 *      Author: kohit
 */
#include <iostream>
#include <cstdio>
#define DEFAULT_CAPACITY 50

using namespace std;
const int INF = 1 << 31;

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
			elem[_size++] = data;
			return ;
		}
		for ( int i = _size; i > index; i-- )
			elem[i] = elem[i - 1];
		elem[index] = data;
		_size++;
	}
	T & operator[] ( Rank r ) const {
		return elem[r];
	}
	int remove( Rank lo, Rank hi ){   // [ , )
		if ( lo >= hi || hi > _size ) return -1;
		while( hi < _size ){
			elem[ lo++ ] = elem[ hi++ ];
		}
		_size = lo;
		return hi - lo;
	}
	int remove( Rank r ){
		if ( r < 0 || r >= _size ) return INF;
		T e = elem[ r ];
		remove( r, r + 1 );
		return e;
	}
	int erase( T const & e ){
		for ( int i = 0; i < _size; i++ )
			if ( elem[i] == e ){
				remove( i, i + 1 );
				return i;
			}
		return -1;
	}
	Rank find( T const & e ){
		for ( int i = 0; i < _size; i++ )
			if ( elem[i] == e )
				return i;
		return -1;
	}
	void showall(){
		for ( int i = 0; i < _size; i++ )
			cout << elem[i] << " ";
		cout << endl;
	}
	int size(){
		return _size;
	}
};

int main(){
	LinearList< int > linearList; // 构造
	cout << "依次插入1-5:" << endl;
	for ( int i = 0; i < 5; i++ )
		linearList.insert( i + 1, i ); // 在秩为i处插入i + 1
	linearList.showall(); // 显示所有元素
	cout << "查找元素 3" << endl;
	int rank = linearList.find( 3 ); // 查找 3
	cout << "查找元素的秩为 "  << rank << endl; // 返回 3 的秩
	cout << "删除元素 3" << endl;
	rank = linearList.erase( 3 ); // 删除 3
	cout << "被删除元素的秩为" << rank << endl; // 返回 3 的秩
	linearList.showall();
	cout << "删除秩为2的元素" << endl;
	int e = linearList.remove( 2 ); // 删除秩为2的元素
	cout << "被删除的元素为" << e << endl; // 返回该元素
	linearList.showall(); // 显示所有元素
	return 0;
}
