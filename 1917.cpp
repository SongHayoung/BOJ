#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
int map[6][6];
int square[44][6][6] = {
        {       {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,0,1,0},
                {0,1,1,1,1,0},
                {0,0,0,1,0,0},
                {0,0,0,0,0,0}},

        {       {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,0,1,0},
                {0,1,1,1,1,0},
                {0,0,1,0,0,0},
                {0,0,0,0,0,0}},

        {       {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,0,1,0},
                {0,1,1,1,1,0},
                {0,1,0,0,0,0},
                {0,0,0,0,0,0}},

        {       {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,1,0,0},
                {0,1,1,1,1,0},
                {0,0,0,1,0,0},
                {0,0,0,0,0,0}},

        {       {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,1,0,0},
                {0,1,1,1,1,0},
                {0,0,1,0,0,0},
                {0,0,0,0,0,0}},

        {       {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,1,1,0},
                {0,1,1,1,0,0},
                {0,0,1,0,0,0},
                {0,0,0,0,0,0}},

        {       {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,1,1,1},
                {0,1,1,1,0,0},
                {0,0,0,0,0,0},
                {0,0,0,0,0,0}},

        {       {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,1,1,0},
                {0,1,1,1,0,0},
                {0,0,0,1,0,0},
                {0,0,0,0,0,0}},

        {       {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,1,1,0},
                {0,1,1,1,0,0},
                {0,1,0,0,0,0},
                {0,0,0,0,0,0}},

        {       {0,0,0,0,0,0},
                {0,0,0,1,1,0},
                {0,0,1,1,0,0},
                {0,1,1,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,0,0,0}},

        {       {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,0,1,0},
                {0,1,1,1,1,0},
                {0,0,0,0,1,0},
                {0,0,0,0,0,0}},
};
int sq2[44][6][6];
int sq3[44][6][6];
int sq4[44][6][6];
bool equal(int movedMap[6][6]) {
    for(int k = 0; k < 44; k++) {
        int f1 = 0, f2 = 0, f3 = 0, f4 =0;
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++) {
                if(movedMap[i][j]) {
                    if(square[k][i][j]) ++f1;
                    if(sq2[k][i][j]) ++f2;
                    if(sq3[k][i][j]) ++f3;
                    if(sq4[k][i][j]) ++f4;
                }
            }
        if(f1 == 6 || f2 == 6 || f3 == 6 || f4 == 6)
            return true;
    }
    return false;
}
bool chk() {
    int top = 99, bottom = -1, left = 99, right = -1;
    int movedMap[6][6];
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
            if(map[i][j]) {
                top = min(top, i);
                bottom = max(bottom, i);
                left = min(left, j);
                right = max(right, j);
            }
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
            if(map[i][j])
                swap(map[i][j], map[i-top][j-left]);
    bottom -= top; right -= left; top = left = 0;
    for(int i = 0; i < 6 - bottom; i++) {
        for (int j = 0; j < 6 - right; j++) {
            memset(movedMap, 0, sizeof(movedMap));
            for(int k = 0; k < 6; k++)
                for(int l = 0; l < 6; l++)
                    if(map[k][l])
                        movedMap[k+i][l+j] = 1;
            if(equal(movedMap))
                return true;
        }
    }
    return false;
}
int main() {
    for(int k = 11; k < 22; k++)
        for(int i = 0; i < 6; i++)
            for(int j = 0; j < 6; j++)
                square[k][i][j] = square[k-11][i][6-j];
    for(int k = 22; k < 44; k++)
        for(int i = 0; i < 6; i++)
            for(int j = 0; j < 6; j++)
                square[k][i][j] = square[k-22][6-i][6-j];
    for(int k = 0; k < 44; k++)
        for(int i = 0; i < 6; i++)
            for(int j = 0; j < 6; j++)
                sq2[k][j][i] = square[k][i][j];
    for(int k = 0; k < 44; k++)
        for(int i = 0; i < 6; i++)
            for(int j = 0; j < 6; j++)
                sq3[k][i][j] = square[k][6-i][6-j];
    for(int k = 0; k < 44; k++)
        for(int i = 0; i < 6; i++)
            for(int j = 0; j < 6; j++)
                sq4[k][j][i] = sq3[k][i][j];
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                scanf("%d", &map[i][j]);
        printf("%s\n",chk() ? "yes" : "no");
    }
}
