#include <stdio.h>
#define pc(x) putchar_unlocked(x)
#define gc() getchar_unlocked()
int main(int argc, char** argv){
	register int r = 0, p = 0, answer = 0, len = 0 , i = 0;
	int DP[200001] = { 0, };
	char s[200001];
	do {
		s[len++] = '#';	s[len++] = gc();
	} while (s[len-1] != '\n');
	s[len++] = '#';
	for (; i < len-answer; i++) {
		if (i <= r)	DP[i] = DP[(p<<1) - i] > r - i ? r - i : DP[(p<<1) - i];
		while (i - DP[i] - 1 >= 0 && i + DP[i] + 1 < len && s[i - DP[i] - 1] == s[i + DP[i] + 1]) DP[i]++; 
		if (r < i + DP[i]) {
			r = i + DP[i];	p = i;
		}
		answer = DP[i] > answer ? DP[i] : answer;
	}
	r = p = 0;
	while (!(answer % 10)) { p++; answer /= 10; } //obtain the count of the number of 0s
	while (answer) { r = (r << 3) + (r << 1) + answer % 10; answer /= 10; }  //store reverse of N in rev
	while (r) { pc(r % 10 + '0'); r /= 10; }
	while (p--) pc('0');
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
