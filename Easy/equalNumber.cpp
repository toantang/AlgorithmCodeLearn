#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int sum = 0;
void equalNumber(vector<int> arr) {
    int len = arr.size();
    //int sum = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < len; i++) {
        sum = sum + arr[i];
    }
    while(true) {
            sort(arr.begin(), arr.end());
            cout <<"sum = " << sum << endl;
            for (int i = 0; i < len; i++) {
               cout << arr[i] << " ";
            }
            cout << endl;
            if (arr[0] * len == sum) {
                break;
            }
            for (int i = 0; i < len - 1; i++) {
                arr[i] += 1;
            }
            sum = sum + (len-1);
            ans++;
        }
}
int main() {
    vector<int> arr= {1, 2, 3};
    equalNumber(arr);
    cout << ans << endl;
    cout << "sum = " << sum << endl;
    return 0;
}