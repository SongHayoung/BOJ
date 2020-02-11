#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXSIZE 10000
char arr[MAXSIZE][MAXSIZE];
int N;

void answer_func(int k, int x, int y, int n)
{
	if (k == 0)
	{
		arr[x][y] = '*';
		arr[x + 1][y] = '*';
		arr[x + 1][y + 2] = '*';
		arr[x + 2][y] = '*';
		arr[x + 2][y + 1] = '*';
		arr[x + 2][y + 2] = '*';
		arr[x + 2][y + 3] = '*';
		arr[x + 2][y + 4] = '*';
		return;
	}
	
	answer_func(k - 1, x, y, n / 2);
	answer_func(k - 1, x + n / 2, y, n / 2);
	answer_func(k - 1, x + n / 2, y + n, n / 2);
}

int main(void)
{
	int k;
	int t1, t2;
	cin >> N;
	for (int i = 0; i < MAXSIZE; i++)
	{
		for (int j = 0; j < MAXSIZE; j++)
		{
			arr[i][j] = ' ';
		}
	}
	for (int i = 0; i <= 10; i++)
	{
		if (N / 3 == pow(2, i))
		{
			k = i;
			break;
		}
	}

	answer_func(k,0,0,N);
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = N - i; j > 0; j--)
		{
			cout << " ";
		}

		for (int j = 0; j < (i-1)*2+1; j++)
		{
			cout << arr[i - 1][j];
		}

		for (int j = N - i+1; j > 0; j--)
		{
			cout << " ";
		}
		cout << endl;
	}
}
