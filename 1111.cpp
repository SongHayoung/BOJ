#include <stdio.h>
#include <queue>
using namespace std;
int main(int argc, char** argv) {
	int N, arr[50], tc;
	bool flag = true;
	scanf("%d", &N);
	scanf("%d", &arr[0]);
	for (tc = 1; tc < N; tc++) {
		scanf("%d", &arr[tc]);
		if (arr[tc] != arr[tc - 1])
			flag = false;
	}
	if (N == 1) printf("A");
	else if (flag) printf("%d", arr[0]);
	else if (N == 2) printf("A");
	else {
		queue<pair<int, int>> q;
		for (int i = -500; i <= 500; i++) {
			q.push(make_pair(i, arr[1] - i * arr[0]));
		}
		for (int i = 1; i < N - 1; i++) {
			int size = q.size();
			for (int j = 0; j < size; j++) {
				int a = q.front().first;
				int b = q.front().second;
				q.pop();
				if (arr[i] * a + b == arr[i + 1])
					q.push(make_pair(a, b));
			}
		}
		switch (q.size()) {
		case 0: printf("B"); break;
		case 1: printf("%d", arr[N - 1] * q.front().first + q.front().second); break;
		default: printf("A");
		}
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
