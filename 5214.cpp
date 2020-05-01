#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int N, M, K, num;
bool visit[100001];
class station{
public:
    int stn;
    int ln;
    int jumped;
    station(int a, int b, int c) : stn(a), ln(b), jumped(c) {}
};
int main(int argc, char** argv){
    scanf("%d %d %d",&N, &M, &K);
    vector<vector<int>> lines(K,vector<int>(M));
    vector<vector<int>> info(N+1,vector<int>());
    for(int i = 0; i < K; ++i)
        for(int j = 0; j < M; ++j){
            scanf("%d",&num);
            lines[i].emplace_back(num);
            info[num].emplace_back(i);
        }
    visit[1] = true;
    queue<station> q;
    for(int i = 0; i < info[1].size(); ++i)
        q.emplace(1,info[1][i],1);
    while(!q.empty()){
        station st = q.front();
        if(st.stn==N){
            printf("%d",st.jumped);
            exit(0);
        }
        q.pop();
        for(int i = 0; i < lines[st.ln].size(); ++i){
            if(visit[lines[st.ln][i]]) continue;
            visit[lines[st.ln][i]] = true;
            for(int j = 0; j < info[lines[st.ln][i]].size(); ++j){
                q.emplace(lines[st.ln][i],info[lines[st.ln][i]][j],st.jumped+1);
            }
        }
    }
    printf("-1");
    
    
}
