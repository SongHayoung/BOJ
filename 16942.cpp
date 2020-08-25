#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
string s;
short ans = 1, len, dp[1001];
short dpf(int n) {
    if(dp[n] != -1) return dp[n];
    dp[n] = 1;
    for(int i = n + 1; i < len; i += 2)
        if(s[n] == s[i])
            dp[n] = max(dp[n], (short)(dpf(i) + 1));
    return dp[n];
}
int main(void) {
    cin >> s;
    memset(dp, -1, sizeof(dp));
    len = s.length();
    for(int i = 0; i < len; ++i)
        ans = max(dpf(i), ans);
    printf("%d",ans);
}
