#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int M, N;
    cin>>N>>M;
    int require[M];
    vector<int> rq(N);
    for(int i=1;i<=N;i++)
        rq[i-1]=i;

    for(int i=0;i<M;i++)
        cin>>require[i];
    int answer = 0;
    for(int i=0;i<M;i++){
        for(int j=0;j<rq.size();j++){
            if(rq[j]==require[i]){
                answer += j<rq.size()-j ? j:rq.size()-j;
                vector<int> new_rq(N-i-1);
                int idx = j+1;
                for(int k=0;k<rq.size()-1;k++){
                    if(idx==rq.size())
                        idx=0;
                    new_rq[k]=rq[idx++];
                }
                rq.assign(new_rq.begin(),new_rq.end());
                break;
            }
        }
    }
    cout<<answer<<endl;
}
