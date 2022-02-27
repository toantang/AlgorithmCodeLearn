#include <bits/stdc++.h>

using namespace std;

bool sumOfThree(string s) {
    int sum = 0;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        sum = sum + s[i] - '0';
    }
    if (sum%3 == 0) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    return 0;
}