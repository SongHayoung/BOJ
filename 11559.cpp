#include <iostream>
#include <queue>
using namespace std;

char MAP[12][6];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

void down(){
    for(int j=0;j<6;j++){
        for(int i=10;i>=0;i--){ //
            if(MAP[i][j]!='.'){
                int k = i;
                bool flag = false;
                while(MAP[k+1][j]=='.'){
                    ++k;
                    flag = true;
                }
                if(flag) {
                    MAP[k][j] = MAP[i][j];
                    MAP[i][j] = '.';
                }
            }
        }
    }
}

bool play(){
    bool flag = false;
    bool visited[12][6] = {false, };
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            if(MAP[i][j]=='.'){
                visited[i][j]=true;
            }
            else{
                int cnt = 1;
                queue<pair<int, int>> q;
                queue<pair<int, int>> dq;
                q.push(make_pair(i,j));
                dq.push(make_pair(i,j));
                visited[i][j]=true;
                while(!q.empty()){
                    int x = q.front().second;
                    int y = q.front().first;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(0<=nx&&nx<6 && 0<=ny&&ny<12){
                            if(MAP[y][x]==MAP[ny][nx]&&!visited[ny][nx]){
                                ++cnt;
                                q.push(make_pair(ny,nx));
                                dq.push(make_pair(ny,nx));
                                visited[ny][nx] = true;
                            }
                        }
                    }
                }
                if(cnt>=4){
                    flag = true;
                    while(!dq.empty()){
                        int x = dq.front().second;
                        int y = dq.front().first;
                        dq.pop();
                        MAP[y][x] = '.';
                    }
                }
            }
        }
    }
    return flag;
}
int main(void){
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            cin>>MAP[i][j];
        }
    }
    int answer = 0;
    while(play()){
        ++answer;
        down();
    }
    cout<<answer<<endl;
}
