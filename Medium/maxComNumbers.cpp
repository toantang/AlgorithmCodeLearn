#include <bits/stdc++.h>

using namespace std;

int maxComNumbers(long long n) {
    if (n <= 2) return -1;
    else if(n == 4) return 1;
    else if (n == 5 || n == 7) return -1;
    else if (n == 6) return 1;
    else if (n%4 == 0 || n%4 == 2) {
        return n/4;
    }
    else if (n%4 == 1 || n%4 == 3) {
        return (n/4) - 1;
    }
    return -1;
}

int main() {
    long long a[] = {8, 5, 215, 77, 9993};
    for (long long i = 0; i < 5; i++) {
        cout << maxComNumbers(a[i]) << endl;
    }
    return 0;
}