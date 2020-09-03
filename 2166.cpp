#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
long long area(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    return (ll)(b.first - a.first) * (c.second - a.second) - (ll)(c.first - a.first) * (b.second - a.second);
}
int main() {
    int n;
    pair<int, int> a, b, c;
    scanf("%d",&n);
    n-=2;
    ll ans = 0;
    scanf("%d %d %d %d",&a.first,&a.second, &b.first, &b.second);
    for(int i = 0; i < n; i++) {
        scanf("%d %d",&c.first, &c.second);
        ans += area(a,b,c);
        b = c;
    }
    ans = abs(ans);
    printf("%lld.%d",ans/2,ans%2 ? 5 : 0);
}
