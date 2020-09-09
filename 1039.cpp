#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int n, k, ans;
bool v[1000000][10];
int isUppercase(string& str) {
    for(int i = 0; i < str.length(); i++) {
        for(int j = i + 1; j < str.length(); j++)
            if(str[i] < str[j])
                return i;
    }
    return -1;
}
void dfs(string str, int d) {
    int num = atoi(str.c_str());
    if(d == k) {
        ans = max(ans, num);
        return ;
    }
    if(v[num][d]) return;
    v[num][d] = true;
    int start = isUppercase(str);
    string nString;
    if(start == -1) {
        for(int i = 1; i < str.length(); i++)
            if(str[i] == str[i-1]) {
                ans = max(ans, num);
                return ;
            }
        nString = str;
        swap(nString[nString.length()-1], nString[nString.length()-2]);
        dfs(nString, d+1);
        return;
    }
    for(int i = start; i < str.length(); i++)
        for(int j = i + 1; j < str.length(); j++) {
            nString = str;
            swap(nString[i], nString[j]);
            dfs(nString, d + 1);
        }
}
int main(){
    scanf("%d %d",&n, &k);
    if(n <= 10 || (n < 100 && !(n % 10))) {
        printf("-1");
        exit(0);
    }
    dfs(to_string(n),0);
    cout<<ans;
}
