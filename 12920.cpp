#include <stdio.h>
#include <vector>
using namespace std;

int main(void) {
    int N, M;
    int DP[10001] = {0, };
    vector<int> V;
    vector<int> C;
    int _V, _C, _K, multi;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
        scanf("%d %d %d",&_V,&_C,&_K);
        for(;_K>0; _K>>=1){
            multi = _K-(_K>>1);
            V.push_back(_V*multi);
            C.push_back(_C*multi);
        }
    }
    for(int i = 0; i< V.size();i++){
        for(int j = M; j >= V[i]; j--){
            DP[j] = DP[j-V[i]] + C[i] > DP[j] ?  DP[j-V[i]] + C[i] : DP[j];
        }
    }
    printf("%d\n",DP[M]);
    return 0;
}
