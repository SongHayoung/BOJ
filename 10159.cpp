#include <stdio.h>
#include <memory.h>
#include <vector>
using namespace std;
int N, M, f, b;
bool visit[101][2];
vector<int> v[101];
vector<int> v2[101];
int DFS(int n) {
    if (visit[n][0]) return 0;
    visit[n][0] = true;
    int cnt = 0;
    for (int i = 0; i < v[n].size(); ++i)
        cnt += DFS(v[n][i]);
    return cnt+1;
}
int DFS2(int n) {
    if (visit[n][1])  return 0;
    visit[n][1] = true;
    int cnt = 0;
    for (int i = 0; i < v2[n].size(); ++i)
        cnt += DFS2(v2[n][i]);
    return cnt+1;
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &f, &b);
        v[f].push_back(b);
        v2[b].push_back(f);
    }
    for (int i = 1; i <= N; ++i) {
        memset(visit,false,sizeof(visit));
        printf("%d\n",N+1-DFS(i)-DFS2(i));
    }
}
