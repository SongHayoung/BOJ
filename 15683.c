# pragma optimize("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <stdio.h>
#define gc() getchar_unlocked()
int map[8][8], N, M;
int cctv[9][4], cctvs=0, ans = 987654321;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int fRI(){
    register int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3) + (r<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return r;
}
void run(int f){
    register int ny, nx;
    for(int i = 0; i < cctvs; ++i){
        if(cctv[i][2]==5) continue;
        switch(cctv[i][2]){
            case 1:
                nx = cctv[i][1] + dx[cctv[i][3]];
                ny = cctv[i][0] + dy[cctv[i][3]];
                while(0<=nx&&nx<M && 0<=ny&&ny<N && map[ny][nx]!=6){
                    f ? ++map[ny][nx] : --map[ny][nx];
                    ny += dy[cctv[i][3]];
                    nx += dx[cctv[i][3]];
                }
                break;
            case 2:
                nx = cctv[i][1] + dx[cctv[i][3]];
                ny = cctv[i][0] + dy[cctv[i][3]];
                while(0<=nx&&nx<M && 0<=ny&&ny<N && map[ny][nx]!=6){
                    f ? ++map[ny][nx] : --map[ny][nx];
                    ny += dy[cctv[i][3]];
                    nx += dx[cctv[i][3]];
                }
                nx = cctv[i][1] + dx[(cctv[i][3]+2)];
                ny = cctv[i][0] + dy[(cctv[i][3]+2)];
                while(0<=nx&&nx<M && 0<=ny&&ny<N && map[ny][nx]!=6){
                    f ? ++map[ny][nx] : --map[ny][nx];
                    ny += dy[cctv[i][3]+2];
                    nx += dx[cctv[i][3]+2];
                }
                break;
            case 3:
                nx = cctv[i][1] + dx[cctv[i][3]];
                ny = cctv[i][0] + dy[cctv[i][3]];
                while(0<=nx&&nx<M && 0<=ny&&ny<N && map[ny][nx]!=6){
                    f ? ++map[ny][nx] : --map[ny][nx];
                    ny += dy[cctv[i][3]];
                    nx += dx[cctv[i][3]];
                }
                nx = cctv[i][1] + dx[(cctv[i][3]+1)%4];
                ny = cctv[i][0] + dy[(cctv[i][3]+1)%4];
                while(0<=nx&&nx<M && 0<=ny&&ny<N && map[ny][nx]!=6){
                    f ? ++map[ny][nx] : --map[ny][nx];
                    ny += dy[(cctv[i][3]+1)%4];
                    nx += dx[(cctv[i][3]+1)%4];
                }
                break;
            case 4:
                nx = cctv[i][1] + dx[cctv[i][3]];
                ny = cctv[i][0] + dy[cctv[i][3]];
                while(0<=nx&&nx<M && 0<=ny&&ny<N && map[ny][nx]!=6){
                    f ? ++map[ny][nx] : --map[ny][nx];
                    ny += dy[cctv[i][3]];
                    nx += dx[cctv[i][3]];
                }
                nx = cctv[i][1] + dx[(cctv[i][3]+1)%4];
                ny = cctv[i][0] + dy[(cctv[i][3]+1)%4];
                while(0<=nx&&nx<M && 0<=ny&&ny<N && map[ny][nx]!=6){
                    f ? ++map[ny][nx] : --map[ny][nx];
                    ny += dy[(cctv[i][3]+1)%4];
                    nx += dx[(cctv[i][3]+1)%4];
                }
                nx = cctv[i][1] + dx[(cctv[i][3]+2)%4];
                ny = cctv[i][0] + dy[(cctv[i][3]+2)%4];
                while(0<=nx&&nx<M && 0<=ny&&ny<N && map[ny][nx]!=6){
                    f ? ++map[ny][nx] : --map[ny][nx];
                    ny += dy[(cctv[i][3]+2)%4];
                    nx += dx[(cctv[i][3]+2)%4];
                }
                break;
            default: break;
        }
    }
}
void DFS(int cur){
    if(cur==cctvs){
        run(1);
        int sagak = 0;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                if(!map[i][j]) ++sagak;
        ans = ans > sagak ? sagak : ans;
        run(0);
        return;
    }
    if(cctv[cur][2]==5) {DFS(cur+1); return;}
    if(cctv[cur][2]==2) {
        cctv[cur][3]=0;
        DFS(cur+1);
        cctv[cur][3]=1;
        DFS(cur+1);
        return;
    }
    for(int i = 0; i < 4; ++i){
        cctv[cur][3] = i;
        DFS(cur+1);
    }
}
int main(void){
    register int i, j;
    N = fRI(), M = fRI();
    for(i = 0; i < N; ++i)
        for(j = 0; j < M; ++j) {
            map[i][j] = fRI();
            if(map[i][j]&&map[i][j]!=6){
                cctv[cctvs][0] = i;
                cctv[cctvs][1] = j;
                cctv[cctvs++][2] = map[i][j];
            }
        }
    for(i = 0; i < cctvs; ++i)
        if(cctv[i][2]==5){
            int nx, ny;
            for(j=0;j<4;j++){
                nx = cctv[i][1] + dx[j];
                ny = cctv[i][0] + dy[j];
                while(0<=nx&&nx<M && 0<=ny&&ny<N && map[ny][nx]!=6){
                    ++map[ny][nx];
                    ny += dy[j];
                    nx += dx[j];
                }
            }
        }
    DFS(0);
    printf("%d",ans);
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
