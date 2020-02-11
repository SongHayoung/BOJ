#include <iostream>
#include <string>

using namespace std;
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1,-1,-1,  0, 0,  1, 1, 1};
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int kx, ky;
    int sx, sy;
    int d, n;
    char c;
    cin>>c>>d;
    kx=c-'A';   ky=8-d;
    cin>>c>>d;
    sx=c-'A';   sy=8-d;
    cin>>n;
    string cmd;
    getline(cin, cmd);
    int nkx, nky, nsx, nsy, Icmd;
    for(int i=0;i<n;i++) {
        getline(cin, cmd);
        if (cmd == "LT")
            Icmd = 0;
        else if (cmd == "T")
            Icmd = 1;
        else if(cmd=="RT")
            Icmd = 2;
        else if(cmd=="L")
            Icmd = 3;
        else if(cmd=="R")
            Icmd = 4;
        else if(cmd=="LB")
            Icmd = 5;
        else if(cmd=="B")
            Icmd = 6;
        else if(cmd=="RB")
            Icmd = 7;

        nkx = kx + dx[Icmd];
        nky = ky + dy[Icmd];
        if (0 <= nkx && nkx <= 7 && 0 <= nky && nky <= 7) {
            if (nkx == sx && nky == sy) {
                nsx = sx + dx[Icmd];
                nsy = sy + dy[Icmd];
                if(0 <= nsx && nsx <= 7 && 0 <= nsy && nsy <= 7){
                    sx = nsx; sy = nsy; ky = nky; kx = nkx;
                }
            }
            else{
                kx = nkx;   ky = nky;
            }
        }
    }
    c = kx+'A'; d = 8-ky;
    cout<<c<<d<<endl;
    c = sx+'A'; d = 8-sy;
    cout<<c<<d<<endl;
}
