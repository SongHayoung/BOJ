#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXSIZE 20

int n;
int cache[MAXSIZE];
int testcase[MAXSIZE];

int main(void)
{
	cin >> n;
	memset(cache, -1, sizeof(cache));
	cache[1] = 1;
	cache[2] = 2;
	cache[3] = 4;
	for (int i = 4; i <= 11; i++)
	{
		cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> testcase[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << cache[testcase[i]] << endl;;
	}


}
