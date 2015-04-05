/*
*  Created by FongYoung Vane
*             Date 2014/5/9
*
* ����˵����
* ��������ʱ��Ӹ�Ŀ¼��data.dat�ж�������
* �������ʱ�Ὣ����д���Ŀ¼��data.dat��
*
* Դ��ʹ����C++11�¹��ܣ�����visual studio 2013 ����g++ 4.8���ϰ汾�ı��������б�����
* ����g++��ʹ�ã���ȥ��windows.hͷ�ļ��Լ�������ĩβ�����system("pause")
* ���ڰ�ȫ���ǣ����ִ�"_s"�ĺ����޷���g++�ϱ��룬��ȥ�������������"_s"���Լ�����define���
*
* �������ɵ��ļ�һ�ɷ��ڸ�Ŀ¼��
* data.dat std.dat sort.dat next.dat�ֱ�Ϊԭ����ѧ��/ƽ���������Լ������������
* ���� ����.txt ���ļ��ǲ���֪ͨ���� _����.txt ���ļ�����ѧ֪ͨ��
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
		cout << "��¼Ϊ�գ�" << endl;
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
	 * ������д��ȡ ע��win�²�֧��g++����
	ifstream inFile("data.dat", ios::in );
	if (!inFile){
		cout << "��¼Ϊ�գ�" << endl;
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
	cout << "���ڱ����¼������رճ���" << endl;
	FILE *f = fopen( filename, "w" );
	list<StudentInfo>::iterator iter;
	for (iter = Students.begin(); iter != Students.end(); iter++){
		StudentInfo s = *iter;
		fprintf( f, "%lld %s %d %d %d %d %d\n", s.id, s.name.c_str(), s.Math, s.English, s.Physical, s.Program, s.Mph, s.Ave );
	}
	fclose(f);
	return ;
/*	������д�� ע��win�²�֧��g++
 * ofstream OutFile("data.dat", ios::out );
	list<StudentInfo>::iterator iter;
	for (iter = Students.begin(); iter != Students.end(); iter++){
		StudentInfo s = *iter;
		OutFile.write((char *)& s, sizeof(s));
	}
	OutFile.close();
	cout << "����ɹ���" << endl;
	*/
}

/* display */
void ShowMenu(){
	cout << "............................" << endl;
	cout << "   ������ѡ����( 0 ~ 4 )" << endl;
	cout << "............................" << endl;
	cout << ". 1 ���� ¼��ɼ�." << endl;
	cout << ". 2 ���� ͳ�Ƴɼ�." << endl;
	cout << ". 3 ���� ����ѧ��." << endl;
	cout << ". 4 ���� �޸ĳɼ�." << endl;
	cout << ". 0 ���� �˳�ϵͳ." << endl;
	cout << "............................" << endl;
}
void ShowModify(){
	cout << "............................" << endl;
	cout << "   ������ѡ����( 0 ~ 2 )" << endl;
	cout << "............................" << endl;
	cout << ". 1 ���� �����ֲ���." << endl;
	cout << ". 2 ���� ��ѧ�Ų���." << endl;
	cout << ". 0 ���� ����." << endl;
	cout << "............................" << endl;
}
void ShowSubject(){
	cout << "............................" << endl;
	cout << "   �������Ŀ���( 0 ~ 5 )" << endl;
	cout << "............................" << endl;
	cout << ". 1 ���� ����." << endl;
	cout << ". 2 ���� Ӣ��." << endl;
	cout << ". 3 ���� ����." << endl;
	cout << ". 4 ���� �������." << endl;
	cout << ". 5 ���� ���˼������ѧ." << endl;
	cout << ". 0 ���� ����." << endl;
	cout << "............................" << endl;
}
void ShowStatisticsMenu(){
	cout << "............................" << endl;
	cout << "   ������ѡ����( 0 ~ 4 )" << endl;
	cout << "............................" << endl;
	cout << ". 1 ���� ��ѧ������." << endl;
	cout << ". 2 ���� ����ƽ���ֲ�����." << endl;
	cout << ". 3 ���� ͳ�Ʒ�����." << endl;
	cout << ". 4 ���� ����." << endl;
	cout << ". 0 ���� �˳�ϵͳ." << endl;
	cout << "............................" << endl;
}
void ShowDeal(){
	cout << "............................" << endl;
	cout << "   ������ѡ����( 0 ~ 4 )" << endl;
	cout << "............................" << endl;
	cout << ". 1 ���� ���ɲ���ʾ����֪ͨ��." << endl;
	cout << ". 2 ���� ���ɲ���ʾ��ѧ֪ͨ��." << endl;
	cout << ". 3 ���� ���ɲ���ʾ������." << endl;
	cout << ". 4 ���� ����." << endl;
	cout << ". 0 ���� �˳�ϵͳ." << endl;
	cout << "............................" << endl;
}

/* Functions */
// 1
void EnterInfo(){
	cout << "���˵�->¼��ɼ�" << endl;
	cout << "����������ÿ��ѧ��ѧ�ţ������Լ� ������Ӣ�����������ơ����˹������ѧ�ĳɼ�" << endl;
	while (true) {
		StudentInfo stu;
		cout << "ѧ�ţ�" << endl;
		cin >> stu.id;
		cout << "������" << endl;
		cin >> stu.name;
		cout << "������" << endl;
		cin >> stu.Math;
		cout << "Ӣ�" << endl;
		cin >> stu.English;
		cout << "����" << endl;
		cin >> stu.Physical;
		cout << "������ƣ�" << endl;
		cin >> stu.Program;
		cout << "���˼������ѧ��" << endl;
		cin >> stu.Mph;
		stu.CalAve();
		Students.push_back(stu);
		cout << "����������������� y, ���������ַ�����¼��ɼ��������ո���⣩ " << endl;
		char ch;
		cin >> ch;
		if (ch != 'y')
			break;
	}
	return;
}
// 2
void SortId(){
	cout << "����ִ�� ��ѧ������ �����������ĵȴ�..." << endl;
	list<StudentInfo> StudentCopy;
	StudentCopy = Students;
	StudentCopy.sort(CompareID);
	Storage( "std.dat" );
	cout << "�����ɹ���std.dat �ļ��ѳɹ������ڳ����Ŀ¼��" << endl;
}
void SortAve(){
	cout << "����ִ�� ��ƽ�������� �����������ĵȴ�..." << endl;
	list<StudentInfo> StudentCopy;
	StudentCopy = Students;
	StudentCopy.sort(CompareAve);
	Storage( "sort.dat" );
	cout << "�����ɹ���sort.dat �ļ��ѳɹ������ڳ����Ŀ¼��" << endl;
}
void StatisticsGrade(){
	cout << "����ͳ�Ƹ������������������ĵȴ�..." << endl;
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
	cout << "              ���Ʒ�����ͳ�Ʊ�" << endl;
	cout << "............................................................." << endl;
	cout << "     . 90�ּ�����. 80 ~ 89��. 70 ~ 79��. 60 ~ 69��. 60������." << endl;
	printf("���� .%11d. %9d. %9d. %9d. %8d.\n", Math.A, Math.B, Math.C, Math.D, Math.E);
	printf("Ӣ�� .%11d. %9d. %9d. %9d. %8d.\n", English.A, English.B, English.C, English.D, English.E);
	printf("���� .%11d. %9d. %9d. %9d. %8d.\n", Physical.A, Physical.B, Physical.C, Physical.D, Physical.E);
	printf("��� .%11d. %9d. %9d. %9d. %8d.\n", Program.A, Program.B, Program.C, Program.D, Program.E);
	printf("���� .%11d. %9d. %9d. %9d. %8d.\n", Mph.A, Mph.B, Mph.C, Mph.D, Mph.E);
	cout << "............................................................." << endl;
	cout << "��������" << Students.size() << endl;
}
int StatisticsInfo(){
	cout << "���˵�->ͳ�Ƴɼ�" << endl;
	ShowStatisticsMenu();
	int choise;
	while (cin >> choise) {
		if (choise == 0){
			cout << "ȷ���˳�ϵͳ������ y ,�������� n �������ַ����ո���⣩" << endl;
			char ch;
			cin >> ch;
			if (ch == 'y'){
				Storage( "data.dat" );
				cout << "��л����ʹ�ã�ϵͳ�������˳����밴���������������" << endl;
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
		default: cout << "����������0~4ѡ���Ӧ����" << endl; ShowStatisticsMenu(); break;
		}
	}
	return 0;
}
// 3
void MakeUp(){
	char filename[20];
	list<StudentInfo>::iterator iter;
	cout << "���������Ŀ�Ĳ���ʱ��͵ص㣨ʱ��ص���������ո�" << endl;
	cout << "�� 30/9/1/4 3-402 ��ʾ4��1��9��30��3-402�μӲ���" << endl;
	string mtime, mloca, etime, eloca, ptime, ploca, protime, proloca, mphtime, mphloca;
	cout << "��ѧ ����ʱ��͵ص�" << endl;
	cin >> mtime >> mloca;
	cout << "Ӣ�� ����ʱ��͵ص�" << endl;
	cin >> etime >> eloca;
	cout << "���� ����ʱ��͵ص�" << endl;
	cin >> ptime >> ploca;
	cout << "������� ����ʱ��͵ص�" << endl;
	cin >> protime >> proloca;
	cout << "���˼������ѧ ����ʱ��͵ص�" << endl;
	cin >> mphtime >> mphloca;
	for (iter = Students.begin(); iter != Students.end(); iter++){
		if (iter->Math < 60 || iter->English < 60 || iter->Physical < 60 || iter->Program < 60 || iter->Mph < 60){
			sprintf(filename, "%s.txt", iter->name.c_str());
			FILE *f = fopen( filename, "w");
			fprintf(f, "�װ���%sͬѧ�� �������¿�Ŀ��Ҫ����\n", iter->name.c_str());
			cout << "-----------------------------------------" << endl;
			printf("ѧ��:%lld  ������%s\n", iter->id, iter->name.c_str());
			fprintf(f, "      ��Ŀ            ʱ��        �ص�\n");
			printf("       ��Ŀ          ʱ��         �ص�\n");
			if (iter->Math < 60){
				fprintf(f, "      ����         %s      %s\n", mtime.c_str(), mloca.c_str());
				printf("      ����         %s      %s\n", mtime.c_str(), mloca.c_str());
			}
			if (iter->English < 60){
				fprintf(f, "      Ӣ��         %s      %s\n", etime.c_str(), eloca.c_str());
				printf("      Ӣ��         %s      %s\n", etime.c_str(), eloca.c_str());
			}
			if (iter->Physical < 60){
				fprintf(f, "      ����         %s      %s\n", ptime.c_str(), ploca.c_str());
				printf("      ����         %s      %s\n", ptime.c_str(), ploca.c_str());
			}
			if (iter->Program < 60){
				fprintf(f, "     �������      %s      %s\n", protime.c_str(), proloca.c_str());
				printf("     �������      %s      %s\n", protime.c_str(), proloca.c_str());
			}
			if (iter->Mph < 60){
				fprintf(f, " ���˼������ѧ    %s      %s\n", mphtime.c_str(), mphloca.c_str());
				printf(" ���˼������ѧ    %s      %s\n", mphtime.c_str(), mphloca.c_str());
			}
			cout << "------------------------------------------" << endl;
			fclose(f);
		}
	}
	cout << "֪ͨ��(����.txt)���ɳɹ��������ڸ�Ŀ¼��" << endl;
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
			fprintf(f, "�𾴵�%sͬѧ��\n", iter->name.c_str());
			fprintf(f, "  �������ڱ��ο�������3�����Ͽ�Ŀ�����񣬸���ѧУ��ѧ������ʵʩϸ�򡷹涨��ѧУ�����������ѧ����лл������\n");
			fprintf(f, "                  ���ο��Բ������Ŀ����\n");
			fprintf(f, "ѧ�ţ� %010lld   ������ %s\n", iter->id, iter->name.c_str());
			cout << "-------------------------------------" << endl;
			printf("ѧ�ţ� %lld   ������ %s\n", iter->id, iter->name.c_str());
			if (iter->Math < 60){
				fprintf(f, "��ѧ�� %d\n", iter->Math);
				printf("��ѧ�� %d\n", iter->Math);
			}
			if (iter->English < 60){
				fprintf(f, "Ӣ� %d\n", iter->English);
				printf("Ӣ� %d\n", iter->English);
			}
			if (iter->Physical < 60){
				fprintf(f, "���� %d\n", iter->Physical);
				printf("���� %d\n", iter->Physical);
			}
			if (iter->Program < 60){
				fprintf(f, "������ƣ� %d\n", iter->Program);
				printf("������ƣ� %d\n", iter->Program);
			}
			if (iter->Mph < 60){
				fprintf(f, "���˼������ѧ�� %d\n", iter->Mph);
				printf( "���˼������ѧ�� %d\n", iter->Mph);
			}
			cout << "-------------------------------------" << endl;
			fclose(f);
			iter = Students.erase(iter);
			if (iter == Students.end())
				break;
		} // end if
	} // end for
	cout << "��ѧ֪ͨ����_����.txt�����ɳɹ����ѱ����ڸ�Ŀ¼��" << endl;
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
	fprintf( f, "                             ������\n" );
	fprintf( f, "ѧ��               ����           ����      Ӣ��      ����      ���     ����\n");
	for (iter = Register.begin(); iter != Register.end(); iter++){
		fprintf( f, "%010lld %15s %9d %9d %9d %9d %9d\n", iter->id, iter->name.c_str(), iter->Math, iter->English, iter->Physical, iter->Program, iter->Mph);
	}
	fclose(f);
	cout << "�����ɹ���next.dat �ļ��ѳɹ������ڳ����Ŀ¼��" << endl;


}
int DealSchoolRoll(){
	ShowDeal();
	int choise = 0;
	while (cin >> choise){
		if (choise == 0){
			cout << "ȷ���˳�ϵͳ������ y ,�������� n �������ַ����ո���⣩" << endl;
			char ch;
			cin >> ch;
			if (ch == 'y'){
				Storage( "data.dat" );
				cout << "��л����ʹ�ã�ϵͳ�������˳����밴���������������" << endl;
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
		default: cout << "����������0~4ѡ���Ӧ����" << endl; ShowDeal(); break;
		}
	}
	return 0;
}
// 4
int SearchName(){
	list<StudentInfo>::iterator iter;
	cout << "������ѧ������" << endl;
	string name;
	cin >> name;
	for (iter = Students.begin(); iter != Students.end(); iter++){
		if (iter->name == name)
			break;
	}
	if (iter == Students.end())
		return -1;
	printf("%010lld %s: ������%d Ӣ�%d ����%d ��̣�%d ���ܣ�%d\n", iter->id, iter->name.c_str(), iter->Math, iter->English, iter->Physical, iter->Program, iter->Mph);
	ShowSubject();
	int choise;
	while (true){
		cin >> choise;
		if (choise == 0)
			break;
		switch (choise){
		case 1: cout << "����������ɼ���" << endl; cin >> iter->Math; cout << "�޸ĳɹ���" << endl; ShowSubject(); break;
		case 2: cout << "������Ӣ��ɼ���" << endl; cin >> iter->English; cout << "�޸ĳɹ���" << endl; ShowSubject(); break;
		case 3: cout << "����������ɼ���" << endl; cin >> iter->Physical; cout << "�޸ĳɹ���" << endl; ShowSubject(); break;
		case 4: cout << "�����������Ƴɼ���" << endl; cin >> iter->Program; cout << "�޸ĳɹ���" << endl; ShowSubject(); break;
		case 5: cout << "���������˼������ѧ�ɼ���" << endl; cin >> iter->Mph; cout << "�޸ĳɹ���" << endl; ShowSubject(); break;
		default: cout << "����������0~5ѡ���Ӧ����" << endl; ShowSubject(); break;
		}
	}
	return 0;
}
int SearchId(){
	list<StudentInfo>::iterator iter;
	cout << "������ѧ��ѧ��" << endl;
	long long id;
	cin >> id;
	for (iter = Students.begin(); iter != Students.end(); iter++){
		if (iter->id == id)
			break;
	}
	if (iter == Students.end())
		return -1;
	printf("%010lld %s: ������%d Ӣ�%d ����%d ��̣�%d ���ܣ�%d\n", iter->id, iter->name.c_str(), iter->Math, iter->English, iter->Physical, iter->Program, iter->Mph);
	ShowSubject();
	int choise;
	while (true){
		cin >> choise;
		if (choise == 0)
			break;
		switch (choise){
		case 1: cout << "����������ɼ���" << endl; cin >> iter->Math; cout << "�޸ĳɹ���" << endl; ShowSubject(); break;
		case 2: cout << "������Ӣ��ɼ���" << endl; cin >> iter->English; cout << "�޸ĳɹ���" << endl; ShowSubject(); break;
		case 3: cout << "����������ɼ���" << endl; cin >> iter->Physical; cout << "�޸ĳɹ���" << endl; ShowSubject(); break;
		case 4: cout << "�����������Ƴɼ���" << endl; cin >> iter->Program; cout << "�޸ĳɹ���" << endl; ShowSubject(); break;
		case 5: cout << "���������˼������ѧ�ɼ���" << endl; cin >> iter->Mph; cout << "�޸ĳɹ���" << endl; ShowSubject(); break;
		default: cout << "����������0~5ѡ���Ӧ����" << endl; ShowSubject(); break;
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
	cout << "���˵�->�޸ĳɼ�" << endl;
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
				cout << "δ�ҵ���ѧ���������Ƿ��������󣬷����볢�԰�ѧ�Ų���" << endl;
			ShowModify(); break;
		case 2: statue = SearchId();
			if (statue == -1)
				cout << "δ�ҵ���ѧ���������Ƿ��������󣬷����볢�԰���������" << endl;
			ShowModify(); break;
		default: cout << "����������0~2ѡ���Ӧ����" << endl; ShowModify(); break;
		}
	}
	return ;
}

/* ->MAIN FUNCTION<- */
int main() {
	LoadInfo();
	cout << "                     ��ӭʹ��ѧ��ѧ������ϵͳ" << endl;
	ShowMenu();
	int choise = 0;
	int state = 0;
	while (cin >> choise){
		if (choise == 0){
			cout << "ȷ���˳�ϵͳ������ y ,�������� n �������ַ����ո���⣩" << endl;
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
		default: cout << "����������0~4ѡ���Ӧ����" << endl; ShowMenu(); break;
		}
	}
	Storage( "data.dat" );
	cout << "��л����ʹ�ã�ϵͳ�������˳����밴���������������" << endl;
	system("pause");
	return 0;
}
