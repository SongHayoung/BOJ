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
int n;
int item1, item2;
vector<int> ans_arr;
vector<pair<int,int>> arr;
int ans;
int comp;

int main(void)
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        ans = 1;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>item1>>item2;
            arr.push_back(make_pair(item1, item2));
        }
        
        sort(arr.begin(),arr.end());
        comp=arr[0].second;
        for(int j=1;j<arr.size();j++)
        {
            if(arr[j].second<comp)
            {
                comp=arr[j].second;
                ans++;
            }
        }
        arr.erase(arr.begin(),arr.end());
        ans_arr.push_back(ans);
    }
    for(int i=0;i<ans_arr.size();i++)
        cout<<ans_arr[i]<<endl;
}
