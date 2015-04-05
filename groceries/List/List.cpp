/*
 * List.cpp
 *
 *  Created on: 2014��10��3��
 *      Author: kohit
 *
 * List
 * �ӿڣ�
 * ����List<T>();
 * ����:
 * insert( int rank, T data )����Ϊrank������data��
 * insertAsFirst( T data )��listǰ�����data��
 * insertAsSequence( T data )����Ԫ�أ�ʹ֮��Ϊ��С�������е�����List
 * ɾ����remove( T data )ɾ��ֵ��data��ͬ�ĵ�һ��Ԫ��
 * ���ң�
 * find( T data )����׸�ֵΪdata��Ԫ�ص���
 * indexOf( int rank )�����Ϊrank��Ԫ�ص�ֵ
 * �����clear()���list
 * �鿴��
 * size()����list�Ĵ�С
 * showall()��ʾlist������Ԫ��
 */
#include <iostream>
using namespace std;

template < typename T >
struct Node{
	T data;
	Node * next;
	Node( T _data, Node * _next ){
		this->data = _data; this->next = _next;
	}
	Node(){}
};

template <typename T>
class List{
private:
	Node<T> * header;
	int _size;
public:
	List(){
		_size = 0;
		header = new Node<T>;
		header->next = NULL;
	}
	~List(){
		Node<T> * p = header->next;
		while( p != NULL ){
			Node<T> * _p = p;
			p = p->next;
			delete _p;
		}
	}
	void clear(){
		Node<T> * p = header->next;
		while( p != NULL ){
			Node<T> * _p = p;
			p = p->next;
			delete _p;
		}
		header->next = NULL;
		_size = 0;
	}
	void insertAsFirst( T const & _data ){
		Node<T> * _node = new Node<T>( _data, header->next );
		header->next = _node;
		_size++;
	}
	void insert( int rank, T const & _data ){
		Node<T> * p = header;
		int i = 0;
		while( i < rank && p->next != NULL ){
			p = p->next;
			i++;
		}
		Node<T> * _p = new Node<T>( _data, p->next );
		p->next = _p;
		_size++;
	}
	void insertAsSequence( T const & _data ){
		Node<T> * p = header;
		while( p->next != NULL && p->next->data < _data ){
			p = p->next;
		}
		Node<T> * _p = new Node<T>( _data, p->next );
		p->next = _p;
		_size++;
	}
	T indexOf( int rank ){
		Node<T> * p = header;
		int i = 0;
		while( i < rank && p->next != NULL ){
			p = p->next;
			i++;
		}
		return p->next->data;
	}
	int find( T const & _data ){
		Node<T> * p = header->next;
		int rank = 0;
		while( p != NULL ){
			if ( _data == p->data ) return rank;
			p = p->next;
			rank++;
		}
		return -1;
	}
	int size(){
		return _size;
	}
	void remove( T const & _data ){
		Node<T> * p = header;
		while( p->next != NULL ){
			if ( p->next->data == _data ){
				Node<T> * target = p->next;
				p->next = target->next;
				delete target;
				_size--;
				return;
			}
			p = p->next;
		}
	}
	void showall(){
		Node<T> * p = header->next;
		while( p != NULL ){
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
};

int main(){
	List<int> list; // ����int���͵�List
	for ( int i = 0; i < 10; i++ )
		list.insertAsFirst( i ); //��listǰ����
	list.showall(); // ��ʾ����Ԫ��
	list.insert( 0, 11 ); // ����Ϊ0������11
	cout << "����Ϊ0������ 11 ��" << endl;
	list.showall();
	int rank = list.find( 7 ); // ����7����
	cout << "7 ����Ϊ " << rank << endl;
	int data = list.indexOf( 7 ); // ������Ϊ7��Ԫ��
	cout << "��Ϊ7��Ԫ��Ϊ  " << data << endl;
	list.remove( 11 ); // ɾ��11
	cout << "ɾ�� 11 �� " << endl;
	list.showall();
	list.clear(); //���
	list.insertAsSequence(0);
	list.insertAsSequence( 1 ); // ����Ԫ�أ�ʹ֮��Ϊ��������Ԫ�ذ��մӡ�С������������
	list.insertAsSequence( 3 );
	list.insertAsSequence( 2 );
	cout << "����insertAsSequence���� 0 1 3 2 ��" << endl;
	list.showall();
}

