#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
int N,M,K;
int yangbun[11][11];
int cur_yangbun[11][11];
int add_yangbun[11][11];
vector<int> trees[11][11];
int dx[8] = {-1,0,1,-1,1,-1,0,1};
int dy[8] = {-1,-1,-1,0,0,1,1,1};

void bunsik(int x, int y)
{
    for(int i=0;i<8;i++)
    {
        int near_x = x + dx[i];
        int near_y = y + dy[i];
        if(1<=near_x && near_x<=N && 1<=near_y && near_y<=N)
        {
            trees[near_y][near_x].push_back(1);
        }
    }
}

void spring()
{
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            sort(trees[i][j].begin(),trees[i][j].end());
            for(int k = 0; k<trees[i][j].size();k++){
                if(trees[i][j].at(k)==0)
                    continue;

                if(trees[i][j].at(k)<=cur_yangbun[i][j]){
                    cur_yangbun[i][j] -= trees[i][j].at(k);
                    trees[i][j].at(k) = trees[i][j].at(k) + 1;
                }
                else{
                    add_yangbun[i][j] += trees[i][j].at(k)/2;
                    trees[i][j].erase(trees[i][j].begin()+k);
                    k=k-1;
                }
            }
        }
    }
}
void summer()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cur_yangbun[i][j] += add_yangbun[i][j];
            add_yangbun[i][j] = 0;
        }
    }
}

void fall()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            for(int k=0;k<trees[i][j].size();k++)
            {
                if((trees[i][j].at(k)%5)==0 && trees[i][j].at(k)>0)
                {
                    bunsik(j,i);
                }
            }
        }
    }
}

void winter()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cur_yangbun[i][j] += yangbun[i][j];
        }
    }

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>yangbun[i][j];
            cur_yangbun[i][j]=5;
            trees[i][j].push_back(0);
        }
    }
    for(int i=0;i<M;i++)
    {
        int x,y,age;
        cin>>x>>y>>age;
        trees[x][y].push_back(age);
    }

    for(int i=0;i<K;i++)
    {
        spring();
        summer();
        fall();
        winter();
    }
    int ans = 0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            ans += trees[i][j].size()-1;
        }
    }
    cout<<ans<<endl;
}
