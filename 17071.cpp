#include <cstdio>
#include <queue>
using namespace std;
#define MAX 500000
int N, K, t;
int BFS(){
    bool v[MAX+1][2]={false,};
    queue<int> q;
    q.emplace(N);
    v[N][0] = true;
    for(t=1;K+t<=MAX;++t){
        K+=t;
        int size = q.size();
        for(int i = 0; i < size; ++i){
            int n = q.front();
            q.pop();
            if(n&&!v[n-1][t&1]) v[n-1][t&1] = true, q.emplace(n-1);
            if(n!=MAX&&!v[n+1][t&1]) v[n+1][t&1] = true, q.emplace(n+1);
            if(n*2<=MAX&&!v[n*2][t&1]) v[n*2][t&1] = true, q.emplace(n*2);
        }
        if(v[K][t&1]) return t;
    }
    return -1;
}
int main(){
    scanf("%d %d",&N, &K);
    printf("%d",N==K?0:BFS());
}
