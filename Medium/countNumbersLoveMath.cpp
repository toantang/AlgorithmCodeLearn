#include <bits/stdc++.h>

using namespace std;

long long ans;

void countNumbersLoveMath(long long m, long long n, long long p) {
    if (m > n) {
        swap(m, n);
    }

    if (m <= p && n <= p) {
        ans = m + n - p;
    }
    if (n > p) {
        ans = m;
    }
} 
int main() {
    return 0;
}