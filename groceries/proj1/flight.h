/*
 * flight.h
 *
 *  Created on: 2014Äê10ÔÂ31ÈÕ
 *      Author: kohit
 */

class Flight{
public:
	string city, airnum;
	List<Customer> customer;
	int thour, tmin, totalseat, size, price, discount;
	float ptime;
	Flight(){}
	Flight( string _c, string _a, int _h, int _m, int _to, float _pt, int _pr, int _dis ){
		city = _c; airnum = _a; thour = _h; tmin = _m; totalseat = _to; ptime = _pt; size = 0;
		price = _pr; discount = _dis;
	}
	Flight( const Flight & e ){
		city = e.city; airnum = e.airnum; thour = e.thour; tmin = e.tmin;
		totalseat = e.totalseat; ptime = e.ptime; size = e.size; customer = e.customer;
		price = e.price; discount = e.discount;
	}
};
