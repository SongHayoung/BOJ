#pragma GCC optimize ("O3")
#include <stdio.h>
#include <stdlib.h>
struct paper{
    int garo;
    int sero;
};
int compare(const void *a, const void *b){
    paper A = *(paper*)a;
    paper B = *(paper*)b;
    if(A.garo==B.garo)
        return A.sero > B.sero ? 1 : -1;
    return A.garo > B.garo ? 1 : -1;
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(void){
    int N,answer = 0, DP[100]={[0 ... 99] = 1};
    paper P[100];
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d %d",&P[i].garo,&P[i].sero);
        if(P[i].sero>P[i].garo) swap(&P[i].garo,&P[i].sero);
    }
    qsort(P,N,sizeof(paper),compare);
    for(int i = 0; i < N; i++){
        for(int j = i -1; j >= 0 ; j--)
            if(P[j].garo<=P[i].garo&&P[j].sero<=P[i].sero&&DP[j]+1>DP[i]) DP[i] = DP[j]+1;
        answer = answer > DP[i]? answer : DP[i];
    }
    printf("%d",answer);
}
