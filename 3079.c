#pragma optimize("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <stdio.h>
#define gc() getchar_unlocked()
#define MID(a,b) ((a)+((b-a)>>1))
#define REP(i,a,b) for(int i = a; i < b; i++)
#define FRI1(i) for(;48>i||57>i;i=gc());
#define ull unsigned long long
#define reg register
#define pf(a) printf("%llu",a);
#define IF(a,b) (((a)>=(b)) ? (1) : (0))
#define FFF(a,b) ((a<<3)+(a<<1)+(b&0b1111));
int K[100000];
int fRI(){
	int ret = 0, N = gc();
	for (; 0x30>N || N>0x3A; N = gc());
	for (; 0x30 <= N && N <= 0x3A; N = gc()) ret = FFF(ret, N)
	return ret;
}
int main(int argc, char** argv) {
	reg int i, N = fRI(), M = fRI();
	REP(i,0,N) K[i] = fRI();
	reg ull left = 1, right = 0xfffffffffffffff, mid, sum;
	while (left!=right) {
		mid = MID(left, right);
		sum = 0;
		REP(i, 0, N) if (IF(sum += mid / K[i],M)) break;
		IF(sum,M) ? right = mid : left = mid + 1;
	}
	pf(left)
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
