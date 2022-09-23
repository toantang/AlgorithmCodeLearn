#include <bits/stdc++.h>

using namespace std;

vector<int> v;

bool checkPrime(int n) {
    if (n%2 == 0) {
        return false;
    }
    if (n%3 == 0) {
        return false;
    }
    if (n%5 == 0) {
        return false;
    }
    if (n%7 == 0) {
        return false;
    }

    int x = sqrt(n);
    for (int i = 2; i <= x; i++) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}

void find100Prime() {
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    int cnt = 4;
    int n = 11;
    while(cnt <= 100) {
        if (checkPrime(n)) {
            v.push_back(n);
            cnt++;
        }
        if (n%2 == 0) {
            n++;
        }
        else {
            n = n + 2;
        }
    }
}

int findNumber(int n) {
    return v[n-1] * n;
}
int main() {
    find100Prime();
    int n = 7;
    cout << findNumber(n);
    return 0;
}