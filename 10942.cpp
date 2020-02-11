#include <iostream>
#include <memory.h>

using namespace std;

#define endl '\n'

int N,M,S,E;
int dp[2001][2001];
int arr[2001];

int func(int s, int e)
{
    if(s==e)
        return 1;
    if(s+1==e&&arr[s]==arr[e])
        return 1;

    int &ret = dp[s][e];
    if(ret!=-1)
        return ret;
    ret = 0;
    if(arr[s]==arr[e])
        ret = func(s+1,e-1);

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>arr[i];

    memset(dp,-1,sizeof(dp));
    cin>>M;
    for(int i=0;i<M;i++)
    {
        cin>>S>>E;
        cout<<func(S,E)<<endl;
    }

}

