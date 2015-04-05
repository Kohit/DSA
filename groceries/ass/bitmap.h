/*
 * bitmap.h
 *
 *  Created on: 2014��11��9��
 *      Author: kohit
 */

class Bitmap{
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
