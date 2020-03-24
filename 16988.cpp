#include <stdio.h>
#include <memory.h>
#include <queue>
#define gc() getchar_unlocked()
using namespace std;
int map[20][20], N, M, answer = 0;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
queue<pair<int,int>> q;
int fRI(){
    int N=gc(),ret = 0;
    for(;N<48||N>57;N=gc());
    do{
        ret = (ret<<3) + (ret<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return ret;
}
void simulation(){
    register int killed = 0, kill_flag, cnt;
    int map_cpy[20][20];
    memcpy(map_cpy,map,sizeof(map_cpy));
    for(register int i = 0; i < N; ++i)
        for(register int j = 0; j < M; ++j){
            if(map_cpy[i][j]==2){
                kill_flag = cnt = 1;
                q.push(make_pair(i,j));
                map_cpy[i][j] = -1;
                while(!q.empty()){
                    int x = q.front().second;
                    int y = q.front().first;
                    q.pop();
                    for(int k = 0; k < 4; ++k){
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if(0<=nx && nx < M && 0<=ny&&ny<N){
                            if(map_cpy[ny][nx]==2){
                                ++cnt;
                                q.push(make_pair(ny,nx));
                                map_cpy[ny][nx]=-1;
                            }
                            else if(map_cpy[ny][nx]==0){
                                kill_flag = 0;
                            }
                        }
                    }
                }
                killed = killed + cnt*kill_flag;
            }
        }
    answer = answer > killed ? answer : killed;
}
void DFS(int c, int s){
    if(c==2){
        simulation();
        return;
    }
    register int search = 0, i, j;
    for(i = 0 ; i < N; ++i)
        for(j = 0; j < M; ++j){
            ++search;
            if(!map[i][j]&&search > s){
                map[i][j] = 1;
                DFS(c+1,search);
                map[i][j] = 0;
            }
        }
}
int main(void){
    register int i, j;
    N = fRI(); M = fRI();
    for(i = 0 ; i < N; ++i)
        for(j = 0; j < M; ++j)
            map[i][j] = fRI();
    DFS(0,0);
    printf("%d",answer);
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
