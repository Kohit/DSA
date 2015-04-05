/*
 * vetcot.cpp
 *
 *  Created on: 2014年10月2日
 *      Author: kohit
 *
 *
 * Vector
 * 构造： Vector( int capacity ) 构造容量为capacity的向量，参数为空采用默认容量
 * 插入：insert( T e, Rank r ) 在秩为r的地方插入元素
 * 删除：remove( Rank lo, Rank hi ) 删除区间[lo,hi)的元素; remove( Rank r ) 删除秩为r的元素; erase ( T e ) 删除元素e，不存在则返回负无穷
 * 查找：find( T e )，命中返回秩，否则返回-1
 * 查看：showall() 输出向量中的所有元素
 */
#include <iostream>
#include <cstdio>
#define DEFAULT_CAPACITY 50
using namespace std;
const int INF = 1 << 31;

typedef int Rank;
template < typename T >
class Vector{
private:
	Rank size;
	int capacity;
	T* elem;
public:
	Vector( int _capacity ){
		capacity = _capacity;
		size = 0;
		elem = new T[ capacity ];
	}
	Vector( ){
		capacity = DEFAULT_CAPACITY;
		size = 0;
		elem = new T[ capacity ];
	}
	~Vector(){
		delete [] elem;
	}
	void expand(){
		if ( size < capacity ) return;
		T* oldE = elem;
		capacity *= 2;  //
		elem = new T[ capacity ];
		for ( int i = 0; i < size; i++ )
			elem[i] = oldE[i];
		delete [] oldE;
	}
	void insert( T const & data, Rank index ){
		expand();
		if ( index < 0 || size == 0 )
			index = 0;
		for ( int i = size; i > index; i-- )
			elem[i] = elem[i - 1];
		elem[index] = data;
		size++;
	}
	T & operator[] ( Rank r ) const {
		return elem[r];
	}
	int remove( Rank lo, Rank hi ){   // [ , )
		if ( lo >= hi || hi > size ) return -1;
		while( hi < size ){
			elem[ lo++ ] = elem[ hi++ ];
		}
		size = lo;
		return hi - lo;
	}
	int remove( Rank r ){
		if ( r < 0 || r >= size ) return INF;
		T e = elem[ r ];
		remove( r, r + 1 );
		return e;
	}
	int erase( T const & e ){
		for ( int i = 0; i < size; i++ )
			if ( elem[i] == e ){
				remove( i, i + 1 );
				return i;
			}
		return -1;
	}
	Rank find( T const & e ){
		for ( int i = 0; i < size; i++ )
			if ( elem[i] == e )
				return i;
		return -1;
	}
	void showall(){
		if ( size == 0 ) cout << "向量为空" << endl;
		for ( int i = 0; i < size; i++ )
			cout << elem[i] << " ";
		cout << endl;
	}
};

int main(){
	Vector< int > vector; // 构造
	for ( int i = 0; i < 5; i++ )
		vector.insert( i + 1, i ); // 在秩为i处插入i + 1
	vector.showall(); // 显示所有元素
	int rank = vector.find( 3 ); // 查找 3
	cout << "查找元素 的秩为 "  << rank << endl; // 返回 3 的秩
	rank = vector.erase( 3 ); // 删除 3
	cout << "被删除元素的秩为" << rank << endl; // 返回 3 的秩
	vector.showall();
	int e = vector.remove( 2 ); // 删除秩为2的元素
	cout << "被删除的元素为" << e << endl; // 返回该元素
	vector.showall(); // 显示所有元素
	return 0;
}

