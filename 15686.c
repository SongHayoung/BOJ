# pragma optimize("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
int house[100][2], N, M, chouse = 0,ans = 987654321, temp, houses = 0;
int chickenhouses[13][3];
int dp[100][13];
int fRI(){
    register int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3) + (r<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return r;
}
int abs(int a){
    return a > 0 ? a : -a;
}
void DFS(int open, int lchoosed){
    if(open==M){
        int dis = 0;
        int c_dis;
        for(int i = 0; i <  houses&&dis<ans; ++i){
            c_dis = 987654321;
            for(int j = 0; j <  chouse; ++j){
                if(!chickenhouses[j][2]) continue;
                if(!dp[i][j]) dp[i][j] = abs(house[i][0]-chickenhouses[j][0]) + abs(house[i][1]-chickenhouses[j][1]);
                c_dis = c_dis > dp[i][j] ? dp[i][j] : c_dis;
            }
            dis += c_dis;
        }
        ans = ans > dis ? dis : ans;
        return;
    }
    for(int i = lchoosed; i < chouse; ++i){
        if(chickenhouses[i][2]){
            chickenhouses[i][2] = 0;
            DFS(open-1,i+1);
            chickenhouses[i][2] = 1;
        }
    }
}
int main(void){
    register int i, j;
    memset(dp,0,sizeof(dp));
    memset(house,0,sizeof(house));
    memset(chickenhouses,0,sizeof(chickenhouses));
    N = fRI(); M = fRI();
    for(i=0;i<N;++i) {
        for (j = 0; j < N; ++j) {
            temp = fRI();
            if (temp == 2) {
                chickenhouses[chouse][0] = i;
                chickenhouses[chouse][1] = j;
                chickenhouses[chouse++][2] = 1;
            } else if (temp == 1) {
                house[houses][0] = i;
                house[houses++][1] = j;
            }
        }
    }
    DFS(chouse,0);
    printf("%d",ans);
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
