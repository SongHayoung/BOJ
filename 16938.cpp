#include <iostream>
int ans, N, X, L, R;
int arr[15];
bool vi[1<<16];
void dfs(int min, int max, int sum, int q, int n, int v) {
    if(max - min >= X && q >= 2 && L <= sum && sum <= R && !vi[v])
        vi[v] = ++ans;

    if(n >= N || sum > R) return;
    dfs(min,max,sum,q,n + 1, v);
    dfs(min > arr[n] ? arr[n] : min, max > arr[n] ? max : arr[n], sum + arr[n], q + 1, n + 1, v | 1<<(n+1));
}

int main(void) {
    scanf("%d %d %d %d",&N, &L, &R, &X);
    for(int i = 0; i < N; ++i)
        scanf("%d",&arr[i]);
    dfs(987654321, -987654321, 0, 0, 0, 0);
    printf("%d",ans);
}
