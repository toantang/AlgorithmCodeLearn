#include <bits/stdc++.h>

using namespace std;

int ans = 0;

void minNotPay(vector<int> arr) {
    int len = arr.size();
    bool sign = false;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < len; i++) {
        if (arr[i] - ans > 1) {
            ans += 1;
            sign = true;
            break;
        }
        else {
            ans += arr[i];
        }
    }
    if (sign == false) {
        ans += 1;
    }
}

int main() {
    vector<int> arr;
    arr = {2, 4, 1, 9, 100};
    minNotPay(arr);
    cout << ans << endl;
    return 0;
}