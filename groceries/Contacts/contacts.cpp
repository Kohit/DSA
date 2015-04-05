/*
 * connecter.cpp
 *
 *  Created on: 2014��1��8��
 *   Modify on: 2014��5��23��
 *      Author: FongYoung Vane
 */
 /*
 * ���ܼ�飺
 * ���������ʵ����ӣ���ѯ���޸ģ�ɾ�������˵�
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
	friend void NewConnecter();        // �������ϵ����Ϣ
	friend void Inquire();             // ��ѯ��ϵ����Ϣ
	friend void Revise();              // �޸���ϵ����Ϣ
	friend void Delete();              // ɾ����ϵ��
	friend void showAll();             // ��ʾ������ϵ��
};

list< People > Contacts;

/* ���ܺ��� */
void loadinfo(){
	cout << "loading..." << endl;
	FILE * f = fopen( "data.dat", "r" );
	if ( !f ){
		cout << "��¼Ϊ�գ�" << endl;
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
	cout << "���ڱ����¼" << endl;
	FILE * f = fopen( "data.dat", "w" );
	list< People >::iterator iter;
	for ( iter = Contacts.begin(); iter != Contacts.end(); iter++ ) {
		fprintf( f, "%s %s %s\n", iter->name.c_str(), iter->phone.c_str(), iter->address.c_str() );
	}
	cout << "����ɹ���" << endl;
	fclose( f );
}
void NewConnecter();        // �������ϵ����Ϣ
void Inquire();             // ��ѯ��ϵ����Ϣ
void Revise();              // �޸���ϵ����Ϣ
void Delete();              // ɾ����ϵ��
void showAll();             // ��ʾ������ϵ��

void showmenu() {
	cout << " _______________________________________________________________________________" << endl;
	cout << " 1.����������     2.��ѯ������      3.�޸���������Ϣ     4.ɾ��������         5.�鿴����������    0.�ر� " << endl;
	cout << " _______________________________________________________________________________" << endl;
	cout << "��Ҫ�����������������Ӧ����ǰ�����֣��˳�����������0����";
}


int main(){
	loadinfo();
	int choise = 0;
	cout << "                ��ӭʹ��ͨѶ¼" << endl << "��ѡ�����" << endl;
	showmenu();
	while(cin >> choise){
		if ( choise == 0 ){
			cout << "ȷ���˳������� y �������������������ַ�" << endl;
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
		default : cout << "���������������������:" << endl; showmenu(); break;
		}
	}
	storage();
	cout << "��л����ʹ�ã��ټ�" << endl;
	system ( "pause" );
	return 0;
}

/* �������ϵ�� */
void NewConnecter(){
    People * peo = new People;
	cout << "--------------------------------------------------------------------" << endl;
	cout << "��ѡ��-->�½���ϵ��" << endl;
	cout << " ������";
	cin >> peo->name;
	cout << " ���룺";
	cin >> peo->phone;
	cout << " סַ��";
	cin >> peo->address;
	cout << endl;
	Contacts.push_back( *peo );
	cout << "�ɹ���������ˣ�" << endl;
}

/* ��ѯ��ϵ�� */
void Inquire(){
	cout << "--------------------------------------------------------------------" << endl;
	cout << "��ѡ��-->��ѯ������" << endl;
	cout << "��������ϵ��������" << endl;
	string name;
	cin >> name;
	list< People >::iterator iter;
	for ( iter = Contacts.begin(); iter != Contacts.end(); iter++ ){
		if ( iter->name == name )
			break;
	}
	if ( iter == Contacts.end() )
		cout << "�޷��ҵ��������ˣ����������Ƿ�����" << endl;
	else{
		cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
		cout << "������" << iter->name << endl;
		cout << "���룺" << iter->phone << endl;
		cout << "סַ��" << iter->address << endl;
		cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	}
}

/* �޸���ϵ�� */
void Revise(){
	cout << "--------------------------------------------------------------------" << endl;
	cout << "��ѡ��-->�޸���������Ϣ" << endl;
	cout << "������������������" << endl;
	string name;
	cin >> name;
	list< People >::iterator iter;
	for ( iter = Contacts.begin(); iter != Contacts.end(); iter++ ){
		if ( name == iter->name )
			break;
	}
	if ( iter == Contacts.end() )
		cout << "�޷��ҵ��������ˣ����������Ƿ�����" << endl;
	else{
		cout << "��ѡ��Ҫ�޸ĵ����ݣ�" << endl;
		cout << "�޸�������������1�� �޸ĺ��룬������2���޸ĵ�ַ��������3������������0" << endl;
		int choise = 0;
		while( cin >> choise ) {
			if ( choise == 0 )
				break;
			switch ( choise ) {
				case 1: cout << "������" << iter->name << "����������" ;cin >> iter->name; cout << "�޸ĳɹ���" << endl; break;
				case 2: cout << "������" << iter->phone << "���º��룺" ;cin >> iter->phone; cout << "�޸ĳɹ���" << endl; break;
				case 3: cout << "������" << iter->address << "����סַ��" ;cin >> iter->address; cout << "�޸ĳɹ���" << endl; break;
				default:cout << "��������,���������룡" << endl; break;
			}
		}

	}
}

/* ɾ����ϵ�� */
void Delete(){
	cout << "--------------------------------------------------------------------" << endl;
	cout << "��ѡ��-->ɾ��������" << endl;
	cout << "������������������" << endl;
	string name;
	cin >> name;
	list< People >::iterator iter;
	for ( iter = Contacts.begin(); iter != Contacts.end(); iter++ )
		if ( iter->name == name )
			break;
	if ( iter == Contacts.end() )
		cout << "δ�ҵ������ˣ����������Ƿ�����" << endl;
	else {
		Contacts.erase( iter );
		cout << "ɾ���ɹ���" << endl;
	}
}

/* ��ʾ������ϵ�� */
void showAll(){
    cout << endl;
	cout << "--------------------------------------------------------------------" << endl;
	cout << "��ѡ��-->��������Ϣ" << endl;
	if ( Contacts.empty() ){
		cout << "�ף���û�������������" << endl;
		return;
	}
	list< People >::iterator iter;
    cout << "                            �ҵ�������" << endl;
    cout << "_____________________________________________________________________" << endl;
	cout << "   ����        ����                      סַ             "  << endl;
	cout << "_____________________________________________________________________" << endl;
	for ( iter = Contacts.begin(); iter != Contacts.end(); iter++ ){
		cout << setw(9) << iter->name << setw(14) << iter->phone << setw(30) << iter->address << endl;
		cout << "_____________________________________________________________________" << endl;
	}
}
