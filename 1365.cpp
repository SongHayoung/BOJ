#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXSIZE 100000

int n;
int num;
int ans = 0;
vector<int> arr;

int main(void)
{
	cin >> n;
	arr.push_back(-1);
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (arr.back() < num)
		{
			arr.push_back(num);
			ans++;
		}
		else
		{
			auto it = upper_bound(arr.begin(), arr.end(), num);
			*it = num;
		}
	}
	cout << n-ans << endl;
}
