#include <bits/stdc++.h>

using namespace std;

int UCLN(int a, int b) {
    while(a != b) {
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
    }
    return a;
}
int divideArray(vector<int> a, vector<int> b) {
    int lenA = a.size();
    int lenB = b.size();
    int bcnn = 0;
    if (lenB == 0) {
        return 0;
    }
    if (lenB == 1) {
        bcnn = b[0];
    }
    else {
        bcnn = lcm(b[0], b[1]);
        for (int i = 2; i < lenB; i++) {
            int ucln = UCLN(bcnn, b[i]);
            bcnn = bcnn/ucln * b[i];
        }
    }
    int ans = 0;
    for (int i = 0;  i < lenA; i++) {
        if (a[i]%bcnn == 0) {
            ans++;
        }
    }
    return ans;
}
int main() {
    return 0;
}