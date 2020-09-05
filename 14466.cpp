#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;
int n, k, r;
int ans;
pair<int,int> c[101];
int map[101][101];
list<pair<int,int>> road[101][101];
bool meet[101];
int gr[101], g;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
bool isRoad(int y1, int x1, int y2, int x2) {
    if(road[y1][x1].empty()) return false;
    for(pair<int,int> p : road[y1][x1])
        if(p.first == y2 && p.second == x2)
            return true;
    return false;
}
void dfs(int cur) {
    if(meet[cur]) return;
    bool visit[101][101] = {false, };
    queue<pair<int,int>> q;
    q.push(c[cur]);
    gr[g] = 1;
    visit[c[cur].first][c[cur].second] = meet[cur] = true;
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = p.second + dx[i];
            int ny = p.first + dy[i];
            if(0 < nx && nx <= n && 0 < ny && ny <= n && !visit[ny][nx] && !isRoad(p.first, p.second, ny, nx)) {
                visit[ny][nx] = true;
                q.push({ny,nx});
                if(map[ny][nx] > cur) {
                    meet[map[ny][nx]] = true;
                    ++gr[g];
                }
            }
        }
    }
    g++;
}
int main() {
    scanf("%d %d %d",&n,&k,&r);
    for(int i = 0; i < r; i++) {
        int y1,x1,y2,x2;
        scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
        road[y1][x1].push_back({y2,x2});
        road[y2][x2].push_back({y1,x1});
    }
    for(int i = 1; i <= k; i++) {
        scanf("%d %d", &c[i].first, &c[i].second);
        map[c[i].first][c[i].second] = i;
    }
    for(int i = 1; i <= k; i++)
        dfs(i);
    for(int i = 0; i < g; i++)
        ans += gr[i] * (k-=gr[i]);
    printf("%d",ans);
}
