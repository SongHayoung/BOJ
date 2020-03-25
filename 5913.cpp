#include <stdio.h>
int map[5][5];
struct people{
    int y;
    int x;
    int collect;
};
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int ans = 0, apples = 25;
void DFS(people &a, people &b){
    if(a.x == b.x && a.y == b.y){
        if(a.collect + b.collect == apples + 1)
            ++ans;
        return;
    }
    people na, nb;
    for(int i = 0; i < 4; ++i) {
        na.x = a.x + dx[i];
        na.y = a.y + dy[i];
        if(0<=na.x && na.x < 5 && 0<=na.y && na.y < 5 && !map[na.y][na.x]) {
            for (int j = 0; j < 4; ++j) {
                nb.x = b.x + dx[j];
                nb.y = b.y + dy[j];
                if(0<=nb.x && nb.x < 5 && 0<=nb.y && nb.y < 5 && !map[nb.y][nb.x]){
                    map[na.y][na.x] = map[nb.y][nb.x] = 1;
                    na.collect = a.collect + 1;
                    nb.collect = b.collect + 1;
                    DFS(na,nb);
                    map[na.y][na.x] = map[nb.y][nb.x] = 0;
                }
            }
        }
    }
}


int main(void) {
    int N,x,y;
    scanf("%d",&N);
    apples -= N;
    for(int i = 0; i < N; ++i) {
        scanf("%d %d", &y, &x);
        map[y-1][x-1] = 1;
    }
    people a, b;
    a.x = a.y = 0;
    a.collect = b.collect = 1;
    b. x = b.y = 4;
    map[0][0] = map[4][4] = 1;
    DFS(a,b);
    printf("%d",ans);
    return 0;
}
