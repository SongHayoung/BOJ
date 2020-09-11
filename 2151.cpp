#include <iostream>
#include <memory.h>
#include <list>
#include <queue>
using namespace std;
struct light {
    list<pair<int, int>> mirrors;
    int dir;
};
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
char map[50][51];
int visit[50][50];
int n, sx = -1, sy = -1, ex, ey;
queue<light> q;
int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%s", &map[i]);
        for(int j = 0; j < n; j++) {
            visit[i][j] = 987654321;
            if (map[i][j] == '#') {
                if (sx == -1) sx = j, sy = i;
                else ex = j, ey = i;
            }
        }
    }
    list<pair<int,int>> mirrors;
    visit[sy][sx] = 1;
    mirrors.push_back({sy,sx});
    q.push({.mirrors = mirrors, .dir = 0});
    q.push({.mirrors = mirrors, .dir = 1});
    q.push({.mirrors = mirrors, .dir = 2});
    q.push({.mirrors = mirrors, .dir = 3});
    while(!q.empty()) {
        light l = q.front();
        q.pop();
        for(int i = 1; i <= n; i++) {
            int nx = l.mirrors.back().second + dx[l.dir] * i;
            int ny = l.mirrors.back().first + dy[l.dir] * i;
            if(0 <= nx && nx < n && 0 <= ny && ny < n) {
                if(map[ny][nx] == '.') continue;
                if(map[ny][nx] == '*') break;
                if(map[ny][nx] == '!' && visit[ny][nx] > l.mirrors.size() + 1) {
                    list<pair<int,int>> tmp = l.mirrors;
                    visit[ny][nx] = mirrors.size() + 1;
                    tmp.push_back({ny,nx});
                    q.push({.mirrors = tmp, .dir = (l.dir + 1)%4});
                    q.push({.mirrors = tmp, .dir = (l.dir + 3)%4});
                }
                if(map[ny][nx] == '#' && visit[ny][nx] > l.mirrors.size()) {
                    visit[ny][nx] = l.mirrors.size();
                }
            }
            else
                break;
        }
    }
    printf("%d",visit[ey][ex] - 1);
}
