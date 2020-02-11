#include <stdio.h>

int answer_func(int num,int depth,int cur)
{
	int i;
	int temp = 0;
	int ret = 0;

	if (depth == 0 && (num == cur))
		return 1;
	else if (depth == 0 && (num!=cur))
		return 0;

	for (i = 1; i <= 44; i++)
	{
		temp = temp + i;

		ret = ret + answer_func(num, depth - 1, cur + temp);
	}
	if (ret >= 1)
		return 1;
	else
		return 0;
}

int main(void)
{
	int test_case;
	int i;
	int num;
	int k1 = 1, k2 = 1, k3 = 2;

	scanf("%d", &test_case);

	for (i = 0; i < test_case; i++)
	{
		scanf("%d", &num);
		printf("%d\n", answer_func(num,3,0));
	}
}
