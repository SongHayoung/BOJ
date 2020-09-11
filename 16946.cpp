#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int n, m, g = 1;
char map[1000][1001];
int group[1000][1000];
vector<int> vec;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
void dfs(int y, int x) {
    int cnt = 1;
    group[y][x] = g;
    queue<pair<int, int>> q;
    q.push({y,x});
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];
            if(0 <= nx && nx < m && 0 <= ny && ny < n && !group[ny][nx] && map[ny][nx] == '0') {
                group[ny][nx] = g;
                ++cnt;
                q.push({ny, nx});
            }
        }
    }
    vec.push_back(cnt);
    ++g;
}
int ans(int y, int x) {
    if(map[y][x] == '0') return 0;
    int ret = 1;
    set<int> s;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(0 <= nx && nx < m && 0 <= ny && ny < n)
            s.insert(group[ny][nx]);
    }
    for(auto val : s)
        ret += vec[val];
    return ret % 10;
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++)
            scanf("%s",&map[i]);
    vec.push_back(0);
    for(int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(map[i][j] == '0' && !group[i][j])
                dfs(i,j);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            printf("%d",ans(i,j));
        printf("\n");
    }
}
