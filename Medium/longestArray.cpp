#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int u[N];
int maxValue = 0;

int GCD(int a, int b) {
    while(a != b) {
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    return a;
}

void longestArray(std::vector<int> a) {
    int len = a.size();
    sort(a.begin(), a.end());
    vector<int> v;
    for (int i = 1; i < len; i++) {
        int gcd = GCD(a[i], a[i-1]);
        if (gcd > 1) {
            v.push_back(gcd);
        }
    }
    int size = v.size();
    for (int i = 0; i < size; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        u[v[i]]++;
        if (u[v[i]] > maxValue) {
            maxValue = u[v[i]];
        }
    }
    maxValue += 1;
    cout << maxValue << endl;
}

int main() {
    vector<int> a;
    a = {2, 3, 9, 3, 12, 4};
    longestArray(a);
    return 0;
}