#include <iostream>
#include <vector>
using namespace std;
int N;
long long answer = 0;

vector<vector<int>> rotate(vector<vector<int>> b) {
    vector<vector<int>> ret(N+1, vector<int>(N+1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ret[j][N - i - 1] = b[i][j];
        }
    }
    return ret;
}
void DFS(int depth, vector < vector <int>> board) {
    if (depth <= 5) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                answer = answer < board[i][j] ? board[i][j] : answer;
        if(depth==5)
            return;
    }
    vector<vector<int>> _board(N+1, vector<int>(N+1));
    vector<vector<int>> _board2(N+1, vector<int>(N+1));
    _board = board;
    for (int i = 0; i < 4; i++) {
        _board2 = _board;
        for (int j = 0; j < N; j++) {
            int zero_cnt = 0;
            for (int k = 0; k < _board2[j].size(); k++) {
                if (_board2[j][k] == 0) {
                    _board2[j].erase(_board2[j].begin() + k);
                    --k;   ++zero_cnt;
                }
            }
            for (int k = 0; k < zero_cnt; k++)
                _board2[j].push_back(0);
            for (int k = 0; k < _board2[j].size()-1; k++) {
                if (_board2[j][k] == _board2[j][k + 1]&&_board2[j][k]!=0) {
                    _board2[j][k] *= 2;
                    _board2[j].erase(_board2[j].begin() + k + 1);
                    _board2[j].push_back(0);
                }
            }
        }
        DFS(depth + 1, _board2);
        _board = rotate(_board);
    }
}

int main(void)
{
    cin >> N;
    vector<vector<int>> board(N+1, vector<int>(N+1));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    DFS(0, board);
    cout << answer << endl;
}
