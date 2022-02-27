#include <bits/stdc++.h>

using namespace std;

int cntIndexRight(vector<int> arr, int len) {
    int indexRight = 0;
    for (int i = 0; i < len; i++) {
        if (i%2 == 0) {
            if (arr[i]%2 == 0) {
                indexRight++;
            }
        }
        else {
            if (arr[i]%2 == 1) {
                indexRight++;
            }
        }
    }

    return indexRight;
}

int cnt = 0;
int caculateSumBalance(vector<int> arr, int len) {
    int sumBalance = 0;

    for (int i = 0; i < len; i++) {
        if (i%2 == 0) {
            if (arr[i] < 2) {
                sumBalance += -1;
                cnt++;
            }
            else {
                sumBalance += arr[i] - 2;
            }
        }
        else {
            if (arr[i] < 1) {
                sumBalance += -1;
                cnt++;
            }
            else {
                sumBalance += arr[i] - 1;
            }
        }
    }

    return sumBalance;
}

int minimumChocolateMoves(std::vector<int> arr)
{
    int len = arr.size();
    int indexRight = cntIndexRight(arr, len);
    cout << "indexRight = " << indexRight << endl;
    int indexNotRight = len - indexRight;
    int sumBalance = caculateSumBalance(arr, len);

    if (sumBalance < 0) {
        return -1;
    }

    if (indexNotRight%2 == 1) {
        return -1;
    }

    int val = indexNotRight - cnt;
    if (val%2 == 0) {
        return cnt;
    }
    return cnt + val/2;
}


vector<int> makeRandomArray(int n) {
    vector<int> arr;
    int i = 0;
    srand((int)time(0));
    while(i < n) {
        int val = rand();
        arr.push_back(val);
        i++;
    }
    return arr;
}
int main() {
    vector<int> arr;
    arr = {1, 1, 1, 1, 1, 1};
    arr = {6, 1, 2, 1, 2, 1};
    int n = 1;
    arr = makeRandomArray(n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int ans = minimumChocolateMoves(arr);
    cout << "ans = " << ans << endl;
    return 0;
}