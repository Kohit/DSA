#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class CARS{
    public:
    string name;
    int catalog;
    int pcost;
    int drcost;
};

class SPYS{
public:
    string name;
    string carname;
    int pick;
    int mile;
    int damage;
    int havecar;
    int total;
    int flag;
};

int compar( const void *p, const void *q){
	return (*(string *)p > *(string *)q);
}

int main(){
    int test = 0;
    int n = 0, m = 0;
    cin >> test;
    while(test){
        test--;
        cin >> n >> m;
        CARS *car = new CARS[n];
        SPYS *spy = new SPYS[m];

        for (int i = 0; i < n; i++){
            cin >> car[i].name >> car[i].catalog >> car[i].pcost >> car[i].drcost;
        }
        for (int i = 0; i < m; i++){
            spy[i].flag = 0;
        }

        int tim = 0;
        for (int i = 0; i < m; i++){
            string name;
            cin >> tim >> name;
            int found = 0;
            int index = 0;
            int j = 0;
            if (i == 0){
                spy[i].name = name;
                spy[i].flag = 1;
                index = 0;
            }
            else{
                for ( j = 0; j < m; j++){

                    if ( name == spy[j].name ){
                        //cout << name << " " << spy[j].name << endl;
                        found = 1;
                        index = j;
                    }
                }
                if (found == 0){
                    spy[i].name = name;
                    index = i;
                    spy[i].flag = 1;
                   // cout << index << endl;
                }
            }
            char c;
            cin >> c;
            switch(c){
                case 'p': cin >> spy[index].carname;break;
                case 'r': cin >> spy[index].mile; spy[index].havecar = 1; break;
                case 'a': cin >> spy[index].damage; break;
            }

        }

        for ( int i = 0; i < m; i++ ){
            if (spy[i].havecar){
                for (int j = 0; j < n; j++){
                    if(spy[i].carname == car[j].name){
                        spy[i].pick = car[j].pcost;
                        spy[i].total = spy[i].pick + spy[i].damage * car[j].catalog / 100 + spy[i].mile * car[j].drcost;
                        break;
                    }
                }
            }
        }
        string output[100];
        int mark = 0;
        for (int i = 0; i < m; i++){
        	if(spy[i].flag){
        		if (spy[i].havecar){
        			output[mark] = spy[i].name;
        			char buf[10];
        			sprintf(buf,"%d",spy[i].total);
        			output[mark] += " ";
        			output[mark] += buf;
        			mark++;
        		}
        		else{
        			output[mark] = spy[i].name;
        			output[mark] += " INCONSISTENT";
        			mark++;
        		}
        	}
        }

        qsort(output, mark-1, sizeof(string), compar);

        for ( int i = 0; i < mark; i++ ){
        	cout << output[i] << endl;
        }
    }
    return 0;
}
