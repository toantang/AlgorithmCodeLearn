#include <bits/stdc++.h>

using namespace std;

int sum;
int cnt = 0;
int start = 0;
int ans = INT_MIN;

void lotsOfPie(int n, int k, vector<int> pies) {
    for (int i = 0; i < k; i++) {
        sum += pies[i];
    }
    for (int i = 0; i < n - k - 1; i++) {
        sum = sum + pies[i+k] - pies[i];
        ans = max(sum, ans);
    }
}
int main() {
    vector<int> pies;
    int n, k;
    n = 12, k = 3;
    pies = {18,22,-3,13,39,2,12,33,40,33,20,-3};
    //n = 15, k = 5;
    //pies = {-8,14,35,61,100,142,91,8,114,45,59,69,-6,137,89};
    lotsOfPie(n, k, pies);
    cout << ans << endl;
    return 0;
}