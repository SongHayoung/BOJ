#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXSIZE 500001

int n;
int arr[MAXSIZE];
int temp[MAXSIZE];
long long ans = 0;

void merge_sort(int from, int mid, int to)
{
	int i = from;
	int j = mid+1;
	int index = from;

	while (i <= mid && j <= to)
	{
		if (arr[i] <= arr[j])
			temp[index++] = arr[i++];
		else
		{
			temp[index++] = arr[j++];
			ans = ans + j-index;
		}
	}

	if (i > mid)
	{
		for (int l = j; l <= to; l++)
			temp[index++] = arr[l];
	}
	else
	{
		for (int l = i; l <= mid; l++)
		{
			temp[index++] = arr[l];
		}
	}
	
	for (int l = from; l <= to; l++)
	{
		arr[l] = temp[l];
	}
}

void merge(int from, int to)
{
	int mid;

	if (from < to)
	{
		mid = (from + to) / 2;
		merge(from, mid);
		merge(mid + 1, to);
		merge_sort(from, mid, to);
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	merge(0,n-1);
	cout << ans<< endl;
}
