#include <vector>
#include <iostream>
#include <queue>
using namespace std;
void solution(){
    int v,e,from,to,cur;
    cin>>v>>e;
    vector<vector<int>> Edges(v+1,vector<int>());
    int groups[20001] = {0, };
    for(int i=0;i<e;i++){
        cin>>from>>to;
        Edges[from].push_back(to);
        Edges[to].push_back(from);
    }
    queue<int> q;
    for(int i=1;i<=v;i++){
        if(groups[i]!=0)
            continue;
        q.push(i);
        groups[i]=1;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            for(int j=0;j<Edges[cur].size();j++){
                if(groups[Edges[cur][j]]==0){
                    groups[Edges[cur][j]] = groups[cur] == 1?2:1;
                    q.push(Edges[cur][j]);
                }
                else if(groups[Edges[cur][j]]==groups[cur]){
                    cout<<"NO"<<endl;
                    return ;
                }
            }
        }
    }
    cout<<"YES"<<endl;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int TC;
    cin>>TC;
    for(int i=0;i<TC;i++){
        solution();
    }
}
