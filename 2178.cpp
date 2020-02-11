#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
#include <queue>
using namespace std;

//string map[100];
int map[100][100];
bool visit[100][100];
int ans[100][100];
int N,M;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> q;
void func(int x,int y)
{
    q.push(make_pair(x,y));
    ans[0][0]=1;
    visit[0][0]=true;
    while(!q.empty()) {
        int new_x = q.front().first;
        int new_y = q.front().second;
        int dis = ans[new_x][new_y]+1;
        q.pop();

        if (new_x == N - 1 && new_y == M - 1)
            return;

        for(int i=0;i<4;i++)
        {
            int next_x = new_x+dx[i];
            int next_y = new_y+dy[i];
            if(next_x>=0&&next_x<N&&next_y>=0&&next_y<M)
                if(map[next_x][next_y]=='1'&&!visit[next_x][next_y]) {
                    q.push(make_pair(next_x, next_y));
                    ans[next_x][next_y] = dis;
                    visit[next_x][next_y]=true;
                }
        }
    }
}

int main(void)
{
    memset(visit, false,sizeof(visit));
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        for(int j=0;j<M;j++)
            map[i][j]=str[j];
    }

    func(0,0);
    cout<<ans[N-1][M-1]<<endl;
}
