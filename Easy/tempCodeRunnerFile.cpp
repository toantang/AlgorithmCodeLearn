#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int d[N];
int k = 0;

bool checkSort(std::vector<int> a)
{
    int len = a.size();
    d[0] = a[0];
    k++;
    for (int i = 1; i < len; i++) {
        if (a[i] != a[i]) {
            d[k] = a[i];
            k++;
        }
    }

    sort(d, d + k);
    for (int i = 1; i <= k; i++) {
        if (d[i] == d[i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> a;
    a = {1,1,1,3,3,2,2,2,1,1};
    cout << checkSort(a) << endl;
    return 0;
}