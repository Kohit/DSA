/*
 * 25050.cpp
 *
 *  Created on: 2014年7月24日
 *      Author: Administrator
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int MAXN = 100001;
struct Task{
	int x, y;
	bool operator<( Task b ) const {
		if ( x == b.x )
			return y < b.y;
		return x < b.x;
	}
	Task( int xx, int yy ): x(xx), y(yy){}
	Task(){}
};
Task my[MAXN], query[MAXN];

bool Greater( Task a, Task b ){
	if ( a.x == b.x )
		return a.y > b.y;
	return a.x > b.x;
}
int main(){
	int n, m;
	while( scanf ( "%d%d", &n, &m ) != EOF ){
		for ( int i = 0; i < n; i++ )
			scanf ( "%d%d", &my[i].x, &my[i].y );
		for ( int i = 0; i < m; i++ )
			scanf ( "%d%d", &query[i].x, &query[i].y );
		sort ( my, my + n, Greater );
		sort ( query, query + m, Greater );
		multiset<Task> Set;  // 按升序排列
		int award = 0;
		long long sum = 0;
		multiset<Task>::iterator iter;
		for ( int i = 0, j = 0; i < m && j < n; i++ ){
			while( j < n && my[j].x >= query[i].x ) {Set.insert( my[j] ); j++;}
			iter = Set.lower_bound( query[i] );
			if ( iter != Set.end() ){
				award++;
				sum += 500 * query[i].x + 2 * query[i].y;
				Set.erase( iter );
			}
		}
		printf ( "%d %lld\n", award, sum );
	}
	return 0;
}



