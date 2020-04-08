#include <stdio.h>
#include <queue>
using namespace std;
struct INFO{
    int num;
    int cost;
};
short arr[100001];
short info[100001];
bool use[100001][6];
int useage[6];
int last_num=2;
bool operator< (INFO a, INFO b){
    if(a.cost==b.cost)
        return a.num > b.num;
    return a.cost>b.cost;
}
void init(int n){
    priority_queue<INFO> q;
    for(int i = 1; i <= 5; ++i)
        q.push({i,useage[i]});
    while(!q.empty()){
        int num = q.top().num;
        q.pop();
        if(use[n][num]) continue;
        arr[n] = num;
        break;
    }
    ++useage[arr[n]];
    int near = n==1 ? 6-info[n] : 5-info[n];
    use[n + 1][arr[n]] = true;
    ++info[n + 1];
    for(int i = last_num; i < last_num+near&&i<=10000; ++i)
        use[i][arr[n]] = true, ++info[i];
    last_num += near-1;
}
int main(){
    info[2] = -1;
    for(int i = 1; i <= 100000; ++i)
        init(i);
    int tc, n;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        printf("%d\n",arr[n]);
    }
}
