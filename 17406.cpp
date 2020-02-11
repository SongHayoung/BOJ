#include <iostream>
#include <memory.h>
#include <cstring>

using namespace std;

#define MAXSIZE 51
int arr[MAXSIZE][MAXSIZE];
int cpy_arr[MAXSIZE][MAXSIZE];
int _rotate[6][3];
int list[6];
bool used[6];
int ans=987654321;
int N,M,K;

void print()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
            cout<<cpy_arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<endl;
}

void rotate_func(int y1,int x1, int y2, int x2, int depth)
{
    if(depth==0)
        return ;
    int start_point = cpy_arr[y1][x1];
    for(int i=y1+1;i<=y2;i++)
    {
        cpy_arr[i-1][x1]=cpy_arr[i][x1];
    }
    for(int i=x1+1;i<=x2;i++)
    {
        cpy_arr[y2][i-1]=cpy_arr[y2][i];
    }
    for(int i = y2-1;i>=y1;i--)
    {
        cpy_arr[i+1][x2]=cpy_arr[i][x2];
    }
    for(int i=x2-1;i>=x1+1;i--)
    {
        cpy_arr[y1][i+1]=cpy_arr[y1][i];
    }
    cpy_arr[y1][x1+1]=start_point;
    rotate_func(y1+1, x1+1, y2-1, x2-1, depth-1);
}
void func()
{
    memcpy(cpy_arr,arr,sizeof(cpy_arr));
    for(int i=0;i<K;i++)
    {
        rotate_func(_rotate[list[i]][0]-_rotate[list[i]][2],_rotate[list[i]][1]-_rotate[list[i]][2],
                    _rotate[list[i]][0]+_rotate[list[i]][2],_rotate[list[i]][1]+_rotate[list[i]][2], _rotate[list[i]][2]);
        
        //print();
    }
    for(int i=1;i<=N;i++)
    {
        int total = 0;
        for(int j=1;j<=M;j++)
            total += cpy_arr[i][j];
        ans = min(ans,total);
    }
    
}

void DFS(int idx)
{
    if(idx==K)
        func();
    else
    {
        for(int i=0;i<K;i++)
        {
            if(used[i])
                continue;
            
            used[i]=true;
            list[idx]=i;
            DFS(idx+1);
            used[i]=false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M>>K;
    
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin>>arr[i][j];
    
    for(int i=0;i<K;i++)
        for(int j=0;j<3;j++)
            cin>>_rotate[i][j];
    
    DFS(0);
    
    cout<<ans<<'\n';
}
