#include <cstdio>
#include <algorithm>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
int main(int argc, char** argv){
	register int N, A, B, answer = 0; int a[2000], b[3000];
	scanf("%d %d %d", &N, &A, &B);
	for (int i = 0; i < A; i++)
		scanf("%d",a + i);
	for (int i = 0; i < B; i++)
		scanf("%d", b + i);
	sort(a, a+A);
	if (N & 1) answer += a[--A];
	N >>= 1;
	for (int i = 0; i < (A>>1); i++) 
		b[B++] = a[A - (i<<1) - 1] + a[A - (i<<1) - 2];
	sort(b, b + B);
	for (int i = 0; i < N; i++)
		answer += b[B - i - 1];
	printf("%d", answer);
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
