#include <iostream>
using namespace std;
short dp[4001][4001], ans;
int main(){
    string a, b;
    cin>>a>>b;
    for(int i = 1; i <= a.length(); i++)
        for(int j = 1; j <= b.length(); j++)
            if(a[i-1] == b[j-1])
                ans=max(ans, dp[i][j] = dp[i-1][j-1] + 1);
    printf("%d",ans);
}
