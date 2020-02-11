//
//  main.cpp
//  Algo
//
//  Created by SummerFlower on 25/09/2019.
//  Copyright © 2019 SummerFlower. All rights reserved.
//
// c++_algo.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include <stdio.h>


int process[2000000][2];
int N, cnt;

void topmove(int n, int from, int to)
{
    int left = 6-from-to;
    if(n==1)
    {
        process[cnt][0] = from;
        process[cnt++][1] = to;
    }
    else
    {
        topmove(n-1,from,left);
        process[cnt][0] = from;
        process[cnt++][1] = to;
        topmove(n-1,left,to);
    }
    
}
int main(void)
{
    scanf("%d",&N);
    topmove(N,1,3);
    printf("%d\n",cnt);
    for(int i = 0;i<cnt;i++)
        printf("%d %d\n",process[i][0], process[i][1]);
}
