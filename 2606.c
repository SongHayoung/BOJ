#include <stdio.h>
int conn[101][101], virus[101], q[100];
int N, line, f, e, v, ans, i;
int main(void) {
    scanf("%d %d",&N, &line);
    q[0] = virus[1] = 1;
    for(i = 0;i < line; ++i){
        scanf("%d %d",&f,&e);
        conn[f][e] = conn[e][f] = 1;
    }
    f = 0; e = 1;
    while(f^e){
        v = q[f++];
        for(i = 2; i <= N; ++i)
            if(!virus[i]&&conn[v][i])
                virus[i] = q[e++] = i, ++ans;
    }
    printf("%d",ans);
    return 0;
}
