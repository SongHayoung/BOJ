#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;

int N,x;
vector<int> v;
int main(void) {
    v.push_back(-1);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin >> x;
        if(v.back()<x)
        {
            v.push_back(x);
        } else{
            auto it = lower_bound(v.begin(),v.end(),x);
            *it=x;
        }
    }
    cout<<v.size()-1<<endl;
}
