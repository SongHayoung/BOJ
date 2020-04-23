#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;
int psumA[1001], psumB[1001];
int a, b, t, i, j, target;
long nums;
int main() {
    scanf("%d",&t);
    scanf("%d",&a);
    for(i = 1; i <= a; ++i){
        scanf("%d",&nums);
        psumA[i] = psumA[i-1] + nums;
    }
    scanf("%d",&b);
    for(i = 1; i <= b; ++i){
        scanf("%d",&nums);
        psumB[i] = psumB[i-1] + nums;
    }
    vec.reserve(b*b);
    for(i = 0; i < b; ++i)
        for(j = i+1; j <= b; ++j)
            vec.push_back(psumB[j]-psumB[i]);
    sort(vec.begin(),vec.end());
    for(i = nums = 0; i < a; ++i)
        for(j = i+1; j <= a; ++j){
            target = t-psumA[j]+psumA[i];
            auto lit = lower_bound(vec.begin(),vec.end(),target);
            if(target==*lit) nums += upper_bound(vec.begin(),vec.end(),target)-lit;
        }
    printf("%ld",nums);
}
