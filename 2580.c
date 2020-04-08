#include <stdio.h>
#include <stdlib.h>
int sudoku[9][9];
int info[81][2],info_idx;
int left=0,prevleft;
void pM(){
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j)
            printf("%d ",sudoku[i][j]);
        printf("\n");
    }
}
int vertical_check(int y, int x){
    int arr[10] = {0, };
    int cnt = 9;
    int posy = y/3*3, posx = x/3*3;
    for(int i = 0; i < 9; ++i) {
        if (sudoku[y][i]&&!arr[sudoku[y][i]]) ++arr[sudoku[y][i]], --cnt;
        if (sudoku[i][x]&&!arr[sudoku[i][x]]) ++arr[sudoku[i][x]], --cnt;
    }
    for(int i = posy; i < posy+3; ++i)
        for(int j = posx; j < posx+3; ++j)
            if(sudoku[i][j]&&!arr[sudoku[i][j]]) ++arr[sudoku[i][j]], --cnt;
    if(cnt==1){
        for(int i = 1; i <= 9; ++i)
            if(!arr[i]) return i;
    }
    return 0;
}
int possible(int y, int x){
    int arr[10] = {0,};
    int posy = y/3*3, posx = x/3*3;
    int ret = 0;
    for(int i = 0; i < 9; ++i) {
        if (sudoku[y][i]) ++arr[sudoku[y][i]];
        if (sudoku[i][x]) ++arr[sudoku[i][x]];
    }
    for(int i = posy; i < posy+3; ++i)
        for(int j = posx; j < posx+3; ++j)
            if(sudoku[i][j]) ++arr[sudoku[i][j]];
    for(int i = 1; i <= 9; ++i)
        if(!arr[i]) ret+=(1<<(i-1));
    return ret;
}
void initsudoku(){
    for(int i = 0; i < 9; ++i)
        for(int j = 0; j < 9; ++j){
            if(sudoku[i][j]) continue;
            int ret = vertical_check(i,j);
            if(ret){
                sudoku[i][j] = ret;
                --left;
            }
        }
}

void DFS(int c){
    if(c==info_idx){
        pM();
        exit(0);
    }
    int comb = possible(info[c][0],info[c][1]);
    if(!comb) return;
    for(int i = 0; i < 9; ++i) {
        if(comb&(1<<i)) {
            sudoku[info[c][0]][info[c][1]] = i+1;
            DFS(c + 1);
            sudoku[info[c][0]][info[c][1]] = 0;
        }
    }
}
int main(){
    for(int i = 0; i < 9; ++i)
        for(int j = 0; j < 9; ++j) {
            scanf("%d", &sudoku[i][j]);
            if(!sudoku[i][j]) ++left;
        }
    while(left!=prevleft) {
        prevleft = left;
        initsudoku();
    }
    for(int i = 0; i < 9; ++i)
        for(int j = 0; j < 9; ++j){
            if(sudoku[i][j]) continue;
            info[info_idx][0] = i;
            info[info_idx++][1] = j;
        }
    DFS(0);
}
