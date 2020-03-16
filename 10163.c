#include <stdio.h>
int p[102][102];
int a[101];
int main(int argc, char** argv) {
	int N, answer = 0, x, y, dx, dy;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d %d", &y, &x, &dy, &dx);
		for (int _x = x; _x < x + dx; _x++)
			for (int _y = y; _y < y + dy; _y++)
				p[_y][_x] = i;
	}
	for (int i = 0; i <= 101; i++)
		for (int j = 0; j <= 101; j++)
			a[p[i][j]]++;
	for (int i = 1; i <= N; i++)
		printf("%d\n", a[i]);
}
