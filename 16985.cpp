#include <stdio.h>
#include <memory.h>
#include <queue>

#define gc() getchar_unlocked()
using namespace std;
int map[5][5][5][4], answer = 987654321;
int maze[5][5][5];
int C[5][2];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
struct INFO{
    int x;
    int y;
    int s;
    int c;
};
void Rotate90(int stair, int origin){
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j)
            map[stair][j][4-i][origin+1] = map[stair][i][j][origin];
}
int fRI(){
    int N=gc(),ret = 0;
    for(;N<48||N>57;N=gc());
    do{
        ret = (ret<<3) + (ret<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return ret;
}
void simulation(pair<int,int> sp, pair<int,int> ep){
    if(!maze[0][sp.first][sp.second]||!maze[4][ep.first][ep.second]) return;
    int maze_cpy[5][5][5];
    queue<INFO> q;
    struct INFO info;
    int y, x, s, c;
    info.y = sp.first;
    info.x = sp.second;
    info.s = 0;
    info.c = 0;
    q.push(info);
    memcpy(maze_cpy,maze,sizeof(maze_cpy));
    maze_cpy[0][info.y][info.x] = 0;
    while(!q.empty()){
        y = q.front().y;
        x = q.front().x;
        s = q.front().s;
        c = q.front().c;
        q.pop();
        if(c>answer) return;
        if(s==4&&y==ep.first&&x==ep.second){
            answer = answer > c ? c : answer;
            return;
        }
        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0<=nx && nx<5 && 0<=ny && ny<5 && maze_cpy[s][ny][nx]){
                maze_cpy[s][ny][nx] = 0;
                info.y = ny;
                info.x = nx;
                info.c = c+1;
                info.s = s;
                q.push(info);
            }
        }
        if(s<4 && maze_cpy[s+1][y][x]){
            maze_cpy[s+1][y][x] = 0;
            info.y = y;
            info.x = x;
            info.c = c+1;
            info.s = s+1;
            q.push(info);
        }
        if(s && maze_cpy[s-1][y][x]){
            maze_cpy[s-1][y][x] = 0;
            info.y = y;
            info.x = x;
            info.c = c+1;
            info.s = s-1;
            q.push(info);
        }
    }
}
void DFS(int s,int p){
    if(s==5){
        for(int stair = 0; stair < 5; ++stair){
            for(int i = 0; i < 5; ++i)
                for(int j = 0; j < 5; ++j)
                    maze[stair][i][j] = map[C[stair][0]][i][j][C[stair][1]];
        }
        simulation(make_pair(0,0),make_pair(4,4));
        return;
    }
    for(int plate = 0; plate < 5; ++plate){
        if((1<<plate) & p) continue;
        C[s][0] = plate;
        for(int rotate = 0; rotate < 4; ++rotate){
            C[s][1] = rotate;
            DFS(s+1,p+(1<<plate));
        }
    }
}
int main(void) {
    register int i, j, stair;
    for (stair = 0; stair < 5; ++stair) {
        for (i = 0; i < 5; ++i)
            for (j = 0; j < 5; ++j)
                map[stair][i][j][0] = fRI();
        Rotate90(stair,0);
        Rotate90(stair,1);
        Rotate90(stair,2);
    }
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j)
            maze[0][i][j] = map[0][i][j][0];
    DFS(0,0);
    if(answer!=987654321)
        printf("%d", answer);
    else
        printf("-1");
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
