#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans=0;
class snake
{
public:
    pair<int,int> position;
    int go;

    snake(int a,int b, int w) :go(w)
    {
        position = make_pair(a,b);
    }
};

vector<pair<int,int>> body;
vector<pair<int,int>> apples;
vector<pair<int,char>> moves;
int N,K,L;
snake s(1,1,1);

void move()
{
    while(1) {
        ans++;
        pair<int, int> tail = body.at(0);
        if (s.go == 0)
            s.position.second--;
        else if (s.go == 1)
            s.position.first++;
        else if (s.go == 2)
            s.position.second++;
        else
            s.position.first--;


        if (!moves.empty()) {
            if (moves.at(0).first == ans) {
                if (moves.at(0).second == 'L')
                    s.go = (s.go + 3) % 4;
                else
                    s.go = (s.go + 1) % 4;

                moves.erase(moves.begin());
            }
        }

        if (s.position.first <= 0 || s.position.first > N || s.position.second <= 0 || s.position.second > N)
            return;
        vector<pair<int, int>>::iterator bodyit;
        for (bodyit = body.begin(); bodyit != body.end(); bodyit++) {
            if (bodyit->first == s.position.first && bodyit->second == s.position.second)
                return;
        }

        body.push_back(s.position);

        vector<pair<int, int>>::iterator appleit;
        if(!apples.empty()){
        for (appleit = apples.begin(); appleit != apples.end(); appleit++) {
            if (appleit->first == s.position.first && appleit->second == s.position.second) {
                apples.erase(appleit);
                break;
            }
            if (*appleit == apples.back()) {
                body.erase(body.begin());
            }
        }
        } else
            body.erase(body.begin());
    }
}

int main(void)
{
    cin>>N;
    cin>>K;
    for(int i=0;i<K;i++)
    {
        int x, y;
        cin>>y>>x;
        apples.push_back(make_pair(x,y));
    }
    cin>>L;
    for(int i=0;i<L;i++)
    {
        int s;
        char m;
        cin>>s>>m;
        moves.push_back(make_pair(s,m));
    }

    body.push_back(s.position);
    move();
    cout<<ans<<endl;

}
