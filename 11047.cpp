#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXSIZE 1000

int arr[10];
int ans=0;
int N,K;

int main(void)
{
	cin >> N>>K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	N--;
	while (K != 0)
	{
		if (K >= arr[N])
		{
			K -= arr[N];
			ans++;
		}
		else
			N--;
	}
	cout << ans << endl;
}
