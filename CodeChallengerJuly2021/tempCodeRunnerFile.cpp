#include <bits/stdc++.h>

using namespace std;

int beauty(std::vector<int> arr)
{
    int countA = arr[0];
    int countB = arr[1];
    int maxA = arr[2];
    int maxB = arr[3];
    int ans = 0;

    if (maxA == 0 && maxB == 0) {
        return 0;
    }
    if (countA == 0 && countB == 0) {
        return 0;
    }
    int sum = countA + countB;
    int value = maxA + maxB;
    if (sum > value) {
        int minValue = min(maxA, maxB);
        cout << minValue << endl;
        for (int i = 1; i <= minValue; i++) {
            cout << "i: " << i << endl;
            int valueA = countA/i;
            int valueB = countB/i;
            int soduA = countA - valueA;
            int soduB = countB - valueB;

            if (soduA > maxA) {
                soduA = maxA;
            }
            if (soduB > maxB) {
                soduB = maxB;
            }

            int currentAns = (valueA + valueB)*i + soduA + soduB;
            if (currentAns > ans) {
                ans = currentAns;
            }
            cout << "   ans = " << ans << endl;
        }
        return ans;
    }
    else if (sum == value) {
        return value;
    }
    else {
        return sum;
    }
}

int main() {
    vector<int> arr;
    arr = {15,20,2,1};
    cout << beauty(arr);
    return 0;
}