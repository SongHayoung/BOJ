#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <queue>
using namespace std;
int N, tc;
bool visit[102];
int dist[102][2];
bool reachable(int c, int d){
    return abs(dist[c][0]-dist[d][0]) + abs(dist[c][1]-dist[d][1]) <= 1000;
}
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&N);
        memset(visit,false,sizeof(visit));
        for(int i = 0; i < N+2; ++i)
            scanf("%d %d",&dist[i][0],&dist[i][1]);
        queue<int> q;
        q.push(0);
        visit[0] = true;
        while(!q.empty()&&!visit[N+1]){
            int c = q.front();
            q.pop();
            for(int i = 1; i < N+2; ++i){
                if(visit[i]) continue;
                if(reachable(c,i)){
                    q.push(i);
                    visit[i] = true;
                }
            }
        }
        visit[N+1] ? printf("happy\n") : printf("sad\n");
    }
}
