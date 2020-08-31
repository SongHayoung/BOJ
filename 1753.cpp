#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321
vector<pair<int,int>> v[20001];
int ans[20001];
int n, m, s, a, b, c;
bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}
struct p {
    int n;
};
bool operator<(p a, p b) {
    return ans[a.n] > ans[b.n];
}
void dijkstra(int cur) {
    ans[cur] = 0;
    priority_queue<p> q;
    q.push(p{.n = cur});
    int prev = 0;
    while(!q.empty()) {
        p c = q.top();
        q.pop();
        if(prev == c.n) continue;
        prev = c.n;
        for(auto it : v[c.n]) {
            if(ans[it.first] > ans[c.n] + it.second) {
                q.push(p{.n = it.first});
                ans[it.first] = ans[c.n] + it.second;
            }
        }
    }
}
void init() {
    map<int,int> edge[20001];
    scanf("%d %d %d",&n,&m,&s);
    for(int i = 1; i <= n; ++i)
        ans[i] = INF;
    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d",&a,&b,&c);
        edge[a][b] = edge[a][b] ? min(edge[a][b], c) : c;
    }
    for(int i = 1; i <= n; ++i) {
        v[i].reserve(edge[i].size());
        for(auto& it : edge[i])
            v[i].push_back(it);
        sort(v[i].begin(), v[i].end(), cmp);
    }
}
int main() {
    init();
    dijkstra(s);
    for(int i = 1; i <= n; ++i)
        ans[i] == INF? printf("INF\n") : printf("%d\n",ans[i]);
}
