#include <bits/stdc++.h>

using namespace std;

int ans;

bool checkPrime(int i) {
    if (i%2 == 0 || i%3 == 0 || i%5 == 0 || i%7 == 0) {
        return false;
    }
    
    int x = sqrt(i);
    for (int j = 2; j <= x; j++) {
        if (i%j == 0) {
            return false;
        }
    }

    while(i != 0) {
        int v = i%10;
        if (v != 2 && v != 3 && v != 5 && v != 7) {
            return false;
        }
        i = i/10;
    }
    return true;
}
void primeDigits(int n) {
    if (n == 2) {
        ans = 1;
    }
    else if (n <= 3) {
        ans = 2;
    }
    else if (n <= 5) {
        ans = 3;
    }
    else if (n >= 7) {
        ans = 4;
    }
    
    for (int i = 23; i <= n; i++) {
        if (checkPrime(i)) {
            cout << i << endl;
            ans++;
        }
    }
}
int main() {
    int n;
    n = 1000000;
    primeDigits(n);
    cout << ans << endl;
    return 0;
}