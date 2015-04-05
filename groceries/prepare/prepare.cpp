/*
 * prepare.cpp
 *
 *  Created on: 2014Äê3ÔÂ9ÈÕ
 *      Author: KoHit
 */
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class headquarter{
public:
	int strength;
	string warriors[100];
	int dragon, ninja, iceman, lion, wolf;
	headquarter (int life, int d, int n, int i, int l, int w){
		strength = life;
		dragon = d; ninja = n; iceman = i; lion = l; wolf = w;
	}
};

class Warriors{
	//int mark;
public:
	int strength;
	Warriors(int n){
		strength = n;
	}
};

int main(){
	int test = 0;
	cin >> test;
	for (int j = 1; j <= test; j++){

		int life = 0;
		cin >> life;
		int strength;
		int minstrength = 1000;
		cin >> strength;
		minstrength = strength;
		Warriors Dragon(strength);
		cin >> strength;
		if (strength < minstrength)
			minstrength = strength;
		Warriors Ninja(strength);
		cin >> strength;
		if (strength < minstrength)
			minstrength = strength;
		Warriors Iceman(strength);
		cin >> strength;
		if (strength < minstrength)
			minstrength = strength;
		Warriors Lion(strength);
		cin >> strength;
		if (strength < minstrength)
			minstrength = strength;
		Warriors Wolf(strength);

		headquarter RED(life, 0, 0, 0, 0, 0);
		headquarter BLUE(life, 0, 0, 0, 0, 0);

		string Rcatalog[100];
		string Bcatalog[100];

		int Rmark = 0, Rtime = 0;
		int Bmark = 0, Btime = 0;

		/* RED */
		while(RED.strength >= minstrength){
			// ICEMAN
			if (RED.strength >= Iceman.strength){
				RED.warriors[Rmark++] = "iceman";
				RED.iceman++;
				RED.strength -= Iceman.strength;
				char buf[5];
				char sbuf[5];
				char cbuf[5];
				sprintf(buf, "%d", Rmark);
				sprintf(sbuf, "%d", Iceman.strength);
				sprintf(cbuf, "%d", RED.iceman);
				Rcatalog[Rtime] = "red iceman ";
				Rcatalog[Rtime]+= buf;
				Rcatalog[Rtime]+= " born with strength ";
				Rcatalog[Rtime]+= sbuf;
				Rcatalog[Rtime]+= ",";
				Rcatalog[Rtime]+= cbuf;
				Rcatalog[Rtime]+= " iceman in red headquarter";
				Rtime++;
			}
			// LION
			if (RED.strength >= Lion.strength){
				RED.warriors[Rmark++] = "lion";
				RED.lion++;
				RED.strength -= Lion.strength;
				char buf[5];
				char sbuf[5];
				char cbuf[5];
				sprintf(buf, "%d", Rmark);
				sprintf(sbuf, "%d", Lion.strength);
				sprintf(cbuf, "%d", RED.lion);
				Rcatalog[Rtime] = "red lion ";
				Rcatalog[Rtime]+= buf;
				Rcatalog[Rtime]+= " born with strength ";
				Rcatalog[Rtime]+= sbuf;
				Rcatalog[Rtime]+= ",";
				Rcatalog[Rtime]+= cbuf;
				Rcatalog[Rtime]+= " lion in red headquarter";
				Rtime++;
			}
			// WOLF
			if (RED.strength >= Wolf.strength){
				RED.warriors[Rmark++] = "wolf";
				RED.wolf++;
				RED.strength -= Wolf.strength;
				char buf[5];
				char sbuf[5];
				char cbuf[5];
				sprintf(buf, "%d", Rmark);
				sprintf(sbuf, "%d", Wolf.strength);
				sprintf(cbuf, "%d", RED.wolf);
				Rcatalog[Rtime] = "red wolf ";
				Rcatalog[Rtime]+= buf;
				Rcatalog[Rtime]+= " born with strength ";
				Rcatalog[Rtime]+= sbuf;
				Rcatalog[Rtime]+= ",";
				Rcatalog[Rtime]+= cbuf;
				Rcatalog[Rtime]+= " wolf in red headquarter";
				Rtime++;
			}
			// NINJA
			if (RED.strength >= Ninja.strength){
				RED.warriors[Rmark++] = "ninja";
				RED.ninja++;
				RED.strength -= Ninja.strength;
				char buf[5];
				char sbuf[5];
				char cbuf[5];
				sprintf(buf, "%d", Rmark);
				sprintf(sbuf, "%d", Ninja.strength);
				sprintf(cbuf, "%d", RED.ninja);
				Rcatalog[Rtime] = "red ninja ";
				Rcatalog[Rtime]+= buf;
				Rcatalog[Rtime]+= " born with strength ";
				Rcatalog[Rtime]+= sbuf;
				Rcatalog[Rtime]+= ",";
				Rcatalog[Rtime]+= cbuf;
				Rcatalog[Rtime]+= " ninja in red headquarter";
				Rtime++;
			}
			// DRAGON
			if (RED.strength >= Dragon.strength){
				RED.warriors[Rmark++] = "dragon";
				RED.dragon++;
				RED.strength -= Dragon.strength;
				char buf[5];
				char sbuf[5];
				char cbuf[5];
				sprintf(buf, "%d", Rmark);
				sprintf(sbuf, "%d", Dragon.strength);
				sprintf(cbuf, "%d", RED.dragon);
				Rcatalog[Rtime] = "red dragon ";
				Rcatalog[Rtime]+= buf;
				Rcatalog[Rtime]+= " born with strength ";
				Rcatalog[Rtime]+= sbuf;
				Rcatalog[Rtime]+= ",";
				Rcatalog[Rtime]+= cbuf;
				Rcatalog[Rtime]+= " dragon in red headquarter";
				Rtime++;
			}
		}
		// END RED
		Rcatalog[Rtime] = "red headquarter stops making warriors";

		/* BLUE */
		while(BLUE.strength >= minstrength){
			// LION
			if (BLUE.strength >= Lion.strength){
				BLUE.warriors[Bmark++] = "lion";
				BLUE.lion++;
				BLUE.strength -= Lion.strength;
				char buf[5];
				char sbuf[5];
				char cbuf[5];
				sprintf(buf, "%d", Bmark);
				sprintf(sbuf, "%d", Lion.strength);
				sprintf(cbuf, "%d", BLUE.lion);
				Bcatalog[Btime] = "blue lion ";
				Bcatalog[Btime]+= buf;
				Bcatalog[Btime]+= " born with strength ";
				Bcatalog[Btime]+= sbuf;
				Bcatalog[Btime]+= ",";
				Bcatalog[Btime]+= cbuf;
				Bcatalog[Btime]+= " lion in blue headquarter";
				Btime++;
			}
			// DRAGON
			if (BLUE.strength >= Dragon.strength){
				BLUE.warriors[Bmark++] = "dragon";
				BLUE.dragon++;
				BLUE.strength -= Dragon.strength;
				char buf[5];
				char sbuf[5];
				char cbuf[5];
				sprintf(buf, "%d", Bmark);
				sprintf(sbuf, "%d", Dragon.strength);
				sprintf(cbuf, "%d", BLUE.dragon);
				Bcatalog[Btime] = "blue dragon ";
				Bcatalog[Btime]+= buf;
				Bcatalog[Btime]+= " born with strength ";
				Bcatalog[Btime]+= sbuf;
				Bcatalog[Btime]+= ",";
				Bcatalog[Btime]+= cbuf;
				Bcatalog[Btime]+= " dragon in blue headquarter";
				Btime++;
			}
			// NINJA
			if (BLUE.strength >= Ninja.strength){
				BLUE.warriors[Bmark++] = "ninja";
				BLUE.ninja++;
				BLUE.strength -= Ninja.strength;
				char buf[5];
				char sbuf[5];
				char cbuf[5];
				sprintf(buf, "%d", Bmark);
				sprintf(sbuf, "%d", Ninja.strength);
				sprintf(cbuf, "%d", BLUE.ninja);
				Bcatalog[Btime] = "blue ninja ";
				Bcatalog[Btime]+= buf;
				Bcatalog[Btime]+= " born with strength ";
				Bcatalog[Btime]+= sbuf;
				Bcatalog[Btime]+= ",";
				Bcatalog[Btime]+= cbuf;
				Bcatalog[Btime]+= " ninja in blue headquarter";
				Btime++;
			}
			// ICEMAN
			if (BLUE.strength >= Iceman.strength){
				BLUE.warriors[Bmark++] = "iceman";
				BLUE.iceman++;
				BLUE.strength -= Iceman.strength;
				char buf[5];
				char sbuf[5];
				char cbuf[5];
				sprintf(buf, "%d", Bmark);
				sprintf(sbuf, "%d", Iceman.strength);
				sprintf(cbuf, "%d", BLUE.iceman);
				Bcatalog[Btime] = "blue iceman ";
				Bcatalog[Btime]+= buf;
				Bcatalog[Btime]+= " born with strength ";
				Bcatalog[Btime]+= sbuf;
				Bcatalog[Btime]+= ",";
				Bcatalog[Btime]+= cbuf;
				Bcatalog[Btime]+= " iceman in blue headquarter";
				Btime++;
			}
			// WOLF
			if (BLUE.strength >= Wolf.strength){
				BLUE.warriors[Bmark++] = "wolf";
				BLUE.wolf++;
				BLUE.strength -= Wolf.strength;
				char buf[5];
				char sbuf[5];
				char cbuf[5];
				sprintf(buf, "%d", Bmark);
				sprintf(sbuf, "%d", Wolf.strength);
				sprintf(cbuf, "%d", BLUE.wolf);
				Bcatalog[Btime] = "blue wolf ";
				Bcatalog[Btime]+= buf;
				Bcatalog[Btime]+= " born with strength ";
				Bcatalog[Btime]+= sbuf;
				Bcatalog[Btime]+= ",";
				Bcatalog[Btime]+= cbuf;
				Bcatalog[Btime]+= " wolf in blue headquarter";
				Btime++;
			}
		}
		// END BLUE
		Bcatalog[Btime] = "blue headquarter stops making warriors";

		int Finaltime = Btime > Rtime ? Btime : Rtime;
		/* OUTPUT */

		cout << "Case:" << j << endl;
		for (int i = 0; i <= Finaltime; i++){
			if (i <= Rtime){
				if (i > 99)
					cout << i << " " << Rcatalog[i] << endl;
				else if (i > 9)
					cout << "0" << i << " " << Rcatalog[i] << endl;
				else
					cout << "00" << i << " " << Rcatalog[i] << endl;
			}
			if (i <= Btime){
				if (i > 99)
					cout << "i" << " " << Bcatalog[i] << endl;
				else if (i > 9)
					cout << "0" << i << " " << Bcatalog[i] << endl;
				else
					cout << "00" << i << " " << Bcatalog[i] << endl;
			}
		}
	}
	return 0;
}

