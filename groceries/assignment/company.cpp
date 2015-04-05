/*
 * company.cpp
 *
 *  Created on: 2014年10月27日
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAX_N = 10000007;
int emp[MAX_N];

// 读大数据用，借鉴ProgramCaiCai的思路
struct read{
    char in[ MAX_N >> 1 ];
    char out[ MAX_N >> 1 ];
    read(){
        setvbuf( stdin, in, _IOFBF, MAX_N >> 1 );
        setvbuf( stdout, out, _IOFBF, MAX_N >> 1 );
    }
}io;

class Bitmap{ // 参考习题[2-34]
private:
	int size, top; // 栈指针
	int * S, * F;
protected:
	bool valid( int r ) { return ( 0 <= r ) && ( r < top ); } // 检验秩是否合法
	bool erased( int k ){ return valid( F[k] ) && !( S[ F[ k ] ] + 1 + k ); } // 检验秩与值是否合法，约定此时值为-k-1
public:
	Bitmap( int _size ){
		size = _size; top = 0;
		S = new int[ size ]; // 值
		F = new int[ size ]; // 秩
	}
	~Bitmap(){
		delete [] S; delete [] F;
	}
	void renew(){
		top = 0; // 将栈指针置为0，表示栈空（初始化所有元素）
	}
	void set( int k ){
		if ( test( k ) ) return ; // 避免重复
		if ( !erased( k ) ) F[k] = top++; // 删除过后重置秩
		S[ F[k] ] = k; // "存储" k
	}
	void remove( int k ){
		if ( test( k ) ) // 避免重复
			S[ F[ k ] ] = -k - 1; // 约定删除过的值为-k-1
	}
	bool test( int k ){
		return valid( F[k] ) && ( k == S[ F[k] ] ); // 当秩与值同时满足表示元素在bitmap中
	}
};

int main(){
	int res = 0;
	int n, m;
	scanf ( "%d%d", &n, &m );
	Bitmap bitmap( n );
	char state;
	int ema = 1, code = 0, busy = 0;
	for ( int j = 0; j < m; j++ ){
		scanf ( " %c", &state );
		switch ( state ){
		case 'I':
			scanf ( "%d%d", &ema, &code );
			if ( !bitmap.test( ema ) ) { // ema下班或未上班，工作人数增加
				busy++;
				bitmap.set( ema );
			}
			emp[ema] = code;
			break;
		case 'O':
			scanf ( "%d", &ema );
			if ( bitmap.test( ema ) ) {
				busy--;
				bitmap.remove( ema );
			}
			break;
		case 'C':
			bitmap.renew(); busy = 0; break; // 初始化O(1)
		case 'N':
			res += busy; break;
		case 'Q':
			scanf ( "%d", &ema );
			if ( bitmap.test( ema ) )
				res += emp[ema];
			else
				res+= -1;
			break;
		default: break;
		}
	}
	printf ( "%d\n", res );
	return 0;
}
*/
