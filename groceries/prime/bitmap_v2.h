/*
 * bitmap_v2.h
 *
 *  Created on: 2014��12��17��
 *      Author: kohit
 */
#include <cstring>
using namespace std;

class Bitmap{
private:
	char * M;
	long long N;
public:
	Bitmap( long long n = 8 ){
		M = new char[ N = ( n + 7 ) / 8 ];
		memset( M, 0, N );
	}
	~Bitmap(){
		delete [] M; M = NULL;
	}
	void set( long long k ){
		M[k >> 3] |= ( 0x80 >> ( k & 0x07 ) );
	}
	void clear( long long k ){
		M[k >> 3] &= ~( 0x80 >> ( k & 0x07 ) );
	}
	bool test( long long k ){
		return M[k >> 3] & ( 0x80 >> ( k & 0x07 ) );
	}
	/*
	void expand( int k ){
		if ( k < 8 * N ) return ;
		int oldN = N;
		char * oldM = M;
		M = new char[ N = ( 2 * k + 7 ) / 8 ];
		memcpy( M, oldM, oldN );
		delete [] oldM;
	}
	*/

};
