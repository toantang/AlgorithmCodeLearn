//da xong
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int ans;
int a[MAX];
int f; // tổng hiện tại

bool check(int n, int v, int k) {
    if (f + v <= n && v > a[k-1] && v <= n - f) {
        return true;
    }
    return false;
}

void TRY(int n, int k) {
    for (int v = a[k-1] + 1; v <= n; v++) {
        if (check(n, v, k)) {
            a[k] = v;
            f = f + v;
            if (f == n) {
                for (int i = 0; i <= k; i++) {
                    cout << a[i] << " ";
                }
                cout << endl;
                ans++;
            }
            else {
                if (f + a[k] <= n) {
                    TRY(n, k + 1);
                }
            }

            f = f - v;
        }
    }
}

void countCaseArray(int n) {

}
int main() {
    int n;
    n = 99;
    //n = 33;
    //n = 25;
    //n = 6;
    for (int i = 1; i < n; i++) {
        a[0] = i;
        f = i;
        TRY(n, 1);
    }
    ans = ans + 1;
    cout << ans << endl;
    return 0;
}