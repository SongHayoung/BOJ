#include <stdio.h>
#define gF(a, b) (!(((a) / ((b)*(b))*((b)*(b)))^m1)) ? (0) : ((((a) / ((b)*(b)) + 1)*((b)*(b))) - (a))
#define mul(a) ((a)*(a))
const int PREV[3] = { 2,3,5 };
int main() {
	long m1, m2;
	bool ssJGS[1000001] = { false, };
	scanf("%ld %ld", &m1, &m2);
	register long i, from, answer = m2 - m1 + 1;
	for (i = 0; i < 3; i++)
		for (from = gF(m1, PREV[i]); from <= m2 - m1; from += mul(PREV[i]))
			if (!ssJGS[from]) ssJGS[from] = answer--;
	for (i = 7; (i*i) <= m2; i += 2) {
		if (!(i % 3)) continue;
		if (!(i % 5)) continue;
		for (from = gF(m1, i); from <= m2 - m1; from += mul(i))
			if (!ssJGS[from]) ssJGS[from] = answer--;
	}
	printf("%ld", answer);
}
