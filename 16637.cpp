#include <iostream>
#include <memory.h>
#include <cstring>
#include <string>

using namespace std;

string str;
int ans=-2147483648;
int N;
int i_arr[20],i_idx=0,c_idx=0;;
char c_arr[10];

int calc(int a, int b, char c)
{
    if(c == '+')
        return a+b;
    else if(c == '-')
        return a-b;
    else if(c == '*')
        return a*b;
    return 0;
}

void DFS(int idx,int res)
{
    if(idx>=N/2)
    {
        ans = max(ans,res);
        return ;
    }
    
    int result = calc(res,i_arr[idx+1],c_arr[idx]);
    DFS(idx+1,result);
    
    if(idx+1<N/2)
    {
        int result2 = calc(i_arr[idx+1],i_arr[idx+2],c_arr[idx+1]);
        int result3 = calc(res,result2,c_arr[idx]);
        DFS(idx+2,result3);
    }
    
    
    return ;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin>>N;
    cin>>str;
    
    
    for(int i=0;i<str.length();i++)
    {
        if(i%2==0)
            i_arr[i_idx++] = str[i]-48;
        else
            c_arr[c_idx++] = str[i];
    }
    
    
    if(str.length()==1)
    {
        cout<<i_arr[0]<<endl;
        return 0;
    }
    else if(str.length()==3)
    {
        ans = calc(i_arr[0],i_arr[1],c_arr[0]);
    }
    else
        DFS(0,i_arr[0]);
    
    cout<<ans<<endl;
    
}
