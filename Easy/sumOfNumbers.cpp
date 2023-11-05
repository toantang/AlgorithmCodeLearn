#include <bits/stdc++.h>

using namespace std;

int sumOfNumbers(std::vector<int> arr, int n)
{
    int len = arr.size();
    long long sum = 0;
    if (n == 0 || len == 0) {
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < len; j++) {
            if (i%arr[j] == 0) {
                sum += i;
                break;
            }
        }
    }
    return sum;
}
int main() {
    return 0;
}