#include <iostream>
#define pc(x) putchar_unlocked(x)
#define gc() getchar_unlocked()
using namespace std;
int increment[1399];
int n, d, z, o;
int fri(){
    int N = gc(), ret = 0;
    do{
        ret = (ret<<3) + (ret<<1) + (N & 0b1111);    N=gc();
    }while('0'<=N&&N<='9');
    return ret;
}
inline void fri (int n){
    if (n == 0) { pc('0'); pc(' '); return ;}
    if (n<0) { n = -n; pc('-');}
    int N = n, rev, count = 0;
    rev = N;
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 | 0b110000); rev /= 10;}
    while (count--) pc('0');
    pc(' ');
}
int main() {
    n = fri(), d = fri();
    for(int k = 0; k < d; k++){
        z = fri(), o = fri(), fri();
        increment[z]++;
        increment[z + o]++;
    }
    for(int i = 1; i < 2 * n + 1; i++)
        increment[i] += increment[i-1];
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            fri(!j ? increment[n - i - 1] + 1 : increment[n + j - 1] + 1);
        pc('\n');
    }
}
