#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int ans;
//int countOne = 0;
int a[N];
int spt = 0;

int convertBinary(int n) {
    spt = 0;
    int countOne = 0;
    while(n != 0) {
        a[spt] = n%2;
        if (a[spt] == 1) {
            countOne++;
        }
        spt++;
        n = n/2;
    }
    for (int i = 0; i < spt; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return countOne;
}

void maxBits(int n) {
    int val = convertBinary(n);
    for (int i = n + 1; i <= 1000; i++) {
        if (convertBinary(i) == val) {
            break;
        }
    }

    for (int i = 0; i < spt; i++) {
        if (a[i] != 0) {
            ans = ans + pow(2, i);
        }
    }
    cout << ans << endl;
}
int main() {
    int n;
    n = 56;
    maxBits(n);
    return 0;
}