#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;

int map[1001][1001];
bool visit[1001];
int N,M,V;
vector<int> BFS_ans;
vector<int> DFS_ans;
queue<int> q;
void DFS(int v)
{
    if(visit[v])
        return;
    DFS_ans.push_back(v);
    visit[v]=true;
    for(int i=1;i<=N;i++)
    {
        if(map[v][i]!=-1)
            DFS(i);
    }
}
void BFS(int v)
{
    if(visit[v])
        return;
    BFS_ans.push_back(v);
    visit[v]=true;
    for(int i=1;i<=N;i++)
    {
        if(map[v][i]!=-1&&!visit[i])
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int tq = q.front();
        q.pop();
        BFS(tq);
    }
}

int main(void)
{
    memset(map,-1,sizeof(map));
    cin>>N>>M>>V;
    for(int i=0;i<M;i++)
    {
        int n,m;
        cin>>n>>m;
        map[n][m]=1;
        map[m][n]=1;
    }
    memset(visit,false,sizeof(visit));
    DFS(V);
    memset(visit,false,sizeof(visit));
    q.push(V);
    BFS(V);
    for(int i=0;i<DFS_ans.size();i++)
        cout<<DFS_ans[i]<<" ";
    cout<<endl;
    for(int i=0;i<BFS_ans.size();i++)
        cout<<BFS_ans[i]<<" ";
}
