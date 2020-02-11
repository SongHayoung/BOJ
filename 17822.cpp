#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int N,M,T;
vector<int> circles[50];
int cmd[50][3];
bool visit[50][50];
int xi, di, ki;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool flag;
long long ans = 0;


void rotate(int x, int d, int k){
    for(int i=0;i<N;i++){
        if((i+1)%x!=0)
            continue;

        if(d==0){
            for(int j=0;j<k;j++){
                int num = circles[i][M-1];
                circles[i].erase(circles[i].end()-1);
                circles[i].insert(circles[i].begin(),num);
            }
        }
        else{
            for(int j=0;j<k;j++){
                int num = circles[i][0];
                circles[i].erase(circles[i].begin());
                circles[i].push_back(num);
            }
        }
    }

}

void removeOrReplace(){
    memset(visit,false,sizeof(visit));

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visit[i][j])
                continue;
            visit[i][j] = true;
            if(circles[i][j]==0)
                continue;
            queue<pair<int,int>> q;
            q.push(make_pair(i,j));
            int num = circles[i][j];
            while(!q.empty()){
                int cur_x = q.front().second;
                int cur_y = q.front().first;
                q.pop();
                for(int k=0;k<4;k++){
                    int near_x = cur_x+dx[k];
                    int near_y = cur_y+dy[k];
                    if(near_x==M)
                        near_x = 0;
                    if(near_x==-1)
                        near_x = M-1;
                    if(0<=near_x && near_x<M && 0<=near_y && near_y<N){

                        if(circles[near_y][near_x]==num && !visit[near_y][near_x]){
                            flag = false;
                            circles[i][j] = 0;
                            circles[near_y][near_x]=0;
                            visit[near_y][near_x]=true;
                            q.push(make_pair(near_y,near_x));
                        }
                    }
                 }
            }
        }
    }
}

void caculate_avg(){
    long double num = 0;
    double cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(circles[i][j]!=0){
                cnt+=1;
                num+=(double)circles[i][j];
            }
        }
    }
    if(cnt==0)
        return ;

    long double avg = num/cnt;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(circles[i][j]!=0){
                if((double)circles[i][j]>avg){
                    circles[i][j]-=1;
                }
                else if((double)circles[i][j]<avg){
                    circles[i][j]+=1;
                }
            }
        }
    }
}

int main(void){
    cin>>N>>M>>T;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int num;
            cin>>num;
            circles[i].push_back(num);
        }
    }

    //print_circle();
    for(int i=0;i<T;i++){
        cin>>xi>>di>>ki;
        rotate(xi,di,ki);
        flag = true;
        removeOrReplace();
        if(flag){
            caculate_avg();
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            ans += circles[i][j];
        }
    }
    cout<<ans<<endl;
}
