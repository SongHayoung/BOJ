#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const ll INF = 1LL<<32;
ll arr[20002][3], n;
ll getCnt(long long m) {
    ll ret = 0;
    for(int i = 0; i < n; i++)
        if(arr[i][0] <= m)
            ret += (min(m,arr[i][2]) - arr[i][0]) / arr[i][1] + 1;
    return ret;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld %lld %lld", &arr[i][0], &arr[i][2], &arr[i][1]);
    ll l = 0, r = INF, m;
    while (l < r) {
        m = (l + r) / 2;
        if (getCnt(m) & 1)
            r = m;
        else
            l = m + 1;
    }
    if (l == INF)
        printf("NOTHING");
    else
        printf("%lld %lld", l, getCnt(l) - getCnt(l - 1));
}
