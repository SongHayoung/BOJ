#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
int N;
int cards[1001];
int DP[1001];

int func(int n){
    int &ret = DP[n];
    if(ret!=-1)
        return ret;
    ret = cards[n];
    for(int i=1;i<=n/2;i++){
        ret = max(ret,func(i)+func(n-i));
    }
    return ret;
}

int main(void){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>cards[i];
    memset(DP,-1,sizeof(DP));
    DP[0] = cards[0] = 0;
    DP[1] = cards[1];
    func(N);
    cout<<DP[N]<<endl;
}
