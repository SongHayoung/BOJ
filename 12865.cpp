#include <stdio.h>
#include <vector>
using namespace std;

int main(void) {
    int N, M;
    vector<int> DP(100001,0);
    int V[101];
    int C[101];
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
        scanf("%d %d",&V[i],&C[i]);
    }
    for(int i = 1; i<= N;i++){
        for(int j = M; j >= V[i]; j--){
            DP[j] = DP[j-V[i]] + C[i] > DP[j] ?  DP[j-V[i]] + C[i] : DP[j];
        }
    }
    printf("%d\n",DP[M]);
    return 0;
}
