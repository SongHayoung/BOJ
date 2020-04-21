#include <stdio.h>
#include <memory.h>
#include <vector>
using namespace std;
int N;
bool primes[4000001];
vector<long long> pSum;
int ans;
int main() {
    scanf("%d",&N);
    pSum.push_back(2);
    memset(primes,false,sizeof(primes));
    for(long long i = 3; i <= N; i+=2){
        if(primes[i]) continue;
        pSum.push_back(i+pSum.back());
        for(long long j = i*i; j <= N; j+=(i*2)){
            primes[j] = true;
        }
    }
    for(int i = 0; i < pSum.size(); ++i){
        if(pSum[i]<N) continue;
        if(pSum[i]==N) ++ans;
        else{
            for(int j = i-1; j >= 0&&pSum[i]<=N+pSum[j]; --j)
                if(pSum[i]==pSum[j]+N) ++ans;
        }
    }
    printf("%d",ans);
}
