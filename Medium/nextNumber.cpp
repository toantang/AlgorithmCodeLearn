#include <bits/stdc++.h>

using namespace std;

const int N = 17;
long long c[N];

void makeDefaultArray() {
    c[0] = 1;
    for (int i = 1; i <= 15; i++) {
        c[i] = pow(10, i) + c[i-1];
    }
}

long long nextNumber(long long n) {
    for (int i = 0; i <= 15; i++) {
        if (c[i] * 9 < n) {
            continue;
        }
        int val = 0;
        int j = 1;
        while(j <= 9) {
            val = val + c[i];
            if (val >= n) {
                return val;
            }
            j++;
        }
    }
}
int main() {
    return 0;
}