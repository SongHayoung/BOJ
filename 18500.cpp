#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;
string map[100];
int h, w, n, cmd;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
bool down(int y, int x) {
    if(y == h-1) return false;
    bool v[100][100];
    memset(v,false,sizeof(v));
    v[y][x] = true;
    queue<pair<int,int>> q;
    q.push({y,x});
    int maxMove = 987654321, i, j, k;
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for(i = 0; i < 4; i++) {
            int nx = p.second + dx[i];
            int ny = p.first + dy[i];
            if(0 <= nx && nx < w && 0 <= ny && ny < h && !v[ny][nx] && map[ny][nx] == 'x') {
                v[ny][nx] = true;
                q.push({ny,nx});
                if(ny == h-1) return false;
            }
        }
    }
    for(i = 0; i < h - 1; i++)
        for(j = 0; j < w; j++)
            if(v[i][j] && !v[i+1][j]) {
                for(k = i + 1; k < h && map[k][j] == '.'; k++);
                if(k != h && v[k][j]) continue;
                maxMove = min(maxMove, (k-1)-i);
            }
    for(int i = h - 1; i >= 0; i--)
        for(int j = 0; j < w; j++)
            if(v[i][j]) {
                map[i][j] = '.';
                map[i+maxMove][j] = 'x';
            }
    return true;
}
void hit(int y, bool start) {
    int x = start ? w - 1 : 0;
    while(true) {
        if(x >= w || x < 0) return;
        if(map[y][x] == 'x') {
            map[y][x] = '.';
            break;
        }
        start ? --x : ++x;
    }
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < w && 0 <= ny && ny < h && map[ny][nx] == 'x' && down(ny, nx))
            return;
    }
}
int main() {
    scanf("%d %d",&h,&w);
    for(int i = 0; i < h; i++)
        cin>>map[i];
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",&cmd);
        hit(h - cmd, i & 1);
    }
    for(int i = 0; i < h; i++)
        cout<<map[i]<<'\n';
}
