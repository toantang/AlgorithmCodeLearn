#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> divisor;
int ans = 0;

void findDivisor(int n) {
    int x = sqrt(n);
    for (int i = 2; i <= x; i++) {
        if (n%i == 0) {
            pair<int, int> m;
            m.first = i;
            m.second = n/i;
            divisor.push_back(m);
        }
    }
}

void isPairMult(vector<int> arr, int n) {
    int x = sqrt(n);
    int length = arr.size();

    vector<int> divisorArray;
    int index = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] <= x) {
            int divisorLength = divisor.size();
            for (int j = 0; j < divisorLength; j++) {
                if (arr[i] == divisor[j].first) {
                    divisorArray.push_back(arr[i]);
                }
            }
        }
        else {
            index = i;
            break;
        }
    }

    for (int i = index; i < length; i++) {
        int divisorArrayLength = divisorArray.size();
        for (int j = 0; j < divisorArrayLength; j++) {
            if (divisorArray[j] * arr[i] == n) {
                ans = 1;
                break;
            }
        }
    }
}
int main() {
    vector<int> arr; int n;
    arr = {1, 2, 3, 9, 11, 15, 21}, n = 10;
    findDivisor(n);
    isPairMult(arr, n);
    cout << ans << endl;
    return 0;
}