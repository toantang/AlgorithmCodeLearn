#include <bits/stdc++.h>

using namespace std;

int ans;
int best;

void doingHomework(vector<int> a) {
    int len = a.size();
    ans = a[0];
    best = ans;
    for (int i = 1; i < len; i++) {
        if (a[i] > a[i-1]) {
            best = max(a[i], best + a[i]);
            ans = max(best, ans);
        }
        else {
            best = a[i];
        }
    }
    cout << ans << endl;
}
int main() {
    vector<int> a;
    a = {1, 2, 3, 5, 1};
    a = {1,2,3,2,4,5,6};
    doingHomework(a);
    return 0;
}