#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXSIZE 1001
vector<int> temp;
int n;
int num;
int ans = 0;

int main(void)
{
	cin >> n;
	temp.push_back(-1);

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (temp.back() < num)
		{
			temp.push_back(num);
			ans++;
		}
		else
		{
			auto it = lower_bound(temp.begin(), temp.end(), num);
			*it = num;
		}
	}

	cout << ans << endl;
}
