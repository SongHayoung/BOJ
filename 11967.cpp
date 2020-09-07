#include <iostream>
#include <cmath>
#include <queue>
#include <list>
using namespace std;
int n, m;
bool map[101][101][2];
int ans = 1;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
list<pair<int, int>> l[101][101];
int main() {
    scanf("%d %d",&n, &m);
    map[1][1][0] = map[1][1][1] = true;
    for(int i = 0; i < m; i++) {
        int a, b, c, d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        l[a][b].push_back({c,d});
    }
    queue<pair<int,int>> q;
    q.push({1,1});
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = p.second + dx[i];
            int ny = p.first + dy[i];
            if(0 < nx && nx <= n && 0 < ny && ny <= n && map[ny][nx][0] && !map[ny][nx][1]) {
                q.push({ny, nx});
                map[ny][nx][1] = true;
            }
        }
        for(auto light : l[p.first][p.second]) {
            if(map[light.first][light.second][0]) continue;
            map[light.first][light.second][0] = true;
            ++ans;
            if(!map[light.first][light.second][1]) {
                for(int i = 0; i < 4; i++) {
                    int nx = light.second + dx[i];
                    int ny = light.first + dy[i];
                    if(0 < nx && nx <= n && 0 < ny && ny <= n && map[ny][nx][1]) {
                        q.push({light.first, light.second});
                        map[light.first][light.second][1] = true;
                        break;
                    }
                }
            }
        }
    }
    printf("%d",ans);
}
