#include <iostream>
#include <memory.h>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int L, N;
    cin>>L>>N;
    bool cake[L+1];
    int answer1, answer2;
    int most_expected = 0;
    int most_get = 0;
    int from,to;
    int get = 0;
    memset(cake,false,sizeof(cake));
    for(int i=1;i<=N;i++){
        cin>>from>>to;
        if(most_expected<(to-from+1)){
            most_expected = to-from+1;
            answer1 = i;
        }
        get = 0;
        for(int k=from;k<=to;k++){
            if(!cake[k]){
                cake[k]=true;
                ++get;
            }
        }
        if(most_get<get){
            most_get = get;
            answer2 = i;
        }
    }
    cout<<answer1<<endl<<answer2<<endl;
}
