#include <iostream>
using namespace std;
int dp[5][5][100000], n, i;
void init(int val) {
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            dp[i][j][val] = 987654321;
}
int getAns(int val) {
    int ans = 987654321;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            ans = min(ans, dp[i][j][val]);
    return ans;
}
int main() {
    init(0);
    dp[0][0][0] = 0;
    for(i = 0; i < 100001; i++) {
        scanf("%d",&n);
        if(!n) break;
        init(i+1);
        for(int l = 0; l < 5; l++)
            for(int r = 0; r < 5; r++) {
                if(dp[l][r][i] == 987654321) continue;
                dp[n][r][i+1] = min(dp[n][r][i+1], dp[l][r][i] + (l == n ? 1 : l == 0 ? 2 : (l&1) == (n&1) ? 4 : 3));
                dp[l][n][i+1] = min(dp[l][n][i+1], dp[l][r][i] + (r == n ? 1 : r == 0 ? 2 : (r&1) == (n&1) ? 4 : 3));
                }
    }
    printf("%d",getAns(i));
}
