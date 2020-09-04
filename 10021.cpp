#include <iostream>
#include <memory.h>
#include <cmath>
#include <queue>
using namespace std;
int n, c;
struct edge {
    int f, e, c;
};
bool operator< (edge a, edge b) {
    return a.c > b.c;
}
priority_queue<edge> pq;
pair<int, int> pos[2000];
int g[2000];
int getG(int cur) {
    return g[cur] == cur ? cur : g[cur] = getG(g[cur]);
}

bool makeG(int a, int b) {
    int ga = getG(a);
    int gb = getG(b);
    if(ga == gb)
        return false;
    g[ga] = g[gb] = min(ga,gb);
    return true;
}
int distance(int i, int j) {
    return abs(pos[i].first - pos[j].first) * abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second) * abs(pos[i].second - pos[j].second);
}
int main() {
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d %d",&pos[i].first, &pos[i].second);
        for(int j = 0; j < i; j++) {
            int d = distance(i, j);
            if(d >= c)
                pq.push({.f = i, .e = j, .c = d});
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++)
        g[i] = i;
    while(!pq.empty()) {
        edge e = pq.top();
        pq.pop();
        if(makeG(e.f, e.e))
            ans += e.c;
    }
    for(int i = 0; i < n; i++)
        if(g[i]) {
            printf("-1");
            exit(0);
        }
    printf("%lld",ans);
}
