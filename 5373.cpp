#include <iostream>
#include <queue>
#include <stdlib.h>
#include <memory.h>
using namespace std;
queue<pair<char,char>> q;
void swap(char &a, char&b, char&c, char&d){
    char temp = a;
    a = d;
    d = c;
    c = b;
    b = temp;
}

void play(){            // 0  1   2      3   4   5       6   7   8
    char cube[12][9] =  {{' ',' ',' ',  'o','o','o',    ' ',' ',' '},   //0
                         {' ',' ',' ',  'o','o','o',    ' ',' ',' '},   //1
                         {' ',' ',' ',  'o','o','o',    ' ',' ',' '},   //2
                         {'g','g','g',  'w','w','w',    'b','b','b'},   //3
                         {'g','g','g',  'w','w','w',    'b','b','b'},   //4
                         {'g','g','g',  'w','w','w',    'b','b','b'},   //5
                         {' ',' ',' ',  'r','r','r',    ' ',' ',' '},   //6
                         {' ',' ',' ',  'r','r','r',    ' ',' ',' '},   //7
                         {' ',' ',' ',  'r','r','r',    ' ',' ',' '},   //8
                         {' ',' ',' ',  'y','y','y',    ' ',' ',' '},   //9
                         {' ',' ',' ',  'y','y','y',    ' ',' ',' '},   //10
                         {' ',' ',' ',  'y','y','y',    ' ',' ',' '}};  //11
    char c, o;
    while(!q.empty()){
        c=q.front().first;
        o=q.front().second;
        q.pop();
        if(c=='U'){
            if(o=='+'){
                swap(cube[3][3],cube[3][5],cube[5][5],cube[5][3]);
                swap(cube[3][4],cube[4][5],cube[5][4],cube[4][3]);

                swap(cube[2][3],cube[3][6],cube[6][5],cube[5][2]);
                swap(cube[2][4],cube[4][6],cube[6][4],cube[4][2]);
                swap(cube[2][5],cube[5][6],cube[6][3],cube[3][2]);
            }
            else{
                swap(cube[3][3],cube[5][3],cube[5][5],cube[3][5]);
                swap(cube[3][4],cube[4][3],cube[5][4],cube[4][5]);

                swap(cube[2][3],cube[5][2],cube[6][5],cube[3][6]);
                swap(cube[2][4], cube[4][2], cube[6][4], cube[4][6]);
                swap(cube[2][5], cube[3][2], cube[6][3], cube[5][6]);
            }
        }
        else if(c=='F'){
            if(o=='+'){
                swap(cube[6][3],cube[6][5],cube[8][5],cube[8][3]);
                swap(cube[6][4],cube[7][5],cube[8][4],cube[7][3]);

                swap(cube[5][3],cube[5][6],cube[9][5],cube[5][0]);
                swap(cube[5][4],cube[5][7],cube[9][4],cube[5][1]);
                swap(cube[5][5],cube[5][8],cube[9][3],cube[5][2]);
            }
            else{
                swap(cube[6][3],cube[8][3],cube[8][5],cube[6][5]);
                swap(cube[6][4],cube[7][3],cube[8][4],cube[7][5]);

                swap(cube[5][3],cube[5][0],cube[9][5],cube[5][6]);
                swap(cube[5][4],cube[5][1],cube[9][4],cube[5][7]);
                swap(cube[5][5],cube[5][2],cube[9][3],cube[5][8]);
            }
        }
        else if(c=='D'){
            if(o=='+'){
                swap(cube[9][3],cube[9][5],cube[11][5],cube[11][3]);
                swap(cube[9][4],cube[10][5],cube[11][4],cube[10][3]);

                swap(cube[8][3],cube[5][8],cube[0][5],cube[3][0]);
                swap(cube[8][4],cube[4][8],cube[0][4],cube[4][0]);
                swap(cube[8][5],cube[3][8],cube[0][3],cube[5][0]);
            }
            else{
                swap(cube[9][3],cube[11][3],cube[11][5],cube[9][5]);
                swap(cube[9][4],cube[10][3],cube[11][4],cube[10][5]);

                swap(cube[8][3],cube[3][0],cube[0][5],cube[5][8]);
                swap(cube[8][4],cube[4][0],cube[0][4],cube[4][8]);
                swap(cube[8][5],cube[5][0],cube[0][3],cube[3][8]);
            }
        }
        else if(c=='B'){
            if(o=='+'){
                swap(cube[0][3],cube[0][5],cube[2][5],cube[2][3]);
                swap(cube[0][4],cube[1][5],cube[2][4],cube[1][3]);

                swap(cube[11][3],cube[3][8],cube[3][5],cube[3][2]);
                swap(cube[11][4],cube[3][7],cube[3][4],cube[3][1]);
                swap(cube[11][5],cube[3][6],cube[3][3],cube[3][0]);
            }
            else{
                swap(cube[0][3],cube[2][3],cube[2][5],cube[0][5]);
                swap(cube[0][4],cube[1][3],cube[2][4],cube[1][5]);

                swap(cube[11][3],cube[3][2],cube[3][5],cube[3][8]);
                swap(cube[11][4],cube[3][1],cube[3][4],cube[3][7]);
                swap(cube[11][5],cube[3][0],cube[3][3],cube[3][6]);
            }
        }
        else if(c=='L'){
            if(o=='+'){
                swap(cube[3][0],cube[3][2],cube[5][2],cube[5][0]);
                swap(cube[3][1],cube[4][2],cube[5][1],cube[4][0]);

                swap(cube[0][3],cube[3][3],cube[6][3],cube[9][3]);
                swap(cube[1][3],cube[4][3],cube[7][3],cube[10][3]);
                swap(cube[2][3],cube[5][3],cube[8][3],cube[11][3]);
            }
            else{
                swap(cube[3][0],cube[5][0],cube[5][2],cube[3][2]);
                swap(cube[3][1],cube[4][0],cube[5][1],cube[4][2]);

                swap(cube[0][3],cube[9][3],cube[6][3],cube[3][3]);
                swap(cube[1][3],cube[10][3],cube[7][3],cube[4][3]);
                swap(cube[2][3],cube[11][3],cube[8][3],cube[5][3]);
            }
        }
        else{
            if(o=='+'){
                swap(cube[3][6],cube[3][8],cube[5][8],cube[5][6]);
                swap(cube[3][7],cube[4][8],cube[5][7],cube[4][6]);

                swap(cube[0][5],cube[9][5],cube[6][5],cube[3][5]);
                swap(cube[1][5],cube[10][5],cube[7][5],cube[4][5]);
                swap(cube[2][5],cube[11][5],cube[8][5],cube[5][5]);
            }
            else{
                swap(cube[3][6],cube[5][6],cube[5][8],cube[3][8]);
                swap(cube[3][7],cube[4][6],cube[5][7],cube[4][8]);

                swap(cube[0][5],cube[3][5],cube[6][5],cube[9][5]);
                swap(cube[1][5],cube[4][5],cube[7][5],cube[10][5]);
                swap(cube[2][5],cube[5][5],cube[8][5],cube[11][5]);
            }
        }
    }

    for(int i=3;i<6;i++) {
        for (int j = 3; j < 6; j++)
            cout << cube[i][j];
        cout <<endl;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc, n;
    char c,o;
    cin>>tc;
    for(int test=0;test<tc;test++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>c>>o;
            q.push(make_pair(c,o));
        }
        play();
    }
}
