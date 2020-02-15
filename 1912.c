#include <stdio.h>
int main(int argc, char** argv)
{
    register int i=0, answer, cmp;
    int N,num;
    scanf("%d",&N);
    answer = -987654321;
    cmp = 0;
    for(;i<N;i++) {
        scanf("%d", &num);
        if(cmp + num>=0) {
            cmp += num;
            answer = answer > cmp ? answer : cmp;
        }
        else if(answer < num) {
            cmp = 0;
            answer = num;
        }
        else
            cmp = 0;
    }
    printf("%d\n",answer);
    
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
/*
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
*/
