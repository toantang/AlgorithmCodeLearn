#include <bits/stdc++.h>

#define MAX 17
using namespace std;

int a[MAX];
long long c[MAX];
int spt = 0;
vector<long long> ans;
long long minNumber;
long long maxNumber = -1;

void solve() {
    c[0] = 1;
    for (int i = 1; i < 17; i++) {
        c[i] = c[i-1] * 10;
    }
}
void divideNumber(long long n) {
    int b[MAX];
    while(n != 0) {
        b[spt] = n%10;
        n = n/10;
        spt++;
    }
    for (int i = 0; i < spt; i++) {
        a[i] = b[spt - 1 - i];
    }
}

void TRY(long long n, int k, int start, int end, int m) {
    if (n > 0 && m > k) {
        n = n/10;
        end--;
        m--;
        if (m == k) {
            //cout << "n = " << n << endl;
            if (n > maxNumber) {
                maxNumber = n;
            }
            if (n < minNumber) {
                minNumber = n;
                
            }
        }
        else {
            TRY(n, k, start, end, m);
        }
        //cout << "n = " << n << ", m = " << m << ", end = " << end << endl;
        
        end++;
        m++;
        n = n*10 + a[end];
    }
    cout << "n = " << n << ", m = " << m << ", start = " << start << ", end = " << end << endl;
    //cout << "n = " << n << endl;
    if (n > 0 && m > k) {
        n = n - a[start] * c[m-1];
        start++;
        m--;
        if (m == k) {
            //cout << n << endl;
            if (n > maxNumber) {
                maxNumber = n;
            }
            if (n < minNumber) {
                minNumber = n;
                //cout << "minNumber = " << minNumber << endl;
            }
        }
        else {
            TRY(n, k, start, end, m);
        }
       // cout << "n = " << n << ", m = " << m << ", end = " << end << endl;
        start--;
        m++;
        n = n + a[start] * c[m-1];
    }

}
int main() {
    long long n; int k;
    n = 15423, k = 2;
    //n = 99, k = 1;
    solve();
    divideNumber(n);
    minNumber = n;
    TRY(n, k, 0, spt - 1, spt);
    cout << minNumber << ", " << maxNumber << endl;
    return 0;
}