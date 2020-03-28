#include <stdio.h>
#include <queue>
#define gc() getchar_unlocked()
using namespace std;
short domino[500][1000];
int tile[500][1000];
bool visit[500][1000];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int N;
struct TILE{
    short y;
    short x;
    int cost;
    int maxt;
    vector<int> visit;
};
short fRS(){
    short N=gc(),ret = 0;
    for(;N<48||N>57;N=gc());
    do{
        ret = (ret<<3) + (ret<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return ret;
}
int tilenum(int &y, int &x){
    return y&1 ? ((y - 1)>>1)*((N<<1)-1)+1+N+((x-1)>>1):((y>>1)*((N<<1)-1))+1+(x>>1);
}
int main(){
    N = fRS();
    register int i, j;
    register short nx, ny, nnx, nny;
    for(i = 0; i < N; ++i){
        if(i&1) for(j = 1; j < (N<<1)-1; ++j) domino[i][j] = fRS(),tile[i][j] = tilenum(i,j);
        else for(j = 0; j < (N<<1); ++j) domino[i][j] = fRS(),tile[i][j] = tilenum(i,j);
    }
    queue<TILE> q;
    vector<int> v,ansv;
    int maxt = 1,mincost = 1;
    v.push_back(1);
    ansv.push_back(1);
    register TILE t{0,1,1,1,v},nt;
    q.push(t);
    visit[0][0] = visit[0][1] = 1;
    while(!q.empty()){
        t = q.front();
        if(t.maxt>maxt){
            maxt = t.maxt;
            mincost = t.cost;
            ansv = t.visit;
        }
        else if(t.maxt==maxt&&mincost>t.cost){
            mincost = t.cost;
            ansv = t.visit;
        }
        q.pop();
        for(i = 0; i < 4; ++i){
            nx = t.x + dx[i];
            ny = t.y + dy[i];
            if(0<=nx&&nx<2*N && 0<=ny&&ny<N && !visit[ny][nx] && domino[ny][nx]==domino[t.y][t.x]){
                nt = t;
                visit[ny][nx] = 1;
                nt.x = nx;
                nt.y = ny;
                nt.visit.push_back(tile[ny][nx]);
                nt.maxt = max(nt.maxt,tile[ny][nx]);
                q.push(nt);
                for(j = 1; j < 4; j+=2){
                    nnx = nx+dx[j];
                    nny = ny+dy[j];
                    if(0<=nnx&&nnx<2*N&&0<=nny&&nny<N&&!visit[nny][nnx]&&domino[nny][nnx]&&tile[ny][nx]==tile[nny][nnx]){
                        nt.x = nnx;
                        nt.y = nny;
                        q.push(nt);
                    }
                }
            }
        }
    }
    printf("%d\n",mincost);
    for(int i = 0; i < ansv.size(); ++i)
        printf("%d ",ansv[i]);
    
}
