#include <stdio.h>

int answer_func(int num,int cur)
{
	int i;
	int ret=0;

	if (num < cur)
		return 0;
	if (num == cur)
		return 1;
	

	for (i = 1; i <= 3; i++)
	{
		ret = ret + answer_func(num, cur+i);
	}

	return ret;
}

int main(void)
{
	int test_case;
	int i;
	int num;

	scanf("%d", &test_case);

	for (i = 0; i < test_case; i++)
	{
		scanf("%d", &num);
		printf("%d\n", answer_func(num,0));
	}
}
