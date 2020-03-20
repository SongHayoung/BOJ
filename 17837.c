# pragma optimize("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <stdio.h>
#define gc() getchar_unlocked()
struct horse{
    int x;
    int y;
    int dir;
    int stair;
};
int fRI(){
    register int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3) + (r<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return r;
}
int main(void){
    int map[13][13];
    struct horse h[10];
    int dx[5] = {0,1,-1,0,0};
    int dy[5] = {0,0,0,-1,1};
    register int N = fRI(), K = fRI(), i, j, k, ny, nx, cur_x, cur_y;
    for(i=1;i<=N;++i)
        for(j=1;j<=N;++j)
            map[i][j]=fRI();
    for(i=0;i<K;++i){
        h[i].y = fRI();
        h[i].x = fRI();
        h[i].dir = fRI();
        h[i].stair = 1;
    }
    for(i=1;i<=1000;++i){
        for(j=0;j<K;++j){
            ny = h[j].y + dy[h[j].dir];
            nx = h[j].x + dx[h[j].dir];
            if(!ny||!nx||nx>N||ny>N||map[ny][nx]==2){
                switch(h[j].dir){
                    case 1: h[j].dir = 2; break;
                    case 2: h[j].dir = 1; break;
                    case 3: h[j].dir = 4; break;
                    case 4: h[j].dir = 3; break;
                    default: break;
                }
                ny = h[j].y + dy[h[j].dir];
                nx = h[j].x + dx[h[j].dir];
                if(!ny||!nx||nx>N||ny>N||map[ny][nx]==2) { }
                else if(map[ny][nx]){
                    int max_stair = h[j].stair;
                    int min_stair = h[j].stair;
                    int dest_max_stair = 0;
                    cur_x = h[j].x;
                    cur_y = h[j].y;
                    for(k = 0; k < K; ++k){
                        if(cur_x==h[k].x&&cur_y==h[k].y&&max_stair<h[k].stair)
                            max_stair = h[k].stair;
                        else if(h[k].x==nx&&h[k].y==ny&&dest_max_stair<h[k].stair)
                            dest_max_stair = h[k].stair;
                    }
                    for(k = 0; k < K; ++k){
                        if(cur_x==h[k].x&&cur_y==h[k].y&&min_stair<=h[k].stair){
                            h[k].x = nx; h[k].y = ny; h[k].stair = max_stair - h[k].stair + 1 + dest_max_stair;
                        }
                    }
                }
                else {
                    int min_stair = h[j].stair;
                    int dest_max_stair = 0;
                    cur_x = h[j].x;
                    cur_y = h[j].y;
                    for(k = 0; k < K; ++k){
                        if(h[k].x==nx&&h[k].y==ny&&dest_max_stair<h[k].stair)
                            dest_max_stair = h[k].stair;
                    }
                    for(k = 0; k < K; ++k){
                        if(cur_x==h[k].x&&cur_y==h[k].y&&min_stair<=h[k].stair){
                            h[k].x = nx; h[k].y = ny; h[k].stair = h[k].stair - min_stair + 1 + dest_max_stair;
                        }
                    }
                }
            }
            else if(map[ny][nx]){
                int max_stair = h[j].stair;
                int min_stair = h[j].stair;
                int dest_max_stair = 0;
                cur_x = h[j].x;
                cur_y = h[j].y;
                for(k = 0; k < K; ++k){
                    if(cur_x==h[k].x&&cur_y==h[k].y&&max_stair<h[k].stair)
                        max_stair = h[k].stair;
                    else if(h[k].x==nx&&h[k].y==ny&&dest_max_stair<h[k].stair)
                        dest_max_stair = h[k].stair;
                }
                for(k = 0; k < K; ++k){
                    if(cur_x==h[k].x&&cur_y==h[k].y&&min_stair<=h[k].stair){
                        h[k].x = nx; h[k].y = ny; h[k].stair = max_stair - h[k].stair + 1 + dest_max_stair;
                    }
                }
            }
            else{
                int min_stair = h[j].stair;
                int dest_max_stair = 0;
                cur_x = h[j].x;
                cur_y = h[j].y;
                for(k = 0; k < K; ++k){
                    if(h[k].x==nx&&h[k].y==ny&&dest_max_stair<h[k].stair)
                        dest_max_stair = h[k].stair;
                }
                for(k = 0; k < K; ++k){
                    if(cur_x==h[k].x&&cur_y==h[k].y&&min_stair<=h[k].stair){
                        h[k].x = nx; h[k].y = ny; h[k].stair = h[k].stair - min_stair + 1 + dest_max_stair;
                    }
                }
            }
            for(k = 0; k < K; ++k){
                if(h[k].stair>=4) { printf("%d",i); return 0;}
            }
        }
    }
    printf("-1");
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
