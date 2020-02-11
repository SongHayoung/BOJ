#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
#include <queue>
using namespace std;

int map[1000][1000];
int N,M;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int ans = -1;
void BFS()
{
    queue<pair<int,int>> q;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(map[i][j]==1) {
                q.push(make_pair(i, j));
            }

    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int next_x = x+dx[i];
            int next_y = y+dy[i];
            if(next_x<0||next_x>=N||next_y<0||next_y>=M)
                continue;
            if(map[next_x][next_y]==0)
            {
                map[next_x][next_y] = map[x][y]+1;
                q.push(make_pair(next_x,next_y));
            }
        }
    }
}

int main(void)
{

    cin>>M>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>map[i][j];
    BFS();


    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            if(map[i][j]==0){
                cout<<"-1"<<endl;
                return 0;
            }
            else{
                ans = max(ans,map[i][j]);
            }
        }

    cout<<ans-1<<endl;
    return 0;
}
