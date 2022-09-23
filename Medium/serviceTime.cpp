#include <bits/stdc++.h>

using namespace std;

int a[7] = {0, 1, 2, 3, 4, 5, 6};
char x[7] = {'x', 'a', 'b', 'c', 'd', 'e', 'f'};

long long ans = 0;

int findService(string ns) {
    for (int i = 1; i < 7; i++) {
        if (x[i] == ns[1]) {
            return a[i];
            break;
        }
    }
    return 0;
}

void serviceTime(string ns) {
    int row = (int) ns[0] - 48;
    if (row == 1) {
        ans = findService(ns);
    }
    else if (row == 2) {
        ans = 7 + findService(ns);
    }
    else if (row == 3) {
        ans = findService(ns);
    }
    else if (row == 4) {
        ans = 7 + findService(ns);
    }
    else {
        if (row%2 == 0) {
            ans = 16 + 4*(row - 6)  + findService(ns);
        }
        else {
            ans = 16 + 7*(row - 5)/2 + findService(ns);
        }
    }
}
int main() {
    string ns;
    ns = "8a";
    serviceTime(ns);
    cout << ans << endl;
    return 0;
}