#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <stdlib.h>
typedef unsigned long long ull;
using namespace std;
ull n, num;
vector<ull> vec;

void dfs(list<ull> l) {
    if(l.size() == n) {
        for(ull n : l)
            cout<<n<<" ";
        exit(0);
    }
    ull n = l.back();
    if((!(n % 3)) && (n / 3 == *lower_bound(vec.begin(), vec.end(), n / 3))) {
        l.push_back(n/3);
        dfs(l);
        l.pop_back();
    }
    if((n<<1) == *lower_bound(vec.begin(), vec.end(), n<<1)) {
        l.push_back(n<<1);
        dfs(l);
        l.pop_back();
    }
}
int main(void) {
    scanf("%d",&n);
    vec.reserve(n + 1);
    for(int i = 0; i < n; i++) {
        cin>>num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < n; ++i) {
        dfs(list<ull> {vec[i]});
    }
}
