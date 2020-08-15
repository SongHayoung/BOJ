#include <iostream>
#include <algorithm>
using namespace std;
int n, m, day;
int dp[106][41];
bool stay[101];
int dpf(int d, int c) {
    if(dp[d][c] != 987654321) return dp[d][c];
    if(stay[d]) return dp[d][c] = dpf(d+1,c);
    dp[d][c] = min(min(min(dp[d][c], dpf(d + 1, c) + 10),dpf(d+3,c+1) + 25),dpf(d+5,c+2) + 37);
    if(c >= 3) dp[d][c] = min(dp[d][c],dpf(d+1,c-3));
    return dp[d][c];
}
int main(void) {
    scanf("%d %d",&n, &m);
    for(int i = 0; i < m; ++i){
        scanf("%d",&day);
        stay[day] = true;
    }
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j < 41; ++j)
            dp[i][j] = 987654321;
    printf("%d",dpf(1,0));
    if(dpf(1,0))printf("000");
}
