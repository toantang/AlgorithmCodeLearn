#include <bits/stdc++.h>

using namespace std;

int ans;
int len = 0;
vector<int> v;

void multiplyTable(int n, int k) {
    int x = sqrt(k);

    if (x * x == k) {
        if (x <= n) {
            ans++;
        }
        for (int i = 1; i < x; i++) {
            if (k%i == 0) {
                if (i <= n && k/i <= n) {
                    len++;
                }
            }
        }
    }
    else {
        for (int i = 1; i <= x; i++) {
            if (k%i == 0) {
                if (i <= n && k/i <= n) {
                    len++;
                }
            }
        }
    }
}
int main() {
    int n, k;
    n = 100000, k = 1000000000;
    multiplyTable(n, k);
    cout << "ans = " << ans << ", len = " << len << endl;
    cout << ans + len*2 << endl;
    return 0;
}