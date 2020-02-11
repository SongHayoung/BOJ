#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF 987654321
int N;
int arr[17][17];
int dp[17][1<<16];

int tsp(int visit, int pos)
{
    if(visit==(1<<N)-1)
    {
        if(arr[pos][0]!=0)
            return arr[pos][0];
        return INF;
    }

    int &ret = dp[pos][visit];

    if(ret!=-1)
        return ret;

    ret = INF;

    for(int i=1;i<N;i++)
        if(!(visit&(1<<i))&&(arr[pos][i]!=0))
            ret = min(ret,tsp(visit|1<<i,i)+arr[pos][i]);

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>arr[i][j];
    
    memset(dp,-1,sizeof(dp));
    cout<<tsp(1, 0)<<endl;

}

