#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXSIZE 500001

struct point {
	int num;
	int index;
	point(int a, int b) : num(a), index(b) {}
};
int n;
vector <point> arr;
int ans = 0;
int num;

bool compare(const point& p1, const point& p2)
{
	if (p1.num == p2.num)
		return p1.index < p2.index;
	return p1.num < p2.num;
}


int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		point P(num, i);
		arr.push_back(P);
	}
	sort(arr.begin(), arr.end(),compare);
	for (int i = 0; i < n; i++)
	{
		ans = max(ans,arr[i].index-i);
	}
	cout << ans+1 << endl;
}
