#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;
int n, h, num;
int ans = 987654321, cnt = 0;
int up[500001];
int down[500001];
int main() {
    scanf("%d %d",&n, &h);
    for(int i = 0; i < n; i++) {
        scanf("%d",&num);
        i&1 ? ++down[num] : ++up[num];
    }
    for(int i = h - 1; i > 0; i--) {
        up[i] += up[i+1];
        down[i] += down[i+1];
    }
    int l = 0, r = n, m;
    while(l < r) {
        m = (l + r) / 2;
        int cur = 0;
        for(int i = 1; i <= h; ++i)
            if(up[i] + down[h+1-i] <= m)
                ++cur;
        if(ans > m && cur) {
            ans = m;
            cnt = cur;
        }
        cur ? r = m : l = m +1;
    }
    printf("%d %d",ans,cnt);
}
