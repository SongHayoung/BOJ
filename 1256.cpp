#include <iostream>
#include <algorithm>
#define ull unsigned long long
using namespace std;
int a, z, k;
ull comb[201][101];
ull combination(int n, int m) {
    return !n || !m ? 1 : comb[n+m][m] ? comb[n+m][m] : comb[n+m][m] = combination(n-1,m) + combination(n,m-1);
}
void dfs(int n, int m, int cur) {
    if(!n) {
        for(int i = 0; i < m; ++i) printf("z");
        exit(0);
    }
    if(!m) {
        for(int i = 0; i < n; ++i)  printf("a");
        exit(0);
    }
    if(combination(n-1,m) < cur) {
        printf("z");
        dfs(n,m-1,cur-combination(n-1,m));
    } else {
        printf("a");
        dfs(n-1,m,cur);
    }
}
int main() {
    scanf("%d %d %d",&a,&z,&k);
    if(combination(a,z) < k){
        printf("-1");
        exit(0);
    }
    dfs(a,z,k);
}
