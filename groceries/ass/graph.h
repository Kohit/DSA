/*
 * graph.h
 *
 *  Created on: 2014Äê11ÔÂ19ÈÕ
 *      Author: kohit
 */


#include "Vector.h"
#include "queue.h"

class Graph{
private:
	int _v, _e;
	Vector<int> * V;
	Vector<int> * E;
	Vector<int> visit;
public:
	Graph(){}
	Graph( int vv, int ee ){
		_v = vv; _e = ee;
		V = new Vector<int>[_v];
		E = new Vector<int>[_v];
		for ( int i = 0; i < _v; i++ )
			visit[i] = 0;
	}
	~Graph(){
		delete [] V;
		delete [] E;
	}
	void reset(){
		for ( int i = 0; i < _v; i++ )
			visit[i] = 0;
	}
	void insert( int v1, int v2 ){
		V[v1].push_back( v2 );
		V[v2].push_back( v1 );
		E[v1][v2] = 1;
		E[v2][v1] = 1;
	}
	void DFSL(){
		reset();
		visit[0] = 1;
		DFSL(0);
		std::cout << std::endl;
	}
	void DFSL( int v ){
		std::cout << v << " ";
		for ( int i = 0; i < V[v].size(); i++ )
			if ( !visit[ V[v][i] ] ){
				visit[ V[v][i] ] = 1;
				DFSL( V[v][i] );
			}
	}
	void DFSM(){
		reset();
		visit[0] = 1;
		DFSM(0);
		std::cout << std::endl;
	}
	void DFSM( int v ){
		std::cout << v << " ";
		for ( int i = 0; i < _v; i++ )
			if ( E[v][i] && !visit[i] ){
				visit[i] = 1;
				DFSM( i );
			}
	}
	void BFSL(){
		reset();
		Queue<int> Q;
		Q.enqueue( 0 );
		visit[0] = 1;
		while( !Q.isempty() ){
			int v = Q.dequeue();
			std::cout << v << " ";
			for ( int i = 0; i < V[v].size(); i++ )
				if ( !visit[ V[v][i] ] ){
					visit[ V[v][i] ] = 1;
					Q.enqueue( V[v][i] );
				}
		}
		std::cout << std::endl;
	}
	void BFSM(){
		reset();
		Queue<int> Q;
		Q.enqueue( 0 );
		visit[0] = 1;
		while( !Q.isempty() ){
			int v = Q.dequeue();
			std::cout << v << " ";
			for ( int i = 0; i < _v; i++ )
				if ( E[v][i] && !visit[i] ){
					visit[i] = 1;
					Q.enqueue( i );
				}
		}
		std::cout << std::endl;
	}

};




