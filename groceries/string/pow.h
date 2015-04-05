/*
 * pow.h
 *
 *  Created on: 2014Äê12ÔÂ30ÈÕ
 *      Author: kohit
 */

long long pow( long long x, int n ){  // x ^ n
	long long res = 1;
	while( n ){
		if ( n & 1 ) res = res * x;
		x *= x;
		n >>= 1;
	}
	return res;
}
