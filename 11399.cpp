#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXSIZE 1000

vector<int> arr;
int ans=0;
int N;
int num;

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++)
	{
		ans += arr[i] * (N - i);
	}
	cout << ans << endl;
}
