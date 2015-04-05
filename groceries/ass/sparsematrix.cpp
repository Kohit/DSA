/*
 * sparsematrix.cpp
 *
 *  Created on: 2014Äê10ÔÂ28ÈÕ
 *      Author: kohit
 */

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 7007;
struct point{
	int r, c, val;
	bool plus;
	point(){}
	point( int rr, int cc, int vv ){
		r = rr; c = cc; val = vv;plus = false;
	}
	bool operator<( const point & b ) const {
		if ( r == b.r ) return c < b.c;
		return r < b.r;
	}
};


int main(){
//	std::ios::sync_with_stdio( false );
	vector< point > A, B;
	int ra, ca, rb, cb;
	int na, nb, nc;
	scanf ( "%d%d%d", &ra, &ca, &na );
	//cin >> ra >> ca >> na;
	for ( int i = 0; i < na; i++ ){
		int r, c, e;
		scanf ( "%d%d%d", &r, &c, &e );
		//cin >> r >> c >> e;
		A.push_back( point( r, c, e ) );
	}
	scanf ( "%d%d%d", &rb, &cb, &nb );
	//cin >> rb >> cb >> nb;
	for ( int i = 0; i < nb; i++ ){
		int r, c, e;
		scanf ( "%d%d%d", &r, &c, &e );
		//cin >> r >> c >> e;
		B.push_back( point( r, c, e ) );
	}
	vector< point >::iterator iterA, iterB;
	for ( iterA = A.begin(); iterA != A.end(); iterA++ ){
		for ( iterB = B.begin(); iterB != B.end(); iterB++ ){
			if ( iterA->r == iterB->r && iterA->c == iterB->c ){
				iterA->val += iterB->val;
				if ( iterA->val == 0 ) {
					na--;
					//A.erase( iterA );
				}
				iterB->plus = true;
				break;
			}
		}
	}
	nc = na;
	int sb = B.size();
	for ( int i = 0; i < sb; i++ ){
		point b = B[i];
		if ( !b.plus ){
			A.push_back( b );
			nc++;
		}
	}
	sort( A.begin(), A.end() );
	printf ( "%d %d %d\n", ra, ca, nc );
	//cout << ra << " " << ca << " " << nc << endl;
	int sa = A.size();
	for ( int i = 0; i < sa; i++ )
		if ( A[i].val != 0 )
			printf ( "%d %d %d\n", A[i].r, A[i].c, A[i].val );
			//cout << A[i].r << " " << A[i].c << " " << A[i].val << endl;

	return 0;
}
*/
