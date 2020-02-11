#include <iostream>
#include <memory.h>
using namespace std;
int DP[500][500];
int triangle[500][500];
int N;

int func(int x,int y){
    if(y==N-1){
        return triangle[y][x];
    }
    int &ret = DP[y][x];
    if(ret!=-1)
        return ret;
    ret = triangle[y][x];
    ret += max(func(x,y+1),func(x+1,y+1));
    return ret;
}

int main(void){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            cin>>triangle[i][j];
        }
    }
    memset(DP,-1,sizeof(DP));
    cout<<func(0,0)<<endl;
}
