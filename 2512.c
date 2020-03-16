#include <stdio.h>
int budget[10000];
int main(int argc, char** argv) {
	int N, M, left = 0, right = 0 , mid, c, answer = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &budget[i]);
		right = right > budget[i] ? right : budget[i];
	}
	scanf("%d", &M);
	while (left <= right) {
		mid = (left + right) / 2;
		c = 0;
		for (int i = 0; i < N; i++) {
			budget[i] > mid ? (c += mid) : (c += budget[i]);
			if (c > M) { right = mid - 1; break; }
		}
		if (c <= M) {
			left = mid + 1;
			answer = answer > mid ? answer : mid;
		}
	}
	printf("%d", answer);
}
