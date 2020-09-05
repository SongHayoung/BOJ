#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;
int n, p, k;
list<pair<int,int>> line[1001];
bool binarySearch(int cost) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    int g[1001];
    g[1] = 0;
    for(int i = 2; i<= n; i++)
        g[i] = 987654321;
    while(!pq.empty()) {
        int pos = pq.top().second;
        int c = -pq.top().first;
        pq.pop();
        if(g[pos] < c) continue;
        for(pair<int,int> p : line[pos]) {
            int nc = c + (p.second > cost);
            if(nc < g[p.first]) {
                g[p.first] = nc;
                pq.push({-nc, p.first});
            }
        }
    }
    return g[n] <= k;
}
int main() {
    scanf("%d %d %d", &n, &p, &k);
    for(int i = 0; i < p; i++) {
        int a, b, c;
        scanf("%d %d %d",&a,&b,&c);
        line[a].push_back(make_pair(b,c));
        line[b].push_back(make_pair(a,c));
    }
    int ans = -1;
    int l = 0, r = 1000001, m;
    while(l < r) {
        m = (l + r) / 2;
        if(binarySearch(m)) {
            ans = m;
            r = m;
        } else
            l = m + 1;
    }
    printf("%d",ans);
}
