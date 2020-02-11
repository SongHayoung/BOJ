#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXSIZE 1000000
int arr[MAXSIZE];
int arr2[MAXSIZE];

int N, M;

int main(void)
{
	int _N = 0, _M = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < M; i++)
	{
		cin >> arr2[i];
	}

	while (1)
	{
		if (N == _N && M == _M)
			break;

		if(N > _N && (M==_M|| arr[_N] < arr2[_M]))
			cout << arr[_N++] << " ";
		else
			cout << arr2[_M++] << " ";
	}
}
