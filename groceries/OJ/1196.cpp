/*
 * 1196.cpp
 *
 *  Created on: 2014��4��2��
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
	int mark;                     // ��ʿ�ı��
	string name;
	Headquarter *pHeadquarter;    // ÿ����ʿ����һ��master
public:
	static int initialLifeValue[WARRIOR_NUM];   // ÿ����ʿ�ĳ�ʼ������ֵ
	virtual void PrintResult( int ntime ) = 0;
};

class dragon: public Warrior{
public:
	static int LifeValue;
	void PrintResult( int ntime );
	dragon( Headquarter *p, int mark_);
};

class ninja: public Warrior{
public:
	static int LifeValue;
	void PrintResult( int ntime );
	ninja( Headquarter *p, int mark_);
};

class iceman: public Warrior{
public:
	static int LifeValue;
	void PrintResult( int ntime );
	iceman( Headquarter *p, int mark_);
};

class lion: public Warrior{
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
	int warriorNum[WARRIOR_NUM];          //���ÿ����ʿ������
	static int makingSeq[2][WARRIOR_NUM]; //��ʿ������˳������
	void Init(int color_, int lv);        //��ʼ��˾�
	~Headquarter () ;
	int Produce(int nTime);               //������ʿ
	string GetColor();
};

dragon::dragon( Headquarter *p, int mark_ ){
	mark = mark_;
	name = "dragon";
	pHeadquarter = p;
}
void dragon::PrintResult( int ntime ){
	string color =  pHeadquarter->GetColor();
	printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n"	,
			ntime, color.c_str(), name.c_str(), mark, LifeValue,
			pHeadquarter->warriorNum[0],name.c_str(),color.c_str());
}

ninja::ninja( Headquarter *p, int mark_ ){
	mark = mark_;
	name = "ninja";
	pHeadquarter = p;
}
void ninja::PrintResult( int ntime ){
	string color =  pHeadquarter->GetColor();
	printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n"	,
			ntime, color.c_str(), name.c_str(), mark, LifeValue,
			pHeadquarter->warriorNum[1],name.c_str(),color.c_str());
}

iceman::iceman( Headquarter *p, int mark_ ){
	mark = mark_;
	name = "iceman";
	pHeadquarter = p;
}
void iceman::PrintResult( int ntime ){
	string color =  pHeadquarter->GetColor();
	printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n"	,
			ntime, color.c_str(), name.c_str(), mark, LifeValue,
			pHeadquarter->warriorNum[2],name.c_str(),color.c_str());
}

lion::lion( Headquarter *p, int mark_ ){
	mark = mark_;
	name = "lion";
	pHeadquarter = p;
}
void lion::PrintResult( int ntime ){
	string color =  pHeadquarter->GetColor();
	printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n"	,
			ntime, color.c_str(), name.c_str(), mark, LifeValue,
			pHeadquarter->warriorNum[3],name.c_str(),color.c_str());
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
		searchingTimes < WARRIOR_NUM ) {     // �����ǰ��ʿ��������ֵ����ʣ���������ֵ������û�б�����ÿ����ʿ
		currentMW = ( currentMW + 1 ) % WARRIOR_NUM ;  // ������һ����ʿ
		searchingTimes ++;
	}
	int kindNo = makingSeq[color][currentMW];//  ��ʿ���� 0 dragon 1 ninja 2 iceman 3 lion 4 wolf
	if( Warrior::initialLifeValue[kindNo] > totalLife ) { // ����ֵ���㣬ֹͣ������ʿ
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
	pWarriors[totalWarrior]->PrintResult(nTime);   // ��������ʿ����ӡ���
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
		printf("\n");
	}
	return 0;
}




