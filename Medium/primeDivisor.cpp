#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int countDivisor(int n) {
    int cnt = 0;
    int sign = false;
    for (int i = 2; i <= n; i++) {
        while(n%i == 0) {
            n = n/i;
            sign = true;
        }
        if (sign == true) {
            v.push_back(i);
            cnt++;
            sign = false;
        }
    }
    return cnt;
}
void primeDivisor(int a, int b, int k) {
    int ans = 0;
    for (int i = a; i <= b; i++) {
        if (countDivisor(i) == k) {
            cout << i << endl;
            ans++;
        }
    }
    cout << "ans = " << ans << endl;
}


bool checkPrime(int n) {
    if (n%2 == 0 || n%3 == 0 || n%5 == 0 || n%7 == 0) {
        return false;
    }
    int val = sqrt(n);
    for (int i = 2; i <= val; i++) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int a, b, k;
    a = 10, b = 13, k = 2;
    a = 2, b = 100000, k = 3;
    a = 2, b = pow(10, 7), k = 5;
    primeDivisor(a, b, k);
    return 0;
}