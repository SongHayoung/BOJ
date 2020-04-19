#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#define INF 987654321
using namespace std;
int map[100][100];
int N, M, A, B, y, x;
vector<pair<int,int>> items;
bool compare(pair<int,int> p1, pair<int,int> p2){
    return p1.first==p2.first ? p1.second<p2.second : p1.first<p2.first;
}
int DFS(pair<int,int> cur, pair<int,int> &dst){
    if(map[cur.first][cur.second]==INF||cur.first>dst.first || cur.second>dst.second) return 0;
    if(map[cur.first][cur.second]!=-1||cur==dst) return map[cur.first][cur.second];
    map[cur.first][cur.second] = 0;
    if(cur.first+1<N) map[cur.first][cur.second] += DFS(make_pair(cur.first+1,cur.second),dst);
    if(cur.second+1<M) map[cur.first][cur.second] += DFS(make_pair(cur.first,cur.second+1),dst);
    return map[cur.first][cur.second];
}
int main() {
    register int i;
    memset(map,-1,sizeof(map));
    scanf("%d %d %d %d",&N,&M,&A,&B);
    for(i = 0; i < A; ++i){
        scanf("%d %d",&y,&x);
        items.emplace_back(y-1,x-1);
    }
    for(i = 0; i < B; ++i){
        scanf("%d %d",&y,&x);
        map[y-1][x-1] = INF;
    }
    items.emplace_back(0,0);
    items.emplace_back(N-1,M-1);
    map[N-1][M-1] = 1;
    sort(items.begin(),items.end(),compare);
    for(i = items.size()-2; i >= 0; --i) DFS(items[i],items[i+1]);
    printf("%d",map[0][0]);
}
