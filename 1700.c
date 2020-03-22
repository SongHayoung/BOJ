#include <stdio.h>
#include <memory.h>
int use[100];
int mtap[100];
int holes, K, ans = 0;
void OPT() {
	int predict[101];
	int hole = 0;
	for (int i = 0; i < K; ++i) {
		int flag = 0;
		for (int j = 0; j < hole; ++j)
			if (mtap[j] == use[i]) { flag = 1; break; }
		if (flag) continue;
		if (hole < holes) {
			mtap[hole] = use[i];
			++hole;
		}
		else {
			memset(predict, 0, sizeof(int)*(K+1));
			for (int j = i; j < K; ++j) {
				if (predict[use[j]]==0) predict[use[j]] = j;
			}
			int umax = 0;
			for (int j = 0; j < hole; ++j) {
				if (!predict[mtap[j]]) { flag = j;	break;	}
				else if (umax < predict[mtap[j]]) {
						umax = predict[mtap[j]];
						flag = j;
					}
			}
			++ans;
			mtap[flag] = use[i];
		}
	}
}
int main() {
	scanf("%d %d", &holes, &K);
	for (int i = 0; i < K; ++i)
		scanf("%d", &use[i]);
	OPT();
	printf("%d", ans);
}
