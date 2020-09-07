#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
struct rb {
    int y, x;
};
bool operator<(rb a, rb b) {
    return a.y == b.y ? a.x > b.x : a.y > b.y;
}
int dx[10] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[10] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
char map[100][101];
string str;
int n, m, y, x;
priority_queue<rb> pq;
queue<rb> q;
int main() {
    scanf("%d %d",&n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%s", map[i]);
        for(int j = 0; j < m; j++) {
            switch (map[i][j]) {
                case 'R':
                    map[i][j] = '.';
                    q.push(rb{.y = i, .x = j});
                    break;
                case 'I':
                    y = i;
                    x = j;
                    map[i][j] = '.';
            }
        }
    }
    cin>>str;
    for(int i = 0; i < str.length(); i++) {
        y = y + dy[str[i]&0b1111];
        x = x + dx[str[i]&0b1111];
        while(!q.empty()) {
            rb r = q.front();
            q.pop();
            if(r.y == y && r.x == x) {
                printf("kraj %d",i+1);
                exit(0);
            }
            int minVal = 987654321;
            int nPos;
            for(int i = 1; i <= 9; i++) {
                int dist = abs(r.y + dy[i] - y) + abs(r.x + dx[i] - x);
                if(dist < minVal) {
                    minVal = dist;
                    nPos = i;
                }
            }
            pq.push(rb{.y = r.y + dy[nPos], .x = r.x + dx[nPos]});
        }
        rb prev{-1, -1};
        bool flag = false;
        while(!pq.empty()) {
            rb r = pq.top();
            if(r.y == y && r.x == x) {
                printf("kraj %d",i+1);
                exit(0);
            }
            pq.pop();
            if(!(r.y == prev.y && r.x == prev.x)) {
                if(flag) 
                    q.push(prev);
                prev = r;
                flag = true;
            } else 
                flag = false;
            if(pq.empty() && flag) 
                q.push(r);
        }
    }
    map[y][x] = 'I';
    while(!q.empty()) {
        rb r = q.front();
        q.pop();
        map[r.y][r.x] = 'R';
    }
    for(int i = 0; i < n; i++)
        printf("%s\n",map[i]);
}
