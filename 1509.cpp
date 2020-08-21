#include <iostream>
#include <memory.h>
using namespace std;
bool pal[2501][2501];
short dp[2501];
int len;
string s;
void func(int f, int e) {
    pal[f][e] = true;
    if (f && e < len && s[f - 1] == s[e + 1])
        func(f - 1, e + 1);
}

short dpf(int n) {
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];
    dp[n] = dpf(n-1);
    for(int i = n - 1; i >= 0; --i)
        if(pal[i][n])
            dp[n] = min(dp[n], dpf(i - 1));
    return ++dp[n];
}

int main(void) {
    cin>>s;
    len = s.length();
    for (int i = 0; i <len; ++i) {
        func(i, i);
        if(s[i] == s[i+1])
            func(i, i + 1);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d",dpf(len - 1));
}
