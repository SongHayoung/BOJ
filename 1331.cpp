#include <stdio.h>
#include <stdlib.h>
char buf[3], nbuf[3], sbuf[3];
int visit[6][6];
int abs(int n){
    int ret = buf[n] - nbuf[n];
    ret = ret > 0 ? ret : -ret;
    return ret == 1 || ret == 2 ? ret : 99;
}
int main(){
    scanf("%s",buf);
    if(buf[0]<'A'||buf[0]>'F'||buf[1]<'1'||buf[1]>'6'){
        printf("Invalid");
        exit(0);
    }
    sbuf[0] = buf[0], sbuf[1] = buf[1];
    visit[buf[0]-'A'][buf[1]-'1'] = 1;
    for(int i = 0; i <35; ++i){
        scanf("%s",nbuf);
        if(nbuf[0]<'A'||nbuf[0]>'F'||nbuf[1]<'1'||nbuf[1]>'6'||abs(0)+abs(1)!=3||visit[nbuf[0]-'A'][nbuf[1]-'1']){
            printf("Invalid");
            exit(0);
        }
        visit[nbuf[0]-'A'][nbuf[1]-'1'] = 1;
        buf[0] = nbuf[0], buf[1] = nbuf[1];
    }
    nbuf[0] = sbuf[0], nbuf[1] = sbuf[1];
    if(abs(0)+abs(1)!=3) printf("Invalid");
    else printf("Valid");
}
