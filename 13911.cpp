#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class info{
public:
    int pos;
    int cost;
    info(int p, int c) : pos(p), cost(c) {}
};
bool operator<(info a, info b){
    return a.cost==b.cost ? a.pos<b.pos : a.cost>b.cost;
}
vector<map<int,int>> graph(10001,map<int,int> ());
int ans[10001][2];
int V, E;
int s, e, cost, ret=987654321;
void BFS(int idx){
    int maxlen, nums, pos, cost;
    priority_queue<info> q;
    bool visit[10001] = {false,};
    scanf("%d %d",&nums,&maxlen);
    for(int i = 0; i < nums; ++i){
        scanf("%d",&pos);
        q.emplace(pos,0);
    }
    while(!q.empty()){
        pos = q.top().pos;
        cost = q.top().cost;
        q.pop();
        if(visit[pos]) continue;
        visit[pos] = true;
        ans[pos][idx] = cost;
        for(auto it : graph[pos]){
            if(visit[it.first]) continue;
            if(cost+it.second>maxlen) continue;
            q.emplace(it.first,cost+it.second);
        }
    }
}
int main(){
    scanf("%d %d",&V, &E);
    for(int i = 0; i < E; ++i){
        scanf("%d %d %d",&s, &e, &cost);
        if(!graph[s][e]) graph[s][e] = graph[e][s] = cost;
        else graph[s][e] = graph[e][s] = min(graph[s][e],cost);
    }
    BFS(0);
    BFS(1);
    for(int i = 1; i <= V; ++i){
        if(!ans[i][0]||!ans[i][1]) continue;
        ret = min(ret,ans[i][0]+ans[i][1]);
    }
    printf("%d",ret==987654321?-1:ret);
}
