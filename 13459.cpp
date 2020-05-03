#include <stdio.h>
struct A{int y,x;};
char B[10][11];
int X[4]={0,1,0,-1},Y[4]={-1,0,1,0},v[10][10][10][10][10],N,M,I,J;
A r,b;
int mb(A &a,A b,int d){
    while(1){
        if(B[a.y][a.x]=='O') {a.y=a.x=0;return 1;}
        else if(B[a.y+Y[d]][a.x+X[d]]!='#'&&!(a.y+Y[d]==b.y&&a.x+X[d]==b.x))a.x=a.x+X[d],a.y=a.y+Y[d];
        else return 0;
    }
}
int DFS(int d,A r,A b){
    if(d==10||v[r.y][r.x][b.y][b.x][d])return 0;
    int i=d;
    for(;i<10;++i)v[r.y][r.x][b.y][b.x][i]=1;
    A nr,nb;
    for(i=0;i<4;++i){
        nr=r,nb=b;
        int rh=mb(nr,nb,i),bh=mb(nb,nr,i);
        if(!rh)rh=mb(nr,nb,i);
        if(bh)continue;
        else if(rh)return 1;
        else if(DFS(d+1,nr,nb))return 1;
    }return 0;
}
main(){
    scanf("%d%d",&N,&M);
    for(;I<N;++I){
        scanf("%s",B[I]);
        for(J=0;J<M;++J){
            if(B[I][J]==82)r.y=I,r.x=J,B[I][J]=46;
            else if(B[I][J]==66)b.y=I,b.x=J,B[I][J]=46;
        }
    }printf("%d",DFS(0,r,b)?1:0);
}
