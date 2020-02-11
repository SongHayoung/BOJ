#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int arr[128][128];
int N;
int white = 0, blue = 0;

void find(int length, int x, int y)
{
	bool same = true;

	if (length == 1)
	{
		if (arr[x][y] == 0)
			white++;
		else
			blue++;

		return;
	}

	for (int i = x; i < x + length; i++)
	{
		if (!same)
			break;

		for (int j = y; j < y + length; j++)
		{
			if (arr[x][y] != arr[i][j])
			{
				same = false;
				find(length / 2, x, y);
				find(length / 2, x+(length/2), y);
				find(length / 2, x, y + (length / 2));
				find(length / 2, x + (length / 2), y + (length / 2));
				break;
			}
		}
	}

	if (same)
	{
		if (arr[x][y] == 0)
			white++;
		else
			blue++;

		return;
	}
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	find(N,0,0);
	cout << white << endl << blue << endl;
}
