#include <stdio.h>
int N, n, ball;
int arr[30];
int table[31][15001];
void init(int cur, int val){
    if(cur>N) return;
    if(table[cur][val]) return;
    table[cur][val] = true;
    init(cur+1,val+arr[cur]);
    init(cur+1,val);
    init(cur+1,val-arr[cur]>0?val-arr[cur]:arr[cur]-val);
}
int main(void){
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)
        scanf("%d",&arr[i]);
    init(0,0);
    scanf("%d",&n);
    while(n--){
        scanf("%d",&ball);
        ball > 15000 ? printf("N ") : table[N][ball] ? printf("Y ") : printf("N ");
    }
}
