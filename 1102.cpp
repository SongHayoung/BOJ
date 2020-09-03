#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>>
using namespace std;
int cost[16][16];
int visit[1<<17];
int ans = 987654321, n, p, cnt;
bool status[16];
char str[17];
struct gen{
    int cost, v, cur;
};
bool operator<(gen a, gen b){
    return a.cost > b.cost;
}
int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d",&cost[i][j]);
    scanf("%s",str);
    scanf("%d",&p);
    int start = 0;
    for(int i = 0; i < n; i++)
        if(str[i]=='Y') {
            status[i] = true;
            cnt++;
            start |= (1<<i);
        }
    if(cnt >= p){
        printf("0");
        exit(0);
    }
    for(int i = 0; i < 1<<(n+1); i++)
        visit[i] = 987654321;
    priority_queue<gen> pq;
    visit[start] = 1;
    pq.push(gen{.cost = 0, .v = start, .cur = cnt});
    while(!pq.empty()) {
        gen g = pq.top();
        pq.pop();
        if(visit[g.v] < g.cost) continue;
        if(g.cost >= ans) continue;
        for(int i = 0; i < n; i++) {
            if(!(g.v&(1<<i))) {
                int minVal = 987654321;
                for (int j = 0; j < n; j++) {
                    if(g.v&(1<<j))
                        minVal = min(minVal, cost[j][i]);
                }
                if(g.cur+1 == p) {
                    ans = min(ans, g.cost + minVal);
                } else if(g.cost + minVal < ans && visit[g.v | (1<<i)] > g.cost + minVal) {
                    visit[g.v | (1<<i)] = g.cost + minVal;
                    pq.push(gen{.cost = g.cost + minVal, .v = g.v | (1 << i), .cur = g.cur + 1});
                }
            }
        }
    }
    printf("%d",ans != 987654321 ? ans:-1);
}
