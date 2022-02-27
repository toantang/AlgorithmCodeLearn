#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int prime[MAX]; // mang chua cac so nguyen to
int k = 0;
int e[MAX]; //mang luu so mu cua prime[i]

int divisor = 0;
int f;
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

void solve() {
    for (int i = 2; i <=  41; i++) {
        if (checkPrime(i)) {
            prime[k] = i;
            k++;
        }
    }
}

void analyzePrime(int n) {
    for (int i = 0; i < k; i++) {
        int x = prime[i];
        while(n%x == 0) {
            ++e[i];
            n /= x;
        }
        f = f * (e[i] + 1);
    }
}

void antiPrimes(int n) {
    for (int i = n; i >= 2; i--) {
        f = 1;
        for (int j = 0; j < k; j++) {
            e[j] = 0;
        }       
        analyzePrime(i);
        if (divisor < f) {
            divisor = f;
            ans = i;
        }
    }
}
int main() {
    int n;
    n = 9;
    //n = 2;
    //n = 17;
    //n = 11;
    //n = 59;
    //n = 71;
    //n = 83;
    solve();
    antiPrimes(n);
    cout << ans << endl;
    return 0;
}
