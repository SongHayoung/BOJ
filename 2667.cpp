#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
#include <queue>
using namespace std;

string map[100];
bool visit[100][100];
int N;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
vector<int> ans;

void BFS()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            if(!visit[i][j]&&map[i][j]=='1')
            {
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                visit[i][j] = true;
                int cnt=0;
                while(!q.empty())
                {
                    cnt++;
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++)
                    {
                        int next_x = x+dx[k];
                        int next_y = y+dy[k];
                        if(next_x<0||next_x>N||next_y<0||next_y>N)
                            continue;
                        if(!visit[next_x][next_y]&&map[next_x][next_y]=='1')
                        {
                            q.push(make_pair(next_x,next_y));
                            visit[next_x][next_y]=true;
                        }
                    }
                }
                ans.push_back(cnt);
            }
        }
}

int main(void)
{

    memset(visit,false,sizeof(visit));
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>map[i];
    BFS();
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
}
