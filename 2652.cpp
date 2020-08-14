#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int map[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1,0,1,0};
int n, u, v, w, x, y;
int blocknum = 2;
int ans = 0;
vector<pair<int, int>> vec;
int main(void) {
    scanf("%d %d %d %d %d %d",&n, &u, &v, &w, &x, &y);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            scanf("%d",&map[i][j]);

    bool vv[50][50] = {false, };

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) {
            if(map[i][j] == 1) {
                int minx = j, maxx = j, miny = i, maxy = i, blockcnt = 0;
                map[i][j] = blocknum;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                vv[i][j] = true;
                //ㄷ자 블록의 범위를 구한다
                while(!q.empty()) {
                    int cy = q.front().first;
                    int cx = q.front().second;
                    q.pop();
                    for(int k = 0; k < 4; ++k) {
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];
                        if(0<=nx && nx < n && 0 <= ny && ny < n && !vv[ny][nx] && map[ny][nx]) {
                            q.push(make_pair(ny,nx));
                            vv[ny][nx] = true;
                            map[ny][nx] = blocknum;
                            minx = min(minx,nx);
                            miny = min(miny,ny);
                            maxx = max(maxx,nx);
                            maxy = max(maxy,ny);
                        }
                    }
                }
                //ㄷ자 블록내에 포함된 블록의 수를 구한다
                //ㄷ자 블록 내에는 다른 ㄷ자 블록이 포함되어 있지 않아야 하므로 다른 블록이 포함되었다면 blockcnt의 값을 바꾼다
                for(int posy = miny; posy <= maxy; ++posy)
                    for(int posx = minx; posx <= maxx; ++posx) {
                        if (map[posy][posx] == blocknum) ++blockcnt;
                        else if (map[posy][posx] != blocknum && map[posy][posx] != 0) blockcnt = -987654321;
                    }
                ++blocknum;
                //ㄷ자 블록의 직사각형 범위에서 비어있는 공간이 ㅗ 블록의 x * y 의 크기와 같지 않다면 그만한다.
                if(((maxx - minx + 1) * (maxy - miny + 1)) - blockcnt != x * y) continue;
                int flag = -1;
                int side = 0;
                // ㄷ자 블록의 비어있는 방향과 비어있는 칸의 크기를 구한다.
                // flag 값
                // 0 : 상
                // 1 : 우
                // 2 : 하
                // 3 : 좌
                for(int k = minx + w; k < minx + w + y && k < maxx; ++k) {
                    if (!map[maxy][k]) flag = 2, ++side;
                }

                for(int k = minx + u - y - w; k < minx + u - w && k < maxx; ++k) {
                    if (!map[miny][k]) flag = 0, ++side;
                }

                for(int k = miny +  u - y - w; k < miny + u - w && k < maxy; ++k) {
                    if (!map[k][maxx]) flag = 1, ++side;
                }

                for(int k = miny + w; k < miny + w + y && k < maxy; ++k) {
                    if (!map[k][minx]) flag = 3, ++side;
                }
                //비어있는 칸의 크기가 y과 같지 않다면 그만한다.
                if(side != y) continue;
                //직사각형이 판 밖으로 나가지 않으면서 ㄷ자의 뚤려있는 변의 길이가 u과 같다면 플레그를 -1로 변경한다.
                switch (flag){
                    case 0:
                        if(miny - v >= 0 && maxx - minx + 1 == u){
                            flag = -1;

                            for(int k = miny - 1; k >= miny - v; --k)
                                for(int l = minx; l <= maxx; ++l) {
                                    if (map[k][l]) flag = 0;
                                }
                        }
                        break;
                    case 1:
                        if(maxx + v <= n - 1 && maxy - miny + 1 == u) {
                            flag = -1;

                            for(int k = miny; k <= maxy; ++k)
                                for(int l = maxx + 1; l <= maxx + v; ++l){
                                    if (map[k][l]) flag = 0;
                                }
                        }
                        break;
                    case 2:
                        if(maxy + v <= n - 1 && maxx - minx + 1 == u) {
                            flag = -1;

                            for(int k = maxy + 1; k <= maxy + v; ++k)
                                for(int l = minx; l <= maxx; ++l){
                                    if (map[k][l]) flag = 0;
                                }
                        }
                        break;
                    case 3:
                        if(minx - v >= 0 && maxy - miny + 1 == u) {
                            flag = -1;

                            for(int k = miny; k <= maxy; ++k)
                                for(int l = minx - 1; l >= minx - v; --l){
                                    if (map[k][l]) flag = 0;
                                }
                        }
                        break;
                }

                if(flag == -1) {
                    ++ans;
                    vec.emplace_back(miny + 1, minx + 1);
                }
            }
        }

    printf("%d\n",ans);
    for(int i = 0; i < ans; ++i)
        printf("%d %d\n",vec[i].first, vec[i].second);
}
