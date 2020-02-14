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
        for(;_K>0; _K>>=1){     //_K이하의 모든 수를 만들 수 있는 조합을 최소의 갯수로 만들기
            multi = _K-(_K>>1); //EX) 9라면 5 2 1 1로 9 이하의 모든 수 표현 가능
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
