#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>

using namespace std;

#define mod 1000000000
int N;
long long ans=0;
long long dp[101][10];

long long func(int num, int length)
{
    long long &ret = dp[length][num];
    if(ret!=-1)
        return ret;
    ret = 0;
    if(num==0)
        ret = func(1,length-1) % mod;
    else if(num==9)
        ret = func(8,length-1) % mod;
    else
        ret = (func(num+1,length-1) + func(num-1,length-1)) % mod;

    return ret;
}

int main(void) {

    cin>>N;
    memset(dp,-1,sizeof(dp));

    for(int i=0;i<=9;i++)
        dp[1][i] = 1;

    for(int i=1;i<=9;i++) {
        ans += func(i, N);
        ans = ans % mod;
    }

    cout<<ans % mod<<endl;
}
