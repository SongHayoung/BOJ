#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool noZero = true;
int N,M,H;
int arr[101][101][101];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int ans = 0;
queue<vector<int>> q;

void BFS()
{
    while(!q.empty())
    {
        int cur_x = q.front()[0];
        int cur_y = q.front()[1];
        int cur_h = q.front()[2];
        int days = q.front()[3];
        ans = max(ans,days);
        q.pop();
        for(int i=0;i<6;i++)
        {
            if(i<4)
            {
                int next_x = cur_x + dx[i];
                int next_y = cur_y + dy[i];
                int next_h = cur_h;

                if(next_x<0||next_y<0||next_h<0||next_x>=N||next_y>=M||next_h>=H)
                    continue;

                if(arr[next_x][next_y][next_h]==0)
                {
                    vector<int> item;
                    item.push_back(next_x);
                    item.push_back(next_y);
                    item.push_back(next_h);
                    item.push_back(days+1);
                    arr[next_x][next_y][next_h]=days+1;
                    q.push(item);
                }
            }
            else
            {
                int next_x = cur_x;
                int next_y = cur_y;
                int next_h = (i==4)?cur_h-1:cur_h+1;

                if(next_x<0||next_y<0||next_h<0||next_x>=N||next_y>=M||next_h>=H)
                    continue;
                if(arr[next_x][next_y][next_h]==0)
                {
                    vector<int> item;
                    item.push_back(next_x);
                    item.push_back(next_y);
                    item.push_back(next_h);
                    item.push_back(days+1);
                    arr[next_x][next_y][next_h]=days+1;
                    q.push(item);
                }
            }
        }
    }
}


int main(void) {
    cin>>M>>N>>H;
    for(int i=0;i<H;i++) {
        for(int j=0;j<N;j++) {
            for (int k = 0; k < M; k++) {
                cin >> arr[j][k][i];
                if(arr[j][k][i]==0)
                 noZero=false;
                if(arr[j][k][i]==1)
                {
                    vector<int> start;
                    start.push_back(j);
                    start.push_back(k);
                    start.push_back(i);
                    start.push_back(1);
                    q.push(start);
                }
            }
        }
    }
    if(noZero) {
        cout << "0" << endl;
        return 0;
    }


    BFS();

    for(int i=0;i<H;i++)
    {
        for(int j=0;j<N;j++) {
            for (int k = 0; k < M; k++) {
                if(arr[j][k][i]==0)
                {
                    cout<<"-1"<<endl;
                    return 0;
                }
            }

        }
    }
    cout<<ans-1<<endl;
}
