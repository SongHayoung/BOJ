#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
#define MAXNUM 10000000
bool is_Prime[5000001];
bool isPall(int n) {
    string num = to_string(n);
    int maxn = num.length()>>1;
    for(int i = 0; i <= maxn; i++) {
        if(num[i] != num[num.length()-1-i])
            return false;
    }
    return true;
}
int main(int argc, char** argv){
    int n;
    memset(is_Prime,true,sizeof(is_Prime));
    is_Prime[0] = false;
    scanf("%d",&n);
    if(n<=2) {
        printf("2");
        exit(0);
    }
    for(int i=3; i*i<=MAXNUM;i+=2){
        if(is_Prime[i>>1]){
            for(int j = i*i; j<=MAXNUM; j += (i<<1))
                is_Prime[j>>1] = false;
        }
    }
    for(int i=3;i<=MAXNUM; i+=2){
        if(i >= n && is_Prime[i>>1] && isPall(i)) {
            printf("%d",i);
            exit(0);
        }
    }
}
