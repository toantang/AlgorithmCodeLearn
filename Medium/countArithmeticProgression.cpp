#include <bits/stdc++.h>

using namespace std;

long long countArithmeticProgression(int n, int m) {
    long long ans = 0;

    int maxD = (n-1)/(m-1);
    long long val = maxD * (maxD + 1)/2;
    unsigned long long value = (m-1) * val;
    ans = n * maxD - value;
    return ans;
}
int main() {
    int n, m;
    n = 4, m = 4;
    m = pow(10,  9);
    n = 10;
    cout << countArithmeticProgression(n, m);
    return 0;
}