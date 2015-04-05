/*
*  Created by FongYoung Vane
*             Date 2014/5/9
*
* 程序说明：
* 程序启动时会从根目录的data.dat中读入数据
* 程序结束时会将数据写入跟目录的data.dat中
*
* 源码使用了C++11新功能，请在visual studio 2013 或者g++ 4.8以上版本的编译器运行本代码
* 如在g++上使用，请去掉windows.h头文件以及主函数末尾的语句system("pause")
* 由于安全考虑，部分带"_s"的函数无法在g++上编译，请去掉函数名后面的"_s"，以及两条define语句
*
* 程序生成的文件一律放在根目录下
* data.dat std.dat sort.dat next.dat分别为原、按学号/平均分排序、以及新名册的数据
* 凡是 姓名.txt 的文件是补考通知单， _姓名.txt 的文件是退学通知单
*
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <list>
#include <iomanip>
#include <memory>
#include <fstream>
#include <windows.h>
#include <string>
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class StudentInfo{
private:
	long long id = 0;
	string name;
	int Math = 0;
	int English = 0;
	int Physical = 0;
	int Program = 0;
	int Mph = 0;
	double Ave = 0;
public:
	StudentInfo(){}
	~StudentInfo(){}
	void CalAve(){
		Ave = (double)( Math + English + Physical + Program + Mph ) / 5.0;
	}
	//friend funtions;
	friend void LoadInfo();
	friend void Storage( char * );
	friend void EnterInfo();
	friend int StatisticsInfo();
	friend int DealSchoolRoll();
	friend void ModifyInfo();
	friend void SortId();
	friend void SortAve();
	friend void StatisticsGrade();
	friend void MakeUp();
	friend int SearchName();
	friend int SearchId();
	friend void QuitSchool();
	friend void NewRegister();
	friend bool CompareID(StudentInfo &, StudentInfo &);
	friend bool CompareAve(StudentInfo & first, StudentInfo & second);
};

class StaGrade{
public:
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	int E = 0;
};

bool CompareID(StudentInfo & first, StudentInfo & second){
	return first.id < second.id;
}

bool CompareAve(StudentInfo & first, StudentInfo & second){
	return first.Ave > second.Ave;
}

/* main list */
list<StudentInfo> Students;
list<StudentInfo> Register;

/* process */
void LoadInfo(){
	cout << "Loading..." << endl;
	FILE *f = fopen( "data.dat", "r" );
	if ( f == NULL ) {
		cout << "记录为空！" << endl;
		return ;
	}
	StudentInfo *stu = new StudentInfo;
	char name[50];
	while( fscanf ( f , "%lld%s%d%d%d%d%d", &stu->id, name, &stu->Math, &stu->English, &stu->Physical, &stu->Program, &stu->Mph, &stu->Ave ) != EOF ){
		stu->name = name;
		Students.push_back( *stu );
		stu = new StudentInfo;
	}
	fclose(f);

	/*
	 * 二进制写读取 注：win下不支持g++环境
	ifstream inFile("data.dat", ios::in );
	if (!inFile){
		cout << "记录为空！" << endl;
		return;
	}
	StudentInfo *stu = new StudentInfo;
	while (inFile.read((char*)& *stu, sizeof(*stu))){
		Students.push_back(*stu);
		stu = new StudentInfo;
	}
	inFile.close();
	*/
}

void Storage( char * filename ){
	cout << "正在保存记录，请勿关闭程序！" << endl;
	FILE *f = fopen( filename, "w" );
	list<StudentInfo>::iterator iter;
	for (iter = Students.begin(); iter != Students.end(); iter++){
		StudentInfo s = *iter;
		fprintf( f, "%lld %s %d %d %d %d %d\n", s.id, s.name.c_str(), s.Math, s.English, s.Physical, s.Program, s.Mph, s.Ave );
	}
	fclose(f);
	return ;
/*	二进制写入 注：win下不支持g++
 * ofstream OutFile("data.dat", ios::out );
	list<StudentInfo>::iterator iter;
	for (iter = Students.begin(); iter != Students.end(); iter++){
		StudentInfo s = *iter;
		OutFile.write((char *)& s, sizeof(s));
	}
	OutFile.close();
	cout << "保存成功！" << endl;
	*/
}

/* display */
void ShowMenu(){
	cout << "............................" << endl;
	cout << "   请输入选项编号( 0 ~ 4 )" << endl;
	cout << "............................" << endl;
	cout << ". 1 —— 录入成绩." << endl;
	cout << ". 2 —— 统计成绩." << endl;
	cout << ". 3 —— 处理学籍." << endl;
	cout << ". 4 —— 修改成绩." << endl;
	cout << ". 0 —— 退出系统." << endl;
	cout << "............................" << endl;
}
void ShowModify(){
	cout << "............................" << endl;
	cout << "   请输入选项编号( 0 ~ 2 )" << endl;
	cout << "............................" << endl;
	cout << ". 1 —— 按名字查找." << endl;
	cout << ". 2 —— 按学号查找." << endl;
	cout << ". 0 —— 返回." << endl;
	cout << "............................" << endl;
}
void ShowSubject(){
	cout << "............................" << endl;
	cout << "   请输入科目编号( 0 ~ 5 )" << endl;
	cout << "............................" << endl;
	cout << ". 1 —— 高数." << endl;
	cout << ". 2 —— 英语." << endl;
	cout << ". 3 —— 物理." << endl;
	cout << ". 4 —— 程序设计." << endl;
	cout << ". 5 —— 马克思主义哲学." << endl;
	cout << ". 0 —— 返回." << endl;
	cout << "............................" << endl;
}
void ShowStatisticsMenu(){
	cout << "............................" << endl;
	cout << "   请输入选项编号( 0 ~ 4 )" << endl;
	cout << "............................" << endl;
	cout << ". 1 —— 按学号排序." << endl;
	cout << ". 2 —— 计算平均分并排序." << endl;
	cout << ". 3 —— 统计分数段." << endl;
	cout << ". 4 —— 返回." << endl;
	cout << ". 0 —— 退出系统." << endl;
	cout << "............................" << endl;
}
void ShowDeal(){
	cout << "............................" << endl;
	cout << "   请输入选项编号( 0 ~ 4 )" << endl;
	cout << "............................" << endl;
	cout << ". 1 —— 生成并显示补考通知单." << endl;
	cout << ". 2 —— 生成并显示退学通知单." << endl;
	cout << ". 3 —— 生成并显示新名册." << endl;
	cout << ". 4 —— 返回." << endl;
	cout << ". 0 —— 退出系统." << endl;
	cout << "............................" << endl;
}

/* Functions */
// 1
void EnterInfo(){
	cout << "主菜单->录入成绩" << endl;
	cout << "请依次输入每个学生学号，姓名以及 高数、英语、物理、程序设计、马克斯主义哲学的成绩" << endl;
	while (true) {
		StudentInfo stu;
		cout << "学号：" << endl;
		cin >> stu.id;
		cout << "姓名：" << endl;
		cin >> stu.name;
		cout << "高数：" << endl;
		cin >> stu.Math;
		cout << "英语：" << endl;
		cin >> stu.English;
		cout << "物理：" << endl;
		cin >> stu.Physical;
		cout << "程序设计：" << endl;
		cin >> stu.Program;
		cout << "马克思主义哲学：" << endl;
		cin >> stu.Mph;
		stu.CalAve();
		Students.push_back(stu);
		cout << "如需继续输入请输入 y, 输入其他字符结束录入成绩操作（空格除外） " << endl;
		char ch;
		cin >> ch;
		if (ch != 'y')
			break;
	}
	return;
}
// 2
void SortId(){
	cout << "正在执行 按学号排序 操作，请耐心等待..." << endl;
	list<StudentInfo> StudentCopy;
	StudentCopy = Students;
	StudentCopy.sort(CompareID);
	Storage( "std.dat" );
	cout << "操作成功！std.dat 文件已成功保存在程序根目录下" << endl;
}
void SortAve(){
	cout << "正在执行 按平均分排序 操作，请耐心等待..." << endl;
	list<StudentInfo> StudentCopy;
	StudentCopy = Students;
	StudentCopy.sort(CompareAve);
	Storage( "sort.dat" );
	cout << "操作成功！sort.dat 文件已成功保存在程序根目录下" << endl;
}
void StatisticsGrade(){
	cout << "正在统计各分数段人数，请耐心等待..." << endl;
	StaGrade Math, English, Physical, Program, Mph;
	list<StudentInfo>::iterator iter;
	for (iter = Students.begin(); iter != Students.end(); iter++){
		
		int math = iter->Math;
		int english = iter->English;
		int physical = iter->Physical;
		int program = iter->Program;
		int mph = iter->Mph;

		if (math >= 90)
			Math.A++;
		else if (math >= 80)
			Math.B++;
		else if (math >= 70)
			Math.C++;
		else if (math >= 60)
			Math.D++;
		else if (math >= 0)
			Math.E++;

		if (english >= 90)
			English.A++;
		else if (english >= 80)
			English.B++;
		else if (english >= 70)
			English.C++;
		else if (english >= 60)
			English.D++;
		else if (english >= 0)
			English.E++;

		if (physical >= 90)
			Physical.A++;
		else if (physical >= 80)
			Physical.B++;
		else if (physical >= 70)
			Physical.C++;
		else if (physical >= 60)
			Physical.D++;
		else if (physical >= 0)
			Physical.E++;

		if (program >= 90)
			Program.A++;
		else if (program >= 80)
			Program.B++;
		else if (program >= 70)
			Program.C++;
		else if (program >= 60)
			Program.D++;
		else if (program >= 0)
			Program.E++;

		if (mph >= 90)
			Mph.A++;
		else if (mph >= 80)
			Mph.B++;
		else if (mph >= 70)
			Mph.C++;
		else if (mph >= 60)
			Mph.D++;
		else if (mph >= 0)
			Mph.E++;
	}
	cout << "              各科分数段统计表" << endl;
	cout << "............................................................." << endl;
	cout << "     . 90分及以上. 80 ~ 89分. 70 ~ 79分. 60 ~ 69分. 60分以下." << endl;
	printf("高数 .%11d. %9d. %9d. %9d. %8d.\n", Math.A, Math.B, Math.C, Math.D, Math.E);
	printf("英语 .%11d. %9d. %9d. %9d. %8d.\n", English.A, English.B, English.C, English.D, English.E);
	printf("物理 .%11d. %9d. %9d. %9d. %8d.\n", Physical.A, Physical.B, Physical.C, Physical.D, Physical.E);
	printf("编程 .%11d. %9d. %9d. %9d. %8d.\n", Program.A, Program.B, Program.C, Program.D, Program.E);
	printf("马哲 .%11d. %9d. %9d. %9d. %8d.\n", Mph.A, Mph.B, Mph.C, Mph.D, Mph.E);
	cout << "............................................................." << endl;
	cout << "总人数：" << Students.size() << endl;
}
int StatisticsInfo(){
	cout << "主菜单->统计成绩" << endl;
	ShowStatisticsMenu();
	int choise;
	while (cin >> choise) {
		if (choise == 0){
			cout << "确认退出系统请输入 y ,否则输入 n 或其他字符（空格除外）" << endl;
			char ch;
			cin >> ch;
			if (ch == 'y'){
				Storage( "data.dat" );
				cout << "感谢您的使用！系统已正常退出，请按任意键结束本窗口" << endl;
				system("pause");
				return -1;
			}
			continue;
		}
		if (choise == 4)
			break;
		switch (choise) {
		case 1: SortId(); break;
		case 2: SortAve(); break;
		case 3: StatisticsGrade(); break;
		default: cout << "请输入数字0~4选择对应功能" << endl; ShowStatisticsMenu(); break;
		}
	}
	return 0;
}
// 3
void MakeUp(){
	char filename[20];
	list<StudentInfo>::iterator iter;
	cout << "请输入各科目的补考时间和地点（时间地点请勿包含空格）" << endl;
	cout << "如 30/9/1/4 3-402 表示4月1日9点30在3-402参加补考" << endl;
	string mtime, mloca, etime, eloca, ptime, ploca, protime, proloca, mphtime, mphloca;
	cout << "数学 补考时间和地点" << endl;
	cin >> mtime >> mloca;
	cout << "英语 补考时间和地点" << endl;
	cin >> etime >> eloca;
	cout << "物理 补考时间和地点" << endl;
	cin >> ptime >> ploca;
	cout << "程序设计 补考时间和地点" << endl;
	cin >> protime >> proloca;
	cout << "马克思主义哲学 补考时间和地点" << endl;
	cin >> mphtime >> mphloca;
	for (iter = Students.begin(); iter != Students.end(); iter++){
		if (iter->Math < 60 || iter->English < 60 || iter->Physical < 60 || iter->Program < 60 || iter->Mph < 60){
			sprintf(filename, "%s.txt", iter->name.c_str());
			FILE *f = fopen( filename, "w");
			fprintf(f, "亲爱的%s同学， 您有以下科目需要补考\n", iter->name.c_str());
			cout << "-----------------------------------------" << endl;
			printf("学号:%lld  姓名：%s\n", iter->id, iter->name.c_str());
			fprintf(f, "      科目            时间        地点\n");
			printf("       科目          时间         地点\n");
			if (iter->Math < 60){
				fprintf(f, "      高数         %s      %s\n", mtime.c_str(), mloca.c_str());
				printf("      高数         %s      %s\n", mtime.c_str(), mloca.c_str());
			}
			if (iter->English < 60){
				fprintf(f, "      英语         %s      %s\n", etime.c_str(), eloca.c_str());
				printf("      英语         %s      %s\n", etime.c_str(), eloca.c_str());
			}
			if (iter->Physical < 60){
				fprintf(f, "      物理         %s      %s\n", ptime.c_str(), ploca.c_str());
				printf("      物理         %s      %s\n", ptime.c_str(), ploca.c_str());
			}
			if (iter->Program < 60){
				fprintf(f, "     程序设计      %s      %s\n", protime.c_str(), proloca.c_str());
				printf("     程序设计      %s      %s\n", protime.c_str(), proloca.c_str());
			}
			if (iter->Mph < 60){
				fprintf(f, " 马克思主义哲学    %s      %s\n", mphtime.c_str(), mphloca.c_str());
				printf(" 马克思主义哲学    %s      %s\n", mphtime.c_str(), mphloca.c_str());
			}
			cout << "------------------------------------------" << endl;
			fclose(f);
		}
	}
	cout << "通知单(名字.txt)生成成功！保存在根目录下" << endl;
}
void QuitSchool(){
	char filename[20];
	list<StudentInfo>::iterator iter;
	for (iter = Students.begin(); iter != Students.end(); iter++){
		int count = 0;
		if (iter->Math < 60)
			count++;
		if (iter->English < 60)
			count++;
		if (iter->Physical < 60)
			count++;
		if (iter->Program < 60)
			count++;
		if (iter->Mph < 60)
			count++;
		if (count > 3){
			sprintf(filename, "_%s.txt", iter->name.c_str());
			FILE *f = fopen( filename, "w");
			fprintf(f, "尊敬的%s同学：\n", iter->name.c_str());
			fprintf(f, "  由于你在本次考试中有3门以上科目不及格，根据学校《学籍管理实施细则》规定，学校将对你进行退学处理，谢谢合作！\n");
			fprintf(f, "                  本次考试不及格科目详情\n");
			fprintf(f, "学号： %010lld   姓名： %s\n", iter->id, iter->name.c_str());
			cout << "-------------------------------------" << endl;
			printf("学号： %lld   姓名： %s\n", iter->id, iter->name.c_str());
			if (iter->Math < 60){
				fprintf(f, "数学： %d\n", iter->Math);
				printf("数学： %d\n", iter->Math);
			}
			if (iter->English < 60){
				fprintf(f, "英语： %d\n", iter->English);
				printf("英语： %d\n", iter->English);
			}
			if (iter->Physical < 60){
				fprintf(f, "物理： %d\n", iter->Physical);
				printf("物理： %d\n", iter->Physical);
			}
			if (iter->Program < 60){
				fprintf(f, "程序设计： %d\n", iter->Program);
				printf("程序设计： %d\n", iter->Program);
			}
			if (iter->Mph < 60){
				fprintf(f, "马克思主义哲学： %d\n", iter->Mph);
				printf( "马克思主义哲学： %d\n", iter->Mph);
			}
			cout << "-------------------------------------" << endl;
			fclose(f);
			iter = Students.erase(iter);
			if (iter == Students.end())
				break;
		} // end if
	} // end for
	cout << "退学通知单（_姓名.txt）生成成功！已保存在根目录下" << endl;
	return;
}
void NewRegister(){
	list<StudentInfo>::iterator iter;
	Register = Students;
	for (iter = Register.begin(); iter != Register.end(); iter++){
		int count = 0;
		if (iter->Math < 60)
			count++;
		if (iter->English < 60)
			count++;
		if (iter->Physical < 60)
			count++;
		if (iter->Program < 60)
			count++;
		if (iter->Mph < 60)
			count++;
		if (count > 3){
			iter = Register.erase(iter);
			if (iter == Register.end())
				break;
		}
	}
	FILE * f = fopen( "next.dat", "w" );
	fprintf( f, "                             新名册\n" );
	fprintf( f, "学号               姓名           高数      英语      物理      编程     马哲\n");
	for (iter = Register.begin(); iter != Register.end(); iter++){
		fprintf( f, "%010lld %15s %9d %9d %9d %9d %9d\n", iter->id, iter->name.c_str(), iter->Math, iter->English, iter->Physical, iter->Program, iter->Mph);
	}
	fclose(f);
	cout << "操作成功！next.dat 文件已成功保存在程序根目录下" << endl;


}
int DealSchoolRoll(){
	ShowDeal();
	int choise = 0;
	while (cin >> choise){
		if (choise == 0){
			cout << "确认退出系统请输入 y ,否则输入 n 或其他字符（空格除外）" << endl;
			char ch;
			cin >> ch;
			if (ch == 'y'){
				Storage( "data.dat" );
				cout << "感谢您的使用！系统已正常退出，请按任意键结束本窗口" << endl;
				system("pause");
				return -1;
			}
			continue;
		}
		if (choise == 4)
			return 0;
		switch (choise) {
		case 1: MakeUp(); ShowDeal(); break;
		case 2: QuitSchool(); ShowDeal(); break;
		case 3: NewRegister(); ShowDeal(); break;
		default: cout << "请输入数字0~4选择对应功能" << endl; ShowDeal(); break;
		}
	}
	return 0;
}
// 4
int SearchName(){
	list<StudentInfo>::iterator iter;
	cout << "请输入学生姓名" << endl;
	string name;
	cin >> name;
	for (iter = Students.begin(); iter != Students.end(); iter++){
		if (iter->name == name)
			break;
	}
	if (iter == Students.end())
		return -1;
	printf("%010lld %s: 高数：%d 英语：%d 物理：%d 编程：%d 马哲：%d\n", iter->id, iter->name.c_str(), iter->Math, iter->English, iter->Physical, iter->Program, iter->Mph);
	ShowSubject();
	int choise;
	while (true){
		cin >> choise;
		if (choise == 0)
			break;
		switch (choise){
		case 1: cout << "请输入高数成绩：" << endl; cin >> iter->Math; cout << "修改成功！" << endl; ShowSubject(); break;
		case 2: cout << "请输入英语成绩：" << endl; cin >> iter->English; cout << "修改成功！" << endl; ShowSubject(); break;
		case 3: cout << "请输入物理成绩：" << endl; cin >> iter->Physical; cout << "修改成功！" << endl; ShowSubject(); break;
		case 4: cout << "请输入程序设计成绩：" << endl; cin >> iter->Program; cout << "修改成功！" << endl; ShowSubject(); break;
		case 5: cout << "请输入马克思主义哲学成绩：" << endl; cin >> iter->Mph; cout << "修改成功！" << endl; ShowSubject(); break;
		default: cout << "请输入数字0~5选择对应功能" << endl; ShowSubject(); break;
		}
	}
	return 0;
}
int SearchId(){
	list<StudentInfo>::iterator iter;
	cout << "请输入学生学号" << endl;
	long long id;
	cin >> id;
	for (iter = Students.begin(); iter != Students.end(); iter++){
		if (iter->id == id)
			break;
	}
	if (iter == Students.end())
		return -1;
	printf("%010lld %s: 高数：%d 英语：%d 物理：%d 编程：%d 马哲：%d\n", iter->id, iter->name.c_str(), iter->Math, iter->English, iter->Physical, iter->Program, iter->Mph);
	ShowSubject();
	int choise;
	while (true){
		cin >> choise;
		if (choise == 0)
			break;
		switch (choise){
		case 1: cout << "请输入高数成绩：" << endl; cin >> iter->Math; cout << "修改成功！" << endl; ShowSubject(); break;
		case 2: cout << "请输入英语成绩：" << endl; cin >> iter->English; cout << "修改成功！" << endl; ShowSubject(); break;
		case 3: cout << "请输入物理成绩：" << endl; cin >> iter->Physical; cout << "修改成功！" << endl; ShowSubject(); break;
		case 4: cout << "请输入程序设计成绩：" << endl; cin >> iter->Program; cout << "修改成功！" << endl; ShowSubject(); break;
		case 5: cout << "请输入马克思主义哲学成绩：" << endl; cin >> iter->Mph; cout << "修改成功！" << endl; ShowSubject(); break;
		default: cout << "请输入数字0~5选择对应功能" << endl; ShowSubject(); break;
		}
	}
	return 0;
}
void ModifyInfo(){
	list<StudentInfo>::iterator iter;
	/*
	for (iter = Students.begin(); iter != Students.end(); iter++){
		cout << iter->id << iter->name << iter->Ave << endl;
	}
	return;
	*/
	cout << "主菜单->修改成绩" << endl;
	ShowModify();
	int choise = 0;
	int statue = 0;
	while (true){
		cin >> choise;
		if (choise == 0)
			break;
		switch (choise){
		case 1: statue = SearchName();
			if (statue == -1)
				cout << "未找到该学生，请检查是否输入有误，否则请尝试按学号查找" << endl;
			ShowModify(); break;
		case 2: statue = SearchId();
			if (statue == -1)
				cout << "未找到该学生，请检查是否输入有误，否则请尝试按姓名查找" << endl;
			ShowModify(); break;
		default: cout << "请输入数字0~2选择对应功能" << endl; ShowModify(); break;
		}
	}
	return ;
}

/* ->MAIN FUNCTION<- */
int main() {
	LoadInfo();
	cout << "                     欢迎使用学生学籍管理系统" << endl;
	ShowMenu();
	int choise = 0;
	int state = 0;
	while (cin >> choise){
		if (choise == 0){
			cout << "确认退出系统请输入 y ,否则输入 n 或其他字符（空格除外）" << endl;
			char ch;
			cin >> ch;
			if (ch == 'y') break;
			continue;
		}
		switch (choise) {
		case 1: EnterInfo(); ShowMenu(); break;
		case 2: state = StatisticsInfo(); 
			if (state == -1){
				return 0;
			}
			ShowMenu();	break;
		case 3: state = DealSchoolRoll();
			if (state == -1){
				return 0;
			}
			ShowMenu();	break;
		case 4: ModifyInfo(); ShowMenu(); break;
		default: cout << "请输入数字0~4选择对应功能" << endl; ShowMenu(); break;
		}
	}
	Storage( "data.dat" );
	cout << "感谢您的使用！系统已正常退出，请按任意键结束本窗口" << endl;
	system("pause");
	return 0;
}
