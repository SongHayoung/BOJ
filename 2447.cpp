#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

char arr[2187][2187];
int N;
void print()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
}

void draw(int x, int y,int length, bool tf)
{
	if (length == 1 && tf)
	{
		arr[x + 1][y + 1] = ' ';
		return;
	}
	if (length == 1 && !tf)
	{
		for (int i = x; i < x+3; i++)
		{
			for (int j = y; j < y+3; j++)
			{
				arr[i][j] = ' ';
			}
		}
		return;
	}

	draw(x, y, length - 1, tf);
	draw(x + pow(3, length - 1), y, length - 1, tf);
	draw(x + (pow(3, length - 1) * 2), y, length - 1, tf);

	draw(x, y +pow(3, length - 1), length - 1, tf);
	draw(x + pow(3, length - 1), y + pow(3, length - 1), length - 1, false);
	draw(x + (pow(3, length - 1) * 2), y + pow(3, length - 1), length - 1, tf);

	draw(x, y + (pow(3, length - 1) * 2), length - 1, tf);
	draw(x + pow(3, length - 1), y + (pow(3, length - 1) * 2), length - 1, tf);
	draw(x + (pow(3, length - 1) * 2), y + (pow(3, length - 1) * 2), length - 1, tf);

}

int main(void)
{
	cin >> N;
	int num=3;
	for (int i = 0; i < 8; i++)
	{
		if (num == N)
		{
			num = i+1;
			break;
		}
		num = num * 3;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = '*';
		}
	}
	draw(0, 0, num, true);
	print();
}
