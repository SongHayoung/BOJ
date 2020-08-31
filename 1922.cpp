#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int com[1001],n,m, ans;
struct conn{
    int f, e, c;
};
bool operator<(conn a, conn b){
    return a.c > b.c;
}
priority_queue<conn> pq;
int getG(int a) {
    return a == com[a] ? a : com[a] = getG(com[a]);
}

void makeG(conn con) {
    int ga = getG(con.f);
    int gb = getG(con.e);
    if(ga == gb) return;
    ans += con.c;
    com[ga] = com[gb] = min(ga, gb);
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; ++i)
        com[i] = i;
    for(int i = 0; i < m; ++i) {
        conn con;
        scanf("%d %d %d",&con.f, &con.e, &con.c);
        pq.push(con);
    }
    while(!pq.empty()) {
        makeG(pq.top());
        pq.pop();
    }
    printf("%d",ans);
}
