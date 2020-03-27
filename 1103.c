#include <stdio.h>
#include <stdlib.h>
#define SH short
char B[50][51];
int N, M;
SH D[50][50], V[50][50], dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
SH DFS(SH y, SH x){
    if(0>x||0>y||x>=M||y>=N||B[y][x]=='H') return 0;
    if(V[y][x]) {printf("-1"); exit(0);}
    if(D[y][x]) return D[y][x];
    V[y][x] = 1;
    for(SH i = 0; i < 4; ++i)
        D[y][x] = D[y][x] > DFS(y+dy[i]*(B[y][x]&0b1111),x+dx[i]*(B[y][x]&0b1111))+1 ? D[y][x] : DFS(y+dy[i]*(B[y][x]&0b1111),x+dx[i]*(B[y][x]&0b1111))+1;
    V[y][x] = 0;
    return D[y][x];
}
int main(void) {
    scanf("%d %d",&N,&M);
    for(SH i = 0; i < N; ++i)
        scanf("%s",B[i]);
    printf("%d",DFS(0,0));
}
