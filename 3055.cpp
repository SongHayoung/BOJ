#include <iostream>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;
int R, C;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int gx, gy;
char MAP[50][50];

void printMAP(){
    for(int i=0;i<C;i++){
        for(int j=0;j<R;j++){
            cout<<MAP[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

queue<pair<int,int>> BFS(queue<pair<int,int>> q){
    queue<pair<int,int>> nq;
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx&&nx<R && 0<=ny&&ny<C){
                if(MAP[ny][nx]=='.'||MAP[ny][nx]=='S'){
                    MAP[ny][nx]='*';
                    nq.push(make_pair(ny,nx));
                }
            }
        }
    }
    return nq;
}
queue<pair<int,int>> dBFS(queue<pair<int,int>> q){
    queue<pair<int,int>> nq;
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx&&nx<R && 0<=ny&&ny<C){
                if(MAP[ny][nx]=='.'||MAP[ny][nx]=='D'){
                    MAP[ny][nx]='S';
                    nq.push(make_pair(ny,nx));
                }
            }
        }
    }
    return nq;
}
int main(void){
    cin>>C>>R;
    int x, y;
    queue<pair<int,int>> q;
    queue<pair<int,int>> dq;
    for(int i=0;i<C;i++)
        for(int j=0;j<R;j++){
            cin>>MAP[i][j];
            if(MAP[i][j]=='S') {
                dq.push(make_pair(i,j));
            }
            else if(MAP[i][j]=='D'){
                gx = j; gy = i;
            }
            else if(MAP[i][j]=='*'){
                q.push(make_pair(i,j));
            }
        }
    int answer = 1;
    while(!dq.empty()){
        q=BFS(q);
        dq=dBFS(dq);
        if(MAP[gy][gx]=='S'){
            cout<<answer<<endl;
            return 0;
        }
        ++answer;
    }

    cout<<"KAKTUS"<<endl;
}
