#include <iostream>
#include <algorithm>
using namespace std;

int n, m, num, standard, minA = 987654321, minB = 987654321;
int A[1000], B[1000];

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &num);
            B[j] += i == 0 || i == n - 1 ? num : num<<1;
            A[i] += j == 0 || j == m - 1 ? num : num<<1;
        }
    }
    standard = B[0] + B[m-1];
    for (int i = 1; i < m - 1; ++i)
        minB = min(minB, B[i]), standard += B[i] << 1;

    for (int i = 1; i < n - 1; ++i)
        minA = min(minA, A[i]);

    printf("%d", max(standard, standard + max(max(A[0], A[n - 1]) - minA, max(B[0], B[m - 1]) - minB)));
}
