#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXSIZE 100001

int N;
int arr[MAXSIZE];
int start_index;
int end_index;

long long compare(int start, int end)
{
	if (start == end)
		return (long long)arr[start] * arr[start];

	long long ret;
	int mid = (start + end) / 2;
	int left = mid;
	int right = mid + 1;

	ret = max(compare(start, left), compare(right, end));

	long long sum = arr[left] + arr[right];
	long long minvalue = min(arr[left], arr[right]);

	ret = max(ret, sum*minvalue);

	while (left>start || right<end)
	{
		if (right < end && (left == start || arr[left-1] < arr[right+1]))
		{
			sum += arr[++right];
			minvalue = min(minvalue, (long long)arr[right]);
		}
		else
		{
			sum += arr[--left];
			minvalue = min(minvalue, (long long)arr[left]);
		}
		long long comparewith = sum * minvalue;
		ret = max(ret, comparewith);
	}

	return ret;
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	cout << compare(0, N-1);

}
