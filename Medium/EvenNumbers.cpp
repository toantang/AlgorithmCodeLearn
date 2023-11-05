#include <bits/stdc++.h>

using namespace std;

int evenNumbers(int N, int P) {
    int n = pow(2, N);
    if (P < n) {
        return 1;
    }
    if (P == n) {
        return 1;
    }
    return P/n * n;
}
int main() {
    return 0;
}