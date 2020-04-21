#include <stdio.h>
#include <vector>
using namespace std;
int target, a, b, ans, atotal, btotal, startpos;
vector<int> A(1000), B(1000), apossible(1000000), bpossible(1000000);
void DFS(int curpos, long cur, vector<int> &vec, vector<int> &possible, int &sz){
    if(cur>target||(curpos+1)%sz==startpos) return;
    ++possible[cur];
    DFS((curpos+1)%sz, cur+vec[(curpos+1)%sz], vec, possible, sz);
}
int main() {
    scanf("%d %d %d", &target, &a, &b);
    for(int i = 0; i < a; ++i) scanf("%d",&A[i]), atotal+=A[i];
    for(int i = 0; i < b; ++i) scanf("%d",&B[i]), btotal+=B[i];
    apossible[0] = bpossible[0] = apossible[atotal] = bpossible[btotal] = 1;
    for(; startpos < a || startpos<b; ++startpos) {
        if(startpos<a) DFS(startpos, A[startpos], A, apossible, a);
        if(startpos<b) DFS(startpos, B[startpos], B, bpossible, b);
    }
    for(int i = 0; i <= target; ++i)
        ans += apossible[i] * bpossible[target - i];
    printf("%d",ans);
    
}
