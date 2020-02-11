#include <stdio.h>
#include <math.h>

int answer = 0;

int func_answer(int num, int cur, int devied_cur)
{
    int func_cur=cur+(devied_cur%10);
    
    if(devied_cur==0&&num==cur)
        return 1;
    else if(devied_cur==0)
        return 0;
    
    return func_answer(num,func_cur,devied_cur/10);
}

int main(void)
{
    int num;
    int i;
    
    scanf("%d",&num);
    
    for(i = 0; i < num; i++)
    {
        if(func_answer(num, i, i))
        {
            answer = i;
            break;
        }
    }
    
    printf("%d\n",answer);
}
