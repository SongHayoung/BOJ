#include <cstdio>
#include <queue>
#include <memory.h>

using namespace std;

class INFO {
public:
    int y, x, crush;
    
    INFO(int y, int x, int c) : y(y), x(x), crush(c) {}
};

int N;
char map[50][51];
int visit[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%s", map[i]);
    memset(visit, -1, sizeof(visit));
    visit[0][0] = 0;
    queue<INFO> q;
    q.emplace(0, 0, 0);
    while (!q.empty()) {
        INFO info = q.front();
        q.pop();
        if (visit[info.y][info.x] != info.crush) continue;
        for (int i = 0; i < 4; ++i) {
            int nx = info.x + dx[i];
            int ny = info.y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (map[ny][nx] == '1' && (visit[ny][nx] == -1 || visit[ny][nx] > info.crush))
                    q.emplace(ny, nx, visit[ny][nx] = info.crush);
                else if (map[ny][nx] == '0' && (visit[ny][nx] == -1 || visit[ny][nx] > info.crush + 1))
                    q.emplace(ny, nx, visit[ny][nx] = info.crush + 1);
            }
        }
    }
    printf("%d", visit[N - 1][N - 1]);
}
