#include <stdio.h>
struct ROBOT{
    int x;
    int y;
    int dir;
};
short R,C,N,M;
short map[100][100];
short dx[4] = {0,1,0,-1};
short dy[4] = {-1,0,1,0};
struct ROBOT r[101];
void simulation(){
    int rn, rep;
    char cmd;
    for(int i = 0; i < M; ++i){
        scanf("%d %c %d",&rn,&cmd,&rep);
        int nx, ny;
        switch(cmd){
            case 'R' : r[rn].dir = (r[rn].dir+rep)%4; break;
            case 'L' : r[rn].dir = (r[rn].dir+3*rep)%4; break;
            case 'F' :
                nx = r[rn].x, ny = r[rn].y;
                for(int j = 0; j < rep; ++j) {
                    nx += dx[r[rn].dir];
                    ny += dy[r[rn].dir];
                    if (nx < 0 || ny < 0 || ny >= R || nx >= C) {
                        printf("Robot %d crashes into the wall", rn);
                        return;
                    }
                    if (map[ny][nx]) {
                        printf("Robot %d crashes into robot %d", rn, map[ny][nx]);
                        return;
                    }
                }
                map[ny][nx] = rn;
                map[r[rn].y][r[rn].x] = 0;
                r[rn].y = ny;
                r[rn].x = nx;
        }
    }
    printf("OK");
}
int main(void) {
    int rx, ry;
    char d;
    scanf("%d %d", &C, &R);
    scanf("%d %d",&N,&M);
    for(int i = 1; i <= N; ++i){
        scanf("%d %d %c",&rx,&ry,&d);
        r[i].x = rx-1;
        r[i].y = R-ry;
        switch(d){
            case 'N' : r[i].dir = 0; break;
            case 'E' : r[i].dir = 1; break;
            case 'S' : r[i].dir = 2; break;
            case 'W' : r[i].dir = 3; break;
        }
        map[r[i].y][r[i].x] = i;
    }
    simulation();
}
