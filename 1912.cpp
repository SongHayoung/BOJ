#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long ans;
long long arr[100010];

int main(void) {

    cin>>N;

    for(int i=1;i<=N;i++)
        cin>>arr[i];

    arr[0]=0;
    ans = arr[1];
    for(int i=1;i<=N;i++)
    {
        arr[i]=max(arr[i],arr[i-1]+arr[i]);
        ans = max(ans,arr[i]);
    }
    cout<<ans<<endl;
}
