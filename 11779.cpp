#include <iostream>
#include <queue>
#include <list>
#include <stack>
using namespace std;
#define INF 987654321
int n, m, f, e, c;
bool g[1001][1001];
struct edge{
    int f, e, c;
};
bool operator<(edge a, edge b) {
    return a.c > b.c;
}
priority_queue<edge> pq;
list<edge> l[1001];
stack<int> ans;
int cost[1001];
void func() {
    for(auto edges : l[f])
        pq.push({.f = f, .e = edges.e, .c = edges.c});
    while(!pq.empty()) {
        edge edg = pq.top();
        pq.pop();
        if(cost[edg.e] <= edg.c) continue;
        cost[edg.e] = edg.c;
        g[edg.f][edg.e] = true;
        if(edg.e == e) return;
        for(auto edges : l[edg.e])
            pq.push({.f = edg.e, .e = edges.e, .c = edges.c + edg.c});
    }
}
bool getans(int cur) {
    if(cur == e) {
        ans.push(e);
        return  true;
    }
    for(int i = 1; i<= n; i++) {
        if(g[cur][i] && getans(i)) {
            ans.push(cur);
            return true;
        }
    }
    return false;
}
int main() {
    scanf("%d %d",&n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d",&f,&e,&c);
        l[f].push_back({f,e,c});
    }
    scanf("%d %d",&f, &e);
    for(int i = 1; i <= n; i++)
        cost[i] = INF;
    cost[f] = 0;
    func();
    printf("%d\n",cost[e]);
    getans(f);
    printf("%d\n",ans.size());
    while(!ans.empty()) {
        printf("%d ",ans.top());
        ans.pop();
    }
}
