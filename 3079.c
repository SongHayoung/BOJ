#include <stdio.h>
#define gc() getchar_unlocked()
int arr[100000];
int N, M;
int fastREADINT() {
	int ret = 0, flag = 1, N=gc();
	for(;'0'>N||N>'9';N=gc())
		if (N == '-') {
			flag = -1;
			N = gc(); break;
		}
	for (; '0' <= N && N <= '9'; N = gc())
		ret = (ret << 3) + (ret << 1) + (N & 0b1111);
	return ret * flag;
}
int main(int argc, char** argv){
	register int i;
	N = fastREADINT();
	M = fastREADINT();
	for (i = 0; i < N; i++)
		arr[i] = fastREADINT();
	long long left = 1, right, mid, sum, ans;
	right = ans = 1000000000000000000LL;
	while (left <= right) {
		mid = (left + right) >> 1;
		sum = 0;
		for (i = 0; i < N; i++)
			sum += mid / arr[i];
		if (sum >= M) {
			right = mid - 1;
			ans = ans > mid ? mid : ans;
		}
		else
			left = mid + 1;
	}
	printf("%ld", ans);
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
