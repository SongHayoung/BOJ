#include <stdio.h>
int R, C;
char buf[10000][501];
int visit[10000][500];
int pipe = 0;
int DFS(int y, int x) {
    if (y < 0 || x < 0 || y >= R || x >= C) return 0;
    if (buf[y][x] == 'x') return 0;
    if (visit[y][x]) return 0;
    if (x == C - 1) {
        buf[y][x] = 'x';
        ++pipe;
        return 1;
    }
    visit[y][x] = 1;
    if (DFS(y - 1, x + 1)) {
        buf[y][x] = 'x';
        return 1;
    }
    if (DFS(y, x + 1)) {
        buf[y][x] = 'x';
        return 1;
    }
    if (DFS(y + 1, x + 1)) {
        buf[y][x] = 'x';
        return 1;
    }
    return 0;
}

int main(void) {
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; ++i)
        scanf("%s", buf[i]);
    for (int i = 0; i < R; ++i) {
        DFS(i, 0);
    }
    printf("%d", pipe);
}
