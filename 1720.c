#include <stdio.h>
long tiles[31] = {1, 1};
int N;
int main() {
    for(int i = 2; i <= 30; ++i)
        tiles[i] = tiles[i-1] + (tiles[i-2]<<1);
    scanf("%d",&N);
    printf("%ld",N&1 ? (tiles[N]+tiles[N>>1])>>1 : (tiles[N]+tiles[N>>1]+(tiles[(N>>1)-1]<<1))>>1);
    
}
