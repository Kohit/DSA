/*
 * company.cpp
 *
 *  Created on: 2014��10��27��
 *      Author: kohit
 */
/*
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAX_N = 10000007;
int emp[MAX_N];

// ���������ã����ProgramCaiCai��˼·
struct read{
    char in[ MAX_N >> 1 ];
    char out[ MAX_N >> 1 ];
    read(){
        setvbuf( stdin, in, _IOFBF, MAX_N >> 1 );
        setvbuf( stdout, out, _IOFBF, MAX_N >> 1 );
    }
}io;

class Bitmap{ // �ο�ϰ��[2-34]
private:
	int size, top; // ջָ��
	int * S, * F;
protected:
	bool valid( int r ) { return ( 0 <= r ) && ( r < top ); } // �������Ƿ�Ϸ�
	bool erased( int k ){ return valid( F[k] ) && !( S[ F[ k ] ] + 1 + k ); } // ��������ֵ�Ƿ�Ϸ���Լ����ʱֵΪ-k-1
public:
	Bitmap( int _size ){
		size = _size; top = 0;
		S = new int[ size ]; // ֵ
		F = new int[ size ]; // ��
	}
	~Bitmap(){
		delete [] S; delete [] F;
	}
	void renew(){
		top = 0; // ��ջָ����Ϊ0����ʾջ�գ���ʼ������Ԫ�أ�
	}
	void set( int k ){
		if ( test( k ) ) return ; // �����ظ�
		if ( !erased( k ) ) F[k] = top++; // ɾ������������
		S[ F[k] ] = k; // "�洢" k
	}
	void remove( int k ){
		if ( test( k ) ) // �����ظ�
			S[ F[ k ] ] = -k - 1; // Լ��ɾ������ֵΪ-k-1
	}
	bool test( int k ){
		return valid( F[k] ) && ( k == S[ F[k] ] ); // ������ֵͬʱ�����ʾԪ����bitmap��
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
			if ( !bitmap.test( ema ) ) { // ema�°��δ�ϰ࣬������������
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
			bitmap.renew(); busy = 0; break; // ��ʼ��O(1)
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
