#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
char buf[5][10];
int use[14];
vector<pair<int, int>> lines[6];
vector<pair<int, int>> pos;

void initilize_info() {
    lines[0].emplace_back(0, 4);lines[0].emplace_back(1, 3);lines[0].emplace_back(2, 2);lines[0].emplace_back(3, 1);
    lines[1].emplace_back(0, 4);lines[1].emplace_back(1, 5);lines[1].emplace_back(2, 6);lines[1].emplace_back(3, 7);
    lines[2].emplace_back(1, 1);lines[2].emplace_back(1, 3);lines[2].emplace_back(1, 5);lines[2].emplace_back(1, 7);
    lines[3].emplace_back(3, 1);lines[3].emplace_back(3, 3);lines[3].emplace_back(3, 5);lines[3].emplace_back(3, 7);
    lines[4].emplace_back(4, 4);lines[4].emplace_back(3, 3);lines[4].emplace_back(2, 2);lines[4].emplace_back(1, 1);
    lines[5].emplace_back(4, 4);lines[5].emplace_back(3, 5);lines[5].emplace_back(2, 6);lines[5].emplace_back(1, 7);
    
    pos.emplace_back(0, 4);
    pos.emplace_back(1, 1);
    pos.emplace_back(1, 3);
    pos.emplace_back(1, 5);
    pos.emplace_back(1, 7);
    pos.emplace_back(2, 2);
    pos.emplace_back(2, 6);
    pos.emplace_back(3, 1);
    pos.emplace_back(3, 3);
    pos.emplace_back(3, 5);
    pos.emplace_back(3, 7);
    pos.emplace_back(4, 4);
}

bool validation(pair<int, int> p) {
    for (int i = 0; i < 6; ++i) {
        bool find = false;
        for (int j = 0; j < 4; ++j)
            if (lines[i][j].first == p.first && lines[i][j].second == p.second)
                find = true;
        if (!find) continue;
        int cnt = 0;
        int num = 0;
        for (int j = 0; j < 4; ++j) {
            if (buf[lines[i][j].first][lines[i][j].second] != 'x')
                ++cnt; num += buf[lines[i][j].first][lines[i][j].second] - 'A' + 1;
        }
        if (cnt == 4 && num != 26)
            return false;
    }
    return true;
}

void init() {
    bool fixed;
    do {
        fixed = false;
        for (int i = 0; i < 6; ++i) {
            int cnt = 0;
            int num = 26;
            for (int j = 0; j < 4; ++j)
                if (buf[lines[i][j].first][lines[i][j].second] != 'x')
                    ++cnt, num -= (buf[lines[i][j].first][lines[i][j].second] - 'A' + 1);
            if (cnt != 3) continue;
            fixed = true;
            for (int j = 0; j < 4; ++j)
                if (buf[lines[i][j].first][lines[i][j].second] == 'x') {
                    buf[lines[i][j].first][lines[i][j].second] = num + 'A' - 1;
                    use[num] = 1;
                }
        }
    } while (fixed);
}
void pM(){
    for(int i = 0; i < 5; ++i)
        printf("%s\n",buf[i]);
}
void DFS(int _pos) {
    if (_pos == 12) {
        pM();
        exit(0);
    }
    if (buf[pos[_pos].first][pos[_pos].second] != 'x') DFS(_pos + 1);
    else {
        for (int i = 1; i <= 12; ++i) {
            if (use[i]) continue;
            use[i] = 1;
            buf[pos[_pos].first][pos[_pos].second] = i - 1 + 'A';
            if (validation(pos[_pos]))
                DFS(_pos + 1);
            buf[pos[_pos].first][pos[_pos].second] = 'x';
            use[i] = 0;
        }
    }
}
int main() {
    for (int i = 0; i < 5; ++i) {
        scanf("%s", buf[i]);
        for (int j = 0; j < 9; ++j)
            if ('A' <= buf[i][j] && buf[i][j] <= 'L')
                use[buf[i][j] - 'A' + 1] = 1;
    }
    initilize_info();
    init();
    DFS(0);
}
