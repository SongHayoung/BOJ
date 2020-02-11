#include <iostream>
#include <memory.h>
#include <queue>
#include <map>
using namespace std;
int N,M;
map<int,int> m;
void BFS()
{
    m.insert(make_pair(N,0));
    queue<int> q;
    q.push(N);
    while(!q.empty())
    {
        if(m.find(M)!=m.end())
            break;

        int now = q.front();
        int t = m.find(now)->second;
        q.pop();
        int tel = now*2;
        int bef = now-1;
        int aft = now+1;

        if(m.find(tel)==m.end()&&tel<=100000&&tel>=0){
            q.push(tel);
            m.insert(make_pair(tel,t+1));
        }
        if(m.find(bef)==m.end()&&bef<=100000&&bef>=0){
            q.push(bef);
            m.insert(make_pair(bef,t+1));
        }
        if(m.find(aft)==m.end()&&aft<=100000&&aft>=0){
            q.push(aft);
            m.insert(make_pair(aft,t+1));
        }
    }
}

int main(void) {
    cin >> N >> M;
    BFS();
    cout<<m.find(M)->second<<endl;
}
