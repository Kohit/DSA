/*
 * ass2.cpp
 *
 *  Created on: 2014��3��27��
 *      Author: KoHit
 */
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int  WARRIOR_NUM = 5;

/*
�췽˾����� iceman��lion��wolf��ninja��dragon ��˳��������ʿ��
����˾����� lion��dragon��ninja��iceman��wolf ��˳��������ʿ��
��ʿ�������� 0 dragon 1 ninja 2 iceman 3 lion 4 wolf
*/

class Headquarter;
class Warrior{
protected:
	int mark;                                // ��ʿ�ı��
	string name;
	Headquarter *pHeadquarter;               // ÿ����ʿ����һ��master
public:
	static int initialLifeValue[WARRIOR_NUM];// ÿ����ʿ�ĳ�ʼ������ֵ
	virtual void PrintResult( int ntime ) = 0;
};

class dragon: public Warrior{
	float morale;
	string weapon;
public:
	static int LifeValue;
	void PrintResult( int ntime );
	dragon( Headquarter *p, int mark_);
};

class ninja: public Warrior{
	string weapon1, weapon2;
public:
	static int LifeValue;
	void PrintResult( int ntime );
	ninja( Headquarter *p, int mark_);
};

class iceman: public Warrior{
	string weapon;
public:
	static int LifeValue;
	void PrintResult( int ntime );
	iceman( Headquarter *p, int mark_);
};

class lion: public Warrior{
	int loyalty;
public:
	static int LifeValue;
	void PrintResult( int ntime );
	lion( Headquarter *p, int mark_);
};

class wolf: public Warrior{
public:
	static int LifeValue;
	void PrintResult( int ntime );
	wolf ( Headquarter *p, int mark_);
};

class Headquarter{
	int color;
	int currentMW;      // ��ǰ��������Warrior
	bool stopped;
	Warrior * pWarriors[1000];
public:
	int totalWarrior, totalLife;
	friend class Warrior;
	int warriorNum[WARRIOR_NUM]; //���ÿ����ʿ������
	static int makingSeq[2][WARRIOR_NUM]; //��ʿ������˳������
	void Init(int color_, int lv);
	~Headquarter () ;
	int Produce(int nTime);
	string GetColor();
};

string GetWeapon( int n ){
	string name;
	if (n == 0)
		return name = "sword";
	if (n == 1)
		return name = "bomb";
	return name = "arrow";
}

dragon::dragon( Headquarter *p, int mark_ ){
	mark = mark_;
	name = "dragon";
	pHeadquarter = p;
	morale = (float)(p->totalLife) / (float)(LifeValue);
	weapon = GetWeapon(mark % 3);
}
void dragon::PrintResult( int ntime ){
	string color =  pHeadquarter->GetColor();
	printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n"	,
			ntime, color.c_str(), name.c_str(), mark, LifeValue,
			pHeadquarter->warriorNum[0],name.c_str(),color.c_str());
	printf("It has a %s,and it's morale is %.2f\n", weapon.c_str(), morale);
}

ninja::ninja( Headquarter *p, int mark_ ){
	mark = mark_;
	name = "ninja";
	pHeadquarter = p;
	weapon1 = GetWeapon(mark % 3);
	weapon2 = GetWeapon((mark + 1) % 3);
}
void ninja::PrintResult( int ntime ){
	string color =  pHeadquarter->GetColor();
	printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n"	,
			ntime, color.c_str(), name.c_str(), mark, LifeValue,
			pHeadquarter->warriorNum[1],name.c_str(),color.c_str());
	printf("It has a %s and a %s\n", weapon1.c_str(), weapon2.c_str());
}

iceman::iceman( Headquarter *p, int mark_ ){
	mark = mark_;
	name = "iceman";
	pHeadquarter = p;
	weapon = GetWeapon(mark % 3);
}
void iceman::PrintResult( int ntime ){
	string color =  pHeadquarter->GetColor();
	printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n"	,
			ntime, color.c_str(), name.c_str(), mark, LifeValue,
			pHeadquarter->warriorNum[2],name.c_str(),color.c_str());
	printf("It has a %s\n", weapon.c_str());
}

lion::lion( Headquarter *p, int mark_ ){
	mark = mark_;
	name = "lion";
	pHeadquarter = p;
	loyalty = p->totalLife;
}
void lion::PrintResult( int ntime ){
	string color =  pHeadquarter->GetColor();
	printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n"	,
			ntime, color.c_str(), name.c_str(), mark, LifeValue,
			pHeadquarter->warriorNum[3],name.c_str(),color.c_str());
	printf("It's loyalty is %d\n", loyalty);
}

wolf::wolf( Headquarter *p, int mark_){
	mark = mark_;
	name = "wolf";
	pHeadquarter = p;
}
void wolf::PrintResult( int ntime ){
	string color =  pHeadquarter->GetColor();
	printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n"	,
			ntime, color.c_str(), name.c_str(), mark, LifeValue,
			pHeadquarter->warriorNum[4],name.c_str(),color.c_str());
}

void Headquarter::Init(int color_, int lv){
	color = color_;
	totalLife = lv;
	totalWarrior = 0;
	stopped = false;
	currentMW = 0;
	for( int i = 0;i < WARRIOR_NUM;i ++ )
		warriorNum[i] = 0;
}

string Headquarter::GetColor()
{
	if( color == 0)
		return "red";
	else
		return "blue";
}

Headquarter::~Headquarter () {
	for( int i = 0;i < totalWarrior;i ++ )
		delete pWarriors[i];
}

int Headquarter::Produce(int nTime)
{
	if( stopped )
		return 0;
	int searchingTimes = 0;
	while( Warrior::initialLifeValue[makingSeq[color][currentMW]] > totalLife &&
		searchingTimes < WARRIOR_NUM ) {
		// �����ǰ��ʿ��������ֵ����ʣ���������ֵ������û�б�����ÿ����ʿ
		currentMW = ( currentMW + 1 ) % WARRIOR_NUM ; // ������һ����ʿ
		searchingTimes ++;
	}
	// ��ʿ���� 0 dragon 1 ninja 2 iceman 3 lion 4 wolf
	int kindNo = makingSeq[color][currentMW];
	if( Warrior::initialLifeValue[kindNo] > totalLife ) {
		stopped = true;
		if( color == 0)
			printf("%03d red headquarter stops making warriors\n",nTime);
		else
			printf("%03d blue headquarter stops making warriors\n",nTime);
		return 0;
	}
	totalLife -= Warrior::initialLifeValue[kindNo];
	currentMW = ( currentMW + 1 ) % WARRIOR_NUM ;
	if (kindNo == 0)
		pWarriors[totalWarrior] = new dragon( this, totalWarrior+1 );
	else if(kindNo == 1)
		pWarriors[totalWarrior] = new ninja( this, totalWarrior+1 );
	else if(kindNo == 2)
		pWarriors[totalWarrior] = new iceman( this, totalWarrior+1 );
	else if(kindNo == 3)
		pWarriors[totalWarrior] = new lion( this, totalWarrior+1 );
	else if(kindNo == 4)
		pWarriors[totalWarrior] = new wolf( this, totalWarrior+1 );
	warriorNum[kindNo]++;
	pWarriors[totalWarrior]->PrintResult(nTime);
	totalWarrior ++;
	return 1;
}

int Headquarter::makingSeq[2][WARRIOR_NUM] = { { 2,3,4,1,0 },{3,0,1,2,4} }; //����˾���ʿ������˳������
int Warrior::initialLifeValue[WARRIOR_NUM];
int dragon::LifeValue;
int ninja::LifeValue;
int iceman::LifeValue;
int lion::LifeValue;
int wolf::LifeValue;

int main(){

	Headquarter RedHeadquarter, BlueHeadquarter;
	int test, life;
	scanf ("%d", &test);
	int nCaseNo = 1;
	while(test--){

		scanf ("%d", &life);
		for (int i = 0; i < WARRIOR_NUM; i++ )
			scanf ("%d", &Warrior::initialLifeValue[i]);

		dragon::LifeValue = Warrior::initialLifeValue[0];
		ninja::LifeValue = Warrior::initialLifeValue[1];
		iceman::LifeValue = Warrior::initialLifeValue[2];
		lion::LifeValue = Warrior::initialLifeValue[3];
		wolf::LifeValue = Warrior::initialLifeValue[4];

		RedHeadquarter.Init( 0, life );
		BlueHeadquarter.Init( 1, life );

		printf("Case:%d\n",nCaseNo++);

		int ntime = 0;
		while(true){
			int tmp1 = RedHeadquarter.Produce(ntime);
			int tmp2 = BlueHeadquarter.Produce(ntime);
			if ( !tmp1 && !tmp2 ) break;
			ntime++;
		}
	}
	return 0;
}
