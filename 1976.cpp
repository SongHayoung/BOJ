#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, tmp;
queue<pair<int,int>> q;
int gr[200];
int getG(int n) {
    return gr[n] == n ? n : gr[n] = getG(gr[n]);
}
void makeG(int f, int e) {
    gr[getG(f)] = gr[getG(e)] = min(getG(e),getG(f));
}
int main() {
    scanf("%d %d",&n, &m);
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &tmp);
            if (tmp)
                q.push({i, j});
        }
        gr[i] = i;
    }
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        makeG(p.first,p.second);
    }
    int prev, cur;
    scanf("%d",&prev);
    for(int i = 1; i < m; i++) {
        scanf("%d", &cur);
        if(gr[prev-1] != gr[cur-1]){
            printf("NO");
            exit(0);
        }
        prev = cur;
    }
    printf("YES");
}
