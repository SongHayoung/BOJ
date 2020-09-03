#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
using namespace std;
struct line {
    pair<int,int> a, b;
};
list<line> l;
int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int op = a.first * b.second + b.first * c.second + c.first * a.second - (a.second * b.first + b.second * c.first + c.second * a.first);
    return op > 0 ? 1 : !op ? 0 : -1;
}
bool isIntersect(line l1, line l2) {
    if(l1.a == l2.a || l1.a == l2.b || l1.b == l2.a || l1.b == l2.b)
        return true;

    int ab = ccw(l1.a, l1.b, l2.a) * ccw(l1.a, l1.b, l2.b);
    int cd = ccw(l2.a, l2.b, l1.a) * ccw(l2.a, l2.b, l1.b);
    if(!ab && !cd) {
        if(l1.a > l1.b) swap(l1.a, l1.b);
        if(l2.a > l2.b) swap(l2.a, l2.b);
        return l2.a <= l1.b && l1.a <= l2.b;
    }
    return ab <= 0 && cd <= 0;
}
int main() {
    int n;
    scanf("%d",&n);
    while(n--) {
        line ll;
        scanf("%d %d %d %d",&ll.a.first, &ll.a.second, &ll.b.first, &ll.b.second);
        l.push_back(ll);
    }
    priority_queue<int> pq;
    while(!l.empty()) {
        queue<line> q;
        q.push(l.front());
        l.pop_front();
        int cnt = 1;
        while(!q.empty() && !l.empty()) {
            list<line> l2;
            line ll = q.front();
            q.pop();
            for(auto it = l.begin(); it != l.end(); it++) {
                if(isIntersect(ll, *it)) {
                    q.push(*it);
                    ++cnt;
                } else l2.push_back(*it);
            }
            l = l2;
        }
        pq.push(cnt);
    }
    printf("%d\n%d",pq.size(), pq.top());
}
