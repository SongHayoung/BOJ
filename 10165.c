# pragma optimize("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <stdio.h>
#include <stdlib.h>
#define gc() getchar_unlocked()
int fRI(){
    register int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3) + (r<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return r;
}
struct BUS{
    int s;
    int e;
    int len;
    int num;
};
struct BUS b[500001];
int a[500];
int compare(const void *A, const void *B){
    struct BUS *a = (struct BUS*) A;
    struct BUS *b = (struct BUS*) B;
    if(a->len==b->len)
        return a->s > b->s ? 1 : -1;
    return a->len > b->len ? -1 : 1;
}
int Ncompare(const void *A, const void *B){
    return *(int*) A > *(int*) B ? 1 : -1;
}
int main(void){
    register int N = fRI(), M = fRI(), i, j, idx = 0, max_len = 0;
    b[0].s = fRI(); b[0].e = fRI(); b[0].len = b[0].s < b[0].e ? (b[0].e-b[0].s+1) : (N-b[0].s+b[0].e+1); b[0].num = 1;
    for(i = 1; i<M; i++) {
        b[i].s = fRI();
        b[i].e = fRI();
        b[i].len = b[i].s < b[i].e ? (b[i].e-b[i].s+1) : (N-b[i].s+b[i].e+1);
        b[i].num = i+1;
        if(b[max_len].len>b[i].len) {
            if (b[max_len].s < b[max_len].e && b[i].s < b[i].e) {
                if (b[max_len].s <= b[i].s && b[max_len].e >= b[i].e) { b[i].s = -1; }
            } else if (b[max_len].s > b[max_len].e) {
                if (b[i].s < b[i].e) {
                    if (b[max_len].s <= b[i].s && b[max_len].s <= b[i].e) { b[i].s = -1; }
                    else if (b[max_len].e >= b[i].e && b[max_len].e >= b[i].s) { b[i].s = -1; }
                } else if (b[max_len].s <= b[i].s && b[max_len].e >= b[i].e) { b[i].s = -1; }
            }
        }
        else
            max_len = i;
    }
    qsort(b,M,sizeof(struct BUS),compare);
    for(i = 0; i < M; i++){
        if(b[i].s==-1) continue;
        a[idx++] = b[i].num;
        for(j = i+1; j < M; j++){
            if(b[j].s==-1) continue;
            if(b[j].len>=b[i].len) continue;
            if(b[i].s<b[i].e && b[j].s<b[j].e){
                if(b[i].s<=b[j].s && b[i].e>=b[j].e) {b[j].s=-1; }
            }
            else if(b[i].s > b[i]. e){
                if(b[j].s < b[j].e){
                    if(b[i].s<= b[j].s && b[i].s <= b[j].e) {b[j].s=-1;}
                    else if(b[i].e >= b[j].e && b[i].e >= b[j].s) {b[j].s=-1;}
                }
                else if(b[i].s<=b[j].s && b[i].e>=b[j].e) {b[j].s=-1; }
            }
        }
    }
    qsort(a,idx,sizeof(int),Ncompare);
    for(i = 0; i < idx; i++)
        printf("%d ",a[i]);
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
