#include <bits/stdc++.h>

using namespace std;

int ans = 0;
void minConvert(int n, int m)
{
    while(m > n) {
        if (m%2 == 0) {
            m = m /2;
        }
        else {
            m = m + 1;
        }
        ans++;
    }
    while(m < n) {
        m = m + 1;
        ans++;
    }
}

int main() {
    int n, m;
    //n = 2, m = 3;
    //n = 2, m = 6;
    //n = 2, m = 100;
    //n = 56, m = 39;
    n = 46, m = 58;
    minConvert(n, m);
    cout << ans << endl;
    return 0;
}