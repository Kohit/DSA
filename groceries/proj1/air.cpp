/*
 * air.cpp
 *
 *  Created on: 2014��10��31��
 *      Author: kohit
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
#include "customer.h"
#include "list.h"
#include "flight.h"
#define iterator(T) Node<T>*

List<Customer> customer;
List<Flight> flight;

void Booking(){
	string ch;
	cout << "��ҳ->��Ʊ" << "   ����" << endl << "   blablabla..." << endl << endl << "�Ƿ�ͬ�����������(yes/no)" << endl;
	cin >> ch; if ( ch == "no" ) return ;
	string city, name, id;
	cout << "����������" << endl; cin >> name;
	cout << "������֤����" << endl; cin >> id;
	cout << "������ص�" << endl; cin >> city;
	int hour = 0, min = 0;
	cout << "�������������ʱ�䣬Сʱ�ͷ���֮����һ�ո�" << endl; cin >> hour >> min;
	bool none = true;
	for ( iterator(Flight) iter = flight.begin(); iter != flight.end(); iter = iter->succ )
		if ( iter->value.city == city && iter->value.size < iter->value.totalseat && iter->value.thour >= hour && iter->value.tmin >= min ){
			cout << "����ţ� " << iter->value.airnum << "  Ŀ�ĳ��У� " << iter->value.city << "  ���ʱ�䣺 " << iter->value.thour << "ʱ" << iter->value.tmin << "��" << "   ����ʱ�䣺 " << iter->value.ptime << endl << "ʣ����λ�� " << iter->value.totalseat - iter->value.size << "  Ʊ�ۣ� " << iter->value.price << "  �ۿۣ� " << iter->value.discount << "%" << endl;
			cout << "�Ƿ�ȷ�Ϲ�Ʊ��(yes/no)" << endl; cin >> ch;
			if ( ch == "yes" ){
				iter->value.size++;
				iter->value.customer.insertAsLast( Customer( name, id, city, iter->value.airnum, iter->value.size, iter->value.thour, iter->value.tmin ) );
				customer.insertAsLast( Customer( name, id, city, iter->value.airnum, iter->value.size, iter->value.thour, iter->value.tmin ) );
				cout << "���ѳɹ���Ʊ������Ϊ�� " << iter->value.airnum << "  Ŀ�ĳ��У� " << iter->value.city << "  ���ʱ�䣺 " << iter->value.thour << "ʱ" << iter->value.tmin << "��" << "   ����ʱ�䣺 " << iter->value.ptime << "  ��λ�ţ� " << iter->value.size << endl;
				cout << "������ǻ�ʱ�䣬����������" << endl; break;
				none = false;
			}
		}
	if ( none ){ cout << "δ��ѯ�����������ĺ��࣬���޸��������²�ѯ" << endl; Booking(); }
}

void refund(){
	string ch, id;
	cout << "��ҳ->��Ʊ" << endl << "�Ƿ������(yes/no)" << endl;
	cin >> ch; if ( ch == "no" ) return ;
	cout << "������֤����" << endl; cin >> id;
	bool none = true;
	for ( iterator(Customer) iter = customer.begin(); iter != customer.end(); iter = iter->succ )
		if ( iter->value.check( id ) ){
			cout << "����ţ� " << iter->value.airnum << "   Ŀ�ĳ��У� " << iter->value.city << "   ���ʱ�䣺 " << iter->value.hour << "ʱ" << iter->value.min << "��" << "   ��λ�ţ� " << iter->value.seat << endl;
			cout << "�Ƿ�ȷ����Ʊ��(yes/no)" << endl; cin >> ch;
			if ( ch == "yes" ){
				for ( iterator(Flight) iterf = flight.begin(); iterf != flight.end(); iterf = iterf->succ )
					if ( iterf->value.airnum == iter->value.airnum ){
						for ( iterator(Customer) iterc = iterf->value.customer.begin(); iterc != iterf->value.customer.end(); iterc = iterc->succ )
							if( iterc->value.check( id ) ){ iterf->value.customer.remove( iterc ); iterf->value.size--; break; }
						break;
					}
				customer.remove( iter ); cout << "��Ʊ�ɹ�!" << endl; break;
			}
			none = false;
		}
	if ( none ){ cout << "δ��ѯ��֤���ţ�������" << endl; refund(); }
}

void searchFlight(){
	string ch, city;
	cout << "��ҳ->�����ѯ" << endl << "�Ƿ������(yes/no)" << endl;
	cin >> ch; if ( ch == "no" ) return ;
	cout << "������Ŀ�ĳ���" << endl; cin >> city;
	printf ( "%10s %10s %10s %10s %6s %8s\n", "�����", "���ʱ��", "����ʱ��", "ʣ����λ", "Ʊ��", "�ۿ�" );
	bool none = true;
	for ( iterator( Flight ) iter = flight.begin(); iter != flight.end(); iter = iter->succ ){
		if ( iter->value.city == city ){
			printf ( "%10s %5d:%-5d %8.1f %8d %8d %8d%%\n", iter->value.airnum.c_str(), iter->value.thour, iter->value.tmin, iter->value.ptime, iter->value.totalseat - iter->value.size, iter->value.price, iter->value.discount );
			none = false;
		}
	}
	if ( none ){ cout << "��" << endl << "��δ��ѯ���ó��еĺ��࣬������" << endl; searchFlight(); }
}

void flightInfo(){
	cout << "������Ϣ" << endl;
	printf ( "%10s %10s %10s %10s %10s %6s %8s\n", "�����","Ŀ�ĳ���", "���ʱ��", "����ʱ��", "ʣ����λ", "Ʊ��", "�ۿ�" );
	bool none = true;
	for ( iterator( Flight ) iter = flight.begin(); iter != flight.end(); iter = iter->succ ){
		printf ( "%10s %10s %5d:%-5d %8.1f %8d %8d %8d%%\n", iter->value.airnum.c_str(), iter->value.city.c_str(), iter->value.thour, iter->value.tmin, iter->value.ptime, iter->value.totalseat - iter->value.size, iter->value.price, iter->value.discount );
		none = false;
	}
	if ( none ){ cout << "���޿��ú���" << endl; }
}

void checkInfo(){
	string ch, id;
	cout << "��ҳ->��Ʊ��ѯ" << endl << "�Ƿ������(yes/no)" << endl;
	cin >> ch; if ( ch == "no" ) return ;
	cout << "������֤����" << endl; cin >> id;
	iterator(Customer) iter = customer.begin();
	for ( ; iter != customer.end(); iter = iter->succ ){
		if ( iter->value.check( id ) ){
			cout << "����ţ� " << iter->value.airnum << "   Ŀ�ĳ��У� " << iter->value.city << "   ���ʱ�䣺  " << iter->value.hour << "ʱ" << iter->value.min << "��" << "   ��λ�ţ� " << iter->value.seat << endl;
			break;
		}
	}
	if ( iter == customer.end() ){ cout << "δ��ѯ����֤���ţ�������" << endl; checkInfo(); }
}

void init(){
	flight.insertAsLast( Flight( "����", "MU2383", 15, 55, 180, 2.5, 528, 40 ) );
	flight.insertAsLast( Flight( "����", "CZ3218", 17, 20, 189, 2.2, 825, 60 ) );
	flight.insertAsLast( Flight( "�Ϻ�", "FM9304", 7, 35, 189, 2.1, 466, 40 ) );
	flight.insertAsLast( Flight( "�Ϻ�", "FM9312", 14, 30, 189, 2.2, 1000, 99 ) );
	flight.insertAsLast( Flight( "�Ϻ�", "CZ3595", 20, 0, 180, 2.2, 961, 80 ) );
	flight.insertAsLast( Flight( "����", "MU2283", 11, 25, 180, 2.2, 528, 40 ) );
	flight.insertAsLast( Flight( "����", "CA1322", 13, 30, 400, 3.1, 1066, 74 ) );
	flight.insertAsLast( Flight( "���", "KA783", 9, 50, 420, 1.1, 1865, 100 ) );
}

int main(){
	init();   // ����Ĭ�Ϻ��࣬for demo
	cout << "���Ԫ�Ŀ�֮����ͻ���" << endl;
	while( 1 ){
		cout << "��ѡ��" << endl;
		cout << "1. ��Ʊ" << endl << "2. ��Ʊ" << endl << "3. �����ѯ" << endl << "4. ������Ϣ" << endl << "5. ��Ʊ��ѯ" << endl << "0. �˳�" << endl << "��������Ӧ������" << endl;
		int option = 0; cin >> option;
		switch( option ){
		case 0: return 0; break;
		case 1: Booking(); break;
		case 2: refund(); break;
		case 3: searchFlight(); break;
		case 4: flightInfo(); break;
		case 5: checkInfo(); break;
		default: cout << "������������������ѡ���Ӧ������" << endl; break;
		}
	}
	return 0;
}
