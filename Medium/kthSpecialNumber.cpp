#include <bits/stdc++.h>

using namespace std;

const int N = 10;
const int c = 100000000;
int f = 0;
int a[N];

int findNums(int k, int len) {
    int val = 
}
bool check(int v, int m) {
    return true;
}

void TRY(int m, int n, vector<int> arr, int len) {
    for (int v = 0; v < len; v++) {
        if (check(v, m)) {
            a[m] = arr[v];
            m++;
            if (m == len) {
                for (int i = 0; i <= m; i++) {
                    cout << a[i];
                }
                cout << endl;
            }
            else {
                TRY(m, n, arr, len);
            }

            m--;

        }
    }
}
string kthSpecialNumber(std::vector<int> arr, int k) {
    return "nhgs";
}
int main() {
    int x = pow(10, 8);
    cout << x << endl;
    return 0;
}