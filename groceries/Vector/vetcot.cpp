/*
 * vetcot.cpp
 *
 *  Created on: 2014��10��2��
 *      Author: kohit
 *
 *
 * Vector
 * ���죺 Vector( int capacity ) ��������Ϊcapacity������������Ϊ�ղ���Ĭ������
 * ���룺insert( T e, Rank r ) ����Ϊr�ĵط�����Ԫ��
 * ɾ����remove( Rank lo, Rank hi ) ɾ������[lo,hi)��Ԫ��; remove( Rank r ) ɾ����Ϊr��Ԫ��; erase ( T e ) ɾ��Ԫ��e���������򷵻ظ�����
 * ���ң�find( T e )�����з����ȣ����򷵻�-1
 * �鿴��showall() ��������е�����Ԫ��
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
		if ( size == 0 ) cout << "����Ϊ��" << endl;
		for ( int i = 0; i < size; i++ )
			cout << elem[i] << " ";
		cout << endl;
	}
};

int main(){
	Vector< int > vector; // ����
	for ( int i = 0; i < 5; i++ )
		vector.insert( i + 1, i ); // ����Ϊi������i + 1
	vector.showall(); // ��ʾ����Ԫ��
	int rank = vector.find( 3 ); // ���� 3
	cout << "����Ԫ�� ����Ϊ "  << rank << endl; // ���� 3 ����
	rank = vector.erase( 3 ); // ɾ�� 3
	cout << "��ɾ��Ԫ�ص���Ϊ" << rank << endl; // ���� 3 ����
	vector.showall();
	int e = vector.remove( 2 ); // ɾ����Ϊ2��Ԫ��
	cout << "��ɾ����Ԫ��Ϊ" << e << endl; // ���ظ�Ԫ��
	vector.showall(); // ��ʾ����Ԫ��
	return 0;
}

