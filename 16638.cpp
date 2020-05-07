#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int len;
bool garo[19];
string str;
pair<bool, int> ans;
string solution(char a, char b, char op){
    return op == '+' ? to_string(a-'0'+b-'0') : op == '-' ? to_string(a-b) : to_string((a-'0')*(b-'0'));
}
string solution(string a, string b, string op){
    return op == "+" ? to_string(stoi(a)+stoi(b)) : op == "-" ? to_string(stoi(a)-stoi(b)) : to_string(stoi(a)*stoi(b));
}
int solution(int a, string b, string op){
    return op == "+" ? a+stoi(b) : op == "-" ? a-stoi(b) : a*stoi(b);
}
string tostring(char c){
    switch (c){
        case '0' : return "0";
        case '1' : return "1";
        case '2' : return "2";
        case '3' : return "3";
        case '4' : return "4";
        case '5' : return "5";
        case '6' : return "6";
        case '7' : return "7";
        case '8' : return "8";
        case '9' : return "9";
        case '+' : return "+";
        case '-' : return "-";
        case '*' : return "*";
    }
}
void calc(){
    vector<string> ns, nss;
    for(int i = 0; i < len; ++i) {
        if (garo[i]) ns.emplace_back(solution(str[i], str[i + 2], str[i + 1])), i += 2;
        else ns.emplace_back(tostring(str[i]));
    }
    nss.emplace_back(ns[0].c_str());
    for(int i = 1; i < ns.size(); ++i){
        if(ns[i]=="*") nss.emplace_back(solution(nss.back(),ns[i+1],ns[i])),nss.erase(nss.end()-2), ++i;
        else nss.emplace_back(ns[i].c_str());
    }
    int ret = stoi(nss[0]);
    for(int i = 1; i < nss.size(); i+=2){
        ret = solution(ret,nss[i+1],nss[i]);
    }
    if(ans.first) ans.second = max(ans.second,ret);
    else ans.second = ret, ans.first = true;
}
void DFS(int cur){
    if(cur+1>=len){
        calc();
        return;
    }
    garo[cur] = true;
    DFS(cur+4);
    garo[cur] = false;
    DFS(cur+2);
}
int main(){
    ans.first = false, ans.second = 0;
    cin>>len>>str;
    DFS(0);
    cout<<ans.second;
}
