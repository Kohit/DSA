/*
 sorting large amount of strings using mergeSort
 1. split strings into small files witch can be fully loaded to memory
 2. sort each files with qsort
 3. merge these files into a single file
 
 assume the input file is out.txt and the output file is sort.txt

 memory: O(batchSize * maxlen), batchSize * maxlen = size of small files
 time: O(lg(n)), n is the number of strings

 7/4/2017
 kohit

 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <algorithm>
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

char *  expensiveFunc(char * str) {
	return str;
}

// �����δ�����Ϊ������ԣ�����ÿ1000���ַ���Ϊһ���Σ�ͬһ���οɿ�����һ�̴߳������������д����ʱ�ı��ļ�
// ����ٶ���Щ�ļ�ʹ�ù鲢�����������
const int batchSize = 1000;
const int maxlen = 1000; // ����ÿ���ַ�������С��1000
// ���طָ���ļ�����
int process(FILE * file) {
	cout << "processing..." << endl;
	int num = 0, line = 0;
	char str[maxlen]; 
	FILE * tmpf = NULL;
	while (fscanf(file, "%s", str) != EOF) {
		line++;
		if (line % batchSize == 0 || tmpf == NULL) { // consider to start a new thread for each batch
			if (tmpf != NULL) fclose(tmpf);
			ostringstream name;
			name << "tmp_0_" << num++ << ".txt";
			tmpf = fopen(name.str().c_str(), "w"); // ��ʱ�ļ���Ϊ tmpxx.txt��xxΪ���֣���0��ʼ
		}

		/////////////////PROCESS//////////////
		char * res = expensiveFunc(str);
		//////////////////////////////////////

		fprintf(tmpf, "%s\n", res); // ���д���ļ�
	}
	if (tmpf != NULL) fclose(tmpf);
	return num;
}

int cmp(const void *a, const void *b) {
	return strcmp((char *)a, (char *)b);
}

// ��ÿ���ļ�����
char tmpstr[batchSize][maxlen];
void sortfile(int filenum) {
	for (int i = 0; i < filenum; i++) {
		cout << "sorting " << i + 1 << " of " << filenum + 1 << "file" << endl;
		ostringstream name;
		name << "tmp_0_" << i << ".txt";
		FILE * tmpf = fopen(name.str().c_str(), "r+");

		//cout << "opening file" << name.str() << endl;
		for (int k = 0; k < batchSize; k++) {
			memset(tmpstr[k], 0, sizeof(char) * maxlen);
		}
		int line = 0;

		//cout << "reading file" << name.str() << endl;
		while(fscanf(tmpf, "%s", tmpstr[line++]) != EOF){}

		//cout << "sorting file" << name.str() << endl;
		qsort(tmpstr, line > batchSize ? batchSize : line, sizeof(char) * maxlen, cmp);

		//cout << "rewriting file" << name.str() << endl;
		rewind(tmpf);
		for (int j = 0; j < line && j < batchSize; j++) {
			if (strlen(tmpstr[j]) > 0)
			fprintf(tmpf, "%s\n", tmpstr[j]);
		}
		fclose(tmpf);
	}
}

// �ϲ��ļ�
void merge(int left) {
	int count = 0;
	cout << "Merging..." << endl;
	while (left > 1) { // ����left���ļ�δ�ϲ�
		int j = 0;
		for (int i = 0; i < left; i += 2) { // ÿ�κϲ������ļ�
			FILE *tmp1 = NULL, *tmp2 = NULL, *tmp3 = NULL; // tmp3Ϊ����ļ�
			char str1[maxlen], str2[maxlen];
			ostringstream name;
			name << "tmp_" << count << "_" << i << ".txt";
			tmp1 = fopen(name.str().c_str(), "r");
			name.clear(); name.str("");
			name << "tmp_" << count + 1 << "_" << j++ << ".txt";
			tmp3 = fopen(name.str().c_str(), "w");
			if (i == left - 1) { // ֻ��һ���ļ���ֱ�Ӹ���
				// last file
				while (fscanf(tmp1, "%s", str1) != EOF) {
					fprintf(tmp3, "%s\n", str1);
				}
				fclose(tmp1);
				fclose(tmp3);
				break;
			}
			name.clear(); name.str("");
			name << "tmp_" << count << "_" << i + 1 << ".txt";
			tmp2 = fopen(name.str().c_str(), "r");

			fscanf(tmp1, "%s", str1);
			fscanf(tmp2, "%s", str2);
			
			// �����Ƚ������ļ����ַ���
			while (strlen(str1) > 0 && strlen(str2) > 0) {
				if (strcmp(str1, str2) <= 0) { // �ַ���1 <= �ַ���2
					fprintf(tmp3, "%s\n", str1);
					if (fscanf(tmp1, "%s", str1) == EOF) { // �ƶ��ļ�1ָ��
						str1[0] = '\0';
						break;
					}
				}
				else {
					fprintf(tmp3, "%s\n", str2);
					if (fscanf(tmp2, "%s", str2) == EOF) {
						str2[0] = '\0';
						break;
					}
				}
			}
			
			// �ռ��ļ�2ʣ���ַ���
			if (strlen(str1) == 0 && strlen(str2) > 0) {
				do {
					fprintf(tmp3, "%s\n", str2);
				} while (fscanf(tmp2, "%s", str2) != EOF);
			}
			
			// �ռ��ļ�1ʣ���ַ���
			if (strlen(str1) > 0 && strlen(str2) == 0) {
				do {
					fprintf(tmp3, "%s\n", str1);
				} while (fscanf(tmp1, "%s", str1) != EOF);
			}
			fclose(tmp1);
			fclose(tmp2);
			fclose(tmp3);
		}
		count++; // ��һ��ϲ�
		left = j; // ����ʣ����ϲ��ļ���Ŀ
	}

	// �������������һ��ϲ������
	cout << "Collecting data..." << endl;
	FILE *tmp = NULL, *res = NULL;
	char str1[maxlen];
	ostringstream name;
	name << "tmp_" << count << "_" << 0 << ".txt";
	tmp = fopen(name.str().c_str(), "r+");
	res = fopen("sort.txt", "w");
	while (fscanf(tmp, "%s", str1) != EOF) {
		fprintf(res, "%s\n", str1);
	}
	fclose(tmp);
	fclose(res);
	cout << "Done! The output file is sort.txt" << endl;
}


int main() {
	char * name = "out.txt"; // ��������Ϊout.txt�����Ϊsort.txt
	FILE * file = fopen(name, "r");
	if (file == NULL) {
		cout << "failed to open file" << endl;
		return -1;
	}
	int filenum = 0;
	filenum = process(file); // ���벢�����δ�����������д����ʱ�ļ�
	fclose(file);
	sortfile(filenum); // ��ÿ����ʱ�ļ�����
	merge(filenum); // �ϲ��ļ�
	return 0;
}