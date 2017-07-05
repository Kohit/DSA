/*
 sorting large amount of strings using mergeSort
 1. split strings into small files witch can be fully loaded to memory
 2. sort each files with qsort
 3. merge these files into a single file
 
 assume the input file is out.txt and the output file is sort.txt (there are some temporary files(temp_x_x.txt) needs to be manually deleted)

 memory: O(batchSize * maxlen), batchSize * maxlen = size of small files
 time: O(n * lg(n)), n is the number of strings

 7/4/2017
 kohit

 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
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

// 分批次处理，为方便调试，这里每1000条字符串为一批次，同一批次可考虑用一线程处理，处理结果写入临时文本文件
// 最后再对这些文件使用归并排序进行排序
const int batchSize = 1000;
const int maxlen = 1000; // 假设每个字符串长度小于1000
// 返回分割的文件数量
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
			tmpf = fopen(name.str().c_str(), "w"); // 临时文件名为 tmpxx.txt，xx为数字，从0开始
		}

		/////////////////PROCESS//////////////
		char * res = expensiveFunc(str);
		//////////////////////////////////////

		fprintf(tmpf, "%s\n\r", res); // 结果写入文件
	}
	if (tmpf != NULL) fclose(tmpf);
	return num;
}

int cmp(const void *a, const void *b) {
	return strcmp((char *)a, (char *)b);
}

// 对每个文件排序
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
			fprintf(tmpf, "%s\n\r", tmpstr[j]);
		}
		fclose(tmpf);
	}
}

// 合并文件
void merge(int left) {
	int count = 0;
	cout << "Merging..." << endl;
	while (left > 1) { // 尚有left个文件未合并
		int j = 0;
		for (int i = 0; i < left; i += 2) { // 每次合并两个文件
			FILE *tmp1 = NULL, *tmp2 = NULL, *tmp3 = NULL; // tmp3为输出文件
			char str1[maxlen], str2[maxlen];
			ostringstream name;
			name << "tmp_" << count << "_" << i << ".txt";
			tmp1 = fopen(name.str().c_str(), "r");
			name.clear(); name.str("");
			name << "tmp_" << count + 1 << "_" << j++ << ".txt";
			tmp3 = fopen(name.str().c_str(), "w");
			if (i == left - 1) { // 只有一个文件，直接复制
				// last file
				while (fscanf(tmp1, "%s", str1) != EOF) {
					fprintf(tmp3, "%s\n\r", str1);
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
			
			// 反复比较两个文件的字符串
			while (strlen(str1) > 0 && strlen(str2) > 0) {
				if (strcmp(str1, str2) <= 0) { // 字符串1 <= 字符串2
					fprintf(tmp3, "%s\n\r", str1);
					if (fscanf(tmp1, "%s", str1) == EOF) { // 移动文件1指针
						str1[0] = '\0';
						break;
					}
				}
				else {
					fprintf(tmp3, "%s\n\r", str2);
					if (fscanf(tmp2, "%s", str2) == EOF) {
						str2[0] = '\0';
						break;
					}
				}
			}
			
			// 收集文件2剩余字符串
			if (strlen(str1) == 0 && strlen(str2) > 0) {
				do {
					fprintf(tmp3, "%s\n\r", str2);
				} while (fscanf(tmp2, "%s", str2) != EOF);
			}
			
			// 收集文件1剩余字符串
			if (strlen(str1) > 0 && strlen(str2) == 0) {
				do {
					fprintf(tmp3, "%s\n\r", str1);
				} while (fscanf(tmp1, "%s", str1) != EOF);
			}
			fclose(tmp1);
			fclose(tmp2);
			fclose(tmp3);
		}
		count++; // 下一层合并
		left = j; // 更新剩余待合并文件数目
	}

	// 保存结果（即最后一层合并结果）
	cout << "Collecting data..." << endl;
	FILE *tmp = NULL, *res = NULL;
	char str1[maxlen];
	ostringstream name;
	name << "tmp_" << count << "_" << 0 << ".txt";
	tmp = fopen(name.str().c_str(), "r+");
	res = fopen("sort.txt", "w");
	while (fscanf(tmp, "%s", str1) != EOF) {
		fprintf(res, "%s\n\r", str1);
	}
	fclose(tmp);
	fclose(res);
	cout << "Done! The output file is sort.txt" << endl;
}


int main() {
	char * name = "out.txt"; // 假设输入为out.txt，输出为sort.txt
	FILE * file = fopen(name, "r");
	if (file == NULL) {
		cout << "failed to open file" << endl;
		return -1;
	}
	int filenum = 0;
	filenum = process(file); // 读入并分批次处理，处理后写入临时文件
	fclose(file);
	sortfile(filenum); // 对每个临时文件排序
	merge(filenum); // 合并文件
	return 0;
}
