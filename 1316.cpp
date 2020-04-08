#include <iostream>
#include <string>
using namespace std;
bool group(string s) {
	bool use[26] = { false, };
	for (int i = 0; i < s.length(); ++i) {
		if (use[s[i] - 'a']) return false;
		if (i+1<s.length()&&s[i] == s[i + 1]) continue;
		use[s[i] - 'a'] = true;
	}
	return true;
}
int main() {
	int N, ans = 0;
	string s;
	cin >> N;
	while (N--) {
		cin >> s;
		if (group(s)) ++ans;
	}
	cout << ans;
}
