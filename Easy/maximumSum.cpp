#include <bits/stdc++.h>

using namespace std;

int maximumSum(vector<int> arr) {
    int sum = 0;
    int minVal;
    minVal = min(arr[0], arr[2]);
    minVal = min(minVal, arr[3]);
    sum += 256*minVal;
    arr[0] = arr[0] - minVal;
    minVal = min(arr[0], arr[1]);
    sum += 32 * minVal;
    return sum;
}
int main() {
    return 0;
}