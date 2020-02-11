#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
int N, M, K;
int MAP[20][20];
int command[1001];
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};
class DICE{
public :
    int x;
    int y;
    int info[4][3];
    DICE(){
        memset(info,0,sizeof(info));
    }
    int print() {
        return info[1][1];
    }
    void move(int cmd) {
        switch(cmd){
            case 1:
                swap(info[1][1],info[1][2]);
                swap(info[1][0],info[1][1]);
                swap(info[3][1],info[1][0]);
                break;
            case 2:
                swap(info[1][1],info[1][0]);
                swap(info[1][2],info[1][1]);
                swap(info[3][1],info[1][2]);

                break;
            case 3:
                swap(info[1][1],info[0][1]);
                swap(info[2][1],info[1][1]);
                swap(info[3][1],info[2][1]);
                break;
            case 4:
                swap(info[2][1],info[3][1]);
                swap(info[1][1],info[2][1]);
                swap(info[0][1],info[1][1]);
                break;
        }
        x += dx[cmd];
        y += dy[cmd];
    }
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }

};
DICE dice;

void print_dice(){
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cout<<dice.info[i][j]<<" ";
        }
        cout<<endl;
    }
}

void play(){
    vector<int> answer;
    for(int i=0;i<K;i++){
        int next_x = dice.x + dx[command[i]];
        int next_y = dice.y + dy[command[i]];
        if(0<=next_x && next_x<M && 0<=next_y && next_y<N){
            dice.move(command[i]);
            if(MAP[next_y][next_x]==0)
                MAP[next_y][next_x]=dice.info[3][1];
            else{
                dice.info[3][1]=MAP[next_y][next_x];
                MAP[next_y][next_x] = 0;
            }
            answer.push_back(dice.print());
        }
    }
    for(int i=0;i<answer.size();i++)
        cout<<answer[i]<<endl;
}

int main(void){
    cin>>N>>M>>dice.y>>dice.x>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>MAP[i][j];
        }
    }
    for(int i=0;i<K;i++){
        cin>>command[i];
    }
    play();
}
