#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
vector<int> g[2001];
bool v[2001], ans;
int n, m, f, e;
void dfs(int cur ,int d) {
    if(d == 5 || ans) {
        ans = true;
        return;
    }
    v[cur] = true;
    for(int val : g[cur])
        if(!v[val])
            dfs(val, d + 1);
    v[cur] = false;
}
int main(void) {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d %d",&f, &e);
        g[f].push_back(e);
        g[e].push_back(f);
    }
    for(int i = 0; i < n && !ans; ++i)
        dfs(i, 1);

    printf("%d ", ans ? 1 : 0);
}
