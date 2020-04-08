#include <stdio.h>
#include <queue>
using namespace std;
int main(){
    bool visit[1001] = {false, };
    int jump[1001], N, i, j, c, size, time = 0;
    queue<int> q;
    scanf("%d",&N);
    for(i = 1; i <= N; ++i) scanf("%d",&jump[i]);
    visit[1] = true, q.push(1);
    for(;!q.empty()&&!visit[N];++time){
        size = q.size();
        for(i = 0; i < size; ++i){
            c = q.front();
            q.pop();
            for(j = c+1; j <= c+jump[c]; ++j)
                if(!visit[j]) visit[j] = true, q.push(j);
        }
    }
    visit[N] ? printf("%d",time) : printf("-1");
}
