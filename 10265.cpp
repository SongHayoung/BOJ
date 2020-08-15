#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, K, g = 1;
int gf[1001];
bool visit[1001][2];
int dist[1001];
int gp[1001];
int info[1001][2];
int dp[1001][1001];
void dfs(int n) {
    if(!visit[n][0]) {
        visit[n][0] = true;
        dfs(gf[n]);
    }
    else if(!visit[n][1] && !dist[n]) {
        visit[n][1] = true;
        queue<int> q;
        q.push(gf[n]);
        int cycle = 1;
        while(q.front() != n) {
            ++cycle;
            visit[q.front()][1] = true;
            q.push(gf[q.front()]);
            q.pop();
        }
        dist[n] = cycle;
        gp[n] = g;
        while(!q.empty())
            q.pop();
        q.push(gf[n]);
        while(q.front() != n) {
            dist[q.front()] = cycle;
            gp[q.front()] = g;
            q.push(gf[q.front()]);
            q.pop();
        }
        g++;
    }
    if(dist[n] == 0) {
        dist[n] = dist[gf[n]] + 1;
        gp[n] = gp[gf[n]];
    }
}

int main(void) {
    scanf("%d %d",&N, &K);
    for(int i = 1; i <= N; ++i)
        scanf("%d",&gf[i]);
    for(int i = 1; i <= N; ++i)
        if(!visit[i][0]) {
            dfs(i);
        }
    for(int i = 1; i <= N; ++i)
        info[gp[i]][1]++;
    for(int i = 1; i <= N; ++i){
        if(info[gp[i]][0] == 0)
            info[gp[i]][0] = dist[i];
        info[gp[i]][0] = min(info[gp[i]][0], dist[i]);
    }
    dp[0][0] = true;
    for(int i = 1; i < g; ++i)
        for(int j = info[i][0]; j <= info[i][1]; ++j) {
            for (int k = 0; k <= K - j; ++k)
                if (dp[i - 1][k])
                    dp[i][k + j] = true;

            for (int k = 0; k <= K; ++k)
                if(dp[i - 1][k]) dp[i][k] = true;
        }
    for(int i = K; i >= 0; --i)
        if(dp[g - 1][i]) {
            printf("%d",i);
            exit(0);
        }
}
