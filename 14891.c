#include <stdio.h>
char to[4][9];
void move(int cur, int ds, int d) {
	if (!ds) {
		if (cur&&to[cur][6] != to[cur - 1][2])
				move(cur - 1, -1, d*-1);
		if (cur != 3 && to[cur][2] != to[cur + 1][6])
				move(cur + 1, 1, d*-1);
	}
	else if (ds==1&&cur!=3&&to[cur][2] != to[cur + 1][6])
				move(cur + 1, 1, d*-1);
	else if(ds==-1&&cur&&to[cur][6] != to[cur - 1][2])
				move(cur - 1, -1, d*-1);
	if (d==-1) {
		char t = to[cur][0];
		for (int i = 0; i < 7; ++i)
			to[cur][i] = to[cur][i + 1];
		to[cur][7] = t;
	}
	else {
		char t = to[cur][7];
		for (int i = 7; i > 0; --i)
			to[cur][i] = to[cur][i - 1];
		to[cur][0] = t;
	}
}
int main() {
	int N, num, dir;
	scanf("%s", to[0]);
	scanf("%s", to[1]);
	scanf("%s", to[2]);
	scanf("%s", to[3]);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d %d", &num, &dir);
		move(num - 1, 0, dir);
	}
	printf("%d", (to[0][0] & 0b1111) + ((to[1][0] & 0b1111) << 1) + ((to[2][0] & 0b1111) << 2) + ((to[3][0] & 0b1111) << 3));
}
