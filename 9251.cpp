#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001][1001];
int lcs(string &a, string &b) {
    for(int i = 1; i <= a.length(); i++)
        for(int j = 1; j <=b.length(); j++)
            dp[i][j] = a[i-1] == b[j-1] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);
    return dp[a.length()][b.length()];
}
int main() {
    string a, b;
    cin>>a>>b;
    cout<<lcs(a,b);
}
