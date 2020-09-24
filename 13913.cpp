#include <iostream>
#include <memory.h>
#include <queue>
#include <stack>
#define INF 100000
using namespace std;
int arr[INF + 1];
stack<int> ans;
int n, k;
int bfs() {
    memset(arr, -1, sizeof(arr));
    arr[n] = 0;
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int val = q.front();
        q.pop();
        if(val + 1 <= INF && arr[val + 1] == -1) {
            arr[val + 1] = arr[val] + 1;
            q.push(val + 1);
            if(val + 1 == k) return arr[k];
        }
        if(val * 2 <= INF && arr[val * 2] == -1) {
            arr[val * 2] = arr[val] + 1;
            q.push(val * 2);
            if(val * 2 == k) return arr[k];
        }
        if(val - 1 >= 0 && arr[val - 1] == -1) {
            arr[val - 1] = arr[val] + 1;
            q.push(val - 1);
            if(val - 1 == k) return arr[k];
        }
    }
}
void makeAns() {
    ans.push(k);
    while(arr[ans.top()]) {
        if(!(ans.top() & 1) && (arr[ans.top() / 2] == arr[ans.top()] - 1))
            ans.push(ans.top() / 2);
        else if(ans.top() + 1 <= INF && arr[ans.top() + 1] == arr[ans.top()] - 1)
            ans.push(ans.top() + 1);
        else if(ans.top() - 1 >= 0 && arr[ans.top() - 1] == arr[ans.top()] - 1)
            ans.push(ans.top() - 1);
    }
}
int main() {
    scanf("%d %d",&n,&k);
    if(n == k) {
        printf("0\n%d",n);
        exit(0);
    }
    memset(arr, -1, sizeof(arr));
    printf("%d\n",bfs());
    makeAns();
    while(!ans.empty()) {
        printf("%d ",ans.top());
        ans.pop();
    }
}
