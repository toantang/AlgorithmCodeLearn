#include <bits/stdc++.h>

using namespace std;

bool squareNumber(long long n) {
    int x = sqrt(n);
    if (x*x == n) {
        return true;
    }
    return false;
}
bool squaredDivided(long long n) {
    if (squareNumber(n)) {
        return true;
    }
    else {
        int m = sqrt(n);
        for (int i = 2; i < m; i++) {
            if (m%i == 0) {
                if (squareNumber(i)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    return 0;
}