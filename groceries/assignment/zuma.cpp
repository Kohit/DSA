/*
 * zuma.cpp
 *
 *  Created on: 2014Äê10ÔÂ16ÈÕ
 *      Author: kohit
 */
/*#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_N = 10002;


/* io plug-in
 * author : ProgramCaiCai
 */
/*
const int SZ = 1<<20;
struct fastio{
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;

struct Node{
	char color;
	Node * pre, * succ;
	Node(){}
	Node( char e, Node * p = NULL, Node * s = NULL ): color( e ), pre( p ), succ( s ){}

};

class List{
private:
	int _size;
	Node * header, * trailer;
public:
	List(){
		_size = 0;
		header = new Node;
		trailer = new Node;
		header->pre = NULL; header->succ = trailer;
		trailer->pre = header; trailer->succ = NULL;
		header->color = 0;
		trailer->color = 0;
	}
	void insertAsLast( char e ){
		Node *p = trailer;
		Node * x = new Node( e, p->pre, p );
		p->pre->succ = x;
		p->pre = x;
		_size++;
	}
	void insertCheckPrint( int r, char e ){
		Node * p = header->succ;
		int i = 0;
		while( p->succ && i++ < r ){
			p = p->succ;
		}
		Node * x = new Node( e, p->pre, p );
		p->pre->succ = x;
		p->pre = x;
		_size++;
		check( x );
	}
	void remove( Node * p ){
		p->pre->succ = p->succ;
		p->succ->pre = p->pre;
		delete p;
		_size--;
		return ;
	}
	int size(){
		return _size;
	}
	void check( Node * x ){
		int lcount = 0, rcount = 0;
		Node * p = x;
		while( ( p = p->pre ) && ( p->color == x->color ) ) lcount++;
		Node * q = x;
		while( ( q = q->succ ) && ( q->color == x->color ) ) rcount++;
		if ( 2 <= lcount + rcount ){
			while( lcount-- ) remove( x->pre );
			while( rcount-- ) remove( x->succ );
			p = x->pre;
			remove( x );
			check( p );
		}
		return ;
	}
	void traverse( char * str ){
		Node * p = header;
		if ( header->succ == trailer ){
			printf( "-\n" );
			return ;
		}
		int i = 0;
		while( (p = p->succ) != trailer ){
			str[i++] = p->color;
		}

		str[i] = '\0';
		printf ( "%s\n", str );
		return ;
	}
};
char str[MAX_N];

/*
 * version 1
 * read the file by manual
 */
/*
char buf[MAX_N * MAX_N];

void analyse( int len, List & list ){
	int i = 0;
	for ( ; i < len; i++ ){
		if ( buf[i] == ' ' || buf[i] == '\n' || buf[i] == '\r')
			break;
		else
			list.insertAsLast( buf[i] ); // read the original part
	}

	i++;i++;
	for ( ; i < len; i++ ){
		if ( buf[i] == ' ' || buf[i] == '\n' || buf[i] == '\r')
			break;
		//n = n * 10 + ( buf[i] - '0' ); // read n
	}

	int r = 0;
	for ( ; i < len; i++  ){ // read r & e
		if ( buf[i] == '\n' || buf[i] == '\r' ) {
			continue;
		}
		else if ( buf[i] == ' ' ) {
			list.insertCheckPrint( r, buf[++i] );
			list.traverse( str );
			r = 0;
		}
		else
			r = r * 10 + ( buf[i] - '0' );
	}
}

void read( List & list ){
	int len = fread( buf, 1, MAX_N * MAX_N, stdin );
	buf[len] = '\0';
	analyse( len, list );
}

int main(){
//	freopen( "data.txt", "rb", stdin );
	List list;
	read( list );
	return 0;
}


/*
 * version 2
 * read a file by fastio
 *
int main(){
	List list;
	gets( str );
	int len = strlen( str );
	for ( int i = 0; i < len; i++ ){
		list.insertAsLast( str[i] );
	}

	int n;
	scanf ( "%d", &n );
	int r; char e;
	for ( int i = 0; i < n; i++ ){
		scanf ( "%d %c", &r, &e );
		list.insertCheckPrint( r, e );
		list.traverse( str );
	}
	return 0;
}
*/
