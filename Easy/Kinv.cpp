#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+1;
int ans;
int d[N];
int spt;

void solve(vector<int> arr) {
    int len = arr.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < len; i++) {
        pair<int, int> c;
        c.first = i;
        c.second = arr[i];
        v.push_back(c);
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < len; i++) {
        pair<int, int> x = v[i];
        int a = x.first;
        int b = x.second;
        for (int j = 0; j < a; j++) {

        }
    }
}
int main() {
    return 0;
}