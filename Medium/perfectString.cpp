#include <bits/stdc++.h>
#define MAX 100

using namespace std;

char a[MAX];
char x[MAX];
string ans="";
int dem = 0;

void solve() {
    a[1] = 'x';
    a[2] = 'y';
    a[3] = 'z';
}
bool check(int v, int m) {
    if (a[v] != x[m-1]) {
        return true;
    }
    return false;
}

void TRY(int m, int k, int n) {
    for (int v = 1; v <= 3; v++) {
        if (check(v, m)) {
            x[m] = a[v];
            if (m == n) {
                dem++;
                if (dem == k) {
                    for (int i = 2; i <= n; i++) {
                        ans = ans + x[i];
                    }
                }
            }
            else {
                TRY(m+1, k, n);
            }
        }
    }
}
string perfectString(int n, int k) {
    int limit = pow(2, n-1);
    if (1 <= k && k <= limit) {
        x[1] = 'x';
    }
    else if (limit+1 <= k && k <= 2*limit) {
        k = k - limit;
        x[1] = 'y';
    }
    else if (2*limit+1 <= k && k <= 3*limit){
        k = k - 2*limit;
        x[1] = 'z';
    }
    else {
        return "";
    }

    ans = ans + x[1];
    if (n >= 2) {
        TRY(2, k, n);
    }
    return ans;
}

int main() {
    //int n = 1, k = 3;
    //int n = 1, k = 4;
    //int n = 3, k = 9;
    //int n = 2, k = 7;
    int n = 2, k = 2;
    solve();
    cout << perfectString(n, k) << endl;
    return 0;
}