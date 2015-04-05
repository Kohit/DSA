/*
 * air.cpp
 *
 *  Created on: 2014年10月31日
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
	cout << "首页->订票" << "   条款" << endl << "   blablabla..." << endl << endl << "是否同意条款并继续？(yes/no)" << endl;
	cin >> ch; if ( ch == "no" ) return ;
	string city, name, id;
	cout << "请输入姓名" << endl; cin >> name;
	cout << "请输入证件号" << endl; cin >> id;
	cout << "请输入地点" << endl; cin >> city;
	int hour = 0, min = 0;
	cout << "请输入最早起飞时间，小时和分钟之间留一空格" << endl; cin >> hour >> min;
	bool none = true;
	for ( iterator(Flight) iter = flight.begin(); iter != flight.end(); iter = iter->succ )
		if ( iter->value.city == city && iter->value.size < iter->value.totalseat && iter->value.thour >= hour && iter->value.tmin >= min ){
			cout << "航班号： " << iter->value.airnum << "  目的城市： " << iter->value.city << "  起飞时间： " << iter->value.thour << "时" << iter->value.tmin << "分" << "   飞行时间： " << iter->value.ptime << endl << "剩余座位： " << iter->value.totalseat - iter->value.size << "  票价： " << iter->value.price << "  折扣： " << iter->value.discount << "%" << endl;
			cout << "是否确认购票？(yes/no)" << endl; cin >> ch;
			if ( ch == "yes" ){
				iter->value.size++;
				iter->value.customer.insertAsLast( Customer( name, id, city, iter->value.airnum, iter->value.size, iter->value.thour, iter->value.tmin ) );
				customer.insertAsLast( Customer( name, id, city, iter->value.airnum, iter->value.size, iter->value.thour, iter->value.tmin ) );
				cout << "您已成功订票，航班为： " << iter->value.airnum << "  目的城市： " << iter->value.city << "  起飞时间： " << iter->value.thour << "时" << iter->value.tmin << "分" << "   飞行时间： " << iter->value.ptime << "  座位号： " << iter->value.size << endl;
				cout << "请留意登机时间，以免错过航班" << endl; break;
				none = false;
			}
		}
	if ( none ){ cout << "未查询到满足条件的航班，请修改条件重新查询" << endl; Booking(); }
}

void refund(){
	string ch, id;
	cout << "首页->退票" << endl << "是否继续？(yes/no)" << endl;
	cin >> ch; if ( ch == "no" ) return ;
	cout << "请输入证件号" << endl; cin >> id;
	bool none = true;
	for ( iterator(Customer) iter = customer.begin(); iter != customer.end(); iter = iter->succ )
		if ( iter->value.check( id ) ){
			cout << "航班号： " << iter->value.airnum << "   目的城市： " << iter->value.city << "   起飞时间： " << iter->value.hour << "时" << iter->value.min << "分" << "   座位号： " << iter->value.seat << endl;
			cout << "是否确认退票？(yes/no)" << endl; cin >> ch;
			if ( ch == "yes" ){
				for ( iterator(Flight) iterf = flight.begin(); iterf != flight.end(); iterf = iterf->succ )
					if ( iterf->value.airnum == iter->value.airnum ){
						for ( iterator(Customer) iterc = iterf->value.customer.begin(); iterc != iterf->value.customer.end(); iterc = iterc->succ )
							if( iterc->value.check( id ) ){ iterf->value.customer.remove( iterc ); iterf->value.size--; break; }
						break;
					}
				customer.remove( iter ); cout << "退票成功!" << endl; break;
			}
			none = false;
		}
	if ( none ){ cout << "未查询到证件号，请重试" << endl; refund(); }
}

void searchFlight(){
	string ch, city;
	cout << "首页->航班查询" << endl << "是否继续？(yes/no)" << endl;
	cin >> ch; if ( ch == "no" ) return ;
	cout << "请输入目的城市" << endl; cin >> city;
	printf ( "%10s %10s %10s %10s %6s %8s\n", "航班号", "起飞时间", "飞行时间", "剩余座位", "票价", "折扣" );
	bool none = true;
	for ( iterator( Flight ) iter = flight.begin(); iter != flight.end(); iter = iter->succ ){
		if ( iter->value.city == city ){
			printf ( "%10s %5d:%-5d %8.1f %8d %8d %8d%%\n", iter->value.airnum.c_str(), iter->value.thour, iter->value.tmin, iter->value.ptime, iter->value.totalseat - iter->value.size, iter->value.price, iter->value.discount );
			none = false;
		}
	}
	if ( none ){ cout << "无" << endl << "暂未查询到该城市的航班，请重试" << endl; searchFlight(); }
}

void flightInfo(){
	cout << "航班信息" << endl;
	printf ( "%10s %10s %10s %10s %10s %6s %8s\n", "航班号","目的城市", "起飞时间", "飞行时间", "剩余座位", "票价", "折扣" );
	bool none = true;
	for ( iterator( Flight ) iter = flight.begin(); iter != flight.end(); iter = iter->succ ){
		printf ( "%10s %10s %5d:%-5d %8.1f %8d %8d %8d%%\n", iter->value.airnum.c_str(), iter->value.city.c_str(), iter->value.thour, iter->value.tmin, iter->value.ptime, iter->value.totalseat - iter->value.size, iter->value.price, iter->value.discount );
		none = false;
	}
	if ( none ){ cout << "暂无可用航班" << endl; }
}

void checkInfo(){
	string ch, id;
	cout << "首页->订票查询" << endl << "是否继续？(yes/no)" << endl;
	cin >> ch; if ( ch == "no" ) return ;
	cout << "请输入证件号" << endl; cin >> id;
	iterator(Customer) iter = customer.begin();
	for ( ; iter != customer.end(); iter = iter->succ ){
		if ( iter->value.check( id ) ){
			cout << "航班号： " << iter->value.airnum << "   目的城市： " << iter->value.city << "   起飞时间：  " << iter->value.hour << "时" << iter->value.min << "分" << "   座位号： " << iter->value.seat << endl;
			break;
		}
	}
	if ( iter == customer.end() ){ cout << "未查询到该证件号，请重试" << endl; checkInfo(); }
}

void init(){
	flight.insertAsLast( Flight( "广州", "MU2383", 15, 55, 180, 2.5, 528, 40 ) );
	flight.insertAsLast( Flight( "广州", "CZ3218", 17, 20, 189, 2.2, 825, 60 ) );
	flight.insertAsLast( Flight( "上海", "FM9304", 7, 35, 189, 2.1, 466, 40 ) );
	flight.insertAsLast( Flight( "上海", "FM9312", 14, 30, 189, 2.2, 1000, 99 ) );
	flight.insertAsLast( Flight( "上海", "CZ3595", 20, 0, 180, 2.2, 961, 80 ) );
	flight.insertAsLast( Flight( "西安", "MU2283", 11, 25, 180, 2.2, 528, 40 ) );
	flight.insertAsLast( Flight( "北京", "CA1322", 13, 30, 400, 3.1, 1066, 74 ) );
	flight.insertAsLast( Flight( "香港", "KA783", 9, 50, 420, 1.1, 1865, 100 ) );
}

int main(){
	init();   // 增加默认航班，for demo
	cout << "异次元的空之航班客户端" << endl;
	while( 1 ){
		cout << "请选择" << endl;
		cout << "1. 订票" << endl << "2. 退票" << endl << "3. 航班查询" << endl << "4. 航班信息" << endl << "5. 订票查询" << endl << "0. 退出" << endl << "请输入相应的数字" << endl;
		int option = 0; cin >> option;
		switch( option ){
		case 0: return 0; break;
		case 1: Booking(); break;
		case 2: refund(); break;
		case 3: searchFlight(); break;
		case 4: flightInfo(); break;
		case 5: checkInfo(); break;
		default: cout << "输入有误，请重新输入选项对应得数字" << endl; break;
		}
	}
	return 0;
}
