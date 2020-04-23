#include <cstdio>
#include <queue>
#include <string>
#define Sh short
using namespace std;
inline Sh D(Sh n){ return (n<<1)%10000; }
inline Sh S(Sh n){ return n ? n-1 : 9999; }
inline Sh L(Sh n){ return (n*10+n/1000)%10000; }
inline Sh R(Sh n){ return n/10 + (n%10)*1000; }
void BFS(){
    Sh start, target, num, nextnum;
    bool visit[10000] = {false};
    string s;
    scanf("%d %d",&start,&target);
    if(start==target){ printf("\n"); return; }
    queue<pair<Sh,string>> q;
    q.emplace(start,"");
    visit[start] = true;
    while(!q.empty()){
        num = q.front().first;
        s = q.front().second;
        q.pop();
        if(!visit[nextnum = D(num)]){
            if(nextnum==target){ printf("%sD\n",s.c_str()); return ; }
            visit[nextnum] = true;
            q.emplace(nextnum,s+"D");
        }
        if(!visit[nextnum = S(num)]){
            if(nextnum==target){ printf("%sS\n",s.c_str()); return ; }
            visit[nextnum] = true;
            q.emplace(nextnum,s+"S");
        }
        if(!visit[nextnum = L(num)]){
            if(nextnum==target){ printf("%sL\n",s.c_str()); return ; }
            visit[nextnum] = true;
            q.emplace(nextnum,s+"L");
        }
        if(!visit[nextnum = R(num)]) {
            if(nextnum==target){ printf("%sR\n",s.c_str()); return ; }
            visit[nextnum] = true;
            q.emplace(nextnum,s+"R");
        }
    }
}
int main() {
    int tc;
    scanf("%d",&tc);
    while(tc--) BFS();
}
