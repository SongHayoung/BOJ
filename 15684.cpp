#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

bool ledder[31][11];
bool ledder_cpy[31][11];
int N, M, H;
int ans = 987654321;

void reach(int added)
{
    for(int i=1;i<=N;i++)
    {
        int cur = i;
        for(int j=1;j<=H;j++)
        {
            if(ledder_cpy[j][cur])
                cur++;
            else if(ledder_cpy[j][cur-1])
                cur--;
        }
        if(cur!=i)
            return;
    }
    ans = added;
}

void ledder_add(int choose, int level, int x, int y)
{
    for(int i=x;i<N;i++)
    {
        for(int j=y;j<=H;j++)
        {
            if(ans<=3)
                return;

            if(ledder_cpy[j][i]||ledder_cpy[j][i-1]||ledder_cpy[j][i+1])
                continue;

            ledder_cpy[j][i]=true;
            if(choose==3)
                reach(level);
            else
                ledder_add(choose+1,level,i-1,j-1);
            ledder_cpy[j][i]=false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M>>H;
    for(int i=0;i<M;i++)
    {
        int a, b;
        cin>>a>>b;
        ledder[a][b]=true;
    }

    memcpy(ledder_cpy,ledder,sizeof(ledder_cpy));
    reach(0);
    if(ans<=3){
        cout<<ans<<endl;
        return 0;
    }

    memcpy(ledder_cpy,ledder,sizeof(ledder_cpy));
    ledder_add(3,1,1,1);
    if(ans<=3){
        cout<<ans<<endl;
        return 0;
    }

    memcpy(ledder_cpy,ledder,sizeof(ledder_cpy));
    ledder_add(2,2,1,1);
    if(ans<=3){
        cout<<ans<<endl;
        return 0;
    }

    memcpy(ledder_cpy,ledder,sizeof(ledder_cpy));
    ledder_add(1,3,1,1);
    if(ans<=3){
        cout<<ans<<endl;
        return 0;
    }
    else
        cout<<"-1"<<endl;
}
