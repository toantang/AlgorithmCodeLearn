#include <bits/stdc++.h>

using namespace std;

int maxWater(vector<int> arr) {
    int ans = 0;

    int len = arr.size();
    int i = 0, j = len - 1;
    while(i < j) {
        if (arr[i] < arr[j]) {
            ans = max(ans, (j-i) * arr[i]);
            i++;
        }
        else if (arr[i] > arr[j]) {
            ans = max(ans, (j - i) * arr[j]);
            j--;
        }
        else {
            ans = max(ans, (j-i) * arr[i]);
            i++;
            j--;
        }
    }
    return ans;
}

int main() {
    //vector<int> a = {1,8,6,2,5,4,8,3,7};
    vector<int> a = {6,2,1,7,7,7,3,3,5,6};
    //vector<int> a = {9,1,8,9,4,9,8,2,9,1,3,0};
    //vector<int> a = {0,5,1,1,7,3,9,7,4,0,3,0,9,1,1,8,5,8,0,6,9,1,4,3,5,3,2,9,0,5};
    /*vector<int> a = {80,61,51,57,45,71,4,94,25,74,99,21,76,49,37,19,22,42,68,85,39,
                    94,13,60,25,69,14,16,3,5,7,35,66,59,44,63,30,48,10,8,23,9,29,99,
                    10,18,70,33,12,38};*/
    //cout << maxWater(a) << endl;
    maxWater(a);
    return 0;
}
