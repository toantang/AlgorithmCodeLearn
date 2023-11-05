#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int a[MAX];
int k = 0;
int UCLN(int a, int b) {
    while(a != b) {
        if (a > b) {
            a = a- b;
        }
        else {
            b = b - a;
        }
    }

    return a;
}

int BCNN(int a, int b) {
    int ucln = UCLN(a, b);
    int x = a/ucln;
    return x*b;
}

void LCM(int n) {
    a[1] = 1;
    for (int i = 2; i <= n; i++) {
        a[i] = BCNN(i, a[i-1]);
    }
}
int main() {
    int n;
    //n = 10;
    //n = 2;
    //n = 5;
    n = 22;
    LCM(n);
    cout << a[n] << endl;
    return 0;
}