#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <memory.h>

using namespace std;

#define MAXSIZE 100
long long dp[MAXSIZE][2];
int n;
long long ans=0;

long long func(int idx,int prev)
{
    if(idx==n)
        return 1;
    
    long long &ret = dp[idx][prev];
    if(ret!=-1)
        return ret;

    if(prev==1)
    {
        ret = func(idx+1,0);
    }
    else
        ret = func(idx+1,1) + func(idx+1,0);
    
    return ret;
}

int main(void)
{
    cin>>n;
    memset(dp,-1,sizeof(dp));
    ans = func(1,1);
    cout<<ans<<endl;
}
