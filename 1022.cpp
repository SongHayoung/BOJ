#include <iostream>
#include <vector>
using namespace std;
long long MAP[50][5];
int main(void) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1 += 5000;
    r2 += 5000;
    c1 += 5000;
    c2 += 5000;
    long long move = 1;
    long long use_moved = move;
    long long max = 0;
    bool flag = true;
    int x = 5000;
    int y = 5000;
    for(long long input = 1; input <= 10001*10001; input++){
        if(r1<=y&&y<=r2 && c1<=x&&x<=c2) {
            MAP[y - r1][x - c1] = input;
            max = max < input ? input : max;
        }
        if(move%2==1){
            if(flag){
                ++x;
                --use_moved;
            }
            else{
                --y;
                --use_moved;
            }
        }
        else{
            if(flag){
                --x;
                --use_moved;
            }
            else{
                ++y;
                --use_moved;
            }
        }
        if(use_moved==0){
            if(flag){
                flag = false;
                use_moved = move;
            }
            else{
                ++move;
                flag = true;
                use_moved = move;
            }
        }
    }
    int cnt = 0;
    while(max>=10){
        max /= 10;
        ++cnt;
    }
    for(int i=0;i<=r2-r1;i++){
        for(int j=0;j<=c2-c1;j++){
            int space = cnt;
            int temp = MAP[i][j];
            while(temp>=10){
                --space;
                temp /= 10;
            }
            for(int k=0;k<space;k++)
                cout<<" ";

            cout<<MAP[i][j];
            if(j!=c2-c1)
                cout<<" ";
        }
        cout<<endl;
    }
}
