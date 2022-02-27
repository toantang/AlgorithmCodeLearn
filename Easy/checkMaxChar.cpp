#include <bits/stdc++.h>

using namespace std;

int ans = INT_MIN;

void checkMaxChar(string str) {
    int len = str.size();
    for (int i = 0; i < len; i++) {
        if (str[i] > ans) {
            ans = str[i];
        } 
    }
}
int main() {
    return 0;
}