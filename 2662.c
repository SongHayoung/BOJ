#pragma GCC optimize ("O3")
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#include <stdio.h>
#include <memory.h>
int fRI(){
    int ret = 0, N = gc();
    for(;'0'>N||N>'9';N=gc());
    do{
        ret = (ret<<3) + (ret<<1) + (N&0b1111); N=gc();
    }while('0'<=N);
    return ret;
}
void fWI(int n){
    int ret = 0, count = 0;
    while(!(n%10)) {count++, n/=10;}
    while(n) {ret = (ret<<3) + (ret<<1) + n%10; n/=10;}
    while(ret) {pc((ret%10)|0b110000); ret/=10;}
    while(count--) pc('0');
    pc('\n');
}
int main(int argc, char** argv) {
    int N = fRI(), M = fRI(),DP[20][301],benefits[20][301],INFO[20][301][20];
    for(int i = 0; i<N;i++){
        DP[0][0] = fRI();
        for(int j = 0; j < M; j++) benefits[j][DP[0][0]] = fRI();
    }
    memcpy(DP[0],benefits[0],sizeof(int)*N);
    for(int i = 1; i <=N;i++)  INFO[0][i][0] = i;
    for(int i=1;i<M;i++){
        for(int j=1;j<=N;j++){
            for(int k = j;k>=0;k--){
                if(DP[i][j]<benefits[i][k] + DP[i-1][j-k]){
                    DP[i][j] = benefits[i][k] + DP[i-1][j-k];
                    memcpy(INFO[i][j],INFO[i-1][j-k],sizeof(int)*i);
                    INFO[i][j][i] = k;
                }
            }
        }
    }
    fWI(DP[M-1][N]);
    for(int i = 0 ; i < M;i++) printf("%d ",INFO[M-1][N][i]);
}
