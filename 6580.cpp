#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXSIZE 600

char arr[MAXSIZE][MAXSIZE];
string bits[MAXSIZE];
string N_string;
string temp;
int N;

int ret_num(char c)
{
	switch (c)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'a':
		return 10;
	case 'b':
		return 11;
	case 'c':
		return 12;
	case 'd':
		return 13;
	case 'e':
		return 14;
	case 'f':
		return 15;
	default:
		break;
	}
	return 0;
}

void insert(int line, int start)
{
	char temp2[2];
	temp2[0] = temp[0];
	temp2[1] = temp[1];
	int hex_num = 16 * ret_num(temp2[0]) + ret_num(temp2[1]);

	for (int i = start + 7; i >= start; i--)
	{
		if (hex_num >= pow(2, i - start))
		{
			hex_num -= pow(2, i - start);
			arr[line][i] = 'B';
		}
		else
			arr[line][i] = 'W';
	}
}

void quard_tree(int x, int y, int n)
{
	bool same = true;

	for (int i = x; i < x+n; i++)
	{
		if (!same)
			break;
		for (int j = y; j < y+n; j++)
		{
			if (arr[i][j] != arr[x][y])
			{
				same = false;
				break;
			}
		}
	}

	if (same)
	{
		cout << arr[x][y];
		return;
	}
	cout << 'Q';
	quard_tree(x, y, n/2);
	quard_tree(x, y+n/2, n / 2);
	quard_tree(x+n/2, y, n / 2);
	quard_tree(x+n/2, y+n/2, n / 2);
}

int main(void)
{
	getline(cin, N_string);
	getline(cin, temp);
	getline(cin, temp);


	N_string = N_string.substr(23, N_string.length());
	N = atoi(N_string.c_str());

	for (int i = 0; i < N+1; i++)
	{
		getline(cin, bits[i]);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N / 8; j++)
		{
			temp = bits[i].substr(2, 4);
			insert(i,j*8);
			bits[i] = bits[i].substr(5, bits[i].length());
		}
	}
	cout << N << endl;
	quard_tree(0,0,N);
}
