# pragma optimize("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <iostream>
#include <list>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    list<char> l;
    string data;
    char cmd;
    cin>>data;
    int m, pos = data.length();
    for(int i = 0; i < data.length(); ++i)
        l.push_back(data[i]);
    cin>>m;
    list<char>::iterator it = l.end();
    --it;
    for(int i = 0; i < m; ++i){
        cin>>cmd;
        switch (cmd) {
            case 'L':
                if(pos) --pos, --it; break;
            case 'D':
                ++it, ++pos;
                if(it == l.end()) --pos, --it; break;
            case 'B':
                if(pos) l.erase(it--), --pos;
                break;
            case 'P': cin>>cmd; l.insert(++it, cmd); --it; ++pos; break;
        }
    }
    for(char c : l)
        cout<<c;
}
