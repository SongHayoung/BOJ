#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXSIZE 4000

int arr[MAXSIZE][MAXSIZE];

int MINUS = 0;
int ZERO = 0;
int PLUS = 0;

void add(int x, int y)
{
	if (arr[x][y] == -1)
		MINUS++;
	if (arr[x][y] == 0)
		ZERO++;
	if (arr[x][y] == 1)
		PLUS++;

	return;
}

void answer_func(int lenth,int x, int y)
{
	bool tf = true;

	if (lenth == 1)
	{
		add(x, y);
		return;
	}

	for (int i = x; i < x + lenth; i++)
	{
		if (!tf)
			break;

		for (int j = y; j < y + lenth; j++)
		{
			if (arr[x][y] != arr[i][j])
			{
				tf = false;
				break;
			}
		}
	}

	if (tf)
	{
		add(x, y);
		return;
	}
	else
	{
		answer_func(lenth / 3, x, y);
		answer_func(lenth / 3, x + lenth / 3, y);
		answer_func(lenth / 3, x + 2 *lenth / 3, y);

		answer_func(lenth / 3, x, y + lenth / 3);
		answer_func(lenth / 3, x + lenth / 3, y + lenth / 3);
		answer_func(lenth / 3, x + 2 * lenth / 3, y + lenth / 3);

		answer_func(lenth / 3, x, y + 2 * lenth / 3);
		answer_func(lenth / 3, x + lenth / 3, y + 2 * lenth / 3);
		answer_func(lenth / 3, x + 2 * lenth / 3, y + 2 * lenth / 3);
	}
}

int main(void)
{
	int n, k;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	answer_func(n,0,0);

	cout << MINUS << endl << ZERO << endl << PLUS << endl;
}
