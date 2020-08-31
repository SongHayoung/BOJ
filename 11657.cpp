#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
#define INF 987654321
int edge[501][501], n, m, a, b, c;
int ans[501];
void dijkstra(int cur, int cost, int depth) {
    if(depth > 500) {
        printf("-1");
        exit(0);
    }
    if(ans[cur] > cost) {
        ans[cur] = cost;
        for(int i = 1; i <= n; ++i)
            if(edge[cur][i] != INF)
                dijkstra(i,cost + edge[cur][i], depth + 1);
    }
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            edge[i][j] = INF;
        ans[i] = INF;
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d",&a,&b,&c);
        edge[a][b] = min(edge[a][b],c);
    }
    dijkstra(1,0, 0);
    for(int i = 2; i <= n; ++i)
        printf("%d\n",ans[i] == INF ? -1 : ans[i]);
}
