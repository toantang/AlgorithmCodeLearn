#include <bits/stdc++.h>

using namespace std;

int functionsNumber(long long n) {
    if (n < 10) {
        return 1;
    }
    int ans = 1;
    for (int i = 10; i <= n; i = i * 10) {
        ans++;
    }
    return ans;
}
int main() {
    return 0;
}