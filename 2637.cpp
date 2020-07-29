#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<vector<pair<int, int>>> vec(101);
int memo[101][101];
bool tool[101];
bool visited[101];
void f(int idx, int mul) {
    if(visited[idx]) return;
    visited[idx] = true;
    if(!tool[idx]){
        memo[idx][idx] = 1;
        return;
    }
    for(pair<int,int> p : vec[idx]) {
        f(p.first, mul * p.second);
        for(int i = 1; i <= N; ++i)
            memo[idx][i] += memo[p.first][i] * p.second;
    }
    return;
}
int main() {
    scanf("%d %d",&N, &M);
    for(int i = 0; i < M; ++i){
        int x, y, z;
        scanf("%d %d %d",&x, &y, &z);
        vec[x].emplace_back(make_pair(y,z));
        tool[x] = true;
    }
    f(N, 1);
    for(int i = 1; i <= N; ++i)
        if(memo[N][i])
            printf("%d %d\n",i,memo[N][i]);
}
