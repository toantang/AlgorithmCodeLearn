#include <bits/stdc++.h>

using namespace std;
const int N = 10000005;
int a[N];
int maxVal = 0;
int ans = 0;

bool checkPrime(int n) {
    int x = sqrt(n);
    for (int i = 2; i <= x; i++) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}

int sumNumber(int n) {
    int sum = 0;
    if (n < 10) {
        return n;
    }
    while(n != 0) {
        sum = sum + n%10;
        n = n/10;
    }
    return sum;
}
void smithNumber(int n) {
    int value = n;
    for (int i = 2; i <= n; i++) {
        while(value%i == 0) {
            if (i > maxVal) {
                maxVal = i;
            }
            a[i]++;
            value = value/i;
        }
        
    }

    for (int i = 0; i <= maxVal; i++) {
        if (a[i] != 0) {
            ans = ans + a[i] * sumNumber(i);
        }
    }
    if (ans == sumNumber(n)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
int main() {
    int n;
    n = 4;
    //n = 22;
    n = 58;
    smithNumber(n);
    cout << ans << endl;
    return 0;
}