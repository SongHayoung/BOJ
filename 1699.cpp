#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int dp[100001];
int N;

int main(void) {
    memset(dp,0,sizeof(dp));
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        dp[i] = i;
        for(int j=1;j*j<=i;j++)
        {
            dp[i] = min(dp[i],dp[i-j*j]+1);
        }
    }
    cout<<dp[N]<<endl;
}
