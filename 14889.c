#include <stdio.h>
int avlity[20][20];
int team[20];
int ans = 987654321, N;
void DFS(int c,int t1,int t2) {
	if (!ans) return;
	if (c == N) {
		int cmp = 0;
		for(int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) {
				if (team[i] == 1 && team[i] == team[j])
					cmp += avlity[i][j];
				else if (team[i] == 2 && team[i] == team[j])
					cmp -= avlity[i][j];
			}
		if (cmp < 0) cmp *= -1;
		ans = ans > cmp ? cmp : ans;
	}
	else if (t1 == (N >> 1)) {
		team[c] = 2;
		DFS(c + 1, t1,t2+1);
	}
	else if (t2 == (N >> 1)) {
		team[c] = 1;
		DFS(c + 1, t1 + 1, t2);
	}
	else {
		team[c] = 1;
		DFS(c + 1, t1 + 1,t2);
		team[c] = 2;
		DFS(c + 1, t1,t2+1);
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf("%d", &avlity[i][j]);
	team[0] = 1;
	DFS(1, 1, 0);
	printf("%d", ans);
}
