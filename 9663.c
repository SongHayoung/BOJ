#include <stdio.h>

#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)

int answer = 0, N;
int st[15], MAP[15][15];
int fRI(){
    int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3)+(r<<1)+(N&0b1111); N = gc();
    }while(0x30<=N&&N<=0x3A);
    return r;
}

void fWI() {
    int r = 0, c = 0;
    if(!answer) {pc(48); return ;}
    while (!(answer % 10)) { c++; answer /= 10; }
    while (answer) { r = (r<<3)+(r<<1)+answer%10; answer /= 10; }
    while (r) { pc(r % 10 + 48); r /= 10; }
    while (c--) pc(0x30);
    return;
}
void DFS(int cur){
    if(cur==N) {answer++; return;}
    for(int i = 0; i < N; i++){
        if(st[i]||MAP[cur][i]) continue;
        st[i] ^= 1;
        for(int j = 1; j < N-cur; j++){
            if(i+j<N) MAP[cur+j][i+j]++;
            if(i-j>=0) MAP[cur+j][i-j]++;
        }
        DFS(cur+1);
        st[i] ^= 1;
        for(int j = 1; j < N-cur; j++){
            if(i+j<N) MAP[cur+j][i+j]--;
            if(i-j>=0) MAP[cur+j][i-j]--;
        }
    }
}
int main(int argc, char** argv){
    N = fRI();
    DFS(0);
    fWI();
}
