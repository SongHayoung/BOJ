#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <queue>
using namespace std;
char map[100][101];
int key[26];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int h, w;
int BFS(){
    int ans = 0;
    int visit[100][100] = {0,};
    vector<pair<int,int>> v;
    queue<pair<int,int>> q;
    for(int i = 0; i < w; ++i){
        if(map[0][i]=='.'||map[0][i]=='$'){
            if(map[0][i]=='$') ++ans,map[0][i]='.';
            visit[0][i] = 1;
            v.emplace_back(0,i);
            q.emplace(0,i);
        }
        else if('A'<=map[0][i] && map[0][i]<='Z' && key[map[0][i]-'A']){
            map[0][i]='.';
            visit[0][i] = 1;
            v.emplace_back(0,i);
            q.emplace(0,i);
        }
        else if('a'<=map[0][i] && map[0][i]<='z'){
            ++key[map[0][i]-'a'];
            map[0][i] = '.';
            visit[0][i] = 1;
            v.emplace_back(0,i);
            q.emplace(0,i);
        }
        if(map[h-1][i]=='.'||map[h-1][i]=='$'){
            if(map[h-1][i]=='$') ++ans,map[h-1][i]='.';
            visit[h-1][i] = 1;
            v.emplace_back(h-1,i);
            q.emplace(h-1,i);
        }
        else if('A'<=map[h-1][i] && map[h-1][i]<='Z' && key[map[h-1][i]-'A']){
            map[h-1][i]='.';
            visit[h-1][i]=1;
            v.emplace_back(h-1,i);
            q.emplace(h-1,i);
        }
        else if('a'<=map[h-1][i] && map[h-1][i]<='z'){
            ++key[map[h-1][i]-'a'];
            map[h-1][i] = '.';
            visit[h-1][i] = 1;
            v.emplace_back(h-1,i);
            q.emplace(h-1,i);
        }
    }
    for(int i = 0; i < h; ++i){
        if(map[i][0]=='.'||map[i][0]=='$'){
            if(map[i][0]=='$') ++ans,map[i][0]='.';
            v.emplace_back(i,0);
            visit[i][0] = 1;
            q.emplace(i,0);
        }
        else if('A'<=map[i][0] && map[i][0]<='Z' && key[map[i][0]-'A']){
            map[i][0]='.';
            visit[i][0]=1;
            v.emplace_back(i,0);
            q.emplace(i,0);
        }
        else if('a'<=map[i][0] && map[i][0]<='z'){
            ++key[map[i][0]-'a'];
            map[i][0] = '.';
            visit[i][0] = 1;
            v.emplace_back(i,0);
            q.emplace(i,0);
        }
        if(map[i][w-1]=='.'||map[i][w-1]=='$'){
            if(map[i][w-1]=='$') ++ans, map[i][w-1] = '.';
            visit[i][w-1] = 1;
            v.emplace_back(i,w-1);
            q.emplace(i,w-1);
        }
        else if('A'<=map[i][w-1] && map[i][w-1]<='Z' && key[map[i][w-1]-'A']){
            map[i][w-1]='.';
            visit[i][w-1]=1;
            v.emplace_back(i,w-1);
            q.emplace(i,w-1);
        }
        else if('a'<=map[i][w-1] && map[i][w-1]<='z'){
            ++key[map[i][w-1]-'a'];
            map[i][w-1] = '.';
            visit[i][w-1] = 1;
            v.emplace_back(i,w-1);
            q.emplace(i,w-1);
        }
    }
    for(int i = 0; i < w; ++i){
        if('A'<=map[0][i] && map[0][i]<='Z' && key[map[0][i]-'A']){
            map[0][i]='.';
            visit[0][i] = 1;
            v.emplace_back(0,i);
            q.emplace(0,i);
        }
        if('A'<=map[h-1][i] && map[h-1][i]<='Z' && key[map[h-1][i]-'A']){
            map[h-1][i]='.';
            visit[h-1][i]=1;
            v.emplace_back(h-1,i);
            q.emplace(h-1,i);
        }
    }
    for(int i = 0; i < h; ++i){
        if('A'<=map[i][0] && map[i][0]<='Z' && key[map[i][0]-'A']){
            map[i][0]='.';
            visit[i][0]=1;
            v.emplace_back(i,0);
            q.emplace(i,0);
        }
        if('A'<=map[i][w-1] && map[i][w-1]<='Z' && key[map[i][w-1]-'A']){
            map[i][w-1]='.';
            visit[i][w-1]=1;
            v.emplace_back(i,w-1);
            q.emplace(i,w-1);
        }
    }
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int k = 0; k < 4; ++k){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(0<=nx && nx < w && 0<=ny && ny < h && !visit[ny][nx] && map[ny][nx]!='*'){
                if(map[ny][nx]=='$'){
                    ++ans;
                    map[ny][nx] = '.';
                    visit[ny][nx] = 1;
                    q.emplace(ny,nx);
                }
                else if(map[ny][nx]=='.'){
                    visit[ny][nx] = 1;
                    q.emplace(ny,nx);
                }
                else if('A'<=map[ny][nx] && map[ny][nx]<='Z'&& key[map[ny][nx]-'A']){
                    map[ny][nx] = '.';
                    visit[ny][nx] = 1;
                    q.emplace(ny,nx);
                }
                else if('a'<=map[ny][nx] && map[ny][nx] <='z'){
                    ++key[map[ny][nx]-'a'];
                    map[ny][nx] = '.';
                    memset(visit,0,sizeof(visit));
                    visit[ny][nx] = 1;
                    q.emplace(ny,nx);
                    for(int j = 0; j < v.size(); ++j){
                        q.emplace(v[j].first,v[j].second);
                        visit[v[j].first][v[j].second] = 1;
                    }
                    for(int i = 0; i < w; ++i){
                        if('A'<=map[0][i] && map[0][i]<='Z' && key[map[0][i]-'A']){
                            map[0][i]='.';
                            visit[0][i] = 1;
                            v.emplace_back(0,i);
                            q.emplace(0,i);
                        }
                        if('A'<=map[h-1][i] && map[h-1][i]<='Z' && key[map[h-1][i]-'A']){
                            map[h-1][i]='.';
                            visit[h-1][i]=1;
                            v.emplace_back(h-1,i);
                            q.emplace(h-1,i);
                        }
                    }
                    for(int i = 0; i < h; ++i){
                        if('A'<=map[i][0] && map[i][0]<='Z' && key[map[i][0]-'A']){
                            map[i][0]='.';
                            visit[i][0]=1;
                            v.emplace_back(i,0);
                            q.emplace(i,0);
                        }
                        if('A'<=map[i][w-1] && map[i][w-1]<='Z' && key[map[i][w-1]-'A']){
                            map[i][w-1]='.';
                            visit[i][w-1]=1;
                            v.emplace_back(i,w-1);
                            q.emplace(i,w-1);
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int main(void) {
    int T;
    char keys[1000];
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&h,&w);
        memset(key,0,sizeof(key));
        for(int i = 0; i < h; ++i)
            scanf("%s",map[i]);
        scanf("%s",keys);
        int len = strlen(keys);
        for(int i = 0; i < len; ++i){
            if(keys[i]=='0') break;
            ++key[keys[i]-'a'];
        }
        printf("%d\n",BFS());
    }
}
