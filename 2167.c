#include <stdio.h>

int main(void) {
    int N, M, num, K;
    int i, j , x, y;
    int arr[301][301] = {0, };
    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++){
            scanf("%d",&num);
            arr[i][j] = num + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    scanf("%d",&K);
    for(int l = 0; l < K; l++){
        scanf("%d %d %d %d",&i,&j,&x,&y);
        printf("%d\n",arr[x][y] - arr[i-1][y] - arr[x][j-1] + arr[i-1][j-1]);
    }
    return 0;
}
