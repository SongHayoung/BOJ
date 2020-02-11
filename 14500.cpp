#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

#define Size 500
int board[Size][Size];
bool visited[Size][Size];
int N, M;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int edx[4][3] = {{-1,0,1},      {1,1,1},    {-1,0,1},   {-1,-1,-1}};
int edy[4][3] = {{-1,-1,-1},    {-1,0,1},   {1,1,1},    {-1,0,1}};

int ans = 0;

void dfs_excp(int x, int y)
{
    for(int i=0;i<4;i++)
    {
        int point = board[y][x];
        for(int j=0;j<3;j++)
        {
            int nx = x + edx[i][j];
            int ny = y + edy[i][j];
            if(0<=nx && nx<M && 0<=ny && ny<N) {
                point += board[ny][nx];
            }
            else {
                point = 0;
            }
        }
        ans = max(ans,point);
    }
}

void dfs(int depth, int x, int y, int point)
{
    if(depth==4) {
        ans = max(ans, point);
        return ;
    }

    visited[y][x] = true;
    for(int i=0;i<4;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(0<=nx && nx<M && 0<=ny && ny<N && !visited[ny][nx])
            dfs(depth+1,nx,ny,point+board[ny][nx]);
    }
    visited[y][x] = false;
}


int main(void)
{
    memset(visited,false,sizeof(visited));
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>board[i][j];

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            dfs(1,j,i,board[i][j]);
            dfs_excp(j,i);
        }

    cout<<ans<<endl;
}
