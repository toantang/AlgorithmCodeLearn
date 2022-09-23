#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
    while(a != b) {
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    return a;
}
int gcdOfNumbers(std::vector<int> a) {
    int len = a.size();
    if (len == 0) {
        return 0;
    }
    if (len == 1) {
        return a[0];
    }
    int gcd = GCD(a[0], a[1]);
    for (int i = 2; i < len; i++) {
        gcd = GCD(gcd, a[i]);
    }
    return gcd;
}
int main() {
    return 0;
}