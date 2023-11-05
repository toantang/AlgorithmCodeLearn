#include <bits/stdc++.h>

using namespace std;

const int C = 1000000007;
unsigned long long a[1000005];

int countWays(int n) {
    for (int i = 3; i <= n; i++) {
        int x = a[i-1]%C;
        x = (2*x)%C;
        int y = a[i-2]%C;
        a[i] = (x+y)%C;
    }
    return a[n];
}
int main() {
    a[1] = 3;
    a[2] = 7;
    int n = 25;
    n = 1000000;
    //unsigned long long x = count(n);
    cout << countWays(n) << endl;
    return 0;
}