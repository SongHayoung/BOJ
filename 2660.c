#include <stdio.h>
#include <stdlib.h>
#define gc() getchar_unlocked()
#define SH short
SH friends[51][51], leader[50], leaders, points = 100, members, q[50];
SH fRI(){
    register SH N=gc(),ret = 0,flag = 1;
    for(;N<48||N>57;N=gc()) if(N=='-') { flag = 0; N = gc(); break; }
    do{
        ret = (ret<<3) + (ret<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return flag ? ret : -ret;
}
SH compare(const void *A, const void *B){
    return *(SH*) A > *(SH*) B ? 1 : -1;
}
void BFS(SH candidate){
    SH prefriend[51] = {0, };
    SH prepoints = 0, f, size, s = 0, e = 0;
    prefriend[candidate] = 1;
    for(SH i = 1; i <= members; ++i)
        if(friends[candidate][i])
            q[e++] = i,prefriend[i] = 1;
    while(s^e){
        size = e-s;
        while(size--){
            f = q[s++];
            for(SH i = 1; i <= members; ++i)
                if(friends[f][i]&&!prefriend[i])
                    q[e++]=i,prefriend[i] = 1;
        }
        ++prepoints;
        if(prepoints>points) return;
    }
    if(points==prepoints) leader[leaders++] = candidate;
    else if(points>prepoints){
        leader[0] = candidate;
        leaders = 1;
        points = prepoints;
    }
    return ;
}
int main(void) {
    register SH f = 0, e = 0;
    members = fRI();
    do{
        friends[f][e] = friends[e][f] = 1;
        f = fRI(), e = fRI();
    }while(f!=-1);
    for(SH i = 1; i <= members; ++i)
        BFS(i);
    qsort(leader,leaders,sizeof(SH),compare);
    printf("%d %d\n",points,leaders);
    for(SH i = 0; i < leaders; ++i)
        printf("%d ",leader[i]);
}
