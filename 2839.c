#include <stdio.h>
int main(void)
{
    int kg;
    int kg_5=0;
    int kg_3=0;
    scanf("%d",&kg);
    while(kg_5*5<kg)
    {
        kg_5++;
    }
    if((kg_5*5)==kg)
    {
        printf("%d\n",kg_5);
    }
    else
    {
        while((kg_5*5+kg_3*3)!=kg)
        {
            kg_5--;
            kg_3=0;
            if(kg_5<0)
                kg_5=0;
            //kg_3++;
            while((kg_5*5+kg_3*3)!=kg)
            {
                kg_3++;
                if((kg_5*5+kg_3*3)>kg)
                    break;
            }
            if((kg_5*5+kg_3*3)==kg)
            {
                
                printf("%d\n",kg_5+kg_3);
                return 0;
            }
            if(kg_3*3>kg)
            {
                printf("-1\n");
                return 0;
                break;
            }
        }
            printf("%d\n",kg_5+kg_3);
    }
    
    return 0;
}
