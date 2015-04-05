/*
 * 24303.cpp
 *
 *  Created on: 2014Äê3ÔÂ8ÈÕ
 *      Author: KoHit
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

class CARS{
    public:
    char name[100];
    int catalog;
    int pcost;
    int drcost;
};

class SPYS{
public:
    char name[100];
    char carname[100];
    int pick;
    int mile;
    int damage;
    int havecar;
    int total;
    int flag;
};

int compar( const void *p, const void *q){
	return strcmp(*(char **)p, *(char **)q);
}

int main(){
    int test = 0;
    int n = 0, m = 0;
    scanf("%d", &test);
    while(test){
        test--;
        scanf ("%d%d", &n, &m);
        CARS *car = new CARS[n];
        SPYS *spy = new SPYS[m];
        getchar();
        for (int i = 0; i < n; i++){
            scanf("%s%d%d%d", car[i].name, &car[i].catalog, &car[i].pcost, &car[i].drcost);
        }
        for (int i = 0; i < m; i++){
            spy[i].flag = 0;
        }

        int tim = 0;
        for (int i = 0; i < m; i++){
            char name[100];
            scanf ("%d%s", &tim, name);
            int found = 0;
            int index = 0;
            int j = 0;
            if (i == 0){
                strcpy(spy[i].name, name);
                spy[i].flag = 1;
                index = 0;
            }
            else{
                for ( j = 0; j < m; j++){

                    if ( !strcmp(name, spy[j].name) ){
                        found = 1;
                        index = j;
                    }
                }
                if (found == 0){
                    strcpy(spy[i].name, name);
                    index = i;
                    spy[i].flag = 1;
                }
            }
            char c;
            cin >> c;
            switch(c){
                case 'p': scanf("%s", spy[index].carname);break;
                case 'r': scanf("%d", &spy[index].mile); spy[index].havecar = 1; break;
                case 'a': scanf("%d", &spy[index].damage); break;
            }

        }

        for ( int i = 0; i < m; i++ ){
            if (spy[i].havecar){
                for (int j = 0; j < n; j++){
                    if(!strcmp(spy[i].carname, car[j].name)){
                        spy[i].pick = car[j].pcost;
                        spy[i].total = spy[i].pick + spy[i].damage * car[j].catalog / 100 + spy[i].mile * car[j].drcost;
                        break;
                    }
                }
            }
        }

        char catalogue[100][100] = { 0 };
        int index = 0;
        for (int i = 0; i < m; i++){
        	if(spy[i].flag){
        		if(spy[i].havecar){
        			strcpy(catalogue[index], spy[i].name);
        			strcat(catalogue[index], " ");
        			char str[100];
        			sprintf(str, "%d", spy[i].total);
        			strcat(catalogue[index], str);
        			index++;
        		}
        		else{
        			strcpy(catalogue[index], spy[i].name);
        			strcat(catalogue[index], " INCONSISTENT");
        			index++;
        		}
        	}
        }

        qsort(catalogue, index, sizeof(char *), compar);

        for ( int i = 0; i < index; i++ ){
        	printf("%s\n", catalogue[i]);
        }

        delete[] car;
        delete[] spy;
    }

    return 0;
}




