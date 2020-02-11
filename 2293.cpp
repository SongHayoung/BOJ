#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <memory.h>

using namespace std;

#define MAXSIZE 101
#define devide 1000000000
int arr[10001]={0,};
int money[100];
int n,k;
int ans=0;


int main(void)
{
    cin>>n>>k;
    memset(arr,0,sizeof(arr));
    for(int i=0;i<n;i++)
        cin>>money[i];
    
    arr[0]=1;
    
    for(int i=0;i<n;i++)
    {
        for(int j=money[i];j<=k;j++)
        {
            arr[j]+=arr[j-money[i]];
        }
    }
    cout<<arr[k]<<endl;
    
}
