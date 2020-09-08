#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int g[11][11];
int gMap[20][20];
int dp[1<<11][11];
int w, h, dust;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
void bfs(int y, int x){
    bool visit[20][20] = {false, };
    visit[y][x] = true;
    g[gMap[y][x]][gMap[y][x]] = 0;
    queue<pair<int,int>> q;
    q.push({y,x});
    int move = 1;
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            pair<int,int> p = q.front();
            q.pop();
            for(int j = 0; j < 4; j++) {
                int ny = p.first + dy[j];
                int nx = p.second + dx[j];
                if(0 <= nx && nx < w && 0 <= ny && ny < h && !visit[ny][nx] && gMap[ny][nx] >= 0) {
                    visit[ny][nx] = true;
                    if(gMap[ny][nx])
                        g[gMap[y][x]][gMap[ny][nx]] = g[gMap[ny][nx]][gMap[y][x]] = move;
                    q.push({ny, nx});
                }
            }
        }
        ++move;
    }
}
int dpf(int cur, int last) {
    if(dp[cur][last] != -1) return dp[cur][last];
    dp[cur][last] = 987654321;
    for(int i = 1; i < dust; i++)
        dp[cur][last] = min(dp[cur][last], dpf(cur | (1<<i), i) + g[last][i]);
    return dp[cur][last];
}
int main(){
    scanf("%d %d",&w, &h);
    while(w) {
        char map[21];
        dust = 2;
        for(int i = 0; i < h; i++) {
            scanf("%s", map);
            for(int j = 0; j < w; j++) {
                switch(map[j]) {
                    case '.' : gMap[i][j] = 0; break;
                    case 'o' : gMap[i][j] = 1; break;
                    case 'x' : gMap[i][j] = -1; break;
                    case '*' : gMap[i][j] = dust++; break;
                }
            }
        }
        for(int i = 1; i < dust; i++)
            for(int j = 1; j < dust; j++)
                g[i][j] = 987654321;
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                if(gMap[i][j] > 0)
                    bfs(i,j);
        memset(dp,-1,sizeof(dp));
        for(int i = 1; i < dust; i++)
            dp[(1<<dust) - 1][i] = 0;
        printf("%d\n",dpf(1,1) >= 987654321 ? -1 : dpf(1,1));
        scanf("%d %d",&w, &h);
    }
}
