#include <bits/stdc++.h>

using namespace std;

int duplicateNumber(std::vector<int> Tst) {
    int len = Tst.size();
    int a[len+1];
    for (int i = 0; i < len; i++) {
        a[i] = -1;
    }
    for (int i = 0; i < len; i++) {
        if (a[i] == -1) {
            a[Tst[i]] = 1;
        }
        else {
            return Tst[i];
        }
    }
}

int main() {
    return 0;
}