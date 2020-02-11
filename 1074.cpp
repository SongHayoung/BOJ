#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define MAXSIZE 32768

int cnt = 0;
int N, x, y;
bool tf = true;

void find(int n, int _x, int _y)
{
    if(n==2)
    {
        if(_x==x&&_y==y)
        {
            tf = false;
            cout<<cnt<<endl;
        }
        if(_x==x&&_y+1==y)
        {
            tf = false;
            cout<<cnt+1<<endl;
        }
        if(_x+1==x&&_y==y)
        {
            tf = false;
            cout<<cnt+2<<endl;
        }
        if(_x+1==x&&_y+1==y)
        {
            tf = false;
            cout<<cnt+3<<endl;
        }
        
        cnt += 4;
        return ;
    }
    if(tf) find(n/2,_x,_y);
    if(tf) find(n/2,_x,_y+n/2);
    if(tf) find(n/2,_x+n/2,_y);
    if(tf) find(n/2,_x+n/2,_y+n/2);
}
int main(void)
{
    cin>>N>>x>>y;
    int n = pow(2,N);
    find(n,0,0);
}
