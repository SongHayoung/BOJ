#include <iostream>
#include <memory.h>
#include <cstring>

using namespace std;

#define MAXSIZE 100
bool used[MAXSIZE];
int team[MAXSIZE];
int data[MAXSIZE][MAXSIZE];
int ans=-1;
int N;

void func()
{
    
    int score = 0;
    int player = 1;
    int game[4];
    memset(game,0,sizeof(game));
    for(int i=1;i<=N;i++)
    {
        int out = 0;
        while(1)
        {
            if(out==3)
                break;
            
            switch (data[i][team[player]]) {
                case 0:
                    out++;
                    break;
                case 1:
                    if(game[3]==1)
                    {
                        score++;
                        game[3]=0;
                    }
                    if(game[2]==1)
                    {
                        game[3]=1;
                        game[2]=0;
                    }
                    if(game[1]==1)
                    {
                        game[2]=1;
                    }
                    game[1]=1;
                    /*
                    score += game[3];
                    game[3]=game[2];
                    game[2]=game[1];
                    game[1]=1;
                     */
                    break;
                case 2:
                    /*
                    score += game[3] + game[2];
                    game[3]=game[1];
                    game[2]=1;
                    game[1]=0;
                     */
                    if(game[3]==1)
                    {
                        score++;
                        game[3]=0;
                    }
                    if(game[2]==1)
                    {
                        score++;
                    }
                    if(game[1]==1)
                    {
                        game[3]=1;
                        game[1]=0;
                    }
                    game[2]=1;
                    break;
                case 3:
                    if(game[3]==1)
                    {
                        score++;
                        game[3]=0;
                    }
                    if(game[2]==1)
                    {
                        score++;
                        game[2]=0;
                    }
                    if(game[1]==1)
                    {
                        score++;
                        game[1]=0;
                    }
                    game[3]=1;
                    break;
                case 4:
                    score += game[3] + game[2] + game[1] + 1;
                    game[3]=0;
                    game[2]=0;
                    game[1]=0;
                    break;
            
                default:
                    break;

            }
            player=(player%9)+1;
        }
        memset(game,0,sizeof(game));
    }
    if(score>ans)
        ans = score;
}
void make(int idx)
{
    if(idx==4)
    {
       /* cout<<cnt++<<" : ";
        for(int i=1;i<10;i++)
            cout<<team[i]<<" ";
        cout<<endl;*/
        func();
        return;
    }
    else
    {
        for(int i=2;i<10;i++)
        {
            if(used[i]==true)
                continue;
        
            team[idx]=i;
            used[i]=true;
            make((idx%9)+1);
            used[i]=false;
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<10;j++)
            cin>>data[i][j];
    
    used[1]=true;
    team[4]=1;
    
    make(5);
    
    cout<<ans<<'\n';
}
