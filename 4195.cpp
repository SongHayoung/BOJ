#include <iostream>
#include <map>
#include <set>

using namespace std;
int tc, n;
int fNum[200002], fSet[200002];
int getG(int num) {
    return fSet[num] == num ? num : fSet[num] = getG(fSet[num]);
}

int unionG(int f1, int f2) {
    int g1 = getG(f1);
    int g2 = getG(f2);
    if(g1 != g2) {
        fSet[g1] = g2;
        fNum[g2] += fNum[g1];
        fNum[g1] = 1;
    }
    return fNum[g2];
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>tc;
    while (tc--) {
        cin>>n;
        int cnt = 0;
        map<string, int> network;
        for(int i = 1; i <= n*2; i++) {
            fSet[i] = i;
            fNum[i] = 1;
        }
        string s1, s2;
        for(int i = 0; i < n; i++) {
            cin >> s1 >> s2;
            if(network.find(s1) == network.end())
                network[s1] = ++cnt;
            if(network.find(s2) == network.end())
                network[s2] = ++cnt;
            cout<<unionG(network[s1],network[s2])<<"\n";
        }
    }
}
