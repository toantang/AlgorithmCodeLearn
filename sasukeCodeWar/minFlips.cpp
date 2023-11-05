#include <bits/stdc++.h>

using namespace std;

int minFlips(string str) {
    int len = str.size();
    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == '0' && str[i+1] == '0') {
            str[i+1] = '1';
            ans++;
        }
    }
    return ans;
}
int main() {
    return 0;
}