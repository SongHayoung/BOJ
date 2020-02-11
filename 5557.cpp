#include <iostream>
#include <memory.h>

using namespace std;

#define endl '\n'

int N;
unsigned  long long dp[101][21];
int arr[101];

unsigned long long func(int idx,int cur)
{
    if(cur<0||cur>20)
        return 0;

    if(idx==0)
    {
        if(cur==arr[0])
            return 1;
        else
            return 0;
    }

    unsigned long long &ret = dp[idx][cur];

    if(ret!=-1)
        return ret;

    ret = func(idx-1,cur+arr[idx]) + func(idx-1,cur-arr[idx]);

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>arr[i];

    memset(dp,-1,sizeof(dp));

    cout<<func(N-2,arr[N-1])<<endl;
}

