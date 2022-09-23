#include <bits/stdc++.h>

using namespace std;

//da lam xong

const int N = 1000005;
vector<vector<int>> d(N);
int ans = 0;

//tim nhung uoc khi chia cho 2 co cung thuong (chia den tan cung)
pair<int, int> findNum(int n) {
    int cnt = 0;
    pair<int, int> c;
    while(n%2 == 0) {
        cnt++;
        n = n/2;
    }
    c.first = n;
    c.second = cnt;
    return c;
}

void printVector(vector<int> x, int len) {
    for (int i = 0; i < len; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}
void minDivision(vector<int> a) {
    int length = a.size();
    sort(a.begin(), a.end());
    vector<int> arr;
    if (a[0]%2 == 0) {
        arr.push_back(a[0]);
    }
    for (int i = 1; i < length; i++) {
        if (a[i]%2 == 0 && a[i] != a[i-1]) {
            arr.push_back(a[i]);
        }
    }

    int len = arr.size();
    int maxVal = INT_MIN;
    for (int i = 0; i < len; i++) {
        pair<int, int> c = findNum(arr[i]);
        d[c.first].push_back(c.second);
        if (c.first > maxVal) {
            maxVal = c.first;
        }
    }

    for (int i = 1; i <= maxVal; i++) {
        cout << "i: " << i << endl;
        vector<int> x = d[i];
        sort(x.begin(), x.end());
        int size = x.size();
        printVector(x, size);
        if (size != 0) {
            for (int i = size - 1; i >= 1; i--) {
                ans += x[i] - x[i-1];
            }
            ans += x[0];
        }
    }
    cout << "ans = " << ans << endl;
}
int main() {
    vector<int> a;
    a = {5, 6, 1, 24};
    a = {8};
    a = {};
   // a = {8, 3, 10, 4};
   //a = {10,16,6,9,3,1,22,2,1};
    //a = {11,15,13,15,18,18,10,16,16,10,15,11,11,13,11,20,16,14,10,11};
    //a = {7,72,35,7,39,40,87,2,39,19,74,55,29,87,26,75,35,29,94,61,89,89,7,20,96,60,41,14,87,97};
    /*a = {73,185,103,20,94,95,82,83,62,180,98,101,132,81,146,181,97,111,
        25,71,156,185,199,17,183,102,33,106,140,27,174,87,192,137,194,51,55,
        2,91,23,32,90,171,106,58,12,22,19,111,194,45,149,48,153,193,138,98,
        100,139,75,183,119,84,71,143,167,16,186,121,153,193,191,5,49,153,114,
        4,124,24,79,18,39,159,199,50,49,171,140,178,86,150,154,65,94,75,73,151,
        133,57,184};*/
    //cout << minDivision(a) << endl;
    int cnt = 0;
    while(cnt <= 10)
    minDivision(a);
    return 0;
}