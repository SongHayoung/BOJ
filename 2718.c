#include <stdio.h>
int dp[101] = { 1,1,5,11 };
int main(void) {
	int N,n;
	scanf("%d", &N);
	for (int i = 4; i <= 100; ++i) {
		dp[i] = (dp[i - 2]<<2) + dp[i - 1];
		for (int j = 3; j <= i; j++)
			dp[i] += j & 1 ? (dp[i - j]<<1) : dp[i - j] * 3;
	}
	while (N--) {
		scanf("%d", &n);
		printf("%d ", dp[n]);
	}
	return 0;
}
