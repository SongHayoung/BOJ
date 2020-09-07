#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool truth[51];
bool v[51];
vector<int> participate[51];
vector<int> day[51];
queue<int> q;
int n, m, ans, temp, num;
int main() {
    scanf("%d %d %d",&n,&m, &temp);
    for(int i = 0; i < temp; i++) {
        scanf("%d", &num);
        q.push(num);
        v[num] = true;
    }
    for(int i = 0; i < m; i++) {
        scanf("%d",&temp);
        for(int j = 0; j < temp; j++) {
            scanf("%d",&num);
            day[i].push_back(num);
            participate[num].push_back(i);
        }
    }
    while(!q.empty()) {
        int val = q.front();
        q.pop();
        for(auto party : participate[val]) {
            if(truth[party]) continue;
            for(auto person : day[party]) {
                if(v[person]) continue;
                v[person] = true;
                q.push(person);
            }
            truth[party] = true;
        }
    }
    for(int i = 0; i < m; i++)
        if(!truth[i]) ++ans;
    printf("%d",ans);
}
