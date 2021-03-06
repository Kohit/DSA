/*
 randomly generate n strings to output file,
 length of each string in range[minlen, maxlen]
 input arguments are number of strings, min length, max length, output filename
 e.g.
 g++ genstring.cpp -o genstring // compile
 ./genstring 10000 5 30 out.txt // generate 10000 strings, length of each string in range[5,30], the output file is out.txt

 memory: O(MAXLEN), here MAXLEN = 1000;
 time: O(n * LEN), n is the number of strings, LEN is the average length of strings

 7/4/2017
 kohit
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
using namespace std;

const int sz = 1 << 20;
struct fastio {  // set larger io buffer size to speed up
	char inbuf[sz];
	char outbuf[sz];
	fastio() {
		setvbuf(stdin, inbuf, _IOFBF, sz);
		setvbuf(stdout, outbuf, _IOFBF, sz);
	}
}io;

char dictionary[52];
const int MAXLEN = 1000; // assume maxlen < 1000;
void gen(int n, int minlen, int maxlen, char * name) {
	//ofstream outfile;
	//outfile.open(name, ios::out);
	FILE * file = fopen(name, "w"); // usage stdio instead
	srand((unsigned)time(0));
	char str[MAXLEN]; 
	for (int i = 0; i < n; i++) {
		memset(str, 0, sizeof(char) * MAXLEN);
		int len = rand() % (maxlen - minlen + 1) + minlen; // string len in range[minlen, maxlen]
		int j = 0;
		for (; j < len; j++) {  // generate a random string with length = len
			int index = rand() % 52;
			str[j] = dictionary[index];
		}
		str[j] = '\0';
		//cout << str << endl;
		//outfile << str << endl; 
		fprintf(file, "%s\n\r", str);  // write to file
		cout << "progress: " << (double)(i + 1) / n * 100 << "%" << endl;
	}
	//outfile.close();
	fclose(file);
}

int main(int argc, char * argv[]) { 
	// arguments are number of strings, min length, max length, output filename
	for (int i = 'A'; i <= 'Z'; i++)
		dictionary[i - 'A'] = i;
	for (int i = 'a'; i <= 'z'; i++)
		dictionary[i - 'a' + 26] = i;
	int num = 0, minlen = 0, maxlen = 0;
	char name[80];
	sscanf(argv[1], "%d", &num);
	sscanf(argv[2], "%d", &minlen);
	sscanf(argv[3], "%d", &maxlen);
	sscanf(argv[4], "%s", name);
	gen(num, minlen, maxlen, name);
	return 0;
}

