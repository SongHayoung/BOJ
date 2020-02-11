#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

#define MAXSIZE 17
int map[MAXSIZE][MAXSIZE];
int cache[MAXSIZE][MAXSIZE][3];
int N;
int ans;

int dp(int y, int x, int type)
{
    if(x>N||y>N)
        return 0;
    int &ret = cache[y][x][type];
    if(ret!=-1)
        return ret;
    
    ret = 0;
    switch (type) {
        case 0:
        {
            if(!map[y][x])
            {
                if(x==N&&y==N)
                {
                    ret = 1;
                    return 1;
                }
                else
                    ret = dp(y,x+1,0) + dp(y+1,x+1,2);
            }
            else
                return 0;
            break;
        }
        case 1:
        {
            if(!map[y][x])
            {
                if(x==N&&y==N)
                {
                    ret = 1;
                    return 1;
                }
                else
                    ret = dp(y+1,x,1) + dp(y+1,x+1,2);
            }
            else
                return 0;
            break;
        }
        case 2:
        {
            if(!map[y][x]&&!map[y-1][x]&&!map[y][x-1])
            {
                if(x==N&&y==N)
                {
                    ret = 1;
                    return 1;
                }
                else
                    ret = dp(y,x+1,0) + dp(y+1,x,1) + dp(y+1,x+1,2);
            }
            else
                return 0;
            break;
        }
        default:
            return 0;
            break;
    }
    
    return ret;
}

int main(void)
{
    cin>>N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin>>map[i][j];
    
    memset(cache,-1,sizeof(cache));
    ans = dp(1,2,0);
    cout<<ans<<endl;
}
