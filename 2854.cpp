#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
int arr1[100001], arr2[100001], n;
long long dp[100001][2];
int main(void) {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &arr1[i]);
    for(int i = 1; i < n; ++i)
        scanf("%d", &arr2[i]);
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = ((dp[i-1][0] * (arr1[i] + arr2[i-1])) + dp[i-1][1] * (arr1[i] + arr2[i-1] -1))%MOD;
        dp[i][1] = (arr2[i] * (dp[i-1][1] +dp[i-1][0])) % MOD;
    }
    printf("%d\n",dp[n][0]);
}
