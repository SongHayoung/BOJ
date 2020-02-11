#include <iostream>
#include <algorithm>
#include <memory.h>
#define mod 10007
using namespace std;
int dp[1001][1001];
int N,K;
int func(int n, int k)
{
    if(n==k)
        return 1;
    if(k==0)
        return 1;

    int &ret = dp[n][k];
    if(ret != -1)
        return ret;

    ret = (func(n-1,k-1)+func(n-1,k))%mod;

    return ret;
}

int main(void) {
    memset(dp,-1,sizeof(dp));
    cin>>N>>K;
    dp[1][0]=1;
    cout<<func(N,K)<<endl;
}
