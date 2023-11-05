#include <bits/stdc++.h>

using namespace std;

long long chooseGoodsToWin(int n, long long a, long long b, vector<long long> w, vector<long long> v)
{
    long long max = 0;
    int index;
    for (int i = 0; i < n; i++) {
        if (v[i] > max && w[i] > a && w[i] < b) {
            max = w[i];
            index = i;
        }
    }
    if (max == 0 || w.size() == 0 || v.size() == 0) {
        return -1;
    }
    else {
        return v[index];
    }
}
int main() {
    return 0;
}