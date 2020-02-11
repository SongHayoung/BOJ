#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

#define MAXSIZE 100000
int N;
int item1, item2;
vector<pair<int,int>> arr;
priority_queue<int> pq;
int ans=0;

int main(void)
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>item1>>item2;
        arr.push_back(make_pair(item2,item1));
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++)
    {
        pq.push(-arr[i].second);
        ans+=arr[i].second;
        if(pq.size()>arr[i].first)
        {
            ans += pq.top();
            pq.pop();
        }
    }
    cout<<ans<<endl;
}
