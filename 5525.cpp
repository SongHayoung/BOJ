#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <memory.h>

using namespace std;

#define MAXSIZE 100
long long dp[MAXSIZE][2];
int n,m;
string s, comp;
long long ans=0;

int main(void)
{
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)
    {
        if(s[i]=='O')
            continue;
        if(s[i+1]=='O'&&s[i+2]=='I')
        {
            int cnt=0;
            while(s[i+1]=='O'&&s[i+2]=='I')
            {
                i+=2, cnt++;
                if(s[i]=='I'&&cnt==n)
                {
                    cnt--, ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}
