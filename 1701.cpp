#include <iostream>
#include <vector>
using namespace std;
vector<int> kmptable(string &str) {
    int len = str.length(), j = 0;
    vector<int> table(len, 0);
    for(int i = 1; i < len; i++) {
        while(j && str[i] != str[j])
            j = table[j-1];
        if(str[i] == str[j])
            table[i] = ++j;
    }
    return table;
}
bool kmp(string &s, string &p) {
    int ret = 0;
    auto table = kmptable(p);
    int n = s.size(), m = p.size(), j = 0;
    for(int i = 0; i < n; i++) {
        while (j && s[i] != p[j])
            j = table[j - 1];
        if (s[i] == p[j])
            if(j == m-1) {
                ret++;
                j = table[j];
                if(ret >= 2) return true;
            }  else
                j++;
    }
    return false;
}

int binarysearch(string& s) {
    int l = 0, r = s.length(), m, ans = 0;
    while(l < r) {
        bool find = false;
        m = (l + r) / 2;
        for(int i = 0; i < s.length() - m && !find; i++)
            find = kmp(s, s.substr(i,m));
        if(find) {
            l = m + 1;
            ans = max(ans, m);
        } else {
            r = m;
        }
    }
    return ans;
}
int main(int argc, char** argv){
    string str;
    cin>>str;
    cout<<binarysearch(str);
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
