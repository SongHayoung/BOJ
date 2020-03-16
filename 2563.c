#include <stdio.h>
int p[100][100];
int main(int argc, char** argv) {
	int N, answer = 0, x, y;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		for (int _x = x; _x < x + 10; _x++)
			for (int _y = y; _y < y + 10; _y++)
				p[_y][_x] = 1;
	}
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (p[i][j]) ++answer;
	printf("%d", answer);
}
