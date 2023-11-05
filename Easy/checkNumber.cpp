#include <bits/stdc++.h>

using namespace std;

int chechNumber(string s) {
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] < 45 || s[i] > 67) {
            return 0;
        }
    }
    return 1;
}
int main() {
    return 0;
}