#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> list;
int main(void) {
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int start, end;
        cin>>start>>end;
        list.push_back(make_pair(end,start));
    }
    sort(list.begin(),list.end());
    int cnt=1;
    int end = list[0].first;
    for(int i=1;i<list.size();i++)
    {
        if(list[i].second>=end)
        {
            end=list[i].first;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
