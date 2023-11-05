#include <bits/stdc++.h>

using namespace std;

int chooseCup(vector<int> arr)
{
    int len = arr.size();
    if (len < 3) {
        return 0;
    }
    else {
        sort(arr.begin(), arr.end());
        int sumMin = arr[0] + arr[1] + arr[2];
        if (len == 3) {
            return sumMin;
        }
        else if (len == 4) {
            return sumMin + arr[4];
        }
        else if (len == 5) {
            return sumMin + arr[3] + arr[4];
        }
        else {
            return sumMin + arr[len-1] + arr[len-2] + arr[len-3];
        }
    }
}

int main() {
    vector<int> arr = {5, 6, 7, 2};
    cout << chooseCup(arr) << endl;
    return 0;
}