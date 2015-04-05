/*
 * connecter.cpp
 *
 *  Created on: 2014年1月8日
 *   Modify on: 2014年5月23日
 *      Author: FongYoung Vane
 */
 /*
 * 功能简介：
 * 本程序可以实现添加，查询，修改，删除联络人等
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>
#include <iomanip>
#include <windows.h>
using namespace std;

class People{
	string name;
	string phone;
	string address;
public:
	People( string newname, string newphone, string newadd ) : name( newname ), phone( newphone ), address( newadd ) { }
	People( ){ }
	friend void loadinfo();
	friend void storage();
	friend void NewConnecter();        // 添加新联系人信息
	friend void Inquire();             // 查询联系人信息
	friend void Revise();              // 修改联系人信息
	friend void Delete();              // 删除联系人
	friend void showAll();             // 显示所有联系人
};

list< People > Contacts;

/* 功能函数 */
void loadinfo(){
	cout << "loading..." << endl;
	FILE * f = fopen( "data.dat", "r" );
	if ( !f ){
		cout << "记录为空！" << endl;
		return ;
	}
	People * peo = new People;

	char name[50];
	char phone[50];
	char address[50];

	while( fscanf( f, "%s%s%s", name, phone, address ) != EOF ){
		peo->name = name; peo->phone = phone; peo->address = address;
		Contacts.push_back( *peo );
		peo = new People;
	}
	fclose( f );
}
void storage(){
	cout << "正在保存记录" << endl;
	FILE * f = fopen( "data.dat", "w" );
	list< People >::iterator iter;
	for ( iter = Contacts.begin(); iter != Contacts.end(); iter++ ) {
		fprintf( f, "%s %s %s\n", iter->name.c_str(), iter->phone.c_str(), iter->address.c_str() );
	}
	cout << "保存成功！" << endl;
	fclose( f );
}
void NewConnecter();        // 添加新联系人信息
void Inquire();             // 查询联系人信息
void Revise();              // 修改联系人信息
void Delete();              // 删除联系人
void showAll();             // 显示所有联系人

void showmenu() {
	cout << " _______________________________________________________________________________" << endl;
	cout << " 1.新增联络人     2.查询联络人      3.修改联络人信息     4.删除联络人         5.查看所有联络人    0.关闭 " << endl;
	cout << " _______________________________________________________________________________" << endl;
	cout << "如要继续操作，请输入对应功能前的数字（退出程序请输入0）：";
}


int main(){
	loadinfo();
	int choise = 0;
	cout << "                欢迎使用通讯录" << endl << "请选择服务：" << endl;
	showmenu();
	while(cin >> choise){
		if ( choise == 0 ){
			cout << "确认退出请输入 y ，否则输入任意其他字符" << endl;
			char ch;
			cin >> ch;
			if ( ch == 'y' )
				break;
			continue;
		}
		switch(choise){
		case 1: NewConnecter(); showmenu(); break;
		case 2: Inquire();  showmenu();   break;
		case 3: Revise();   showmenu();   break;
		case 4: Delete();   showmenu();   break;
		case 5: showAll();  showmenu();   break;
		default : cout << "输入有误，请重新输入操作:" << endl; showmenu(); break;
		}
	}
	storage();
	cout << "感谢您的使用，再见" << endl;
	system ( "pause" );
	return 0;
}

/* 添加新联系人 */
void NewConnecter(){
    People * peo = new People;
	cout << "--------------------------------------------------------------------" << endl;
	cout << "主选单-->新建联系人" << endl;
	cout << " 姓名：";
	cin >> peo->name;
	cout << " 号码：";
	cin >> peo->phone;
	cout << " 住址：";
	cin >> peo->address;
	cout << endl;
	Contacts.push_back( *peo );
	cout << "成功添加联络人！" << endl;
}

/* 查询联系人 */
void Inquire(){
	cout << "--------------------------------------------------------------------" << endl;
	cout << "主选单-->查询联络人" << endl;
	cout << "请输入联系人姓名：" << endl;
	string name;
	cin >> name;
	list< People >::iterator iter;
	for ( iter = Contacts.begin(); iter != Contacts.end(); iter++ ){
		if ( iter->name == name )
			break;
	}
	if ( iter == Contacts.end() )
		cout << "无法找到该联络人，请检查输入是否有误" << endl;
	else{
		cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << "姓名：" << iter->name << endl;
		cout << "号码：" << iter->phone << endl;
		cout << "住址：" << iter->address << endl;
		cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	}
}

/* 修改联系人 */
void Revise(){
	cout << "--------------------------------------------------------------------" << endl;
	cout << "主选单-->修改联络人信息" << endl;
	cout << "请输入联络人姓名：" << endl;
	string name;
	cin >> name;
	list< People >::iterator iter;
	for ( iter = Contacts.begin(); iter != Contacts.end(); iter++ ){
		if ( name == iter->name )
			break;
	}
	if ( iter == Contacts.end() )
		cout << "无法找到该联络人，请检查输入是否有误" << endl;
	else{
		cout << "请选择要修改的内容：" << endl;
		cout << "修改姓名，请输入1； 修改号码，请输入2；修改地址，请输入3；返回请输入0" << endl;
		int choise = 0;
		while( cin >> choise ) {
			if ( choise == 0 )
				break;
			switch ( choise ) {
				case 1: cout << "请输入" << iter->name << "的新姓名：" ;cin >> iter->name; cout << "修改成功！" << endl; break;
				case 2: cout << "请输入" << iter->phone << "的新号码：" ;cin >> iter->phone; cout << "修改成功！" << endl; break;
				case 3: cout << "请输入" << iter->address << "的新住址：" ;cin >> iter->address; cout << "修改成功！" << endl; break;
				default:cout << "输入有误,请重新输入！" << endl; break;
			}
		}

	}
}

/* 删除联系人 */
void Delete(){
	cout << "--------------------------------------------------------------------" << endl;
	cout << "主选单-->删除联络人" << endl;
	cout << "请输入联络人姓名：" << endl;
	string name;
	cin >> name;
	list< People >::iterator iter;
	for ( iter = Contacts.begin(); iter != Contacts.end(); iter++ )
		if ( iter->name == name )
			break;
	if ( iter == Contacts.end() )
		cout << "未找到联络人，请检查输入是否有误" << endl;
	else {
		Contacts.erase( iter );
		cout << "删除成功！" << endl;
	}
}

/* 显示所有联系人 */
void showAll(){
    cout << endl;
	cout << "--------------------------------------------------------------------" << endl;
	cout << "主选单-->联络人信息" << endl;
	if ( Contacts.empty() ){
		cout << "亲，还没有添加联络人呢" << endl;
		return;
	}
	list< People >::iterator iter;
    cout << "                            我的联络人" << endl;
    cout << "_____________________________________________________________________" << endl;
	cout << "   姓名        号码                      住址             "  << endl;
	cout << "_____________________________________________________________________" << endl;
	for ( iter = Contacts.begin(); iter != Contacts.end(); iter++ ){
		cout << setw(9) << iter->name << setw(14) << iter->phone << setw(30) << iter->address << endl;
		cout << "_____________________________________________________________________" << endl;
	}
}
