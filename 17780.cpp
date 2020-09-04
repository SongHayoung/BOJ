#include <iostream>
#include <memory.h>
#include <cmath>
#include <queue>
using namespace std;
struct horse {
    int y, x, dir, up, down;
};
int n, k;
int map[12][12];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
horse h[10];

int convertDir(int dir) {
    switch (dir) {
        case 1: return 1;
        case 2: return 3;
        case 3: return 0;
        case 4: return 2;
    }
}
int findTop(int i) {
    while(h[i].up != i)
        i = h[i].up;
    return i;
}

int findBottom(int i) {
    while(h[i].down != i)
        i = h[i].down;
    return i;
}

void changePos(int ny, int nx, int i) {
    h[i].y = ny;
    h[i].x = nx;
    while(h[i].up != i) {
        h[i].y = ny;
        h[i].x = nx;
        i = h[i].up;
    }
    h[i].y = ny;
    h[i].x = nx;
}

void merge(int i) {
    int curTop = findTop(i);
    int curBottom = findBottom(i);
    for(int j = 0; j < k; j++) {
        if(curTop == findTop(j)) continue;
        if(h[j].y == h[i].y && h[j].x == h[i].x) {
            int top = findTop(j);
            h[top].up = curBottom;
            h[curBottom].down = top;
            return ;
        }
    }
}

void moveWhite(int i) {
    changePos(h[i].y + dy[h[i].dir], h[i].x + dx[h[i].dir], i);
    merge(i);
}

void reverseStack(int i) {
    while(h[i].up != i) {
        swap(h[i].down, h[i].up);
        i = h[i].down;
    }
    swap(h[i].down, h[i].up);
}

void moveRed(int i) {
    changePos(h[i].y + dy[h[i].dir], h[i].x + dx[h[i].dir], i);
    reverseStack(i);
    merge(i);
}

void moveBlue(int i) {
    h[i].dir = (h[i].dir + 2) % 4;
    int nx = h[i].x + dx[h[i].dir];
    int ny = h[i].y + dy[h[i].dir];
    if(0 > ny || ny >= n || 0 > nx || nx >= n)
        return ;
    switch (map[ny][nx]) {
        case 0: moveWhite(i); break;
        case 1: moveRed(i);
    }
}

void move(int i) {
    if(h[i].down != i) return;
    int nx = h[i].x + dx[h[i].dir];
    int ny = h[i].y + dy[h[i].dir];
    if(0 > ny || ny >= n || 0 > nx || nx >= n) {
        moveBlue(i);
        return;
    }
    switch(map[ny][nx]) {
        case 0: moveWhite(i); break;
        case 1: moveRed(i); break;
        case 2: moveBlue(i); break;
    }
}

bool getCount() {
    bool visit[12] = {false,};
    for(int i = 0; i < k; i++) {
        if(visit[i]) continue;
        int cnt = 1;
        int bottom = findBottom(i);
        while(h[bottom].up != bottom) {
            ++cnt;
            bottom = h[bottom].up;
        }
        if(cnt>=4)
            return true;
    }
    return false;
}
int main() {
    scanf("%d %d",&n, &k);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d",&map[i][j]);
    for(int i = 0; i < k; i++) {
        scanf("%d %d %d",&h[i].y, &h[i].x, &h[i].dir);
        h[i].dir = convertDir(h[i].dir);
        h[i].y -= 1;
        h[i].x -= 1;
        h[i].up = h[i].down = i;
    }
    for(int time = 1; time < 1000; time++) {
        for(int i = 0; i < k; i++)
            move(i);
        if(getCount()) {
            printf("%d",time);
            exit(0);
        }
    }
    printf("-1");
}
