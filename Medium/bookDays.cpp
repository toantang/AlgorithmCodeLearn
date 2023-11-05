#include <bits/stdc++.h>

using namespace std;

void bookDays(vector<int> a) {
    int len = a.size();
    unsigned long long sumCurrent = 0.0;
    unsigned long long average = 0.0;
    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (sumCurrent/i < a[i]) {
            ans++;
        }
        sumCurrent += a[i];
        /*(sumCurrent += a[i];
        average = sumCurrent/(i+1);
        if (average > a[i]) {
            ans++;
        }*/
    }
    cout << ans << endl;
}
int main() {
    vector<int> a;
    a = {32,40,4,68,30,52,57,83,6,83};
    bookDays(a);
    return 0;
}