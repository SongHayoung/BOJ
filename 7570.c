#include <stdio.h>
#include <stdlib.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
int fastreadINT_byValue(){
    int N = gc(), ret = 0;
    do{
        ret = (ret<<3) + (ret<<1) + (N & 0b1111);    N=gc();
    }while('0'<=N&&N<='9');
    return ret;
}

void writeFASTINT(int answer){
    int ret = 0, count = 0;
    if(answer==0)   {   pc('0'); pc('\n');   return;}
    while((answer%10)==0) { count++; answer/=10;}
    while(answer)   {ret = (ret<<3)+(ret<<1)+answer%10; answer/=10;}
    while(ret)  {pc(ret%10+'0'); ret/=10;}
    while(count--) pc('0');
    pc('\n');
}
int main(int argc, char** argv){
    register int i, N, n, answer = 0;
    N = fastreadINT_byValue();
    int DP[1000001] = {0,};
    for(i=1;i<=N;i++){
        n = fastreadINT_byValue();
        DP[n] = DP[n-1]+1;
        answer = answer > DP[n] ? answer : DP[n];
    }
    writeFASTINT(N-answer);
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
