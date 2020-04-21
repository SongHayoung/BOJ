#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<string> ans;
int L, C;
bool alpha[26];
char c;
bool isCorrect(string cur){
    int jaum = 0, moum = 0;
    for(int i = 0; i < cur.length(); ++i){
        switch(cur[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++moum; break;
            default:
                ++jaum; break;
        }
    }
    return moum>=1&&jaum>=2;
}
void DFS(string cur){
    if(cur.length()==L){
        if(isCorrect(cur)) ans.push_back(cur);
        return;
    }
    for(int i = cur.length() > 0 ? cur[cur.length()-1]-'a'+1 : 0; i < 26; ++i){
        if(!alpha[i]) continue;
        switch(i){
            case 0 :  DFS(cur+"a"); break;
            case 1 :  DFS(cur+"b"); break;
            case 2 :  DFS(cur+"c"); break;
            case 3 :  DFS(cur+"d"); break;
            case 4 :  DFS(cur+"e"); break;
            case 5 :  DFS(cur+"f"); break;
            case 6 :  DFS(cur+"g"); break;
            case 7 :  DFS(cur+"h"); break;
            case 8 :  DFS(cur+"i"); break;
            case 9 :  DFS(cur+"j"); break;
            case 10 :  DFS(cur+"k"); break;
            case 11 :  DFS(cur+"l"); break;
            case 12 :  DFS(cur+"m"); break;
            case 13 :  DFS(cur+"n"); break;
            case 14 :  DFS(cur+"o"); break;
            case 15 :  DFS(cur+"p"); break;
            case 16 :  DFS(cur+"q"); break;
            case 17 :  DFS(cur+"r"); break;
            case 18 :  DFS(cur+"s"); break;
            case 19 :  DFS(cur+"t"); break;
            case 20 :  DFS(cur+"u"); break;
            case 21 :  DFS(cur+"v"); break;
            case 22 :  DFS(cur+"w"); break;
            case 23 :  DFS(cur+"x"); break;
            case 24 :  DFS(cur+"y"); break;
            case 25 :  DFS(cur+"z"); break;
        }
    }
}
int main() {
    scanf("%d %d",&L,&C);
    for(int i = 0; i < C; ++i){
        cin>>c;
        alpha[c-'a'] = true;
    }
    DFS("");
    sort(ans.begin(),ans.end());
    for(auto v : ans)
        cout<<v<<endl;
}
