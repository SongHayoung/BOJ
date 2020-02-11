#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main(void) {
    int N,M;
    cin>>N>>M;
    int answer = 0;
    vector<string> MAP(N);
    vector<vector<int>> DP(N+1,vector<int>(M+1,0));
    for(int i=0;i<N;i++){
        cin>>MAP[i];
    }
    for(int i=N-1;i>=0;i--){
        for(int j=M-1;j>=0;j--){
            if(MAP[i][j]=='0')
                DP[i][j]=0;
            else{
                DP[i][j]=1+min(DP[i][j+1],min(DP[i+1][j],DP[i+1][j+1]));
            }
            answer = max(answer,DP[i][j]);
        }
    }
    cout<<answer*answer<<endl;
}
