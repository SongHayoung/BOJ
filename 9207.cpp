#include <stdio.h>
#include <memory.h>
#include <vector>
using namespace std;
char buf[5][10];
int moves, left;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
void DFS(char buf[5][10],vector<pair<int,int>> p,int m){
    char _buf[5][10];
    for(int i = 0; i < p.size(); ++i)
        for(int j = 0; j < 4; ++j){
            int nx = p[i].second + dx[j];
            int ny = p[i].first + dy[j];
            if(0<=nx&&nx<9 && 0<=ny&&ny<9 && buf[ny][nx]=='o' && 0<=nx+dx[j]&&nx+dx[j]<9 && 0<=ny+dy[j]&&ny+dy[j]<9 && buf[ny+dy[j]][nx+dx[j]]=='.'){
                memcpy(_buf,buf,sizeof(_buf));
                _buf[ny][nx] = _buf[p[i].first][p[i].second] = '.';
                _buf[ny+dy[j]][nx+dx[j]] = 'o';
                vector<pair<int,int>> _p;
                for(auto it : p) {
                    if (it.first == ny && it.second == nx) continue;
                    if (it.first == p[i].first && it.second == p[i].second)
                        _p.emplace_back(p[i].first + 2*dy[j], p[i].second + 2*dx[j]);
                    else
                        _p.emplace_back(it.first,it.second);
                }
                DFS(_buf,_p,m+1);
            }
        }
    if(p.size()<left){
        left = p.size();
        moves = m;
    }
    else if(p.size()==left)
        moves = moves > m ? m : moves;
}
int main() {
    int tc;
    scanf("%d",&tc);
    while(tc--){
        vector<pair<int,int>> pinns;
        left = moves = 9;
        for(int i = 0; i < 5; ++i) {
            scanf("%s", buf[i]);
            for(int j = 0; j < 9; ++j)
                if(buf[i][j]=='o') pinns.emplace_back(i,j);
        }
        DFS(buf,pinns,0);
        printf("%d %d\n",left,moves);
    }
}
