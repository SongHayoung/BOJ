#include <iostream>
#include <memory.h>
#include <queue>
#include <algorithm>
using namespace std;
struct edge{
    int s, e, c;
};
bool operator< (edge e1, edge e2) {
    return e1.c > e2.c;
}
int g[10001];
int v, e, ans, n;
priority_queue<edge> pq;
int getG(int cur) {
    return g[cur] == cur ? cur : g[cur] = getG(g[cur]);
}
bool makeG(int st, int ed) {
    int sG = getG(st);
    int eG = getG(ed);
    if(sG == eG) return false;
    g[sG] = g[eG] = min(sG,eG);
    return true;
}
int main() {
    scanf("%d %d",&v,&e);
    for(int i = 1; i <= v; i++)
        g[i] = i;
    while(e--) {
        int s, e, c;
        scanf("%d %d %d",&s,&e,&c);
        pq.push(edge{.s = s, .e = e, .c = c});
    }
    while(n != v - 1) {
        if(makeG(pq.top().s, pq.top().e))
            ans += pq.top().c, ++n;
        pq.pop();
    }
    printf("%d",ans);
}
