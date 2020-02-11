#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXSIZE 1001
int cost[3][MAXSIZE];
int cache[3][MAXSIZE];
int n;

int dp(int color,int depth)
{
	int &ret = cache[color][depth];
	if (ret != -1)
		return ret;

	if (depth == n - 1)
	{
		ret = cost[color][depth];
		return ret;
	}

	ret = min(dp((color + 1) % 3, depth + 1), dp((color + 2) % 3, depth + 1)) + cost[color][depth];
	return ret;
}

int main(void)
{
	cin >> n;
	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> cost[j][i];

	int answer = min(dp(0, 0), dp(1, 0));
	answer = min(answer, dp(2, 0));

	cout << answer << endl;
}
