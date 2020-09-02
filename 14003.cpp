#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;
vector<int> vt;
int p[10000001][2], cnt;
int main(){
    int n;
    scanf("%d",&n);
    scanf("%d", &p[0][1]);
    vt.reserve(n);
    vt.push_back(p[0][1]);
    for(int i=1; i<n; i++){
        scanf("%d",&p[i][1]);
        if(vt[cnt]<p[i][1]) {
            vt.push_back(p[i][1]);
            p[i][0] = ++cnt;
        }
        else{
            int pos = lower_bound(vt.begin(), vt.end(), p[i][1]) - vt.begin();
            vt[p[i][0] = pos] = p[i][1];
        }
    }
    stack<int> s;
    for(int i = n - 1; i >= 0 && cnt >= 0; i--) {
        if(p[i][0] == cnt) {
            s.push(p[i][1]);
            --cnt;
        }
    }
    printf("%d\n",s.size());
    while(!s.empty()) {
        printf("%d ",s.top());
        s.pop();
    }
}
