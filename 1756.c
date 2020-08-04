#include <stdio.h>
int d, n, num, ans;
int o[300001];
int main(void) {
    o[0] = 987654321;
    scanf("%d %d", &d, &n);
    ans = d;
    for(int i = 1; i <= d; ++i) {
        scanf("%d", &num);
        o[i] = o[i - 1] < num ? o[i - 1] : num;
    }
    ans = d + 1;
    for(int i = 0; i < n; ++i) {
        if(!ans) break;
        scanf("%d", &num);
        for(--ans; ans > 0; --ans)
            if(o[ans] >= num) break;
    }
    printf("%d",ans);
}