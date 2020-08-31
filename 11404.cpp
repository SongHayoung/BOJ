#include <iostream>
#include <algorithm>
#include <memory.h>
#define INF 987654321
using namespace std;
int n, m, f, e, c;
int ans[101][101];
int main() {
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; ++j)
            if(i!=j)
                ans[i][j] = INF;
    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d",&f,&e,&c);
        ans[f][e] = min(ans[f][e],c);
    }
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                ans[i][j] = min(ans[i][k] + ans[k][j], ans[i][j]);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j)
            printf("%d ",ans[i][j] == INF ? 0 : ans[i][j]);
        printf("\n");
    }

}
