#include<iostream>
#include <math.h>
using namespace std;
char MAP[20][20];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int R,C;
bool visit[26] = {false, };
int DFS(int x,int y){
    int ret = 1;
    for(int i=0;i<4;i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(0<=next_x&&next_x<C&&0<=next_y&&next_y<R){
            if(!visit[MAP[next_y][next_x]-'A']){
                visit[MAP[next_y][next_x]-'A'] = true;
                ret = max(ret,DFS(next_x,next_y)+1);
                visit[MAP[next_y][next_x]-'A']=false;
            }
        }
    }
    return ret;
}
int main(void)
{
    cin>>R>>C;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            cin>>MAP[i][j];
    visit[MAP[0][0]-'A']=true;
    cout<<DFS(0,0)<<endl;
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
