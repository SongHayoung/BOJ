#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
int dp[2][1000][1000],tc, n;
int cards[1000];
int dpf(int f, int e, int turn) {
    return dp[turn][f][e] != -1 ? dp[turn][f][e] : f == e ? turn ? 0 : cards[f] : dp[turn][f][e] = turn ? min(dpf(f+1, e, turn ^ 1), dpf(f,e - 1, turn ^ 1)) : max(dpf(f + 1, e, turn ^ 1) + cards[f], dpf(f, e-1, turn ^ 1) + cards[e]);
}
int main() {
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            scanf("%d",&cards[i]);
        memset(dp,-1,sizeof(dp));
        printf("%d\n", dpf(0, n-1, 0));
    }
}
