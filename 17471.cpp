#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <queue>

using namespace std;

#define MAXSIZE 11
int N, temp, picked=0, _index=0, popu=0;
int true_picked=0, false_picked=0;
int person[MAXSIZE];
int map[MAXSIZE][MAXSIZE];
bool choose[MAXSIZE];
vector<vector<int> > list;
int ans=987654321;

bool isPossible(vector<int> &list)
{
    if(list.size()==0)
        return false;
    int cnt = 1;
    queue<int> Q;
    Q.push(list.at(0));
    bool visited[MAXSIZE];
    memset(visited,false,sizeof(visited));
    for(int i=1;i<list.size();i++)
    {
        visited[list.at(i)]=true;
    }
    while(Q.empty()==0)
    {
        int x = Q.front();
        Q.pop();

        for(int i=1;i<=N;i++)
        {
            if(map[x][i]==1&&visited[i]==true)
            {
                cnt++;
                visited[i]=false;
                Q.push(i);
            }
        }
    }
    if(cnt==list.size())
        return true;
    return false;
}
void DFS(int idx)
{
    if(idx>N)
    {
        vector<int> true_list, false_list;
        for(int i=1;i<=N;i++)
        {
            if(choose[i])
                true_list.push_back(i);
            else
                false_list.push_back(i);
        }

        if(isPossible(true_list)&&isPossible(false_list))
        {
            list.push_back(vector<int>());
            for(int i=1;i<=N;i++)
                if(choose[i])
                    list.at(_index).push_back(i);
            
            _index++;
        }
        return ;
    }
    
    choose[idx]=true;
    picked++;
    DFS(idx+1);
    
    choose[idx]=false;
    picked--;
    DFS(idx+1);
    
    return ;
}

void calc()
{
    if(list.size()==0)
        cout<<"-1"<<endl;
    else
    {
        for(const auto& i : list){
            int total = 0;
            for(const auto& j : i)
            {
                total += person[j];
            }
            ans = min(ans,abs(popu-2*total));
        }
        cout<<ans<<endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>person[i];
        popu+=person[i];
    }
    
    memset(map,0,sizeof(map));
    
    for(int i=1;i<=N;i++)
    {
        int rep;
        cin>>rep;
        for(int j=0;j<rep;j++)
        {
            cin>>temp;
            map[i][temp]=1;
        }
    }
    DFS(1);
    calc();
}
