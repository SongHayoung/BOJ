#include <iostream>
#include <memory.h>
#include <queue>
#include <list>
using namespace std;
int u, v, tc, root;
list<int> out[1000];
bool isVisited[1000];
bool isRoot[1000];
bool isActive[1000];
bool flag;
queue<int> q;
void init() {
    for(int i = 0; i < 1000; ++i)
        out[i].clear();

    memset(isRoot, true, sizeof(isRoot));
    memset(isVisited, false, sizeof(isRoot));
    memset(isActive, false, sizeof(isActive));

    flag = true;

    while(!q.empty()) q.pop();
}

int getRoot() {
    int ret = -1;
    for(int i = 0; i < 1000; ++i) {
        if(!isActive[i]) continue;
        if(isRoot[i] && ret == -1) {
            ret = i;
        }
        else if(isRoot[i] && ret != -1) {
            flag = false;
            return -1;
        }
    }
    if(ret == -1) flag = false;
    return ret;
}
int main(void) {
    while(true) {
        scanf("%d %d", &u, &v);
        if(u == -1) break;
        init();
        if(u != 0) {

            while (u) {
                out[u].push_back(v);
                isRoot[v] = false;
                isActive[v] = isActive[u] = true;
                scanf("%d %d", &u, &v);
            }

            root = getRoot();
            if (flag) {
                q.push(root);
                isVisited[root] = true;
                while (!q.empty() && flag) {
                    int n = q.front();
                    q.pop();
                    for (int val : out[n]) {
                        if (isVisited[val]) {
                            flag = false;
                            break;
                        }
                        isVisited[val] = true;
                        q.push(val);
                    }
                }
            }

            for (int i = 0; i < 1000 && flag; ++i) {
                if (isActive[i] && !isVisited[i]) flag = flag;
            }
        }

        if(flag) {
            cout<<"Case "<<++tc<<" is a tree.\n";
        } else {
            cout<<"Case "<<++tc<<" is not a tree.\n";
        }
    }
}