#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXSIZE 40000

int n;
int i = 0;
int cache[MAXSIZE];
int ans[MAXSIZE];

void ans_func(int num,int cur,int depth,int start)
{
	if (depth >= 0 && cache[num] == cur)
	{
		ans[num]++;
		return;
	}
	if (cache[num] < cur||depth==0)
		return;

	for (int i = start; i <= 181; i++)
	{
		ans_func(num, cur + i * i, depth - 1, i);
	}
}

int main(void)
{
	memset(ans, -1, sizeof(ans));
	memset(cache, -1, sizeof(cache));
	while (1)
	{
		cin >> cache[i];
		if (cache[i] == 0)
			break;
		ans_func(i++, 0, 4, 1);
	}
	i = 0;
	while (1)
	{
		if (ans[i] == -1)
			break;
		cout << ans[i++] + 1 << endl;
	}

}
