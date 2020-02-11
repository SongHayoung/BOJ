#include <iostream>
using namespace std;
int main(void){
    int N;
    cin>>N;
    int DP[N+1];
    DP[0] = DP[1] = 1;
    for(int i=2;i<=N;i++){
        DP[i]=(DP[i-1]+DP[i-2])%10007;
    }
    cout<<DP[N]<<endl;
}
