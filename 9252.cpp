#include <iostream>
#include <algorithm>
using namespace std;
short dp[1001][1001];
int main() {
    string a, b;
    cin>>a>>b;
    for(int i = 1; i <= a.length(); i++)
        for(int j = 1; j <=b.length(); j++)
            dp[i][j] = a[i-1] == b[j-1] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);
   cout<<dp[a.length()][b.length()]<<"\n";
   string ans="";
   int x = b.length(), y = a.length();
   while(dp[y][x]) {
       while(dp[y-1][x-1]==dp[y][x]) {
           y--;x--;
       }
       while(dp[y-1][x]==dp[y][x]) y--;
       while(dp[y][x-1]==dp[y][x]) x--;
       if(b.length() < a.length())
           ans += b[--x], --y;
       else
           ans += a[--y], --x;
   }
   reverse(ans.begin(),ans.end());
   if(dp[a.length()][b.length()])
        cout<<ans;
}
