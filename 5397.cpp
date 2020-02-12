#include <iostream> 
#include <list>
#include <string>
#pragma warning(disable:4996)  
using namespace std;

int main() {
	int T; cin >> T;
	for(int i=0;i<T;i++){
		string L; cin >> L;
		list<char> keylog;
		list<char>::iterator it = keylog.begin();
		int len = L.size();
		for(int j=0;j<len;j++){
			switch (L[j]) {
			case '<':
				if (it != keylog.begin())
					it--;
				break;
			case '>':
				if (it != keylog.end())
					it++;
				break;
			case '-':
				if (it != keylog.begin())
					keylog.erase((--it)++);
				break;
			default:
				keylog.insert(it, L[j]);
				break;
			}
		}
		for (auto c : keylog)
			printf("%c", c);
		printf("\n");
	}
	return 0;
}
