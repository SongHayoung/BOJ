#include <stdio.h>
#include <queue>
#include <map>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
const int target = 123456789;
int search(int p) {
	int ret = 8;
	while (p) {
		if (p % 10 == 9) return ret;
		p *= 0.1; --ret;
	}
	return ret;
}
int SWAP(int x, int y, int nx, int ny, int num) {
	int p[3][3];
	for (int i = 2; i >= 0; --i)
		for (int j = 2; j >= 0; --j)
			p[i][j] = num % 10, num *= 0.1;
	swap(p[y][x], p[ny][nx]);
	int ret = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			ret = ret * 10 + p[i][j];
	return ret;
}
int main(void) {
	int puzzle = 0, n;
	for (int i = 0; i < 9; ++i) {
		scanf("%d", &n);
		if (!n) n = 9;
		puzzle = puzzle * 10 + n;
	}
	if (puzzle == target) { printf("0"); return 0; }
	queue<int> q;
	map<int, int> m;
	q.push(puzzle);
	m.emplace(puzzle, 0);
	while (!q.empty()) {
		puzzle = q.front();
		q.pop();
		int pos = search(puzzle);
		int x = pos % 3;
		int y = pos / 3;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
				int newpuzzle = SWAP(x, y, nx, ny, puzzle);
				if (newpuzzle == target) {
					printf("%d", m[puzzle] + 1);
					return 0;
				}
				if (!m.count(newpuzzle)) {
					m[newpuzzle] = m[puzzle] + 1;
					q.push(newpuzzle);
				}
			}
		}
	}
	printf("-1");
	return 0;
}
