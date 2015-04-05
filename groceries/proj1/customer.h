/*
 * customer.h
 *
 *  Created on: 2014Äê10ÔÂ31ÈÕ
 *      Author: kohit
 */

class Customer{
private:
	string name, id;
public:
	string city, airnum;
	int seat, hour, min;
	Customer(){}
	Customer( string _n, string _i, string _c = NULL, string _air = NULL, int _s = 0, int _h = 0, int _min = 0 ):name( _n ), id( _i ), city(_c), airnum( _air ), seat( _s ), hour(_h), min(_min){}
	Customer( const Customer & e ){
		name = e.name; id = e.id; airnum = e.airnum; seat = e.seat; hour = e.hour; min = e.min; city = e.city;
	}
	bool check( string & e ){ return id == e; }
	string Name() const { return name; }
};
