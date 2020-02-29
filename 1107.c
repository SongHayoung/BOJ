#include <stdio.h>
#define gc() getchar_unlocked()
int fRI(){
    int ret = 0, N = gc();
    for(;'0'>N||N>'9';N=gc());
    do{
        ret = (ret<<3) + (ret<<1) + (N&0b1111); N=gc();
    }while('0'<=N);
    return ret;
}
int main(int argc, char** argv) {
    register int N = fRI(),M = fRI(),cur,flag,check,answer = N-100 > 0 ? N - 100 : 100 - N;
    int button[10] = {1,1,1,1,1,1,1,1,1,1};
    for(flag=0;flag<M;flag++) button[fRI()] = 0;
    for(check = N-answer > 0 ? N - answer : 0; check <= N + answer; check++){
        cur = check; flag = 0;
        while(button[cur%10]){
            flag++;
            cur/=10;
            if((!cur)) {
                answer = N - check > 0 ? N - check + flag > answer ? answer : N - check + flag : check - N + flag >
                answer ? answer :
                check - N + flag;
                break;
            }
        }
        
    }
    printf("%d",answer);
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
