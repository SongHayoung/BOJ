#include <stdio.h>
#include <vector>
using namespace std;
int dp[10000001];
int n, m, ans = 987654321, sum;
int mem[100];
int c;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i < 10000001; i++)
        dp[i] = 987654321;
    for(int i = 0; i < n; i++)
        scanf("%d",&mem[i]);
    for(int i = 0; i < n; i++) {
        scanf("%d",&c);
        for(int j = sum += mem[i]; j >= mem[i]; j--)
            dp[j] = min(dp[j], dp[j - mem[i]] + c);
    }
    for(int i = m; i < 10000001; i++)
        ans = min(ans,dp[i]);
    printf("%d",ans);
}
