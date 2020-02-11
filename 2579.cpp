#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXSIZE 1000

int N;
long long cache[301][3];
int stairs[301];
long long ans = 0;

long long dp(int idx,int stat)
{
	if (idx > N)
		return -34567890;

	if (idx == N)
		return stairs[idx];
	long long &ret = cache[idx][stat];

	if (ret != -1)
		return ret;

	ret = 0;

	if (stat == 2)
		ret = dp(idx + 2, 1);
	else
		ret = max(dp(idx + 2, 1), dp(idx + 1, 2));

	ret += stairs[idx];

	return ret;

}

int main(void)
{
	cin >> N;
	memset(cache, -1, sizeof(cache));
	stairs[0] = 0;
	for (int i = 1; i <= N; i++)
		cin >> stairs[i];
	ans = max(dp(1, 1),dp(2,1));
	cout << ans << endl;
}
