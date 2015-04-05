/*
 * couch.cpp
 *
 *  Created on: 2014Äê10ÔÂ27ÈÕ
 *      Author: kohit
 */
/*
#include <iostream>
using namespace std;

const int MAX_N = 510000;

int A[MAX_N], B[MAX_N], C[MAX_N];
int ath[MAX_N];

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for ( int i = 1; i <= n; i++ )
		cin >> A[i];
	for ( int i = 1; i <= n; i++ )
		cin >> B[i];
	for ( int i = 1; i <= n; i++ )
		cin >> C[i];
	int k = 0;
	cin >> k;
	int a = 1, b = 1, c = 1;
	while ( true ){
		if ( ath[k] != 0 ) break;
		while ( a <= n && ath[A[a]] ) a++;
		if ( a <= n ) ath[A[a++]] = 1;
		while ( b <= n && ath[B[b]] ) b++;
		if ( b <= n ) ath[B[b++]] = 2;
		while ( c <= n && ath[C[c]] ) c++;
		if ( c <= n ) ath[C[c++]] = 3;
	}
	char res = ath[k] + 'A' - 1;
	cout << res << endl;
	return 0;
}

*/

