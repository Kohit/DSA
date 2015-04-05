/*
 * toy.cpp
 *
 *  Created on: 2014年12月28日
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include "queue_v.h"
using namespace std;

const int maxn = 1 << 20;
struct fastio{
	char inbuf[maxn], outbuf[maxn];
	fastio(){
		setvbuf( stdin, inbuf, _IOFBF, maxn );
		setvbuf( stdout, outbuf, _IOFBF, maxn );
	}
}io;

struct toy{
	char state[9];
	int step;
	int time;         // 用来区分不同次访问
	toy(){
		step = 0;
		time = 0;
	}
	toy( char * s, int ss = 0, int tt = 0 ){
		strcpy( state, s );
		step = ss;
		time = tt;
	}
};

const int M = 80039;
toy ht[80040];

char init[] = "12345678";

int hash( char s[] ){
	int h = 0;
	for ( int n = strlen(s), i = 0; i < n; i++ ){
		h = ( h * 37 + s[i] ) % M;
	}
	return h;
}

int prob( char s[] ){
	int r = hash( s );
	int h = r;
	int p = 1;
	bool neg = false;
	int i = 0;
	while( strlen(ht[r].state) && ( strcmp( ht[r].state, s ) != 0 ) ){
		if ( neg ){
			r = ( h - p * p ) % M;
			if ( r < 0 ) r = - r;     // in case the r might be negative
			neg = false;
		}
		else{
			r = ( h + p * p ) % M;
			neg = true;
		}
		i++;
		if ( i % 2 == 0 ) p++;
	}
	return r;
}

// 记录从目标状态到起始状态，因此过程需要 取反
void convert( int state, char * from, char * to ){
	if ( state == 0 ){
		for ( int i = 0; i < 8; i++ )
			to[i] = from[7 - i];
		to[8] = '\0';
		return ;
	}
	if ( state == 1 ){
		to[3] = from[0];
		for ( int i = 1; i < 4; i++ )
			to[i - 1] = from[i];
		for ( int i = 4; i < 7; i++ )
			to[i + 1] = from[i];
		to[4] = from[7];
		to[8] = '\0';
		return ;
	}
	if ( state == 2 ){
		to[0] = from[0]; to[3] = from[3]; to[4] = from[4]; to[7] = from[7];
		to[6] = from[1]; to[1] = from[2]; to[2] = from[5]; to[5] = from[6];
		to[8] = '\0';
		return ;
	}
}

// time是用来区分不同组数据的标记
int visit( char * state, int step, int time ){
	int r = prob( state );
	if ( strlen(ht[r].state) == 0 ){
		strcpy( ht[r].state, state );
		ht[r].step = step;
		ht[r].time = time;
		return -1;
	}
	if ( ht[r].time != time ){ // 以前访问过，但这次还没访问
		ht[r].time = time;
		return -1;
	}
	return r;
}

Queue<toy> Q(41000);

int BFS( char * st, int time ){
	Q.reset();
	Q.enqueue( toy( init ) );
	visit( init, 0, time );
	while( !Q.isempty() ){
		toy p = Q.dequeue();
		if ( strcmp( p.state, st ) == 0 )
			return p.step;
		for ( int i = 0; i < 3; i++ ){
			char q[9];
			convert( i, p.state, q );
			if ( strcmp( q, st ) == 0 )
				return p.step + 1;
			int r = visit(q, p.step + 1, time);
			if ( r == -1 )                        // 这次还没访问过
				Q.enqueue( toy( q, p.step + 1 ) );
		}
	}
	return -1;
}


int main(){
	int n;
	scanf ( "%d", &n );
	for ( int i = 0; i < n; i++ ){
		char s[9];
		for ( int j = 0; j < 8; j++ )
			scanf ( " %c", &s[j] );
		s[8] = '\0';
		int r = prob( s );
		if ( strcmp( ht[r].state, s ) == 0 ) // 以前访问过，直接输出
			printf ( "%d\n", ht[r].step );
		else{
			int res = BFS( s, i );
			printf ( "%d\n", res );
		}
	}
	return 0;
}
*/

