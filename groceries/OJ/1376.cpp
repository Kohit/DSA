/*
 * 1376.cpp
 *
 *  Created on: 2014Äê4ÔÂ1ÈÕ
 *      Author: KoHit
 */
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#define MAXN 53
using namespace std;

struct point{
	int x, y;
	int step;
};

queue<point> Q;
int M, N;
char maze[MAXN][MAXN];
int dir[5][3] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int EX, EY;

int BFS(point s){
	Q.push(s);
	point head;
	maze[s.x][s.y] = '#';
	while ( !Q.empty() ){
		head = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++){
			int x = head.x + dir[i][0];
			int y = head.y + dir[i][1];
			if (x >= 0 && x <= M - 1 && y >= 0 && y <= N - 1 && maze[x][y] != '#'){
				point tmp;
				tmp.x = x; tmp.y = y; tmp.step = head.step + 1;
				Q.push(tmp);
				maze[x][y] = '#';
			}
			if (x == EX && y == EY){
				return head.step + 1;
			}
		}
	}
	return -1;
}

int main(){
	scanf ("%d%d", &M, &N)£»
	memset(maze, 0, sizeof(maze));
	point start;
	scanf ("%d%d%d%d", &start.x, &start.y, &EX, &EY);
	for (int i = 0; i < M; i++)
		scanf("%s", maze[i]);
	start.step = 0;
	if ( start.x == EX && start.y == EY)
		printf("0\n");
	else{
		int count = BFS( start );
		printf ("%d\n", count);
	}
	return 0;
}
