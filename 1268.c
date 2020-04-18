#include <stdio.h>
int s[1000][5];
int info[1000];
int close[1000][1000];
int N, val, ans;
int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d %d %d %d %d", &s[i][0], &s[i][1], &s[i][2], &s[i][3], &s[i][4]);
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < N - 1; ++j)
			for (int k = j + 1; k < N; ++k) {
				if (close[j][k]) continue;
				if (s[j][i] == s[k][i]) {
					++info[j], ++info[k];
					close[j][k] = close[k][j] = 1;
				}
			}
	for (int i = 0; i < N; ++i)
		if (info[i] > val) val = info[i], ans = i;
	printf("%d", ans + 1);

}
