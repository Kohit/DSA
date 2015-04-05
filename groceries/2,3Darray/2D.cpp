#include <iostream>
using namespace std;

class Array2{
 int row, col;     // �С���
 int s;            // ����Ԫ�ظ���
 int *ptr;         // ��̬��������
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
 /* ���ء�=�� */
 Array2 & operator = (const Array2 & tmp){
  if(ptr == tmp.ptr)           // ��ֹ����a = a��ɵĴ���
   return *this;
  if(tmp.ptr == NULL){         // ���ǶԷ�����Ϊ�յ����
   if(ptr) delete [] ptr;
   ptr = NULL;
   row = 0, col = 0, s = 0;
   return *this;
  }
  if(s < tmp.s){               // �����ǰ�������������������
   if(ptr)
    delete [] ptr;
   ptr = new int[tmp.s];
  }
  memcpy(ptr, tmp.ptr,sizeof(int)*tmp.s);  // ����
  row = tmp.row, col = tmp.col, s = tmp.s;
  return *this;
 }
 /* ���ء�[]�� */
 int * const operator[](int i){   // ���ض�ά�����i����ʼ��ַ�������ַ���ɱ䣨const��
  return &ptr[i * col];
 }
 /* ���ء�()�� */
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
