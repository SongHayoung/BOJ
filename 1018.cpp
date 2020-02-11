#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
int M, N;
char MAP[50][50];
char CMP[8][8] = {{'W','B','W','B','W','B','W','B'},
                  {'B','W','B','W','B','W','B','W'},
                  {'W','B','W','B','W','B','W','B'},
                  {'B','W','B','W','B','W','B','W'},
                  {'W','B','W','B','W','B','W','B'},
                  {'B','W','B','W','B','W','B','W'},
                  {'W','B','W','B','W','B','W','B'},
                  {'B','W','B','W','B','W','B','W'}};
int answer=987654321;

void compare(int x,int y){
    int cnt = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (CMP[i][j] != MAP[y + i][x + j])
                ++cnt;
    if(cnt>=32)
        cnt = 64-cnt;
    answer = answer>cnt ? cnt : answer;
    return ;
}

int main(void){
    cin>>M>>N;
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            cin>>MAP[i][j];

    for(int i=0;i<=M-8;i++)
        for(int j=0;j<=N-8;j++)
            compare(j,i);

    cout<<answer<<endl;
    return 0;
}
