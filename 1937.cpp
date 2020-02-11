#include <iostream>
#include <algorithm>
#include <memory.h>
#define mod 10007
using namespace std;
int dp[500][500];
int map[500][500];
int N;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int ans=0;

int func(int x, int y)
{
    int &ret = dp[x][y];
    if(ret != -1)
        return ret+1;
    ret = 0;
    for(int i=0;i<4;i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(next_x<0||next_x>=N||next_y<0||next_y>=N)
            continue;
        if(map[x][y]<map[next_x][next_y])
            ret = max(ret, func(next_x,next_y));
    }
    return ret+1;
}

int main(void) {
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>map[i][j];

    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            ans = max(ans,func(i,j));
        }
    cout<<ans<<endl;
}
