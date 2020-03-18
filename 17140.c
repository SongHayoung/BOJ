# pragma optimize("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define gc() getchar_unlocked()
struct INFO{
    int num;
    int cnt;
};
int fRI(){
    register int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3) + (r<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return r;
}
int compare(const void *A, const void *B){
    struct INFO* a = (struct INFO*) A;
    struct INFO* b = (struct INFO*) B;
    if(a->cnt==b->cnt)
        return a->num > b->num ? 1 : -1;
    return a->cnt > b->cnt ? 1 : -1;
}
int main(void){
    register int r = fRI(),c = fRI(),k = fRI(), rows = 4, cols = 4, i, j, ans = -1, l, maxN, newsize, replacesize, infoidx;
    int map[101][101], calc[101];
    struct INFO info[50];
    
    for(i = 1; i <= 3; ++i)
        for(j = 1; j <= 3; ++j)
            map[i][j] = fRI();
    
    for(i = 0; i <= 100; ++i){
        if(map[r][c]==k) {ans = i; break;}
        if(rows>=cols){
            replacesize = 0;
            for(j = 1; j < rows; ++j){
                maxN = infoidx = 0;
                newsize = 1;
                for(l = 1; l < cols; ++l){
                    ++calc[map[j][l]];
                    maxN = maxN < map[j][l] ? map[j][l] : maxN;
                    map[j][l] = 0;
                }
                for(l = 1; l <= maxN; ++l){
                    if(!calc[l]) continue;
                    info[infoidx].num = l;
                    info[infoidx++].cnt = calc[l];
                }
                qsort(info,infoidx,sizeof(struct INFO),compare);
                for(l = 0; l < infoidx && newsize<100; l++){
                    map[j][newsize++] = info[l].num;
                    map[j][newsize++] = info[l].cnt;
                }
                replacesize = replacesize > newsize ? replacesize : newsize;
                memset(calc,0,sizeof(int)*(maxN+1));
            }
            cols = replacesize;
        }
        else{
            replacesize = 0;
            for(j = 1; j < cols; ++j){
                maxN = infoidx = 0;
                newsize = 1;
                for(l = 1; l < rows; ++l){
                    ++calc[map[l][j]];
                    maxN = maxN < map[l][j] ? map[l][j] : maxN;
                    map[l][j] = 0;
                }
                for(l = 1; l <= maxN; ++l){
                    if(!calc[l]) continue;
                    info[infoidx].num = l;
                    info[infoidx++].cnt = calc[l];
                }
                qsort(info,infoidx,sizeof(struct INFO),compare);
                for(l = 0; l < infoidx && newsize<100; l++){
                    map[newsize++][j] = info[l].num;
                    map[newsize++][j] = info[l].cnt;
                }
                replacesize = replacesize > newsize ? replacesize : newsize;
                memset(calc,0,sizeof(int)*(maxN+1));
            }
            rows = replacesize;
        }
    }
    printf("%d",ans);
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
