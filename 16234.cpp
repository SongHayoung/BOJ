#include <iostream>
#include <memory.h>
#include <algorithm>
#include <queue>

using namespace std;

int map[50][50];
int group_div[2501];
int group[50][50];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int N,L,R;
int ans = 0;


void print()
{
    cout<<"DAY "<<ans<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<map[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void BFS()
{
    memset(group,0,sizeof(group));
    int group_num=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            group_num++;
            if(group[i][j]!=0)
                continue;
            group[i][j]=group_num;
            queue<pair<int,int>> q;
            int members = 0;
            int total_members = 0;
            q.push(make_pair(i,j));
            while(!q.empty())
            {
                int cur_y = q.front().first;
                int cur_x = q.front().second;
                q.pop();
                members++;
                total_members += map[cur_y][cur_x];
                for(int k=0;k<4;k++)
                {
                    int next_y = cur_y + dy[k];
                    int next_x = cur_x + dx[k];
                    if(0<=next_x&&next_x<N && 0<=next_y&&next_y<N)
                    {
                        if(group[next_y][next_x]==0) {
                            int population = abs(map[cur_y][cur_x] - map[next_y][next_x]);
                            if (L <= population && population <= R) {
                                q.push(make_pair(next_y, next_x));
                                group[next_y][next_x] = group_num;
                            }
                        }
                    }
                }
            }
            group_div[group_num]=total_members/members;
        }
    int map_prev[50][50];
    memcpy(map_prev,map,sizeof(map_prev));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            map[i][j] = group_div[group[i][j]];
        }
    //print();
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(map_prev[i][j]!=map[i][j])
            {
                ans++;
                return;
            }
        }
    }
}

int main(void)
{
    cin>>N>>L>>R;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            cin>>map[i][j];
            }

        while(1)
        {
            int prev_ans = ans;
            BFS();
            if(ans==prev_ans)
            {
                cout<<ans<<endl;
                return 0;
            }
        }
}
