#include <iostream>
#include <memory.h>
#include <cmath>
#include <stack>
using namespace std;
long dp[10][10][2];
bool visit[10][10];
string str;
int setPostfix(string str) {
    stack<int> s;
    stack<char> op;
    for(int i = 0; i < str.length(); i++) {
        if ('0' <= str[i] && str[i] <= '9') {
            s.push(str[i] & 0b1111);
        }
        else {
            if(op.empty()) {
                op.push(str[i]);
            } else {
                if(op.top() == '*' && str[i] != '*') {
                    int a, b;
                    a = s.top();
                    s.pop();
                    b = s.top();
                    s.pop();
                    s.push(a * b);
                    op.pop();
                }
                if(!op.empty() && op.top() == '-') {
                    int a = s.top();
                    a *= -1;
                    s.pop();
                    s.push(a);
                    op.pop();
                    op.push('+');
                }
                op.push(str[i]);
            }
        }
    }
    while(!op.empty()) {
        int a, b;
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();
        switch (op.top()) {
            case '+' : s.push(b + a); break;
            case '-' : s.push(b - a); break;
            case '*' : s.push(b * a); break;
        }
        op.pop();
    }
    return s.top();
}
pair<long,long> calc(int f, int e) {
    if(visit[f][e]) return make_pair(dp[f][e][0],dp[f][e][1]);
    visit[f][e] = true;
    dp[f][e][0] = dp[f][e][1] = setPostfix(str.substr(2*f, (e-f)*2+1));
    for(int i = f; i < e; i++){
        switch (str[i*2+1]) {
            case '+' :
                dp[f][e][0] = max(dp[f][e][0], max(calc(f,i).first, calc(f,i).second) + max(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][0] = max(dp[f][e][0], max(calc(f,i).first, calc(f,i).second) + min(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][0] = max(dp[f][e][0], min(calc(f,i).first, calc(f,i).second) + max(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][0] = max(dp[f][e][0], min(calc(f,i).first, calc(f,i).second) + min(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][1] = min(dp[f][e][1], max(calc(f,i).first, calc(f,i).second) + max(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][1] = min(dp[f][e][1], max(calc(f,i).first, calc(f,i).second) + min(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][1] = min(dp[f][e][1], min(calc(f,i).first, calc(f,i).second) + max(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][1] = min(dp[f][e][1], min(calc(f,i).first, calc(f,i).second) + min(calc(i+1,e).first,calc(i+1,e).second)); break;
            case '-' :
                dp[f][e][0] = max(dp[f][e][0], max(calc(f,i).first, calc(f,i).second) - max(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][0] = max(dp[f][e][0], max(calc(f,i).first, calc(f,i).second) - min(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][0] = max(dp[f][e][0], min(calc(f,i).first, calc(f,i).second) - max(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][0] = max(dp[f][e][0], min(calc(f,i).first, calc(f,i).second) - min(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][1] = min(dp[f][e][1], max(calc(f,i).first, calc(f,i).second) - max(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][1] = min(dp[f][e][1], max(calc(f,i).first, calc(f,i).second) - min(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][1] = min(dp[f][e][1], min(calc(f,i).first, calc(f,i).second) - max(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][1] = min(dp[f][e][1], min(calc(f,i).first, calc(f,i).second) - min(calc(i+1,e).first,calc(i+1,e).second)); break;
            case '*' :
                dp[f][e][0] = max(dp[f][e][0], max(calc(f,i).first, calc(f,i).second) * max(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][0] = max(dp[f][e][0], max(calc(f,i).first, calc(f,i).second) * min(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][0] = max(dp[f][e][0], min(calc(f,i).first, calc(f,i).second) * max(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][0] = max(dp[f][e][0], min(calc(f,i).first, calc(f,i).second) * min(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][1] = min(dp[f][e][1], max(calc(f,i).first, calc(f,i).second) * max(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][1] = min(dp[f][e][1], max(calc(f,i).first, calc(f,i).second) * min(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][1] = min(dp[f][e][1], min(calc(f,i).first, calc(f,i).second) * max(calc(i+1,e).first,calc(i+1,e).second));
                dp[f][e][1] = min(dp[f][e][1], min(calc(f,i).first, calc(f,i).second) * min(calc(i+1,e).first,calc(i+1,e).second)); break;
        }
    }
    return make_pair(dp[f][e][0],dp[f][e][1]);
}
int main() {
    int n;
    cin>>n>>str;
    cout<<max(calc(0,(str.length()-1)/2).first, calc(0,(str.length()-1)/2).second);
}
