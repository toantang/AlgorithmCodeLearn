#include <bits/stdc++.h>

using namespace std;

int c[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
const int N = 10;
vector<int> ans;
int f = 0;
int a[N];
bool check(int m, int v, int n, int k) {
    if (a[m-1] + k == v || a[m-1] - k == v) {
        return true;
    }
    return false;
}
void TRY(int m, int n, int k) {
    for (int v = 0; v <= 9; v++) {
        if (check(m, v, n, k)) {
            a[m] = v;
            f += c[n-1-m] * a[m];
            m++;
            if (m == n) {
                //cout << f << endl;
                ans.push_back(f);
            }
            else {
                TRY(m, n, k);
            }

            m--;
            f -= c[n-1-m] * a[m];
        }
    }
}
void createNumber(int n, int k) {
   //int val = 9-k;
   for (int i = 1; i <= 9; i++) {
       f = 0;
       a[0] = i;
       f += a[0] * c[n-1];
       TRY(1, n, k);
   }
}
int main() {
    //int n = 3, k = 7;
    //int n = 2, k = 1;
    //int n = 3, k = 4;
    //int n = 4, k = 5;
    //int n = 2, k = 5;
    int n = 1, k = 7;
    createNumber(n, k);
    int len = ans.size();
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " ";
    }
    return 0;   
}