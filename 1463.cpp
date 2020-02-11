#include <string>
#include <vector>
#include <memory.h>
#include <iostream>
using namespace std;
int DP[1000001];
int F(int N){
    if(N==1)
        return 0;
    int &ret = DP[N];
    if(ret!=-1)
        return ret;
    ret = 987654321;
    if(N%3==0)
        ret = min(ret,F(N/3)+1);
    if(N%2==0)
        ret = min(ret,F(N/2)+1);
    ret = min(ret,F(N-1)+1);
    return ret;
}
int main(void) {
    int N;
    cin>>N;
    memset(DP,-1,sizeof(DP));
    cout<<F(N)<<endl;
}
