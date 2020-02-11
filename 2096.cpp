#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int N;
int arr[3];
int dp[3][2];
int choose[3];

int main(void)
{
    cin>>N;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<N;i++)
    {
        cin>>arr[0]>>arr[1]>>arr[2];

        choose[0]=max(arr[0]+dp[0][0],arr[0]+dp[1][0]);

        choose[1]=max(arr[1]+dp[2][0],max(arr[1]+dp[0][0],arr[1]+dp[1][0]));

        choose[2]=max(arr[2]+dp[1][0],arr[2]+dp[2][0]);

        dp[0][0]=choose[0];
        dp[1][0]=choose[1];
        dp[2][0]=choose[2];

        choose[0]=min(arr[0]+dp[0][1],arr[0]+dp[1][1]);

        choose[1]=min(arr[1]+dp[2][1],min(arr[1]+dp[0][1],arr[1]+dp[1][1]));

        choose[2]=min(arr[2]+dp[1][1],arr[2]+dp[2][1]);

        dp[0][1]=choose[0];
        dp[1][1]=choose[1];
        dp[2][1]=choose[2];
    }
    cout<<max(max(dp[0][0],dp[1][0]),dp[2][0])<<" "<<min(min(dp[0][1],dp[1][1]),dp[2][1])<<endl;
}
