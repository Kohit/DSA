/*
* Arithmetic.cpp
*
*  Created on: 2014年3月19日
*   revise on: 2014年3月26日
*      Author: KoHit
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define MAX 1000
using namespace std;

bool isFuShu = 0;

class BigN{
public:
	int Number[MAX];
	int len;

	BigN(){
		memset(Number, 0, sizeof(Number));
		len = 1;
	}
	BigN(int num){
		*this = num;
	}
	BigN(const char * s){
		int tmp = strlen(s);
		for (int i = 0; i < tmp; i++){
			Number[i] = (char)(s[i] - '0');
			len++;
		}
	}
	BigN(BigN &goal, int begin, int end)
	{
		memcpy(Number, goal.Number + begin, sizeof(int)* (end - begin + 1));
		len = end - begin + 1;
	}

	string str() const{
		string res = "";
		for (int i = 0; i < len; i++)
			res = (char)(Number[i] + '0') + res;
		if (res == "") res = "0";
		return res;
	}

	void clean() {
		while (len > 1 && !Number[len - 1]) len--;
	}

	friend bool operator==( const BigN & a, const BigN & b){
			if (a.len != b.len)
			return false;
			int i = 0;
			while (a.Number[i] == b.Number[i] && i < a.len && i < b.len)
				i++;
			if (i == a.len && i == b.len)
				return true;
			else
				return false;

	}

	friend bool operator>(const BigN & a, const BigN & b){
		if (a.len > b.len)
			return true;
		else if (a.len == b.len) {
			int index = a.len - 1;
			while (a.Number[index] == b.Number[index] && index > 0)
				index--;
			if (a.Number[index] > b.Number[index])
				return true;
			else
				return false;
		}
		else
			return false;
	}

	BigN & operator=(const char * s){
		len = strlen(s);
		for (int i = 0; i < len; i++)
			Number[i] = s[len - i - 1] - '0';
		return *this;
	}

	BigN  operator=(const int num){
		char s[MAX];
		sprintf(s, "%d", num);
		*this = s;
		return *this;
	}

	BigN & operator+(const BigN & s) {
		BigN num;
		num.len = 0;
		for (int i = 0, g = 0; g || i < max(len, s.len); i++){
			int x = g;
			if (i < len) x += Number[i];
			if (i < s.len) x += s.Number[i];
			num.Number[num.len++] = x % 10;
			g = x / 10;
		}
		*this = num;
		return *this;
	}

	BigN & operator-(const BigN & s) {
		BigN num;
		num.len = 0;
		if (*this > s || *this == s){
			isFuShu = 0;
			for (int i = 0, g = 0; g || i < len; i++){
				int x = Number[i] - g;
				if (i < s.len) x -= s.Number[i];
				if (x < 0) {
					x += 10;
					g = 1;
				}
				else{
					g = 0;
				}
				num.Number[num.len++] = x;
			}
			num.clean();
			*this = num;
			return *this;
		}
		else{
			isFuShu = 1;
			for (int i = 0, g = 0; g || i < s.len; i++){
				int x = s.Number[i] - g;
				if (i < len) x -= Number[i];
				if (x < 0) {
					x += 10;
					g = 1;
				}
				else{
					g = 0;
				}
				num.Number[num.len++] = x;
			}
			num.clean();
			*this = num;
			return *this;
		}
	}

	BigN & operator*(const BigN & s){
		BigN mul;
		mul.len = len + s.len;
		for (int i = 0; i < len; i++)
		for (int j = 0; j < s.len; j++)
			mul.Number[i + j] += Number[i] * s.Number[j];
		for (int i = 0; i < mul.len - 1; i++){
			mul.Number[i + 1] += mul.Number[i] / 10;
			mul.Number[i] %= 10;
		}
		mul.clean();
		*this = mul;
		return *this;
	}

	BigN & operator/(const BigN &s){
		BigN tmp;
		if (!(*this > s)){
			tmp.Number[0] = 0;
			*this = tmp;
			return *this;
		}
		else if (*this == s){
			tmp.Number[0] = 1;
			*this = tmp;
			return *this;
		}
		//find the first location to make the num bigger than b.value
		int indexa = len, indexb = s.len;
		while (Number[indexa] == s.Number[indexb] && indexa > 0 && indexb > 0) {
			indexa--;
			indexb--;
		}
		if (Number[indexa] < s.Number[indexb])
			indexa = len - s.len - 1;
		else
			indexa = len - s.len;
		//execute divide
		tmp.len = 0;
		BigN cal(*this, indexa, len - 1);
		for (int i = indexa; i >= 0; --i) {
			int count = 0;

			while (cal > s || cal == s)  {
				cal = cal - s;
				count++;
			}

			for (int j = cal.len - 1; j >= 0; --j)
				cal.Number[j + 1] = cal.Number[j];
			cal.Number[0] = Number[i - 1];
			if (cal.len > 1)
				cal.len++;
			tmp.Number[tmp.len++] = count;

		}
		//reverse tmp;
		for (int i = 0; i < tmp.len / 2; ++i) {
			int tp = tmp.Number[i];
			tmp.Number[i] = tmp.Number[tmp.len - 1 - i];
			tmp.Number[tmp.len - 1 - i] = tp;
		}
		tmp.clean();
		*this = tmp;
		return *this;
	}
};

istream & operator>> (istream &in, BigN & x){
	char s[MAX];
	in >> s;
	x = s;
	return in;
}

ostream & operator<< (ostream &out, BigN & x){
	out << x.str();
	return out;
}

int main(){

	BigN a, b;

	while ( cin >> a >> b ){
		cout << a * b << endl;
	}

	return 0;
}
