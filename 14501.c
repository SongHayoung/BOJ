# pragma optimize("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <stdio.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define reg register
#define s short
short fRS() {
    reg s N = gc(), r = 0;
    for (;48 > N || N > 57; N = gc());
    do {
        r = (r << 3) + (r << 1) + (N & 0b1111); N = gc();
    } while (48 <= N);
    return r;
}
void fWS(s tc) {
    if(!tc) {pc(48); return;}
    reg s r = 0, c = 0;
    while (!(tc % 10)) { c++; tc /= 10; }
    while (tc) { r = (r << 3) + (r << 1) + (tc % 10); tc /= 10; }
    while (r) { pc(r % 10 | 0b110000); r /= 10; }
    while (c--) pc(0x30);
}
int main(int argc, char** argv){
    reg s N = fRS();
    s Ti[16], Pi[16], DP[17] = {0};
    for(reg s i = 0;i < N; i++)
        Ti[i] = fRS(), Pi[i] = fRS();
    for(reg s i = N-1; i >= 0; i--) {
        if(i+Ti[i]<=N) DP[i] = DP[i+Ti[i]] + Pi[i] > DP[i+1] ? DP[i+Ti[i]] + Pi[i] : DP[i+1];
        else DP[i] = DP[i+1];
    }
    fWS(DP[0]);
}
