#include <iostream>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;


#define MAXSIZE 16
int map[MAXSIZE][MAXSIZE];
int map_cpy[MAXSIZE][MAXSIZE];
bool status[MAXSIZE][MAXSIZE];
bool status_cpy[MAXSIZE][MAXSIZE];
int N,M,D;
int line_start;
int ans=0;
vector<int> arrow;

void play() {
    vector<pair<int, int>> p;
    p.push_back(make_pair(N+1,arrow[0]));
    p.push_back(make_pair(N+1,arrow[1]));
    p.push_back(make_pair(N+1,arrow[2]));
    int cnt = 0;
    bool find;
    while(p[2].first>1)
    {
        vector<pair<int, int>> killed;
        for(int k=0;k<3;k++) {
            find = false;
            for (int i = 1; i <= D; i++) {
                int dx = -1;
                int dy = (i - 1) * (-1);
                for (int j = 1; j < i * 2; j++) {
                    int nx = p[k].first+dx;
                    int ny = p[k].second+dy;

                    dx = (j<i)?dx-1:dx+1;
                    dy++;

                    if(nx<=0||ny<=0||ny>M)
                        continue;
                    if(map_cpy[nx][ny]==1)
                    {
                        if(status_cpy[nx][ny])
                        {
                            cnt++;
                            status_cpy[nx][ny]=false;
                            killed.push_back(make_pair(nx,ny));
                        }
                        find=true;
                        break;
                    }
                }
                if(find)
                    break;
            }
            p[k].first--;
        }
        while(killed.size()>0)
        {
            int nx = killed[0].first;
            int ny = killed[0].second;
            map_cpy[nx][ny]=0;
            killed.erase(killed.begin());
        }
    }
    ans = max(ans, cnt);
    return;
}

void DFS(int idx) {
    if (arrow.size() == 3) {
        memcpy(status_cpy,status,sizeof(status_cpy));
        memcpy(map_cpy,map,sizeof(map_cpy));
        play();
        return ;
    }
    for (int i = idx; i <= M-2+arrow.size(); i++)
    {
        arrow.push_back(i);
        DFS(i+1);
        arrow.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M>>D;
    memset(status,false,sizeof(status));
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
        {
            cin>>map[i][j];
            if(map[i][j]==1)
                status[i][j]=true;
        }

    DFS(1);
    cout<<ans<<endl;
}
