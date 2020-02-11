#include <iostream>

using namespace std;

#define endl '\n'

int N,S,M;
bool dp[1001];
int arr[101];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>S>>M;
    for(int i=0;i<N;i++)
        cin>>arr[i];

    dp[S]=true;
    for(int i=0;i<N;i++)
    {
        bool choose[1001] = {false,};
        for(int j=0;j<=M;j++)
        {
            if(dp[j])
            {
                if(j+arr[i]<=M)
                    choose[j+arr[i]]=true;
                if(j-arr[i]>=0)
                    choose[j-arr[i]]=true;
            }
        }
        for(int j=0;j<=M;j++)
            dp[j]=choose[j];
    }
    for(int i=M;i>=0;i--)
        if(dp[i])
        {
            cout<<i<<endl;
            return 0;
        }
    cout<<"-1"<<endl;
        return 0;
}

