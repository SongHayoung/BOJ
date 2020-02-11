#include <iostream>
#include <algorithm>
#include <memory.h>
#define mod 10007
using namespace std;
int dp[500][500];
int map[500][500];
int N,M;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int func(int x, int y)
{
    if(x==N-1&&y==M-1)
        return 1;

    int &ret = dp[x][y];
    if(ret != -1)
        return ret;
    ret = 0;
    for(int i=0;i<4;i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(next_x<0||next_x>=N||next_y<0||next_y>=M)
            continue;
        if(map[x][y]>map[next_x][next_y])
            ret += func(next_x,next_y);
    }
    return ret;


}

int main(void) {
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>map[i][j];

    memset(dp,-1,sizeof(dp));
    cout<<func(0,0)<<endl;
}
