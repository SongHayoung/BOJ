#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXSIZE 100000
int N;
long long num;
vector<long long> arr;
long long ans=0;

int main(void)
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>num;
        arr.push_back(num);
    }
    sort(arr.begin(),arr.end(),greater<int>());
    for(long long i=0;i<arr.size();i++)
    {
        num=arr[i]-i;
        if(num<=0)
            continue;
        ans+=num;
    }
    cout<<ans<<endl;
}
