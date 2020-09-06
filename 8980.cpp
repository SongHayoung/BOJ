#include <iostream>
#include <algorithm>
#include <memory.h>
#include <list>
#include <queue>
using namespace std;
int n, c;
int dp[2001];
struct box{
    int e, c;
};
bool operator<(box a, box b) {
    return a.e > b.e;
}
priority_queue<box> boxes[2001];
int main() {
    int f, e, w, m;
    memset(dp,-1,sizeof(dp));
    scanf("%d %d %d",&n,&c,&m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d",&f,&e,&w);
        boxes[f].push(box{.e = e, .c = w});
    }
    int cur, ans;
    list<box> l;
    for(int i = 0; i <= n; i++) {
        while(!l.empty()) {
            if(l.front().e == i) {
                ans += l.front().c;
                cur -= l.front().c;
                l.pop_front();
            } else break;
        }
        while(!l.empty()) {
            boxes[i].push(l.back());
            l.pop_back();
        }
        cur = 0;
        while(!boxes[i].empty()) {
            box b = boxes[i].top();
            boxes[i].pop();
            if(cur + b.c <= c) {
                l.push_back(b);
                cur += b.c;
            } else {
                l.push_back(box{.e = b.e, .c = c - cur});
                cur = c;
            }
        }
    }
    printf("%d",ans);
}
