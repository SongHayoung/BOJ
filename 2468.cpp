#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int arr[100][100];
int high=0;
int ans = 1;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
bool visit[100][100];
bool digree[101];

void BFS(int rain)
{
    memset(visit,false,sizeof(visit));
    int cnt=0;
    queue<pair<int,int>> q;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            if(!visit[i][j]&&arr[i][j]>rain)
            {
                q.push(make_pair(i,j));
                visit[i][j]=true;
                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++)
                    {
                        int next_x = x+dx[k];
                        int next_y = y+dy[k];
                        if(next_x<0||next_x>=N||next_y<0||next_y>=N)
                            continue;
                        if(!visit[next_x][next_y]&&arr[next_x][next_y]>rain)
                        {
                            q.push(make_pair(next_x,next_y));
                            visit[next_x][next_y]=true;
                        }
                    }
                }
                cnt++;
            }
        }
    ans = max(ans,cnt);
}

int main(void) {
    cin>>N;
    memset(digree, false,sizeof(digree));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
            high = max(high,arr[i][j]);
            digree[arr[i][j]]=true;
        }

    for(int i=1;i<high;i++)
        if(digree[i])
            BFS(i);

    cout<<ans<<endl;
}
