#include <iostream>
#include <algorithm>
#include <list>
#include <memory.h>
using namespace std;
int n, m, a, b;
bool inLine[32001];
list<int> v[32001];
void push(int n) {
    if(inLine[n]) return;
    inLine[n] = true;
    if(v[n].empty()) {
        printf("%d ",n);
        return;
    }
    for(int nt : v[n])
        push(nt);
    printf("%d ", n);
}
int main() {
    scanf("%d %d",&n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d",&a, &b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; ++i)
        push(i);
}
