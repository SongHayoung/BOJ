#include <iostream>
using namespace std;
int point, n, y, x, b, cur;
int green[6][4], blue[4][6];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
void doGreen() {
    switch(b) {
        case 1: {
            green[0][x] = cur;
            int cy = 0, cx = x;
            while(true) {
                if(cy+1 >= 6 || green[cy+1][cx]) break;
                green[cy][cx] = 0;
                green[++cy][cx] = cur;
            }
        } break;
        case 2: {
            green[1][x] = green[1][x+1] = cur;
            int cy = 1, cx = x;
            while(true) {
                if(cy + 1 >= 6 || green[cy+1][cx] || green[cy+1][cx+1]) break;
                green[cy][cx] = green[cy][cx+1] = false;
                ++cy;
                green[cy][cx] = green[cy][cx+1] = cur;
            }
        } break;
        case 3: {
            green[0][x] = green[1][x] = cur;
            int cy = 1, cx = x;
            while(true) {
                if(cy+1 >= 6 || green[cy+1][cx]) break;
                green[cy-1][cx] = 0;
                green[++cy][cx] = cur;
            }
        } break;
    }
}

void doBlue() {
    switch (b) {
        case 1: {
            blue[y][0] = cur;
            int cy = y, cx = 0;
            while(true) {
                if(cx + 1>= 6 || blue[cy][cx+1]) break;
                blue[cy][cx] = 0;
                blue[cy][++cx] = cur;
            }
        } break;
        case 2: {
            blue[y][0] = blue[y][1] = cur;
            int cy = y, cx = 1;
            while(true) {
                if(cx + 1 >= 6 || blue[cy][cx+1]) break;
                blue[cy][cx-1] = 0;
                blue[cy][cx + 1] = cur;
                ++cx;
            }
        } break;
        case 3: {
            blue[y][1] = blue[y+1][1] = cur;
            int cy = y, cx = 1;
            while(true) {
                if(cx + 1 >= 6 || blue[cy][cx+1] || blue[cy+1][cx+1]) break;
                blue[cy][cx] = blue[cy+1][cx] = 0;
                ++cx;
                blue[cy][cx] = blue[cy+1][cx] = cur;
            }
        } break;
    }
}

void moveGreen() {
    for(int i = 4; i >= 0; --i) {
        for(int j = 0; j < 4; ++j) {
            if(green[i][j]) {
                int cx1 = j, cy1 = i, cy2 = i, cx2 = j;
                for(int k = 0; k < 4; ++k) {
                    if(0 <= i + dy[k] && i + dy[k] < 6 && 0 <= j + dx[k] && j + dx[k] < 4 && green[i+dy[k]][j+dx[k]] == green[i][j])
                        cy2 = i + dy[k], cx2 = j + dx[k];
                }
                while(true) {
                    if(cy1 + 1 >= 6 || cy2 + 1 >= 6) break;
                    if(green[cy1+1][cx1] != 0 && green[cy1+1][cx1] != green[cy1][cx1]) break;
                    if(green[cy2+1][cx2] != 0 && green[cy2+1][cx2] != green[cy2][cx2]) break;
                    green[cy1+1][cx1] = green[cy1][cx1];
                    green[cy2+1][cx2] = green[cy2][cx2];
                    green[cy2][cx2] = 0;
                    if(cy2 + 1 != cy1)
                        green[cy1][cx1] = 0;
                    ++cy1;
                    ++cy2;
                }
            }
        }
    }
}

void moveBlue() {
    for(int i = 4; i >= 0; --i) {
        for(int j = 0; j < 4; ++j) {
            if(blue[j][i]) {
                int cx1 = i, cy1 = j, cx2 = i, cy2 = j;
                for(int k = 0; k < 4; ++k) {
                    if(0 <= j + dy[k] && j + dy[k] < 4 && 0 <= i + dx[k] && i + dx[k] < 6 && blue[j + dy[k]][i+dx[k]] == blue[j][i])
                        cx2 = i+dx[k], cy2 = j + dy[k];
                }
                while(true) {
                    if(cx1 + 1 >= 6 || cx2 + 1 >= 6) break;
                    if(blue[cy1][cx1+1] != 0 && blue[cy1][cx1+1] != blue[cy1][cx1]) break;
                    if(blue[cy2][cx2+1] != 0 && blue[cy2][cx2+1] != blue[cy2][cx2]) break;
                    blue[cy1][cx1+1] = blue[cy1][cx1];
                    blue[cy2][cx2+1] = blue[cy2][cx2];
                    blue[cy2][cx2] = 0;
                    if(cx2+1 != cx1)
                        blue[cy1][cx1] = 0;
                    ++cx1;
                    ++cx2;
                }
            }
        }
    }
}

bool addGreen() {
    bool ret = false;
    for(int i = 2; i < 6; i++) {
        int cnt = 0;
        for(int j = 0; j < 4; ++j)
            if(green[i][j]) ++cnt;
        if(cnt == 4) {
            for (int j = 0; j < 4; ++j)
                green[i][j] = 0;
            ++point;
            ret = true;
        }
    }
    moveGreen();
    return ret;
}
void popGreen() {
    while(addGreen());
    while(green[0][0] || green[1][0] || green[0][1] || green[1][1] ||green[0][2] || green[1][2] ||green[0][3] || green[1][3]) {
        green[5][0] = green[5][1] = green[5][2] = green[5][3] = 0;
        moveGreen();
        while(addGreen());
    }
}
bool addblue() {
    bool ret = false;
    for(int i = 2; i < 6; i++) {
        int cnt = 0;
        for(int j = 0; j < 4; ++j)
            if(blue[j][i]) ++cnt;
        if(cnt == 4) {
            for(int j = 0; j < 4; ++j)
                blue[j][i] = 0;
            ++point;
            ret = true;
        }
    }
    moveBlue();
    return ret;
}
void popBlue() {
    while(addblue());
    while(blue[0][0] || blue[0][1] || blue[1][0] || blue[1][1] ||blue[2][0] || blue[2][1] ||blue[3][0] || blue[3][1]) {
        blue[0][5] = blue[1][5] = blue[2][5] = blue[3][5] = 0;
        moveBlue();
        while(addblue());
    }
}
int blocks() {
    int ret = 0;
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 4; ++j) {
            if(green[i][j]) ++ret;
            if(blue[j][i]) ++ret;
        }
    return ret;
}
int main() {
    scanf("%d",&n);
    for(cur = 1; cur <= n; ++cur) {
        scanf("%d %d %d",&b,&y,&x);
        doGreen();
        doBlue();
        popGreen();
        popBlue();
    }
    printf("%d\n%d",point,blocks());
}
