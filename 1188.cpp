#include <iostream>
using namespace std;
int n, m;
int gcd(int p, int q){
    return q ? gcd(q, p%q) : p;
}

int main(void) {
    scanf("%d %d", &n, &m);
    int g = gcd(n, m);
    m /= g;
    cout<<(m - 1) * g;
}