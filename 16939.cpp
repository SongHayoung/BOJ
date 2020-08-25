#include <iostream>
#include <memory.h>
#include <stdlib.h>
int cube[6][8];
int cube_cpy[6][8];

bool check(int y, int x) {
    return cube_cpy[y][x] == cube_cpy[y][x+1] && cube_cpy[y+1][x] == cube_cpy[y+1][x+1] && cube_cpy[y+1][x] == cube_cpy[y][x];
}

void c() {
    if (check(0, 2) && check(2, 2) && check(4, 2) && check(2, 0) && check(2, 4) && check(2,6)) {
        printf("1");
        exit(0);
    }
}

void f1() {
    memcpy(cube_cpy, cube, sizeof(cube_cpy));
    int n1 = cube_cpy[0][2], n2 = cube_cpy[1][2];
    cube_cpy[0][2] = cube_cpy[2][2], cube_cpy[1][2] = cube_cpy[3][2];
    cube_cpy[2][2] = cube_cpy[4][2], cube_cpy[3][2] = cube_cpy[5][2];
    cube_cpy[4][2] = cube_cpy[3][7], cube_cpy[5][2] = cube_cpy[2][7];
    cube_cpy[3][7] = n1, cube_cpy[2][7] = n2;
    c();
}

void f2() {
    memcpy(cube_cpy, cube, sizeof(cube_cpy));
    int n1 = cube_cpy[3][7], n2 = cube_cpy[2][7];
    cube_cpy[3][7] = cube_cpy[4][2], cube_cpy[2][7] = cube_cpy[5][2];
    cube_cpy[4][2] = cube_cpy[2][2], cube_cpy[5][2] = cube_cpy[3][2];
    cube_cpy[2][2] = cube_cpy[0][2], cube_cpy[3][2] = cube_cpy[1][2];
    cube_cpy[0][2] = n1, cube_cpy[1][2] = n2;
    c();
}

void f3() {
    memcpy(cube_cpy, cube, sizeof(cube_cpy));
    int n1 = cube_cpy[2][0], n2 = cube_cpy[2][1];
    cube_cpy[2][0] = cube_cpy[2][2], cube_cpy[2][1] = cube_cpy[2][3];
    cube_cpy[2][2] = cube_cpy[2][4], cube_cpy[2][3] = cube_cpy[2][5];
    cube_cpy[2][4] = cube_cpy[2][6], cube_cpy[2][5] = cube_cpy[2][7];
    cube_cpy[2][6] = n1, cube_cpy[2][7] = n2;
    c();
}

void f4() {
    memcpy(cube_cpy, cube, sizeof(cube_cpy));
    int n1 = cube_cpy[2][6], n2 = cube_cpy[2][7];
    cube_cpy[2][6] = cube_cpy[2][4], cube_cpy[2][7] = cube_cpy[2][5];
    cube_cpy[2][4] = cube_cpy[2][2], cube_cpy[2][5] = cube_cpy[2][3];
    cube_cpy[2][2] = cube_cpy[2][0], cube_cpy[2][3] = cube_cpy[2][1];
    cube_cpy[2][0] = n1, cube_cpy[2][1] = n2;

    //pM();
    c();
}

void f5() {
    memcpy(cube_cpy, cube, sizeof(cube_cpy));
    int n1 = cube_cpy[1][2], n2 = cube_cpy[1][3];
    cube_cpy[1][2] = cube_cpy[3][1], cube_cpy[1][3] = cube_cpy[2][1];
    cube_cpy[3][1] = cube_cpy[4][3], cube_cpy[2][1] = cube_cpy[4][2];
    cube_cpy[4][3] = cube_cpy[2][4], cube_cpy[4][2] = cube_cpy[3][4];
    cube_cpy[2][4] = n1, cube_cpy[3][4] = n2;
    c();
}

void f6() {
    memcpy(cube_cpy, cube, sizeof(cube_cpy));
    int n1 = cube_cpy[1][2], n2 = cube_cpy[1][3];
    cube_cpy[1][2] = cube_cpy[2][4], cube_cpy[1][3] = cube_cpy[3][4];
    cube_cpy[2][4] = cube_cpy[4][3], cube_cpy[3][4] = cube_cpy[4][2];
    cube_cpy[4][3] = cube_cpy[3][1], cube_cpy[4][2] = cube_cpy[2][1];
    cube_cpy[3][1] = n1, cube_cpy[2][1] = n2;
    c();
}

int main(void) {
    scanf("%d %d %d %d",&cube[0][2], &cube[0][3], &cube[1][2], &cube[1][3]);
    scanf("%d %d %d %d",&cube[2][2], &cube[2][3], &cube[3][2], &cube[3][3]);
    scanf("%d %d %d %d",&cube[4][2], &cube[4][3], &cube[5][2], &cube[5][3]);
    scanf("%d %d %d %d",&cube[2][0], &cube[2][1], &cube[3][0], &cube[3][1]);
    scanf("%d %d %d %d",&cube[2][4], &cube[2][5], &cube[3][4], &cube[3][5]);
    scanf("%d %d %d %d",&cube[2][6], &cube[2][7], &cube[3][6], &cube[3][7]);
    f1();
    f2();
    f3();
    f4();
    f5();
    f6();
    printf("0");
}

