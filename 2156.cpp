#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int N;
long long ans=0;
long long dp[10001][2];
long long arr[10001];
long long dy(int n,int time)
{
    if(n>N)
        return 0;
    long long &ret = dp[n][time];
    if(ret!=-1)
        return ret;

    ret = 0;
    if(time==0)
    {
        ret = max(ret,dy(n+1,1));
        ret = max(ret,dy(n+2,0));
    }
    if(time==1) {
        ret = max(ret, dy(n + 2, 0));
        ret = max(ret, dy(n+3,0));
    }

    ret = ret + arr[n];
    return ret;
}
int main(void) {
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>arr[i];

    memset(dp,-1,sizeof(dp));
    ans = dy(1,0);
    ans = max(ans, dy(2,0));
    cout<<ans<<endl;
}
