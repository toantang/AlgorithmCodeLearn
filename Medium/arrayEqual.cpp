#include <bits/stdc++.h>

using namespace std;

int ans = 0;

void arrayEqual(vector<int> a) {
    int len = a.size();
    sort(a.begin(), a.end());
    int mid = len/2;
    int x = a[mid];
    //cout << "mid = " << mid << ", x = " << x << endl;
    for (int i = 0; i < mid; i++) {
        ans = ans + x - a[i];
    }
    for (int i = mid + 1; i < len; i++) {
        ans = ans + a[i] - x;
    }
}

int main() {
    vector<int> a;
    a = {3,3,3,4};
    arrayEqual(a);
    cout << ans << endl;
    return 0;
}