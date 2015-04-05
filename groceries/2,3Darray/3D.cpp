/*
 * 3D.cpp
 *
 *  Created on: 2014年4月11日
 *      Author: KoHit
 */
#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class CArray3D{
	private:
	    T *** num;
	    int height, width, deep;
	public:
	    CArray3D(int h, int w, int d):height(h),width(w),deep(d) {
	    	    if((h == 0) || (w == 0) || (d == 0)) {
	    	        num = NULL;
	    	        return;
	    	    }

	    	    num = new T **[h];
	    	    for (int i=0;i<h;++i) {
	    	        num[i] = new T *[w];
	    	        for (int j = 0; j < w; j++) {
	    	        	num[i][j] = new T[d];
	    	        }
	    	    }
	    }
	    CArray3D(CArray3D & a) {
	    	    if((a.height == 0) || (a.width == 0) || (a.deep == 0)) {
	    	        num = NULL;
	    	        height = 0;
	    	        width = 0;
	    	        deep = 0;
	    	        return;
	    	    }

	    	    num = new T **[a.height];
	    	    for (int i=0;i<a.height;++i) {
	    	        num[i] = new T *[a.width];
	    	        for ( int j = 0; j < a.width; j++ ) {
	    	        	num[i][j] = new T[a.deep];
	    	        	memcpy( num[i][j], a[i][j], sizeof(T) * a.deep);
	    	        }
	    	    }
	    	    width = a.width;
	    	    height = a.height;
	    	    deep = a.deep;
	    	    //cout<<"Copy constructor called!"<<endl;
	    	}
	    ~CArray3D() {
	    	    if((height != 0) && (width != 0) && (deep != 0)) {
	    	        for(int i=0;i<height;++i) {
	    	            delete [] num[i];
	    	        }
	    	        delete [] num;
	    	    }
	    	    //cout<<"Destructor called!"<<endl;
	    	}
	    // for equating two Array2 objects
	    CArray3D & operator=( const CArray3D & a) {
	    	    if( num == a.num) // 防止a=a
	    	        return * this;

	    	    if((a.height == 0) || (a.width == 0) || (a.deep == 0)) { //如果a里面是空的
	    	        if((height != 0) && (width != 0) && (deep != 0)) {
	    	            for(int i=0;i<height;++i) {
	    	                delete [] num[i];
	    	                num[i] = NULL;
	    	            }
	    	            delete [] num;
	    	        }
	    	        num = NULL;
	    	        height = 0;
	    	        width = 0;
	    	        deep = 0;
	    	        return * this;
	    	    }

	    	    //如果原有空間大，就不用分配新
	    	    bool cond1 = height < a.height;
	    	    bool cond2 = width < a.width;
	    	    if(cond2 && !cond1) {
	    	        if((height != 0) && (width != 0) && (deep != 0)) {
	    	            for(int i=0;i<height;++i) {
	    	                delete [] num[i];
	    	            }
	    	        }
	    	        for(int i=0;i<a.height;++i) {
	    	            num[i] = new T *[a.width];
	    	        }
	    	    }
	    	    if(cond1) {
	    	        if((height != 0) && (width != 0)) {
	    	            for(int i=0;i<height;++i) {
	    	                delete [] num[i];
	    	            }
	    	            delete [] num;
	    	        }
	    	        num = new T **[a.height];
	    	        for(int i=0;i<a.height;++i) {
	    	            num[i] = new T *[a.width];
	    	            for (int j = 0; j < a.width; j++) {
	    	            	num[i][j] = new T [a.deep];
	    	            }
	    	        }
	    	    }
	    	    for(int i=0;i<a.height;++i) {
	    	        memcpy( num[i],a.num[i],sizeof(T)*a.width);
	    	    }
	    	    height = a.height;
	    	    width = a.width;
	    	    deep = a.deep;
	    	    return * this;
	   	} // Array2 & Array2::operator=( const Array2 & a)
	    int getWidth() { return width; } // return the width of the 2D array
	    int getHeight() { return height; } // return the height of the 2D array
	    T ** operator[](int i) { return num[i]; } // return a pointer pointing towards the i-th row of the 2D array
	    int operator()(int i, int j, int k) { return num[i][j][k]; } // for reading the i-th, j-th, k-th element of num stored in Array2 a written in this form a(i,j)

};

int main()

{

               CArray3D<int> a(3,4,5);

               int No = 0;

               for( int i = 0; i < 3; ++ i )

                               for( int j = 0; j < 4; ++j )

                                              for( int k = 0; k < 5; ++k )

                                                             a[i][j][k] = No++;

               for( int i = 0; i < 3; ++ i )

                               for( int j = 0; j < 4; ++j )

                                              for( int k = 0; k < 5; ++k )

                                                             cout << a[i][j][k] << ",";

               return 0;

}




