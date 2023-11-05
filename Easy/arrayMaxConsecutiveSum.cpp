#include <bits/stdc++.h>

using namespace std;

int sum;
int ans = INT_MIN;
int arrayMaxConsecutiveSum(std::vector<int> inputArray, int k)
{
    int n = inputArray.size();
    if (k > n) {
        return -1;
    }
    for (int i = 0; i < k; i++) {
        sum += inputArray[i];
    }
    ans = sum;
    for (int i = 0; i < n - k; i++) {
        sum = sum + inputArray[i+k] - inputArray[i];
        ans = max(sum, ans);
    }
    if (ans <= 0) {
        return -1;
    }
    return ans;
}

int main() {
    return 0;
}