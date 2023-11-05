#include <bits/stdc++.h>

using namespace std;

const int c = 1000000007;

int UCLN(long long a, long long b) {
    while(a != b) {
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
    }
    return a;
}

long long caculate(long long n, long long u1, long long d) {
    long long val = n * (n-1)/2;
    val = val * d;
    return n * u1 + d;
}
int sumDivOfAandB(long long n, long long a, long long b) {
    long long ucln = UCLN(a, b);
    long long bcnn = (a/ucln) * b;
    unsigned long long ans;

    long long na = n/a;
    long long nb = n/b;
    long long nab = n/bcnn;
    ans = caculate(na, a, a)%c + caculate(nb, b, b)%c - caculate(nab, nab, nab)%c;
    return ans;
}
int main() {
    return 0;
}