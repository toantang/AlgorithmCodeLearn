#include <bits/stdc++.h>
#define MAX 17
using namespace std;

long long c[MAX];
int a[MAX];
int k = 0;
int x[MAX];
long long ans = -1;

void solve() {
    c[0] = 1;
    for (int i = 1; i <= 16; i++) {
        c[i] = c[i-1]*10;
    }
}

void divideNumber(long long n) {
    int b[MAX];
    while(n > 0) {
        b[k] = n%10;
        n = n/10;
        k++;
    }
    for (int i = 0; i < k; i++) {
        a[i] = b[k-1-i];
    }
}

void TRY(int m, int n) {
    int start = k - 1 - m;
    int end = x[m-1] - 1;
    if (start < a[m]) {
        start = a[m];
    }
    for (int i = start; i <= end; i++) {
        x[m] = i;
        if (m == k-1) {
            ans = 0;
            for (int i = 0; i < k; i++) {
                long long number = x[i]*c[k-1-i];
                ans = ans + number;
                //cout << ans << " ";
            }
            if (ans > n) {
                break;
            }
        }
        else {
            TRY(m+1, n);
        }
    }
}

bool checkReuctionNumber() {
    for (int i = 1; i < k; i++) {
        if (a[i] != a[i-1] - 1) {
            return false;
        }
    }
    return true;
}

void reductionNumber(long long n) {
    x[0] = a[0];
    bool check = checkReuctionNumber();
    for (int i = 1; i < k; i++) {
        cout << a[i] << endl;
        if (a[i] > a[0] - i || check) {
            if (check == true) {
                cout << "check true";
            }
            x[0] = x[0] + 1;
            cout << "vao ham nay" << endl;
            break;
        }       
    }

    if (k == 0) {
        ans = -1;
    }
    else if (k == 1) {
        ans = a[0] + 1;
    }
    else if (x[0] == a[0]) {
        TRY(1, n);
    }
    else {
        if (x[0] < k - 1) {
            ans = -1;
        }
        else {
            x[k-1] = 0;
            if (k >= 2) {
                for (int i = k - 2; i >= 1; i--) {
                    x[i] = x[i+1] + 1;
                }
            }

            ans = 0;
            for (int i = 0; i < k; i++) {
                long long number = x[i]*c[k-1-i];
                ans = ans + number;
            }
        }

        
    }
}

int main() {
    long long n;
    //n = 6;
    //n = 123;
    //n = 321; //false
    //n = 4543;
    //n = 65467;
    //n = 665623;
    //n = 765764;
    //n = 45758;
    //n = 983; true
    n = 75324;
    solve();
    divideNumber(n);
    reductionNumber(n);
    cout << ans << endl;
    return 0;
}