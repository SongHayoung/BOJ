#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;

int N,M;
int map[50][50];
int map_cpy[50][50];
bool visit[50][50];
int ans = 987654321;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
bool choice[2501];
vector<pair<int,int>> virus;
queue<pair<int,int>> q;

void BFS(){
    int sec = 0;
    while(!q.empty()){
        int cur_x = q.front().second;
        int cur_y = q.front().first;
        q.pop();
        int time = map_cpy[cur_y][cur_x]+1;
        for(int i=0;i<4;i++){
            int near_y = cur_y+dy[i];
            int near_x = cur_x+dx[i];
            if(0<=near_x && near_x<N && 0<=near_y && near_y<N){
                if(map_cpy[near_y][near_x]==0&&!visit[near_y][near_x]){
                    map_cpy[near_y][near_x] = time;
                    sec = max(sec,time);
                    visit[near_y][near_x] = true;
                    q.push(make_pair(near_y,near_x));
                }
                else if(map_cpy[near_y][near_x]==2&&!visit[near_y][near_x]){
                    map_cpy[near_y][near_x] = time;
                    visit[near_y][near_x] = true;
                    q.push(make_pair(near_y,near_x));
                }
            }
        }
    }

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) {
            if (map_cpy[i][j]==0)
                return ;
        }
    ans = min(ans,sec-2);
}

void choose_virus(int choosed, int cur){
    if(choosed == M){
        memcpy(map_cpy,map,sizeof(map_cpy));
        memset(visit,false,sizeof(visit));
        queue<pair<int,int>> temp;
        swap(temp,q);
        for(int i=0;i<virus.size();i++){
            if(choice[i]){
                q.push(make_pair(virus[i].first,virus[i].second));
                visit[virus[i].first][virus[i].second] = true;
            }
        }
        BFS();
        return ;
    }
    for(int i=cur;i<virus.size();i++){
        choice[i] = true;
        choose_virus(choosed+1,i+1);
        choice[i]=false;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    bool flag = true;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            cin>>map[i][j];
            if(map[i][j]==2)
                virus.push_back(make_pair(i,j));
            if(map[i][j]==0)
                flag = false;
        }
    if(flag){
        cout<<"0"<<endl;
        return 0;
    }
    choose_virus(0,0);
    if(ans<87654321)
        cout<<ans<<endl;
    else
        cout<<"-1"<<endl;
}
