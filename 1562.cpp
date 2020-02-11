#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
using namespace std;

#define MAXSIZE 101
#define devide 1000000000
int cache[MAXSIZE][MAXSIZE][1024];
int n;

int ans_func(int last, int left,int used)
{
    if(left==0)
    {
        if(used==1023)
            return 1;
        else
            return 0;
    }
    int &ret = cache[last][left][used];
    
    if(ret!=-1)
        return ret;
    
    if(last==0)
        ret = ans_func(1,left-1,used|2);
    else if(last==9)
        ret = ans_func(8,left-1,used|256);
    else
    {
        int use1 = used|(1<<(last-1));
        int use2 = used|(1<<(last+1));
        ret = ans_func(last-1,left-1,use1) + ans_func(last+1,left-1,use2);
    }
    ret %= devide;
    return ret;
}

int main(void)
{
    int ans=0;
    cin>>n;
    memset(cache,-1,sizeof(cache));
    for(int i=1;i<=9;i++)
    {
        int use = 1<<i;
        ans = (ans + ans_func(i,n-1,use))%devide;
    }
    
    cout<<ans<<endl;
    
}
