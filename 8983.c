#include <stdio.h>
#include <stdlib.h>
#define gc() getchar_unlocked()
int sade[100000];
int fRI(){
    register int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3) + (r<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return r;
}
int compare(const void *A, const void *B){
    return *(int*) A > *(int*) B ? 1 : -1;
}
int abs(int a){
    return a > 0 ? a : -a;
}
int upper_bound(int x, int N){
    int s = 0, e = N, m;
    if(sade[e-1] < x) return N;
    if(sade[0] > x) return 0;
    while(s<e){
        m = (s+e)>>1;
        if(sade[m]<=x) s = m+1;
        else e = m;
    }
    return e;
}
int main(void){
    register int M = fRI(), N = fRI(), L = fRI(), i, ans = 0, x, y, t;
    for(i = 0; i<M; i++)
        sade[i] = fRI();
    qsort(sade,M,sizeof(int),compare);
    for(i = 0; i < N; i++){
        x = fRI(); y = fRI();
        if(y>L) continue;
        t = upper_bound(x,M);
        if(t!=M&&abs(sade[t]-x) + y <= L) ans++;
        else if(t&&abs(sade[t-1]-x)+y<=L) ans++;
    }
    printf("%d",ans);
    
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
