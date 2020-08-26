#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int query, cmd, f, e;
vector<pair<int,int>> part;
void bfs(int f, int e) {
    bool v[100] = {false, };
    queue<int> q;
    q.push(f);
    v[f] = true;
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(int i = 0; i < part.size(); i++) {
            if(!v[i] && ((part[i].first < part[p].first && part[p].first < part[i].second) || (part[i].first < part[p].second && part[p].second < part[i].second))) {
                v[i] = true;
                q.push(i);
                if(i == e) { printf("1\n"); return ; }
            }
        }
    }
    printf("0\n");
    return;
}
int main(void) {
    scanf("%d", &query);
    for(int i = 0; i < query; i++) {
        scanf("%d %d %d", &cmd, &f, &e);
        switch (cmd) {
            case 1: part.push_back(make_pair(f, e)); break;
            case 2: bfs(f-1, e-1); break;
        }
    }
}
