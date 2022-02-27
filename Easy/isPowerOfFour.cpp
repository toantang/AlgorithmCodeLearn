#include <bits/stdc++.h>

using namespace std;

bool isPowerOfFour(long long n) {
    if (n < 4) {
        return false;
    }
    while(n%4 == 0) {
        n = n/4;
    }
    if (n == 1) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    return 0;
}