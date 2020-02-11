#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char arr[51][51];
int A_size;
int answer = 0;

void swap(char *px, char *py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}

void calc(int x, int y)
{
	int cnt = 0;
	int x1, y1;
	x1 = x + 1; y1 = y;
	while (1)
	{
		if (x1 < A_size && arr[x][y] == arr[x1][y])
		{
			x1++;
			cnt++;
		}
		else
			break;
	}
	x1 = x - 1; y1 = y;
	while (1)
	{
		if (x1 >= 0 && arr[x][y] == arr[x1][y])
		{
			x1--;
			cnt++;
		}
		else
			break;
	}
	answer = max(answer, cnt + 1);

	x1 = x; y1 = y + 1; cnt = 0;
	while (1)
	{
		if (y1 < A_size && arr[x][y] == arr[x][y1])
		{
			y1++;
			cnt++;
		}
		else
			break;
	}
	x1 = x; y1 = y - 1;
	while (1)
	{
		if (y1 >= 0 && arr[x][y] == arr[x][y1])
		{
			y1--;
			cnt++;
		}
		else
			break;
	}
	answer = max(answer, cnt + 1);
}

void answer_func()
{
	for (int i = 0; i < A_size; i++)
	{
		for (int j = 0; j < A_size; j++)
		{
			if (i < A_size - 1 && (arr[i][j] != arr[i + 1][j]))
			{
				swap(&arr[i][j], &arr[i + 1][j]);
				for (int x = 0; x < A_size; x++)
				{
					for (int y = 0; y < A_size; y++)
					{
						calc(x, y);
					}
				}
				swap(&arr[i][j], &arr[i + 1][j]);
			}
			if (j < A_size - 1 && (arr[i][j] != arr[i][j + 1]))
			{
				swap(&arr[i][j], &arr[i][j + 1]);
				for (int x = 0; x < A_size; x++)
				{
					for (int y = 0; y < A_size; y++)
					{
						calc(x, y);
					}
				}
				swap(&arr[i][j], &arr[i][j + 1]);
			}
		}
	}
}
int main(void)
{
	cin >> A_size;

	for (int i = 0; i < A_size; i++)
	{
		for (int j = 0; j < A_size; j++)
		{
			cin >> arr[i][j];
		}
	}
	answer_func();
	cout << answer;
}
