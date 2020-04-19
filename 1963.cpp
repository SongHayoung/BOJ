#include <stdio.h>
#include <queue>
using namespace std;
bool primes[10000];
bool isnear(int num, int change){
    if(change<1000||change>9999) return false;
    bool flag = true;
    while(num){
        if((num%10)!=(change%10)){
            if(flag) flag = false;
            else return false;
        }
        num *= 0.1; change *= 0.1;
    }
    return true;
}
int move(int start, int target){
    if(start==target) return 0;
    bool p[10000] = {false,};
    p[start] = true;
    queue<pair<int,int>> q;
    q.emplace(start,0);
    while(!q.empty()){
        int num = q.front().first;
        int mv = q.front().second;
        q.pop();
        for(int i = 1; i <= 1000; i*=10){
            for(int add = i; add <= i*10&&isnear(num,num+add); add+=i){
                if(primes[num+add]||p[num+add]) continue;
                if(num+add==target) return mv+1;
                p[num+add] = true;
                q.emplace(num+add,mv+1);
            }
            for(int minus = i; minus <= i*10&&isnear(num,num-minus); minus+=i){
                if(primes[num-minus]||p[num-minus]) continue;
                if(num-minus==target) return mv+1;
                p[num-minus] = true;
                q.emplace(num-minus,mv+1);
            }
        }
    }
    return -1;
}
int main() {
    for(int i = 2; i <= 9999; ++i)
        for (int j = i * i; !primes[i]&&j <= 9999; j+=i)
            primes[j] = true;
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int s, t;
        scanf("%d %d",&s,&t);
        int ret = move(s,t);
        ret==-1 ? printf("Impossible\n") : printf("%d\n",ret);
    }
}
