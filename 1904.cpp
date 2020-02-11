#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXSIZE 1000001
long long cache[MAXSIZE];
int n;
long long ans = 0;

long long dp(int num)
{
	int ret = cache[num];
	if (ret != -1)
		return ret;

	ret = dp(num - 1) + dp(num - 2);
	return ret;
}
int main(void)
{
	cin >> n;
	memset(cache, -1, sizeof(cache));
	cache[0] = 1;
	cache[1] = 1;
	for (int i = 2; i <= n; i++)
		cache[i] = (cache[i - 2] + cache[i - 1])%15746;
	//ans = cache[i]
	cout << cache[n] << endl;
}
