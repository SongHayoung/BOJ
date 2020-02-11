#include <iostream>
#include <memory.h>
#include <string>

using namespace std;


int main(void)
{
    string str;
    int dp[5001];
    cin>>str;
    if(str.at(0)=='0') {
        cout << "0" << endl;
        return 0;
    }
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=str.length();i++)
    {
        if(str.at(i-1)!='0')
            dp[i]=dp[i-1];
        int x = (str.at(i-2)-48)*10+str.at(i-1)-48;
        if(10<=x&&x<=26)
            dp[i]=(dp[i]+dp[i-2])%1000000;
    }
    cout<<dp[str.length()]<<endl;

}
