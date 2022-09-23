#include <bits/stdc++.h>
#define N 1005
using namespace std;

string a[N][N];

string convertString(int sub) {
    int i = 1;
    string p;
    while(i <= sub) {
        p = p + "0";
        i++;
    }
    return p;
}
string addNumber(string x, string y) {
    string sum = "";

    int lenX = x.size();
    int lenY = y.size();
    int balance = 0;
    int len = lenX;
    if (lenX > lenY) {
        y = convertString(lenX - lenY) + y;
        len = lenX;
    }
    if (lenX < lenY) {
        x = convertString(lenY - lenX) + x;
        len = lenY;
    }

    for (int i = len - 1; i >= 0; i--) {
        int a = x[i] - 48;
        int b = y[i] - 48;
        int val = a + b + balance;
        char num;
        if (val >= 10) {
            val = val%10;
            balance = 1;
        }
        else {
            balance = 0;
        }
        if (val == 0) {
            num = '0';
        }
        num = val + '0';
        sum = num + sum;
    }
    if (balance == 1) {
        sum = "1" + sum;
    }
    return sum;
}


void C(int k, int n) {
    if (k == n || k == 0) {
        a[k][n] = "1";
    }
    if (a[k][n] == "-1") {
        C(k-1, n-1);
        C(k, n - 1);
        a[k][n] = addNumber(a[k-1][n-1], a[k][n-1]);
    }
}
int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = "-1";
        }
    }

    int k, n;
    k = 500;
    n = 1000;
    C(k, n);
    cout << a[k][n] << endl;
    return 0;
}


