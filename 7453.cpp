#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define gc() getchar_unlocked()
vector<int> CD;
int fRI() {
    int ret = 0, flag = 1, n = gc();
    for (; '0'>n || n>'9'; n = gc())
        if (n == '-') {
            flag = -1; n = gc(); break;
        }
    do {
        ret = (ret << 3) + (ret << 1) + (n & 0b1111); n = gc();
    } while ('0' <= n && n <= '9');
    return ret * flag;
}
int main() {
    register int nums[4000][4], N = fRI(), i, j;
    register long ans = 0;
    for(i = 0; i < N; ++i) nums[i][0] = fRI(), nums[i][1] = fRI(), nums[i][2] = fRI(), nums[i][3] = fRI();
    CD.reserve(N*N);
    for(i = 0; i < N; ++i)
        for(j = 0; j < N; ++j)
            CD.push_back(nums[i][2]+nums[j][3]);
    sort(CD.begin(),CD.end());
    for(i = 0; i < N; ++i)
        for(j = 0; j < N; ++j){
            auto lit = lower_bound(CD.begin(),CD.end(),-(nums[i][0]+nums[j][1]));
            if(!(nums[i][0]+nums[j][1]+(*lit)))ans += upper_bound(CD.begin(),CD.end(),-(nums[i][0]+nums[j][1]))-lit;
        }
    printf("%ld",ans);
}
