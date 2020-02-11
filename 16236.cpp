#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

class Shark{
public:
    int x;
    int y;
    int size;
    int eat;
};

int map[20][20];
int dist[20][20];
bool visit[20][20];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int N;
int ans = 0;
pair<int,int> fish;
bool flag = true;
Shark shark;

void set_dist()
{
    queue<pair<int,int>> q;
    memset(visit,false,sizeof(visit));
    dist[shark.y][shark.x] = 0;
    visit[shark.y][shark.x] = true;
    q.push(make_pair(shark.y,shark.x));

    while(!q.empty())
    {
        int cur_x = q.front().second;
        int cur_y = q.front().first;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if(0<=next_x && next_x<N && 0<=next_y && next_y<N)
            {
                if(map[next_y][next_x]<=shark.size && !visit[next_y][next_x])
                {
                    q.push(make_pair(next_y,next_x));
                    dist[next_y][next_x] = dist[cur_y][cur_x] + 1;
                    visit[next_y][next_x] = true;
                }
            }
        }
    }
}

void select_fish()
{
        int min_dist = 987654321;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(min_dist>dist[i][j]&&0<map[i][j]&&map[i][j]<shark.size){
                    min_dist = dist[i][j];
                    fish = make_pair(i,j);
                    flag = true;
                }


    return ;
}

void eat_fish()
{
    shark.x = fish.second;
    shark.y = fish.first;
    shark.eat += 1;
    if(shark.eat==shark.size)
    {
        shark.size += 1;
        shark.eat = 0;
    }
    ans += dist[shark.y][shark.x];
    map[shark.y][shark.x] = 0;
}

void find_fish()
{
    flag = false;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dist[i][j] = 987654321;}}
    set_dist();
    select_fish();
    if(flag)
        eat_fish();
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) {
            cin >> map[i][j];
            if(map[i][j]==9)
            {
                shark.x = j;
                shark.y = i;
                shark.size = 2;
                shark.eat = 0;
                map[i][j] = 0;
            }
        }

    while(flag)
    {
        find_fish();
    }
    cout<<ans<<endl;
}
