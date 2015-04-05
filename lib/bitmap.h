/*
 * bitmap.h
 *
 *  Created on: 2014年11月9日
 *      Author: kohit
 */

class Bitmap{
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
