#include <iostream>
#include <algorithm>
using namespace std;
int g[1000001];
int n, m, c, a, b;
int getG(int n) {
    return g[n] == n ? g[n] : (g[n] = getG(g[n]));
}

void makeG(int a, int b) {
    g[getG(a)] = g[getG(b)] = min(getG(a),getG(b));
}

int main() {
    scanf("%d %d",&n, &m);
    for(int i = 0; i <= n; ++i)
        g[i] = i;
    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d",&c,&a,&b);
        if(c) printf("%s\n", getG(a) ^ getG(b) ? "NO" : "YES");
        else makeG(a,b);
    }
}
