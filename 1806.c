#include <stdio.h>
#define gc() getchar_unlocked()
long psum[100001];
int fRI(){
    int N=gc(),ret = 0;
    for(;N<48||N>57;N=gc());
    do{
        ret = (ret<<3) + (ret<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return ret;
}
int main() {
	register int N = fRI(), target = fRI(), ans = 100002, i, j;
	for (i = 1; i <= N; ++i) psum[i] = fRI() + psum[i - 1];
	for (i = 0; i < N; ++i)
		for (j = i + 1; j <= N && j < i + ans; ++j)
			if (psum[j] >= target + psum[i]) {
				ans = j - i; break;
			}
	printf("%d", ans==100002 ? 0 : ans);
}
