#include <stdio.h>
#include <string.h>
#include <math.h>
char I[100][26],l[100],b[11],N,a,i,j,d,f;
main() {
	scanf("%d",&N);
	for (i = 0; i < N; ++i) {
		scanf("%s", b);
		l[i] = strlen(b);
		for (j = 0; j < l[i]; ++j)
			++I[i][b[j]-'A'];
	}
	for (j = 1; j < N; ++j) {
		if (abs(l[0] - l[j]) >= 2) continue;
		d = f = 0;
		for (i = 0; i < 26; ++i) {
			d += abs(I[0][i]-I[j][i]);
			if(I[0][i]!=I[j][i])++f;
		}
		if(d<=2&&f<=2)++a;
	}
	printf("%d", a);
}
