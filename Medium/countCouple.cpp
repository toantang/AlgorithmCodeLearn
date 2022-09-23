#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000005;
int v[MAX];
int ans = 0;
int maxValue = INT_MIN;

void countCouple(vector<int> a) {
    int len = a.size();
    if (len <= 1) {
        ans = 0;
    }
    else {
        for (int i = 0; i < len; i++) {
            int val = a[i];
            v[val] += 1;
            if (val > maxValue) {
                maxValue = val;
            }
        }

        for (int i = 0; i < maxValue; i++) {
            if (v[i] != 0) {
                ans = ans + v[i]/2;
            }
        }
    }
}
int main() {
    return 0;
}