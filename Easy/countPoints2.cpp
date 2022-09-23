#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

long long countPoints(int n) {
    vector<long long> a;
    a.push_back(0);
    a.push_back(0);
    a.push_back(5);
    for (int i = 3; i <= n; i++) {
        long long x = a.back();
        long long y = x - (3 + 2*(i-3)) + (i*5 - 5);
        a.push_back(y);
    }
    return a.back();
}

int main() {
    int n;
    cin >> n;
    cout << countPoints(n) << endl;
    return 0;
}