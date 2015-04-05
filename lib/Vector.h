/*
* Vector.h
*
*  Created on: 2014年10月8日
*      Author: kohit
*/

#define DEFAULT_CAPACITY 100

typedef int Rank;
template < typename T >
class Vector{
protected:
	Rank _size;
	int capacity;
	T* elem;
public:
	Vector(int _capacity){
		capacity = _capacity;
		_size = 0;
		elem = new T[capacity];
	}
	Vector(){
		capacity = DEFAULT_CAPACITY;
		_size = 0;
		elem = new T[capacity];
	}
	~Vector(){
		delete[] elem;
	}
	void expand(){
		if (size < capacity) return;
		capacity *= 2;
		T * e = new T[capacity];
		for (int i = 0; i < _size; i++){
			e[i] = elem[i];
		}
		delete[] elem;
		elem = e;
	}
	void insert(T const & data, Rank index){
		expand();
		if (index < 0 || size == 0)
			index = 0;
		for (int i = size; i > index; i--)
			elem[i] = elem[i - 1];
		elem[index] = data;
		size++;
	}
	void push_back(T const & data){
		if (_size >= capacity){
			expand();
		}
		elem[_size++] = data;
	}
	T & operator[] (Rank r){
		return elem[r];
	}
	int size(){
		return _size;
	}
	void remove(Rank lo, Rank hi){   // [ , )
		if (lo < 0 || lo >= hi || hi > _size) return;
		while (hi < _size){
			elem[lo++] = elem[hi++];
		}
		_size = lo;
		return;
	}
	T remove(Rank r){
		T e = elem[r];
		remove(r, r + 1);
		return e;
	}
	void mergeSort(){
		mergeSort(0, _size);
	}
	void mergeSort(int lo, int hi){
		if (hi - lo < 2) return;
		int mid = (lo + hi) >> 1;
		mergeSort(lo, mid);
		mergeSort(mid, hi);
		merge(lo, mid, hi);
	}
	void merge(int lo, int mid, int hi){
		int lb = mid - lo;
		int rb = hi - mid;
		T * A = elem + lo;
		T * B = new T[lb];
		T * C = elem + mid;
		for (int i = 0; i < lb; i++) B[i] = A[i];
		for (int i = 0, j = 0, k = 0; j < lb || k < rb;){
			if (j < lb && (k >= rb || B[j] < C[k] || B[j] == C[k])) A[i++] = B[j++];
			if (k < rb && (j >= lb || C[k] < B[j])) A[i++] = C[k++];
		}
		delete[] B;
	}

	template< typename C >
	void mergeSort(C & c){
		mergeSort(0, _size, c);
	}
	template< typename C >
	void mergeSort(int lo, int hi, C & c){
		if (hi - lo < 2) return;
		int mid = (lo + hi) >> 1;
		mergeSort(lo, mid, c);
		mergeSort(mid, hi, c);
		merge(lo, mid, hi, c);
	}
	template< typename D >
	void merge(int lo, int mid, int hi, D & c){
		int lb = mid - lo;
		int rb = hi - mid;
		T * A = elem + lo;
		T * B = new T[lb];
		T * C = elem + mid;
		for (int i = 0; i < lb; i++) B[i] = A[i];
		for (int i = 0, j = 0, k = 0; j < lb || k < rb;){
			if (j < lb && (k >= rb || c(B[j], C[k]) || B[j] == C[k])) A[i++] = B[j++];
			if (k < rb && (j >= lb || c(C[k], B[j]))) A[i++] = C[k++];
		}
		delete[] B;
	}
};
