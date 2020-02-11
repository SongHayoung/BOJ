#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool noans;
int N,M;
int arr[300][300];
int arr_cpy[300][300];
bool visit[300][300];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void BFS(int x, int y)
{
    memcpy(arr_cpy,arr,sizeof(arr_cpy));

    queue<vector<int>> q;
    vector<int> start;
    start.push_back(x);
    start.push_back(y);
    visit[x][y]=true;
    int start_de=0;
    for(int i=0;i<4;i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if(new_x<0||new_y<0||new_x>=N||new_y>=M)
            continue;

        if(arr_cpy[new_x][new_y]==0)
            start_de++;
    }
    arr[x][y]-=start_de;
    if(arr[x][y]<0)
        arr[x][y]=0;

    q.push(start);
    while(!q.empty())
    {
        int cur_x = q.front()[0];
        int cur_y = q.front()[1];
        q.pop();

        for(int i=0;i<4;i++)
        {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if(next_x<0||next_y<0||next_x>=N||next_y>=M)
                continue;
            if(!visit[next_x][next_y]&&arr_cpy[next_x][next_y]!=0)
            {
                vector<int> item;
                item.push_back(next_x);
                item.push_back(next_y);
                q.push(item);
                visit[next_x][next_y]=true;
                int decrease = 0;
                for(int j=0;j<4;j++)
                {
                    int new_x = next_x + dx[j];
                    int new_y = next_y + dy[j];

                    if(new_x<0||new_y<0||new_x>=N||new_y>=M)
                        continue;

                    if(arr_cpy[new_x][new_y]==0)
                        decrease++;
                }
                arr[next_x][next_y]-=decrease;
                if(arr[next_x][next_y]<0)
                    arr[next_x][next_y]=0;
            }
        }
    }
}


int main(void) {
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>arr[i][j];
    int ans=0;
    while(1) {
        bool devide = false;

        memset(visit,false,sizeof(visit));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if(arr[i][j]!=0&&!visit[i][j])
                {
                    if(devide)
                    {
                        cout<<ans-1<<endl;
                        return 0;
                    }
                    visit[i][j]=true;
                    devide = true;
                    BFS(i,j);
                    ans++;
                }
            }


        int total = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                total += arr[i][j];
            }

        if(total==0) {
            cout << "0" << endl;
            return 0;
        }
    }

}
