#include <bits/stdc++.h>

using namespace std;

const int N = 256;
string ans;
int a[N];

void findTheSame(string s) {
    int len = s.size();
    for (int i = 0; i < len; i++) {
        int val = s[i];
        a[val]++;
    }
    for (int i = 0; i < len; i++) {
        char val = s[i];
        int x = a[val];
        if (x > 1) {
            while(x != 0) {
                ans = ans + val;
                x--;
            }
            break;
        }
    }
}
int main() {
    string s;
    s = "fpt30namtienphong";
    findTheSame(s);
    cout << ans << endl;
    return 0;
}