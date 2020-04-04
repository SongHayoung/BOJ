#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;
char prizon[200][200];
vector<pair<int,int>> pos;
int visit[200][200][3];
int T, N, M;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
void init(){
    char buf[101];
    pos.clear();
    pos.emplace_back(0,0);
    for(int i = 0; i <= N+1; ++i)
        prizon[i][0] = prizon[i][M+1] = '.';
    for(int j = 0; j <= M+1; ++j)
        prizon[0][j] = prizon[N+1][j] = '.';
    for(int i = 1; i <= N; ++i) {
        scanf("%s", buf);
        for(int j = 1; j <= M; ++j) {
            prizon[i][j] = buf[j - 1];
            if(buf[j-1]=='$')
                pos.emplace_back(i,j),prizon[i][j]='.';
        }
    }
}
void BFS(){
    for(int val = 0; val < 3; ++val) {
        deque<pair<int, int>> q;
        q.emplace_back(pos[val].first, pos[val].second);
        visit[pos[val].first][pos[val].second][val] = 0;
        while (!q.empty()) {
            int x = q.front().second;
            int y = q.front().first;
            q.pop_front();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx <= M + 1 && 0 <= ny && ny <= N + 1 && visit[ny][nx][val] == -1 &&
                    prizon[ny][nx] != '*') {
                    switch (prizon[ny][nx]) {
                        case '#' :
                            visit[ny][nx][val] = visit[y][x][val] + 1;
                            q.emplace_back(ny, nx);
                            break;
                        case '.' :
                            visit[ny][nx][val] = visit[y][x][val];
                            q.emplace_front(ny, nx);
                            break;
                    }
                }
            }
        }
    }
}
int main(){
    scanf("%d",&T);
    while(T--){
        memset(visit,-1,sizeof(visit));
        scanf("%d %d",&N,&M);
        init();
        BFS();
        int ans = 1e9;
        for(int i = 0; i <= N+1; ++i)
            for(int j = 0; j <= M+1; ++j){
                if(prizon[i][j]=='*') continue;
                if(prizon[i][j]=='#')
                    ans = ans > visit[i][j][0] + visit[i][j][1] + visit[i][j][2] - 2 ?  visit[i][j][0] + visit[i][j][1] + visit[i][j][2] - 2 : ans;
                else
                    ans = ans > visit[i][j][0] + visit[i][j][1] + visit[i][j][2] ?  visit[i][j][0] + visit[i][j][1] + visit[i][j][2] : ans;
            }
        printf("%d\n",ans);
    }
}
