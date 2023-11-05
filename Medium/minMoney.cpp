#include <bits/stdc++.h>

using namespace std;

int a[100];
int f; //sum current money
int cnt = 0;
int ans = INT_MAX;

bool check(int v, int k, int n, vector<int> arr) {
    if (cnt + v > ans || (f + arr[k]*v > n)) {
        return false;
    }
    return true;
}
void TRY(int k, int n, vector<int> arr, int length) {
    int maxValue = (n - f)/arr[k];
    //cout << "maxValue = " << maxValue << endl;
    for (int v = maxValue; v >= 0; v--) {
        //cout << "   v = " << v << endl;
        if (check(v, k, n, arr)) {
            a[k] = v;
            cnt += a[k];
            f += arr[k] * v;
            k--;

            if (k == -1) {
                //cout << "f = " << f << endl;
                if (f == n) {
                    for (int i = 0; i < length; i++) {
                        cout << a[i] << " ";
                    }
                    cout << endl;
                    ans = min(ans, cnt);
                    cout << "ans = " << ans << endl;
                }
            }
            else if (f <= n) {
                TRY(k, n, arr, length);
            }
            k++;
            f -= arr[k] * a[k];
            cnt -= a[k];
        }
    }
}

void minMoney(int n, vector<int> arr) {
    int length = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> d;
    d.push_back(arr[0]);
    for (int i = 1; i < length; i++) {
        if (arr[i] != arr[i-1]) {
            d.push_back(arr[i]);
        }
    }
    
    int size = d.size();
    TRY(size - 1, n, d, size);
}

int main() {
    vector<int> arr;
    int n;
    arr = {1, 2, 3}, n = 10;
    arr = {2}, n = 5;
    arr = {5,1,2,9,2}, n = 97;
    arr = {5,7,2,1,6}, n = 1323; //time limited
    arr = {21,79,48,83,36}, n = 2003;
    minMoney(n, arr);
    cout << ans << endl;
    return 0;
}