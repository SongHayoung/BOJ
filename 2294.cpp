#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXSIZE 1000000
int N, K;
int num;
int cache[MAXSIZE];
int ans = -1;

int dp(int money)
{
    int &ret = cache[money];
    if(ret!=11000)
        return ret;
    ret = 10001;
    for(int i=1;i<=money/2;i++)
    {
        ret = min(ret,dp(i)+dp(money-i));
    }
    return ret;
}
int main(void)
{
    cin>>N>>K;
    for(int i=0;i<MAXSIZE;i++)
        cache[i]=11000;
    
   for(int i=0;i<N;i++)
    {
        cin>>num;
        cache[num]=1;
    }
    dp(K);
    if(cache[K]>10000)
        cout<<"-1"<<endl;
    else
        cout<<cache[K]<<endl;
}
