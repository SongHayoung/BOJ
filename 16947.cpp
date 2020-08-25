#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#include <iostream>
using namespace std;
vector<int> g[3001];
int ans[3001];
bool v[3001];
int n, f, e;
bool loop(int f, int e) {
    if(!ans[e]) return true;
    for(int nt : g[e]) {
        if(nt == f) continue;
        if(loop(e, nt)) {
            ans[e] = 0;
            return true;
        }
    }
    return false;
}
void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(-1, 1));
    v[1] = true;
    while(!q.empty()) {
        pair<int,int> val = q.front();
        q.pop();
        for(int nt : g[val.second]) {
            if(val.first == nt) continue;
            if(!v[nt]) {
                if(g[nt].size() >= 2)
                    q.push(make_pair(val.second,nt));
                v[nt] = true;
            }
            else{
                ans[nt] = 0;
                for(int lnt : g[nt])
                    loop(nt, lnt);
                return;
            }
        }
    }
}
int dfs(int f, int e) {
    if(ans[e] != -1) return ans[e] + 1;
    for(int nt : g[e]) {
        if(nt == f) continue;
        int ret = dfs(e, nt);
        if(ret >= 1)
            return (ans[e] = ret) + 1;
    }
    return -987654321;
}
int main(void) {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d",&f, &e);
        g[f].push_back(e);
        g[e].push_back(f);
    }
    memset(ans, -1, sizeof(ans));
    bfs();
    for(int i = 1; i <= n; ++i) {
        if(ans[i]<0) dfs(-1, i);
        printf("%d ", ans[i]);
    }
}
