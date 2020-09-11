#include <iostream>
#include <queue>

using namespace std;
struct line {
    pair<int, int> a, b;
};
struct sq {
    line lines[4];
};
int ans, n, a, b, c, d;
queue<sq> all, g;
sq s, tmp;
int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int op = a.first * b.second + b.first * c.second + c.first * a.second -
             (a.second * b.first + b.second * c.first + c.second * a.first);
    return op > 0 ? 1 : !op ? 0 : -1;
}
bool isIntersect(line l1, line l2) {
    if (l1.a == l2.a || l1.a == l2.b || l1.b == l2.a || l1.b == l2.b)
        return true;
    int ab = ccw(l1.a, l1.b, l2.a) * ccw(l1.a, l1.b, l2.b);
    int cd = ccw(l2.a, l2.b, l1.a) * ccw(l2.a, l2.b, l1.b);
    if (!ab && !cd) {
        if (l1.a > l1.b) swap(l1.a, l1.b);
        if (l2.a > l2.b) swap(l2.a, l2.b);
        return l2.a <= l1.b && l1.a <= l2.b;
    }
    return ab <= 0 && cd <= 0;
}
bool cross(sq a, sq b) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (isIntersect(a.lines[i], b.lines[j]))
                return true;
    return false;
}
bool isIncludeZero(line l) {
    if(l.a.second == 0 && l.b.second == 0 && l.a.first <= 0 && l.b.first >= 0) return true;
    return l.a.first == 0 && l.b.first == 0 && l.a.second <= 0 && l.b.second >= 0;
}
int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        s.lines[0].a.first = s.lines[0].b.first = s.lines[1].a.first = s.lines[3].a.first = a;
        s.lines[0].a.second = s.lines[1].a.second = s.lines[1].b.second = s.lines[2].a.second = b;
        s.lines[0].b.second = s.lines[2].b.second = s.lines[3].a.second = s.lines[3].b.second = d;
        s.lines[1].b.first = s.lines[3].b.first = s.lines[2].a.first = s.lines[2].b.first = c;
        all.push(s);
        if(!ans)
            for(int i = 0; i < 4; i++)
                if(isIncludeZero(s.lines[i])) ans = -1;
    }
    while (!all.empty()) {
        g.push(all.front());
        all.pop();
        while (!g.empty()) {
            s = g.front();
            g.pop();
            n = all.size();
            for (int i = 0; i < n; i++) {
                tmp = all.front();
                all.pop();
                cross(s,tmp) ? g.push(tmp) : all.push(tmp);
            }
        }
        ++ans;
    }
    printf("%d", ans);
}
