#include <bits/stdc++.h>

using namespace std;

const int N = 11;
int a[N];
int spt;
int ans = 0;
vector<int> v;
void divisorNumber(int x) {
    int b[N];
    while(x != 0) {
        b[spt] = x%10;
        x = x/10;
        spt++;
    }
    for (int i = 0; i <= spt; i++) {
        a[i] = b[spt - 1 - i];
    }
}

bool check(int x, int val) {
    bool sign;

    for (int i = 0; i < spt; i++) {
        int uoc = val;
        while(uoc != 0) {
            int m = uoc%10;
            if (m == a[i]) {
                return true;
            }
            uoc = uoc/10;
        }
    }
    return false;
}
void countNumber(int x) {
    int m = sqrt(x);
    cout << "m = " << m << endl;
    if (x%m == 0) {
        if (check(x, m)) {
            ans++;
        }
    }
    cout << "ans = " << ans << endl;
    for (int i = 1; i < m; i++) {
        if (x%i == 0) {            
            v.push_back(i);
            if (check(x, i)) {
                cout << "i = " << i << endl;
                ans++;
            }
        }
    }

    int len = v.size();
    for (int i = 0; i < len; i++) {
        int val = v[i];
        int value = x/val;
        if (check(x, value)) {
            cout << "value = " << value << endl;
            ans++;
        }
    }
}
int main() {
    int x;
    x = 57249856;
    x = 25;
    x = 16;
    divisorNumber(x);
    countNumber(x);
    cout << ans << endl;
    return 0;
}