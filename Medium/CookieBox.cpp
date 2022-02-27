#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

int m, n;
int f = INT_MAX; //chu vi nhỏ nhất tìm được ở hiện tại

void findEdge(int val) {
    int x = sqrt(val);
    
    for(int i = x; i >= 2; i--) {
        if (val%i == 0) {
            cout << "   i = " << i << endl;
            int y = val/i;
            //cout << "x = " << x << ", i = " << i << endl;
            if (y + i < f) {
                f = y + i;
                m = i;
                n = y;
            }
            else if (x + i == f) {
                if (m > i) {
                    m = i;
                    n = y;
                }
            }
            cout << "   f = " << f << endl;
            //cout << "m = " << m << ", n = " << n << endl;
            break;
        }
    }
}
void cookieBox(int s) {
    for (int v = 0; v <= s; v++) {
        int val = sqrt(s + v);
        if (f > 2*sqrt(s + v)) {
            cout << "v = " << v << ": " << endl;
            findEdge(s + v);
        }
        else {
            break;
        }
    }
}
int main() {
    int s;
    s = 7;
    //s = 31;
    //s = 1000000000;
    //s = 0;
    cookieBox(s);
    cout << "m = " << m << ", n = " << n << endl;
    return 0;
}