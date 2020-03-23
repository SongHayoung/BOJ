#include <stdio.h>
int NUM[30];
int main() {
	char i, token, N, from = 0;
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &NUM[from]);
		from = (from + NUM[from]) % N;
		while (NUM[from]&&i!=N-1) from = (++from) % N;
	} /* end of for */
	printf("%d\n", N);
	for (i = 0; i < N; ++i)
		printf("%d ", NUM[i]);
	
	return(0);
} /* end of main() */
