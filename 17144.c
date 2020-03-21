# pragma optimize("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <stdio.h>
#define gc() getchar_unlocked()
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int map[50][50][2], R, C, T;
int fRI(){
    register int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3) + (r<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return r;
}
int main(void){
    register int clean_down=-1,clean_up=51, time, i, j, cnt, k, ny, nx, ans = 2;
    scanf("%d %d %d",&R,&C,&T);
    for(i = 0; i < R; ++i)
        for(j = 0; j < C; ++j) {
            scanf("%d",&map[i][j][0]);
            if(map[i][j][0]==-1){
                clean_down = clean_down < i ? i : clean_down;
                clean_up = clean_up > i ? i : clean_up;
            }
        }
    for(time = 0; time < T; ++time){
        for(i = 0; i < R; ++i)
            for(j = 0; j < C; ++j){
                if(map[i][j][0]==-1) continue;
                if(!map[i][j][0]) continue;
                cnt = 0;
                for(k = 0; k < 4; ++k){
                    nx = j+dx[k];
                    ny = i+dy[k];
                    if(0<=nx&&nx<C && 0<=ny&&ny<R && map[ny][nx][0]!=-1){
                        map[ny][nx][1] += map[i][j][0]/5;
                        ++cnt;
                    }
                }
                map[i][j][0] = map[i][j][0] - (map[i][j][0]/5*cnt);
            }
        for(i = 0; i < R; ++i)
            for(j = 0; j < C; ++j){
                if(!map[i][j][1]) continue;
                map[i][j][0] += map[i][j][1];
                map[i][j][1] = 0;
            }
        for(i = clean_up-1; i > 0; --i)
            map[i][0][0] = map[i-1][0][0];
        for(i = 0; i < C-1; ++i)
            map[0][i][0] = map[0][i+1][0];
        for(i = 0; i < clean_up; ++i)
            map[i][C-1][0] = map[i+1][C-1][0];
        for(i = C-1; i > 1; --i)
            map[clean_up][i][0] = map[clean_up][i-1][0];
        for(i = clean_down+1; i < R-1; ++i)
            map[i][0][0] = map[i+1][0][0];
        for(i = 0; i < C-1; ++i)
            map[R-1][i][0] = map[R-1][i+1][0];
        for(i = R-1; i > clean_down; --i)
            map[i][C-1][0] = map[i-1][C-1][0];
        for(i = C-1; i > 1; --i)
            map[clean_down][i][0] = map[clean_down][i-1][0];
        map[clean_down][1][0] = map[clean_up][1][0] = 0;
    }
    for(i = 0; i < R; ++i)
        for(j = 0; j < C; ++j)
            ans += map[i][j][0];
    printf("%d",ans);
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}w
