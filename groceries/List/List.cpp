/*
 * List.cpp
 *
 *  Created on: 2014年10月3日
 *      Author: kohit
 *
 * List
 * 接口：
 * 构造List<T>();
 * 插入:
 * insert( int rank, T data )在秩为rank处插入data；
 * insertAsFirst( T data )在list前面插入data；
 * insertAsSequence( T data )插入元素，使之成为从小到大排列的有序List
 * 删除：remove( T data )删除值与data相同的第一个元素
 * 查找：
 * find( T data )输出首个值为data的元素的秩
 * indexOf( int rank )输出秩为rank的元素的值
 * 清除：clear()清空list
 * 查看：
 * size()返回list的大小
 * showall()显示list的所有元素
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
	List<int> list; // 构造int类型的List
	for ( int i = 0; i < 10; i++ )
		list.insertAsFirst( i ); //在list前插入
	list.showall(); // 显示所有元素
	list.insert( 0, 11 ); // 在秩为0处插入11
	cout << "在秩为0处插入 11 后" << endl;
	list.showall();
	int rank = list.find( 7 ); // 查找7的秩
	cout << "7 的秩为 " << rank << endl;
	int data = list.indexOf( 7 ); // 查找秩为7的元素
	cout << "秩为7的元素为  " << data << endl;
	list.remove( 11 ); // 删除11
	cout << "删除 11 后 " << endl;
	list.showall();
	list.clear(); //清除
	list.insertAsSequence(0);
	list.insertAsSequence( 1 ); // 插入元素，使之成为有序链表，元素按照从“小”到“大”排列
	list.insertAsSequence( 3 );
	list.insertAsSequence( 2 );
	cout << "利用insertAsSequence插入 0 1 3 2 后" << endl;
	list.showall();
}

