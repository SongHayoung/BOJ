#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int map[20][20][401];
int dirpriority[401][4][4];
struct shark {
    int y, x, dir, num;
};
bool operator<(shark a, shark b) {
    return a.y != b.y ? a.y > b.y :
    a.x != b.x ? a.x > b.x :
    a.num > b.num;
}
priority_queue<shark> pq;
queue<shark> q;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int n, m, k;
int dirconverter(int input) {
    switch(input) {
        case 1: return 0;
        case 2: return 2;
        case 3: return 3;
        case 4: return 1;
    }
}

int getDirIndex(shark s, int i) {
    return dirpriority[s.num][s.dir][i];
}

bool isSmell(int y, int x) {
    for(int i = 1; i <= m; ++i) {
        if(!map[y][x][i]) continue;
        return false;
    }
    return true;
}

void dfs() {
    while(!q.empty()) {
        shark s = q.front();
        q.pop();
        bool flag = false;
        for(int i = 0; i < 4 && !flag; ++i) {
            int nx = s.x + dx[getDirIndex(s, i)];
            int ny = s.y + dy[getDirIndex(s, i)];
            if(0 <= nx && nx < n && 0 <= ny && ny < n && isSmell(ny,nx)) {
                pq.push(shark{.y = ny, .x = nx, .dir = getDirIndex(s, i), .num = s.num});
                flag = true;
            }
        }
        if(!flag)
        for(int i = 0; i < 4 && !flag; ++i) {
            int nx = s.x + dx[getDirIndex(s, i)];
            int ny = s.y + dy[getDirIndex(s, i)];
            if(0 <= nx && nx < n && 0 <= ny && ny < n && map[ny][nx][s.num]) {
                pq.push(shark{.y = ny, .x = nx, .dir = getDirIndex(s, i), .num = s.num});
                flag = true;
            }
        }
    }
}
void eat() {
    shark pshark = pq.top();
    pq.pop();
    q.push(pshark);
    map[pshark.y][pshark.x][pshark.num] = k + 1;
    while(!pq.empty()) {
        shark s = pq.top();
        pq.pop();
        if(pshark.y == s.y && pshark.x == s.x)  continue;
        pshark = s;
        q.push(s);
        map[pshark.y][pshark.x][pshark.num] = k + 1;
    }
}

void clean() {
    for(int i = 0; i < n; ++i)
        for(int j = 0;j < n; ++j)
            for(int k = 1; k <= m; ++k)
                if(map[i][j][k]) --map[i][j][k];
}
int main(void) {
   scanf("%d %d %d", &n, &m, &k);
   shark sharks[m + 1];
   for(int i = 0; i < n; ++i)
       for(int j = 0; j < n; ++j) {
           scanf("%d",&map[i][j][0]);
           if(map[i][j]) {
               sharks[map[i][j][0]].y = i;
               sharks[map[i][j][0]].x = j;
               map[i][j][map[i][j][0]] = k;
           }
       }
   for(int i = 1; i <= m; ++i) {
       int dir; scanf("%d",&dir);
       q.push(shark{.y = sharks[i].y, .x = sharks[i].x, .dir = dirconverter(dir), .num = i});
   }

   for(int i = 1; i <= m; ++i)
       for(int j = 1; j <= 4; ++j) {
           for(int k = 0; k < 4; ++k) {
               int dir; scanf("%d",&dir);
               dirpriority[i][dirconverter(j)][k] = dirconverter(dir);
           }
       }
   int ans;
   for(ans = 1; ans <= 1000 && q.size() != 1; ++ans) {
       dfs();
       eat();
       clean();
   }
   printf("%d",q.size() == 1 ? ans-1 : -1);
}
