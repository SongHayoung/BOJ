#include <stdio.h>
char buf[5][6];
int c[7], q[7];
int answer, xpos, ypos, s, e, visit, cnt;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int isconnected() {
    q[0] = c[0];
    visit = e = 1; s = 0; cnt = buf[c[0]/5][c[0]%5]=='S' ? 1 : 0;
    while(s!=e&&visit!=(1<<7)-1){
        xpos = q[s]%5;
        ypos = q[s]/5;
        ++s;
        for(int i = 0; i < 4; ++i){
            int ny = ypos+dy[i];
            int nx = xpos+dx[i];
            if(0<=nx&&nx<5 && 0<=ny&&ny<5){
                for(int j = 1; j < 7; ++j)
                    if(c[j]==ny*5+nx && !(visit&(1<<j))){
                        visit |= (1<<j);
                        q[e++] = ny*5+nx;
                        if(buf[ny][nx]=='S') ++cnt;
                        break;
                    }
            }
        }
        
    }
    return cnt>=4 && visit==((1<<7)-1) ? 1 : 0;
}

int main() {
    for (int i = 0; i < 5; ++i)
        scanf("%s", buf[i]);
    for (c[0] = 0; c[0] <= 18; ++c[0])
        for (c[1] = c[0] + 1; c[1] <= 19; ++c[1])
            for (c[2] = c[1] + 1; c[2] <= 20; ++c[2])
                for (c[3] = c[2] + 1; c[3] <= 21; ++c[3])
                    for (c[4] = c[3] + 1; c[4] <= 22; ++c[4])
                        for (c[5] = c[4] + 1; c[5] <= 23; ++c[5])
                            for (c[6] = c[5] + 1; c[6] <= 24; ++c[6])
                                if (isconnected()) ++answer;
    printf("%d", answer);
}
