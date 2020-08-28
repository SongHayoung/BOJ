#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <vector>
using namespace std;
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1};
struct fish{
    int y, x, dir;
    bool l;
};
int map[4][4];
int ans = 0;
fish fishes1[17];
struct shark {
    int y, x, dir, eat;
};
void dfs(int map_cpy[4][4], shark s, fish fishes[17], int d) {
    s.eat += map_cpy[s.y][s.x];
    s.dir = fishes[map_cpy[s.y][s.x]].dir;
    fishes[map_cpy[s.y][s.x]].l = false;
    map_cpy[s.y][s.x] = 0;
    ans = max(ans,s.eat);
    for(int i = 1; i <= 16; i++) {
        if(!fishes[i].l) continue;
        bool moveFlag = false;
        for(int k = 0; k < 8 && !moveFlag; ++k) {
            int ny = fishes[i].y + dy[(fishes[i].dir + k)%8];
            int nx = fishes[i].x + dx[(fishes[i].dir + k)%8];
            if(0 <= ny && ny < 4 && 0 <= nx && nx < 4 && !(ny == s.y && nx == s.x)) {
                fishes[i].dir = (fishes[i].dir + k)%8;
                if(map_cpy[ny][nx]) {
                    fishes[map_cpy[ny][nx]].y = fishes[i].y;
                    fishes[map_cpy[ny][nx]].x = fishes[i].x;
                    map_cpy[fishes[i].y][fishes[i].x] = map_cpy[ny][nx];
                } else 
                    map_cpy[fishes[i].y][fishes[i].x] = 0;
                map_cpy[ny][nx] = i;
                fishes[i].y = ny;
                fishes[i].x = nx;
                moveFlag = true;
            }
        }
    }
    for(int i = 1; i <= 3; ++i) {
        int nx = s.x + dx[s.dir] * i;
        int ny = s.y + dy[s.dir] * i;
        if(0 > nx || 0 > ny || 4 <= nx || 4 <= ny) return;
        if(map_cpy[ny][nx]) {
            int map2[4][4];
            fish fish2[17];
            shark s2{.y = ny, .x = nx, .dir = s.dir, .eat = s.eat };
            memcpy(map2, map_cpy, sizeof(map2));
            memcpy(fish2, fishes, sizeof(fish2));
            dfs(map2,s2,fish2,d+1);
        }
    }
}
int main(void) {
    shark s{.y = 0, .x = 0, .eat = 0};
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j){
            scanf("%d",&map[i][j]);
            scanf("%d",&fishes1[map[i][j]].dir);
            fishes1[map[i][j]].dir--;
            fishes1[map[i][j]].y = i;
            fishes1[map[i][j]].x = j;
            fishes1[map[i][j]].l = true;
        }
    dfs(map,s,fishes1, 1);
    printf("%d",ans);
}
