#include <stdio.h>
int map[1000][1000];
int N, M, answer;
bool check(int y, int x){
    if(y+answer>=N||x+answer>=M) return false;
    for(int i = y; i <= y+answer; ++i)
        for(int j = x; j <= x+answer; ++j)
            if(map[i][j]) return false;
    return true;
}
int main() {
    scanf("%d %d",&N,&M);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            scanf("%d",&map[i][j]);
    for(int i = 0; i < N-answer; ++i)
        for(int j = 0; j < M-answer;++j)
            while(check(i,j)) ++answer;
    printf("%d",answer);
}
