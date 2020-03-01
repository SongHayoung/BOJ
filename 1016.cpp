#include <stdio.h>
int main() {
	long m1, m2;
	bool ssJGS[1000001] = { false, };
	scanf("%ld %ld", &m1, &m2);
    register long i, from, answer = m2-m1+1;
	for (from = !(m1 / 4 * 4 ^ m1) ? 0 : (m1 / 4 + 1) * 4 - m1; from <= m2 - m1; from += 4) {
		if (!ssJGS[from]) {
			ssJGS[from] = true;
			--answer;
		}
	}
	for (from = !(m1 / 9 * 9 ^ m1) ? 0 : (m1 / 9 + 1) * 9 - m1; from <= m2 - m1; from += 9) {
		if (!ssJGS[from]) {
			ssJGS[from] = true;
			--answer;
		}
	}
	for (from = !(m1 / 25 * 25 ^ m1) ? 0 : (m1 / 25 + 1) * 25 - m1; from <= m2 - m1; from += 25) {
		if (!ssJGS[from]) {
			ssJGS[from] = true;
			--answer;
		}
	}
	for (i = 7; (i*i) <= m2; i += 2) {
		if (!(i % 3)) continue;
		if (!(i % 5)) continue;
		for (from = !(m1 / (i*i)*i*i^m1) ? 0 : (m1 / (i*i) + 1)*i*i - m1; from <= m2 - m1; from += i * i) {
			if (!ssJGS[from]) {
				ssJGS[from] = true;
				--answer;
			}
		}
	}
	printf("%ld", answer);
}
