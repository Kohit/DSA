/*
 * 1196.cpp
 *
 *  Created on: 2014年4月2日
 *      Author: KoHit
 */

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int  WARRIOR_NUM = 5;

/*
红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序制造武士。
蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序制造武士。
武士的种类编号 0 dragon 1 ninja 2 iceman 3 lion 4 wolf
*/

class Headquarter;
class Warrior{
protected:
	int mark;                     // 武士的编号
	string name;
	Headquarter *pHeadquarter;    // 每个武士都有一个master
public:
	static int initialLifeValue[WARRIOR_NUM];   // 每种武士的初始化生命值
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
	int currentMW;      // 当前制造哪种Warrior
	bool stopped;
	Warrior * pWarriors[1000];
public:
	int totalWarrior, totalLife;
	friend class Warrior;
	int warriorNum[WARRIOR_NUM];          //存放每种武士的数量
	static int makingSeq[2][WARRIOR_NUM]; //武士的制作顺序序列
	void Init(int color_, int lv);        //初始化司令部
	~Headquarter () ;
	int Produce(int nTime);               //制造武士
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
		searchingTimes < WARRIOR_NUM ) {     // 如果当前武士所需生命值大于剩余的总生命值，并且没有遍历完每种武士
		currentMW = ( currentMW + 1 ) % WARRIOR_NUM ;  // 跳到下一个武士
		searchingTimes ++;
	}
	int kindNo = makingSeq[color][currentMW];//  武士种类 0 dragon 1 ninja 2 iceman 3 lion 4 wolf
	if( Warrior::initialLifeValue[kindNo] > totalLife ) { // 生命值不足，停止制造武士
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
	pWarriors[totalWarrior]->PrintResult(nTime);   // 制造完武士，打印结果
	totalWarrior ++;
	return 1;
}

int Headquarter::makingSeq[2][WARRIOR_NUM] = { { 2,3,4,1,0 },{3,0,1,2,4} }; //两个司令部武士的制作顺序序列
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




