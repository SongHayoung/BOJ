#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool arr[1000];


int main(void)
{
	int test_case;
	int num, strike, ball;
	int strike_cnt, ball_cnt;
	int answer=0;
	string temp,num_temp,num_check;

	cin >> test_case;

	memset(arr, true, sizeof(arr));

	for (int i = 123; i <= 987; i++)
	{
		temp = to_string(i);
		if (temp[1]-'0' == 0 || temp[2] - '0' == 0)
			arr[i] = false;
		if (temp[0] == temp[1] || temp[0] == temp[2] || temp[1] == temp[2])
			arr[i] = false;
	}


	for (int i = 0; i < test_case; i++)
	{
		cin >> num >> strike >> ball;
		num_temp = to_string(num);
		for (int i = 123; i <= 987; i++)
		{
			if (arr[i])
			{
				strike_cnt = 0;
				ball_cnt = 0;
				num_check = to_string(i);

				for (int x = 0; x < 3; x++)
				{
					for (int y = 0; y < 3; y++)
					{
						if (x == y && num_temp[x] == num_check[y])
							strike_cnt++;
						if (x != y && num_temp[x] == num_check[y])
							ball_cnt++;
					}
				}

				if (strike != strike_cnt || ball != ball_cnt)
					arr[i] = false;
			}
		}
	}

	for (int i = 123; i <= 987; i++)
	{
		if (arr[i])
			answer++;
	}

	cout << answer << endl;
}
