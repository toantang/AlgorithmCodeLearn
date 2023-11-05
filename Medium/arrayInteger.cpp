// da xong
#include <bits/stdc++.h>

using namespace std;

int ans;

void arrayInteger(vector<int> a) {
    int len = a.size();
    if (len == 0) {
        ans = 0;
    }
    
    sort(a.begin(), a.end());
    int max = INT_MIN;
    for (int i = 0; i < len; i++) {
        if (i + 1 - a[i] > max) {
            max = i + 1 - a[i];
        }
    }
    
    cout << max << endl;
    
    
    if (max > 0) {
        ans = max;
        for (int i = 0; i < len; i++) {
            a[i] = a[i] + max;
        }
    }

    for (int i = 0; i < len; i++) {
        //cout << a[i] << ", i = " << i << endl;
        ans = ans + a[i] - i - 1;
        //cout << ans << endl;
    }
}
int main() {
    vector<int> a;
    //a = {0,3,1,3};
    a = {1, 2, 4};
    //a = {2,4,-5,-8,9};
    //a = {-6};
    //a = {-9, 5, 8, 3, 9, 0};
    //a = {9, 8, 6, 7, 4, };
    //a = {9};
    arrayInteger(a);
    cout << ans << endl;
    return 0;
}