#include <iostream>
#include <algorithm>
using namespace std;
int N, m, M, T, R;
int main(void){
    cin>>N>>m>>M>>T>>R;
    if(m+T>M){
        cout<<"-1"<<endl;
        return 0;
    }
    int cnt=0, stat = m;
    do{
        if(stat+T<=M){
            stat+=T;
            --N;
        }
        else{
            stat-=R;
            if(stat<m)
                stat = m;
        }
        ++cnt;
    }while(N);
    cout<<cnt<<endl;
}
