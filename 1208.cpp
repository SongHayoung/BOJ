#include <stdio.h>
#include <map>
using namespace std;
int nums[40];
int target, N;
long long ans;
map<int,int> l;
void makesum(int sum, int pos){
    if(pos==N/2){
        l[sum]++;
        return ;
    }
    else {
        makesum(sum + nums[pos], pos + 1);
        makesum(sum, pos + 1);
        return ;
    }
}
void makesum2(int sum, int pos){
    if(pos==N){
        ans += l[target-sum];
        return;
    }
    makesum2(sum+nums[pos],pos+1);
    makesum2(sum,pos+1);
}
int main(int argc, char** argv){
    scanf("%d %d",&N, &target);
    for(int i = 0; i < N; ++i)
        scanf("%d",nums+i);
    makesum(0,0);
    makesum2(0,N/2);
    printf("%lld",target ? ans : --ans);
}
