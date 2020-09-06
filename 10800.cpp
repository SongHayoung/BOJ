#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
struct ball {
    int c, s, idx;
};
bool operator<(ball a, ball b) {
    return a.s == b.s ? a.c > b.c : a.s > b.s;
}
int ans[200000];
int n;
int main() {
    scanf("%d",&n);
    ball b;
    priority_queue<ball> pq;
    for(int i = 0; i < n; i++) {
        scanf("%d %d",&b.c,&b.s);
        pq.push(ball{.c = b.c, .s = b.s, .idx = i});
    }
    int tot = 0, lsize = 0;
    map<int, int> calc,calc2;
    while(!pq.empty()) {
        b = pq.top();
        pq.pop();
        if(b.s != lsize) {
            lsize = b.s;
            map<int, int> temp;
            for(auto it : calc2) {
                calc[it.first] += it.second;
                tot += it.second;
            }
            calc2 = temp;
            calc2[b.c] += b.s;
        } else
            calc2[b.c] += b.s;
        ans[b.idx] = tot - calc[b.c];
    }
    for(int i = 0; i < n; i++)
        printf("%d\n",ans[i]);
}
