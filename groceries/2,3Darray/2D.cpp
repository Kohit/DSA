#include <iostream>
using namespace std;

class Array2{
 int row, col;     // 行、列
 int s;            // 数组元素个数
 int *ptr;         // 动态创建数组
public:
 Array2(int i = 0, int j = 0): row(i), col(j) {
  s = i * j;
  if (s == 0)
   ptr = NULL;
  else
   ptr = new int[row * col];
 }
 ~Array2(){
  if(ptr) delete []ptr;
 }
 /* 重载“=” */
 Array2 & operator = (const Array2 & tmp){
  if(ptr == tmp.ptr)           // 防止出现a = a造成的错误
   return *this;
  if(tmp.ptr == NULL){         // 考虑对方数组为空的情况
   if(ptr) delete [] ptr;
   ptr = NULL;
   row = 0, col = 0, s = 0;
   return *this;
  }
  if(s < tmp.s){               // 如果当前容量不够，创建更大的
   if(ptr)
    delete [] ptr;
   ptr = new int[tmp.s];
  }
  memcpy(ptr, tmp.ptr,sizeof(int)*tmp.s);  // 复制
  row = tmp.row, col = tmp.col, s = tmp.s;
  return *this;
 }
 /* 重载“[]” */
 int * const operator[](int i){   // 返回二维数组第i行起始地址，数组地址不可变（const）
  return &ptr[i * col];
 }
 /* 重载“()” */
 int operator()(int i, int j){
  return ptr[i * col + j];
 }
};

int main() {
	Array2 a(3,4);
	int i,j;
	for(  i = 0;i < 3; ++i )
		for(  j = 0; j < 4; j ++ )
			a[i][j] = i * 4 + j;
	for(  i = 0;i < 3; ++i ) {
		for(  j = 0; j < 4; j ++ ) {
			cout << a(i,j) << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b; 	b = a;
	for(  i = 0;i < 3; ++i ) {
		for(  j = 0; j < 4; j ++ ) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}
