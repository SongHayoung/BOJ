#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Horse{
public:
    int x;
    int y;
    bool run;
    int status;
};
int dice[10];
int map[9][9] = {{40, 0 ,  0,  0, 38, 36, 34, 32, 30},
                 {0 , 0 ,  0,  0,  0,  0,  0, 28,  0},
                 {0 , 0 , 35,  0,  0,  0, 27,  0,  0},
                 {0 , 0 ,  0, 30,  0, 26,  0,  0,  0},
                 {2 , 0 ,  0,  0, 25,  0,  0,  0, 28},
                 {4 , 0 ,  0, 19,  0, 24,  0,  0, 26},
                 {6 , 0 , 16,  0,  0,  0, 22,  0, 24},
                 {8 , 13,  0,  0,  0,  0,  0,  0, 22},
                 {10, 12, 14, 16, 18,  0,  0,  0, 20}};
int score = 0;
int ans = 0;
Horse horse[4];
int choose[10];
bool flag;

bool move(int c_h,int mv){
    if(horse[c_h].status>10){
        flag = false;
        return false;
    }
    int x = horse[c_h].x;
    int y = horse[c_h].y;
    int st = horse[c_h].status;
    int mvc = mv;
    while(1){
        if(mvc == 0)
            break;
        if(st==1){
            y++;
            while(map[y][x]==0){
                y++;
            }
        }
        else if(st==2){
            x++;
            while(map[y][x]==0){
                x++;
            }
        }
        else if(st==3){
            y--;
            while(map[y][x]==0){
                y--;
            }
        }
        else if(st==4){
            x--;
            while(map[y][x]==0){
                x--;
            }
        }
        else if(st==5){
            x++;
            y--;
            while(map[y][x]==0){
                x++;
                y--;
            }
        }
        else if(st==6){
            x--;
            y--;
            while(map[y][x]==0){
                x--;
                y--;
            }
        }
        else if(st==7){
            x--;
            y++;
            while(map[y][x]==0){
                x--;
                y++;
            }
        }
        else if(st==8){
            if(x==0&&y==0){
                horse[c_h].status = 987654321;
                horse[c_h].run = false;
            }
            x--;
            y--;
            while(map[y][x]==0){
                x--;
                y--;
            }
        }


        if(y==4&&x==4){
            st = 8;
        }
        else if(x==0&&y==8){
            st=2;
        }
        else if(x==8&&y==8){
            st=3;
        }
        else if(x==8&&y==0){
            st=4;
        }
        mvc--;
    }
    if(x<0||y<0){
        horse[c_h].status = 987654321;
        horse[c_h].run = false;
        return false;
    }
    if(x==0&&y==8)
        st = 5;
    else if(x==8&&y==8)
        st = 6;
    else if(x==8&&y==0)
        st = 7;
    else if(y==4&&x==4)
        st = 8;
    for(int i=0;i<4;i++)
    {
        if(horse[i].x==x&&horse[i].y==y&&horse[i].run&&horse[c_h].status<10){
            flag = false;
            return false;
        }
    }
    horse[c_h].x = x;
    horse[c_h].y = y;
    horse[c_h].status = st;
    score += map[y][x];
    return true;
}
void dfs(int depth){
    if(depth==10){
        for(int i=0;i<4;i++){
            horse[i].x = 0;
            horse[i].y = 3;
            horse[i].run = false;
            horse[i].status = 1;
        }
        score = 0;
        flag = true;
        for(int i=0;i<10;i++){
                horse[choose[i]].run = true;
        }
        for(int i=0;i<10;i++){
            if(flag)
                 move(choose[i], dice[i]);
            else
                return;
        }
        if(flag)
            ans = max(ans,score);
        return ;
    }

    for(int i=0;i<4;i++){
        choose[depth]=i;
        dfs(depth+1);
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<10;i++)
        cin>>dice[i];

    dfs(0);
    cout<<ans<<endl;

}
