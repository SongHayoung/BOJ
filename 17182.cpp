#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int g[10][10];
int v[1<<11][10];
int n, k;
void dfs(int bit, int cur, int cost) {
    if(v[bit][cur] <= cost) return;
    v[bit][cur] = cost;
    if(bit + 1 == (1<<n)) return;
    for(int i = 0; i < n; i++)
        dfs(bit | (1 << i), i, cost + g[cur][i]);
}
int main() {
    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d",&g[i][j]);
    memset(v,0x3f,sizeof(v));
    dfs(1<<k,k,0);
    int ans = 987654321;
    for(int i = 0; i < n; i++)
        ans = min(ans,v[(1<<n)-1][i]);
    printf("%d",ans);
}
