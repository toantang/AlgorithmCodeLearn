#include <bits/stdc++.h>

using namespace std;

char c[8] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
string ans = "";
int a[6];
int spt = 0;
void divisorNumber(int n) {
    int b[5];
    while(n != 0) {
        b[spt] = n%10;
        n = n/10;
        spt++;
    }
    for (int i = 0; i <= spt; i++) {
        a[i] = b[spt - 1 - i];
    }
}

int convert(int n, int value, int k) {
    int x = n/value;
    int i = 0;
    while(i < x) {
        ans = ans + c[k];
        i++;
    }
    n = n - x*value;
    return n;
}
void romanNumber(int n) {
    while(n != 0) {
        int i = 0;
        if (n >= 1000) {
            cout << "chay vao ham nay" << endl;
            n = convert(n, 1000, 0);
        }
        else if (n >= 500) {
            n = convert(n, 500, 1);
        }
        else if (n >= 100) {
            n = convert(n, 100, 2);
        }
        else if (n >= 50) {
            n = convert(n, 50, 3);
        }
        else if (n >= 10) {
            n = convert(n, 10, 4);
        }
        else if (n >= 5) {
            n = convert(n, 5, 5);
        }
        else {
            n = convert(n, 1, 6);
        }
    }
}
int main() {
    int n;
    n = 1234;
    romanNumber(n);
    cout << ans << endl;
    return 0;
}