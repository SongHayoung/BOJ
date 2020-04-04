# pragma optimize("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <stdio.h>
#define gc() getchar_unlocked()
int input[500000];
int output[500000];
int f(int &cur, int dst){
    return input[dst-1]>=cur ? dst : !input[dst-1] ? 0 : f(cur,output[dst-1]);
}
int fRI() {
    register int ret = 0, n = gc();
    for (; 48>n || n>57; n = gc()) ;
    do {
        ret = (ret << 3) + (ret << 1) + (n & 0b1111); n = gc();
    } while (48<= n);
    return ret;
}
int main(){
    register int i = 0, N=fRI();
    for(; i < N; ++i) input[i]=fRI();
    printf("0 ");
    for(i = 1; i < N; ++i)
        printf("%d ",output[i] = input[i]<=input[i-1] ? i : f(input[i],output[i-1]));
}
