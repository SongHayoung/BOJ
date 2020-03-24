#include <stdio.h>
#include <queue>
#define gc() getchar_unlocked()
#define NMAX 987654321
using namespace std;
struct Monkey{
    int x;
    int y;
    int k;
    int c;
};
int map[200][200];
int visit[200][200][31];
int K, W, H;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int hdx[8] = {1,2,2,1,-1,-2,-2,-1};
int hdy[8] = {-2,-1,1,2,2,1,-1,-2};
int fRI() {
    int N = gc(), ret = 0;
    for (; N < 48 || N > 57; N = gc());
    do {
        ret = (ret << 3) + (ret << 1) + (N & 0b1111);
        N = gc();
    } while (0x30 <= N);
    return ret;
}

int main(void) {
    register int i, j, l;
    struct Monkey m;
    K = fRI(); W = fRI(); H = fRI();
    for (i = 0; i < H; ++i)
        for (j = 0; j < W; ++j) {
            map[i][j] = fRI();
            for (l = 0; l <= K; ++l)
                visit[i][j][l] = NMAX;
        }
    queue<Monkey> q;
    m.x = 0; m.y = 0; m.k = K; m.c = 0;
    visit[0][0][K] = 0;
    q.push(m);
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int k = q.front().k;
        int c = q.front().c;
        q.pop();
        if(visit[y][x][k]!=c) continue;
        if(y==H-1 && x==W-1) {
            printf("%d",c);
            return 0;
        }
        if(k){
            for(i = 0; i < 8; ++i){
                int nx = x + hdx[i];
                int ny = y + hdy[i];
                if(0<=nx && nx<W && 0<=ny && ny < H){
                    if(visit[ny][nx][k-1]>c+1 && !map[ny][nx]){
                        visit[ny][nx][k-1] = c+1;
                        m.x = nx; m.y = ny; m.k = k-1; m.c = c+1;
                        q.push(m);
                    }
                }
            }
        }
        for(i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<W && 0<=ny && ny < H){
                if(visit[ny][nx][k]>c+1 && !map[ny][nx]){
                    visit[ny][nx][k] = c+1;
                    m.x = nx; m.y = ny; m.k = k; m.c = c+1;
                    q.push(m);
                }
            }
        }
    }
    printf("-1");
    return 0;
}
