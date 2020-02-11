#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXSIZE 1000

int N;
vector<int> cells;
int cache[31];
int ans;

int dp(int idx)
{
    int &ret = cache[idx];
    if(ret!=-1)
        return ret;
    
    ret = 3*dp(idx-2);
    for(int i=idx-4;i>=0;i-=2)
    {
        ret += 2*dp(i);
    }
    return cache[idx];
}
int main(void)
{
    cin>>N;
    if(N%2==1)
    {
        cout<<"0"<<endl;
        return 0;
    }
    memset(cache,-1,sizeof(cache));
    cache[0]=1;
    cache[1]=0;
    cache[2]=3;
    ans = dp(N);
    cout<<ans<<endl;
}
