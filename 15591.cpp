#include <iostream>
#include <memory.h>
#include <list>
#include <queue>

using namespace std;
struct info {
    int e, c;
};
int n, q, f, e, c;
list<info> l[5001];
int g[5001][5001];

void buildG(int s) {
    queue<info> q;
    bool visit[5001] = {false,};
    visit[s] = true;
    for (info i : l[s]) {
        q.push(i);
        visit[i.e] = true;
    }
    while (!q.empty()) {
        info i = q.front();
        q.pop();
        g[s][i.e] = g[i.e][s] = i.c;
        for (info in : l[i.e])
            if (!visit[in.e]) {
                q.push(info{.e = in.e, .c = min(in.c, i.c)});
                visit[in.e] = true;
            }
    }
}

int getAns(int k, int v) {
    int ret = 0;
    for (int i = 1; i <= n; i++)
        if (g[v][i] >= k) ++ret;
    return ret;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &f, &e, &c);
        l[f].push_back(info{.e = e, .c = c});
        l[e].push_back(info{.e = f, .c = c});
    }
    for (int i = 1; i <= n; i++)
        buildG(i);
    int k, v;
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &k, &v);
        printf("%d\n", getAns(k, v));
    }
}
