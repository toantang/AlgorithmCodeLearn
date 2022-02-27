#include <bits/stdc++.h>

using namespace std;

const int N = 12;
const int C = 1000000000;
bool checkNum(int n) {
    int a[N];
    int spt = 0;
    while (n != 0) {
        a[spt] = n%10;
        n = n/10;
        spt++;
    }
    cout << "spt = " << spt << endl;
    for (int i = 1; i < spt - 1; i++) {
        cout << (a[i] - a[i-1]) * (a[i+1] - a[i]) << endl;
        if ((a[i] - a[i-1]) * (a[i+1] - a[i]) < 0) {
            return false;
        }
    }
    return true;
}


int findNumber(int n) {
    if (n <= 100) {
        return n;
    }
    for (int i = n; i <= C; i++) {
        if (checkNum(i)) {
            return i;
        }
    }
    return 0;
}
int main() {
    int n;
    n = 525439867;
    cout << findNumber(n) << endl;
    return 0;
}