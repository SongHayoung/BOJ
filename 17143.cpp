#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Shark{
public:
    int x;
    int y;
    int size;
    int speed;
    int direction;
    int moved;
};
long long ans=0;
int R,C,M;
vector<Shark> sharks[101][101];

void eat_shark(){
    for(int i=1; i<=R; i++){
        for(int j=1;j<=C;j++){
            if(sharks[i][j].size()>1)
            {
                while(sharks[i][j].size()!=1){
                    if(sharks[i][j][0].size<sharks[i][j][1].size)
                        sharks[i][j].erase(sharks[i][j].begin());
                    else
                        sharks[i][j].erase(sharks[i][j].begin()+1);
                }
            }
        }
    }
}

void move_shark(int moved)
{
    for(int i=1;i<=R; i++){
        for(int j=1;j<=C;j++){
            for(int k=0;k<sharks[i][j].size();k++){
                if(sharks[i][j][k].moved==moved){
                    Shark shark = sharks[i][j][k];
                    sharks[i][j].erase(sharks[i][j].begin()+k);
                    k--;
                    for(int l = 0;l<shark.speed;l++){
                        if(shark.direction==1){
                            shark.y--;
                            if(shark.y==1)
                                shark.direction = 2;
                        }
                        else if(shark.direction==2){
                            shark.y++;
                            if(shark.y==R)
                                shark.direction = 1;
                        }
                        else if(shark.direction==3){
                            shark.x++;
                            if(shark.x==C)
                                shark.direction = 4;
                        }
                        else if(shark.direction==4){
                            shark.x--;
                            if(shark.x==1)
                                shark.direction = 3;
                        }
                    }
                    shark.moved++;
                    sharks[shark.y][shark.x].push_back(shark);
                }
            }
        }
    }
    eat_shark();
}

void catch_shark(int person)
{
    for(int i=1; i<=R; i++)
    {
        if(sharks[i][person].size()==1){
            ans+=sharks[i][person][0].size;
            sharks[i][person].erase(sharks[i][person].begin());
            return;
        } else
            continue;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>R>>C>>M;
    for(int i=0;i<M;i++)
    {
        int y,x,sp,dr,sz;
        Shark shark;
        cin>>y>>x>>sp>>dr>>sz;
        shark.y = y; shark.x = x; shark.direction = dr; shark.speed = sp;shark.size = sz; shark.moved = 1;
        if(dr==1||dr==2)
            shark.speed = shark.speed % ((R-1)*2);
        else
            shark.speed = shark.speed % ((C-1)*2);

        if(shark.y==1&&shark.direction==1)
            shark.direction=2;
        else if(shark.y==R&&shark.direction==2)
            shark.direction=1;
        else if(shark.x==C&&shark.direction==3)
            shark.direction=4;
        else if(shark.x==1&&shark.direction==4)
            shark.direction=3;

        sharks[y][x].push_back(shark);
    }
    for(int person = 1; person<=C; person++)
    {
        catch_shark(person);
        if(person==C)
            break;
        move_shark(person);
    }
    cout<<ans<<endl;

}
