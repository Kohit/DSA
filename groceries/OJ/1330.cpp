/*
 * 1330.cpp
 *
 *  Created on: 2014Äê3ÔÂ28ÈÕ
 *      Author: KoHit
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAX 315
using namespace std;

int Edg[MAX][MAX];

struct result{
	int list;
	int weight;
};

int cmp(const void *a, const void *b){
	result * p = (result *)a;
	result * q = (result *)b;
	return ((int *)(p->list) - (int *)(q->list));
}


struct ArcNode{
	int adjvex;
	int weight;
	ArcNode *nextarc;
};

struct VNode{
	int Indegree;
	int Outdegree;
	ArcNode *headIn;
	ArcNode *headOut;
};

struct LGraph{
	VNode vertexs[MAX];
	int vexnum, arcnum;
};
LGraph lg;

void CreateLG(){
	memset(Edg, 0, sizeof(Edg));
	for ( int i = 0; i < lg.vexnum; i++ ){
		lg.vertexs[i].headIn = lg.vertexs[i].headOut = NULL;
		lg.vertexs[i].Indegree = lg.vertexs[i].Outdegree = 0;
	}
	ArcNode *p;
	int v1, v2, weight;
	for ( int i = 0; i < lg.arcnum; i++ ){
		scanf( "%d%d%d", &v1, &v2, &weight );
		Edg[v1][v2] = 1;
		lg.vertexs[v1].Outdegree++;
		lg.vertexs[v2].Indegree++;
		p = new ArcNode;
		p->adjvex = v2;
		p->weight = weight;
		p->nextarc = lg.vertexs[v1].headOut;
		lg.vertexs[v1].headOut = p;
		p = new ArcNode;
		p->adjvex = v1;
		p->weight = weight;
		p->nextarc = lg.vertexs[v2].headIn;
		lg.vertexs[v2].headIn = p;
	}
}

void DeleteLG(){
	ArcNode *p;
	for (int i = 0; i < lg.vexnum; i++){
		p = lg.vertexs[i].headIn;
		while(p != NULL){
			lg.vertexs[i].headIn = p->nextarc;
			delete p;
			p = lg.vertexs[i].headIn;
		}
		p = lg.vertexs[i].headOut;
		while(p != NULL){
			lg.vertexs[i].headOut = p->nextarc;
			delete p;
			p = lg.vertexs[i].headOut;
		}
	}
}

void printMatrix(){
	for ( int i = 0; i < lg.vexnum; i++ ){
		for ( int j = 0; j < lg.vexnum; j++ ){
			if(j == 0)
				printf ("%d", Edg[i][j]);
			else
				printf (" %d", Edg[i][j]);
		}
		printf ("\n");
	}
}

int main(){
	ArcNode *p;
	scanf( "%d%d", &lg.vexnum, &lg.arcnum );
	CreateLG();
	printMatrix();
	printf ("\n");
	result Outlist[MAX];
	result Inlist[MAX];
	for (int i = 0; i < lg.vexnum; i++){
		Outlist[i].list = Outlist[i].weight = 0;
		Inlist[i].list = Inlist[i].weight = 0;
	}
	for ( int i = 0; i < lg.vexnum; i++ ){
		int j = 0;
		p = new ArcNode;
		p = lg.vertexs[i].headOut;
		while ( p != NULL ){
			Outlist[j].list = p->adjvex;
			Outlist[j].weight = p->weight;
			p = p->nextarc;
			j++;
		}
		qsort(Outlist, j, sizeof(int), cmp);
		printf ("%d %d %d", i, Outlist[0].list, Outlist[0].weight);
		for ( int k = 1; k < j; k++ )
			printf (" %d %d", Outlist[k].list, Outlist[k].weight);
		printf ("\n");
		delete p;
	}
	for ( int i = 0; i < lg.vexnum; i++ ){
		int j = 0;
		p = new ArcNode;
		p = lg.vertexs[i].headIn;
		while ( p != NULL ){
			Inlist[j].list = p->adjvex;
			Inlist[j].weight = p->weight;
			p = p->nextarc;
			j++;
		}
		qsort(Inlist, j, sizeof(int), cmp);
		printf ("%d %d %d", i, Inlist[0].list, Inlist[0].weight);
		for ( int k = 1; k < j; k++ )
			printf (" %d %d", Inlist[k].list, Inlist[k].weight);
		printf ("\n");
		delete p;
	}
	DeleteLG();
	return 0;
}
