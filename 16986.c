#include <stdio.h>
#include <stdlib.h>
short N, K, sangsung[10][10], uses[10], wincount[3], kroutine[20], kcount, mroutine[20], mcount;
void game(int player){
    if(wincount[0]==K) {printf("1"); exit(0);}
    if(wincount[1]==K||wincount[2]==K) return;
    if(player==3){
        for(int i = 1; i <= 9; ++i){
            if(uses[i]) continue;
            uses[i] = 1;
            if(sangsung[i][kroutine[kcount]]==2){
                ++wincount[0];
                ++kcount;
                game(5);
                --wincount[0];
                --kcount;
            }
            else{
                ++wincount[1];
                ++kcount;
                game(6);
                --kcount;
                --wincount[1];
            }
            uses[i] = 0;
        }
    }
    if(player==5){
        for(int i = 1; i <= 9; ++i){
            if(uses[i]) continue;
            uses[i] = 1;
            if(sangsung[i][mroutine[mcount]]==2){
                ++wincount[0];
                ++mcount;
                game(3);
                --wincount[0];
                --mcount;
            }
            else{
                ++wincount[2];
                ++mcount;
                game(6);
                --mcount;
                --wincount[2];
            }
            uses[i] = 0;
        }
    }
    if(player==6){
        if(sangsung[kroutine[kcount]][mroutine[mcount]]==2){
            ++wincount[1];
            ++kcount;
            ++mcount;
            game(3);
            --wincount[1];
            --mcount;
            --kcount;
        }
        else{
            ++wincount[2];
            ++kcount;
            ++mcount;
            game(5);
            --wincount[2];
            --kcount;
            --mcount;
        }
    }
}
int main(){
    scanf("%d %d",&N, &K);
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            scanf("%d",&sangsung[i][j]);
    for(int i = 0; i < 20; ++i)
        scanf("%d",kroutine+i);
    for(int i = 0; i < 20; ++i)
        scanf("%d",mroutine+i);
    if(N>=K)
        game(3);
    printf("0");
}
