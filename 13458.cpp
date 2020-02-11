#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define Size 1000000
int rooms[Size];
int N, B, C;
long long ans=0;
int main(void)
{

    cin>>N;
    for(int i=0;i<N;i++)
        cin>>rooms[i];

    cin>>B>>C;


    for(int i=0;i<N;i++)
    {
        rooms[i] -= B;
        if(rooms[i]<=0)
            ans = ans + 1;
        else if(rooms[i]%C==0)
            ans = ans + 1 + (rooms[i]/C);
        else
            ans = ans + 2 + (rooms[i]/C);
    }

    cout<<ans<<endl;
}
