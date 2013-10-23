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
#include<limits.h>
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

vector<int> rk, mice, order;

int main()
{
    DRII(N, G);
    rk.assign(N, 0);
    mice.assign(N, 0);
    order.assign(N, 0);
    int tmp;
    REP(i, N){
        RI(tmp);
        mice[i] = tmp;
    }
    REP(i, N){
        RI(tmp);
        order[i] = tmp;
    }
    int cnt = N;
    while(cnt != 1){
        int size = cnt / G, max;
        int cursor = 0;
        REP(i, size){
            max =order[i*G];
            REP(j, G){
                if(mice[max] < mice[order[i*G + j]]){
                    max = order[i*G + j];
                }
                rk[order[i*G + j]] = (cnt - 1)/G + 2;
            }
            order[i] = max;
            cursor++;
        }
        if(cnt > size * G){
            max = order[size * G];
            REPP(i, size * G, cnt){
                if(mice[max] < mice[order[i]])
                    max = order[i];
                rk[order[i]] = (cnt - 1)/G + 2;
            }
            order[size] = max;
            cursor++;
        }
        cnt = cursor;
    }
    
    rk[order[0]] = 1;
    printf("%d", rk[0]);
    REPP(i, 1, N){
        printf(" %d", rk[i]);
    }
    
    return 0;
}