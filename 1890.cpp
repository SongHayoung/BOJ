#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXSIZE 100
int N;
int map[MAXSIZE][MAXSIZE];
long long cache[MAXSIZE][MAXSIZE];

long long dp(int x, int y)
{
    if(x>=N||y>=N||map[x][y]==0)
        return 0;
    
    long long &ret = cache[x][y];
    if(ret != -1)
        return ret;
    
    ret = dp(x+map[x][y], y)+dp(x,y+map[x][y]);
    return ret;
    
}
int main(void)
{
    cin>>N;
    memset(cache,-1,sizeof(cache));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>map[i][j];
        }
    }
    
    cache[N-1][N-1]=1;
    map[N-1][N-1]=1;
    dp(0,0);
    cout<<cache[0][0]<<endl;
}
