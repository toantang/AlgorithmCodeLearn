#include <bits/stdc++.h>

using namespace std;

const int N = 17;
long long c[N];

void makeDefaultArray() {
    c[0] = 1;
    for (int i = 1; i <= 15; i++) {
        c[i] = pow(10, i) + c[i-1];
    }
}

void countNumbersBeautiful(long long a, long long b) {
    int ans = 0;

    if (b < 10) {
        ans = b - a + 1;
    }
    else {
        
        for (int i = 0; i <= 14; i++) {
            cout << "i: " << i << ", " << c[i] << endl;
            if (c[i] > b) {
                cout << "chay vao day break" << endl;
                break;
            }
            if (c[i] * 9 < a) {
                cout << "chay vao ham continue" << endl;
                continue;
            }
            int j = 1;
            long long val = 0;
            
            while(val < c[i+1] && j <= 9) {
                val = val + c[i];
                cout << "   val = " << val << endl;
                if (val >= a && val <= b) {
                    cout << "   j = " << j;
                    cout << ", val = " << val << endl;
                    ans++;
                }
                if (val > b) {
                    cout << "chay vao ham while nay" << endl;
                    break;
                }
                j++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    makeDefaultArray();
    for (int i = 0; i <= 14; i++) {
        cout << c[i] << endl;
    }
    long long a, b;
    a = 43, b = 123;
    a = 11, b = 20;
    a = 8, b = 12;
    a = 11, b = 11;
    a = 3543535, b = 453454353455;
    a = 1, b = 999999999999999;
    //a = 4, b = 8;
    countNumbersBeautiful(a, b);    
    //999 999 999 999 99
    //111 111 111 111 111
    //999 999 999 999 999
    //111 111 111 111 111
    return 0;
}