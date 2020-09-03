
#include <iostream>
#include <algorithm>
using namespace std;
int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int op = a.first * b.second + b.first * c.second + c.first * a.second - (a.second * b.first + b.second * c.first + c.second * a.first);
    return op > 0 ? 1 : !op ? 0 : -1;
}
int main() {
    pair<int, int> a, b, c;
    scanf("%d %d %d %d %d %d",&a.first, &a.second, &b.first, &b.second, &c.first, &c.second);
    printf("%d",ccw(a,b,c));
}
