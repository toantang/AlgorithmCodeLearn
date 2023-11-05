#include <bits/stdc++.h>
#define MAX 400005
using namespace std;

int ans;
int a[MAX];
int maxValue = -1;

void maxChildren(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int len = arr.size();
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            int x = arr[i] + arr[j];
            a[x]++;
            if (x > maxValue) {
                maxValue = x;
            }
        }
    }

    for (int i = 0; i <= maxValue; i++) {
        if (a[i] > ans) {
            ans = a[i];
        }
    }
}
int main() {
    vector<int> arr;
    maxChildren(arr);
    return 0;
}
