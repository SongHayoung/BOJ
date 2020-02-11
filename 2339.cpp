#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXSIZE 20

int arr[MAXSIZE][MAXSIZE];
int n;
int answer = 0;

bool cut(int index, int arg1, int arg2, bool up)
{
	if (up)
	{
		for (int i = arg1; i <= arg2; i++)
			if (arr[index][i] == 2)
				return false;

		return true;
	}
	else
	{
		for (int i = arg1; i <= arg2; i++)
			if (arr[i][index] == 2)
				return false;

		return true;
	}
}

int answer_func(int x1, int x2, int y1, int y2, bool up)
{
	int total = 0;
	int ans = 0;
	bool bul = true;

	if (x2 == n || y2 == n)
		return 1;

	for (int i = x1; i <= x2; i++)
	{
		for (int j = y1; j <= y2; j++)
		{
			total += arr[i][j];
			if (arr[i][j] == 1)
				bul = false;
		}
	}

	if (total < 2)
		return 0;
	if (total == 2)
	{
		return 1;
	}
	if (bul)
		return 0;

	for (int i = x1; i <= x2; i++)
	{
		for (int j = y1; j <= y2; j++)
		{
			if (arr[i][j] == 1 && up && cut(i,y1,y2,up))
			{
				ans = ans +  answer_func(x1, i - 1, y1, y2, !up)*answer_func(i + 1, x2, y1, y2, !up);
			}
			else if (arr[i][j] == 1 && !up && cut(j, x1,x2, up))
			{
				ans = ans + answer_func(x1, x2, y1, j - 1, !up)*answer_func(x1, x2, j + 1, y2, !up);
			}
		}
	}

	return ans;
}

int main(void)
{
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
			{
				answer = answer + answer_func(0, n - 1, 0, j - 1, true)*answer_func(0, n - 1, j + 1, n - 1, true);
				answer = answer + answer_func(0, i - 1, 0, n - 1, false)*answer_func(i + 1, n - 1, 0, n - 1, false);
			}
		}
	}

	if (answer == 0)
		cout << "-1" << endl;
	else
		cout << answer << endl;
}
