#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<functional>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define RREP(I, N) for (int I = (N) - 1; I >= 0; --I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
#define REPCC(I,A, C) for (int I = (A); !(C); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;

#define SIZE 100001

const int SECSIZE = SIZE/100;

int data[SIZE];
int dict[SIZE]={0};
int secdict[SECSIZE] = {0};
int medi[SIZE];

int median(int len){
    len = (len+1)/2;
    int seci = -1;
    REP(i, SECSIZE){
        len -= secdict[i];
        if(len <= 0) {
            len+=secdict[i];
            seci = i;
            break;
        }
    }
    REP(k, 100){
        len -= dict[seci* 100 + k];
        if(len <= 0)
            return seci* 100 + k;
    }
    
    return 0;
}

int main()
{
    int i=0;
    char cmd[11];
    DRI(N);
    REP(k, N){
        RS(cmd);
        if(cmd[2]=='s'){
            DRI(key);
            data[i] = key;
            i++;
            dict[key]++;
            secdict[key/100]++;
            medi[i]=median(i);
        }
        else if(i <= 0){
            printf("Invalid\n");
        }
        else if(cmd[2]=='p'){
            i--;
            dict[data[i]]--;
            secdict[data[i]/100]--;
            printf("%d\n",data[i]);
        }
        else{
            printf("%d\n",medi[i]);
        }
    }
    return 0;
}
