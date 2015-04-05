/*
 * 1308.cpp
 *
 *  Created on: 2014Äê4ÔÂ2ÈÕ
 *      Author: KoHit
 */
#include<cstdio>
#include<cstring>
#include<iostream>
#include<stack>
#define MAXN 53
using namespace std;

struct point{
	int x, y;
	int step;
};

int M, N;
char maze[MAXN][MAXN];
int dir[5][3] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int BFS ( point s, int EX, int EY ) {
	stack<point> S;
	S.push ( s );
	point head;
	maze[s.x][s.y] = '#';
	while ( !S.empty() ) {
		head = S.top();
		S.pop();
		for ( int i = 0; i < 4; i++ ){
			int x = head.x + dir[i][0];
			int y = head.y + dir[i][1];
			if ( x >= 0 && x <= M - 1 && y >= 0 && y <= N - 1 && maze[x][y] != '#' ) {
				point tmp;
				tmp.x = x; tmp.y = y;
				S.push(tmp);
				maze[x][y] = '#';
			}
			if ( x == EX && y == EY ){
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	while ( scanf ( "%d%d", &M, &N ) != EOF ) {
		if ( M == 0 && N == 0 )
			return 0;
		point start;
		int ex, ey;
		scanf ( "%d%d%d%d", &start.x, &start.y, &ex, &ey );
		memset ( maze, 0, sizeof(maze) );
		for ( int i = 0; i < M; i++ )
			scanf ( "%s", maze[i] );
		if ( start.x == ex && start.y == ey )
			printf ( "YES\n" );
		else if ( BFS(start, ex, ey) )
			printf ( "YES\n" );
		else
			printf ( "NO\n" );
	}
	return 0;
}
