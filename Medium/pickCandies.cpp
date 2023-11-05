#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int ans;
int x[MAX];

void pickCandies(vector<int> candies) {
    int len = candies.size();
    x[0] = candies[0];
    x[1] = candies[1];
    for(int i = 2; i < len; i++) {
        x[i] = max(x[i-1], x[i-2] + candies[i]);
    }

    for (int i = 0; i < len; i++) {
        cout << x[i] << " ";
    }
    ans = x[len-1];
}

int main() {
    vector<int> candies;
    candies = {1, 4, 6, 3, 8, 9, 10};
    //candies = {0, 0, 0, 0, 0, 0, 0, 0};
    pickCandies(candies);
    cout << "ans = " << ans << endl;
    return 0;
}