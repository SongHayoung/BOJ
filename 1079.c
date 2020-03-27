#include <stdio.h>
#include <memory.h>
int N;
short conn[17][17];
short value[17];
int yujin, answer = 0;
short NIGHT(int live, short people){
    return live&1<<people && people!=yujin ? 1 : 0;
}
int DAYLIGHT(int live,short val[]){
    short max_val = -1, max_idx = -1;
    for(short i = 0; i < N; ++i)
        if(val[i]>max_val) max_val = val[i],max_idx = i;
    return max_idx;
}
int surviver(int live){
    int ret = 0;
    while(live){
        if(live&1) ++ret;
        live>>=1;
    }
    return ret;
}
void DFS(int live,short day, short val[]){
    short survive = surviver(live);
    if(survive&1){
        short kill = DAYLIGHT(live, val);
        if(kill == yujin){
            answer = answer > day ? answer : day;
            return ;
        }
        short newval[17];
        memcpy(newval,val,sizeof(newval));
        newval[kill] = 0;
        DFS(live^(1<<kill),day,newval);
    }
    else{
        for(int i = 0; i < N; ++i){
            if(NIGHT(live,i)){
                short newval[17];
                memcpy(newval,val,sizeof(newval));
                newval[i] = 0;
                for(short j = 0; j < N; ++j)
                    if(newval[j]) newval[j]+=conn[i][j];
                DFS(live^(1<<i),day+1,newval);
            }
        }
    }
}
int main(void) {
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)
        scanf("%d",&value[i]);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%d",&conn[i][j]);
    scanf("%d",&yujin);
    DFS((1<<N)-1,0,value);
    printf("%d",answer);
}
