#include <bits/stdc++.h>

using namespace std;

void numberFavourite(vector<int> a) {
    int n = a[0];
    int x = a[1];
    int y = a[2];
    int ans = 0;
    int start = 0;
    int value = 0;
    if (x > n) {
        if (y > n) {
            start = x;
            value = y;
            ans = 0;
        }
        else {
            start = y;
            value = x; 
        }
    }
    else {
        if (y <= n) {
            start = min(x, y);
            value = max(x, y);
        }
        else {
            start = x;
            value = y;
        }
    }

    cout << "start = " << start << ", value = " << value << endl;
    for (int i = start; i <= n; i = i + start) {
        cout << "   i = " << i << endl;
        if (i != value) {
            ans++;
            if (i%value == 0) {
                ans++;
            }
        }
    }
    cout << "ans = " << ans << endl;
    if (value == n) {
        ans++;
    }
    if (start != 0) {
        ans++;
    }
    cout << ans << endl;
    //return ans;
}
int main() {
    vector<int> a;
    a = {7,2,3};
    a = {1,2,3};
    a = {10,10,4};
    a = {9,3,9};
    //a = {17,8,2};
   //cout << numberFavourite(a);
   numberFavourite(a);
    return 0;
}