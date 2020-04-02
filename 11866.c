#include <stdio.h>
int v[1001];
int main(void) {
	int N, K, s = 1, c = 0, ss = 0;
	scanf("%d %d", &N, &K);
	printf("<");
	while (c < N) {
		while (ss < K) {
			if (!v[s]) ++ss;
			if (ss == K) break;
			s = s + 1 > N ? 1 : s + 1;
		}
		v[s] = 1; ++c; ss = 0;
		printf("%d", s);
		if (c != N) printf(", ");
		s = s + 1 > N ? 1 : s + 1;
	}
	printf(">");

}
