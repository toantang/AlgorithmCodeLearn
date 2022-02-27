#include <bits/stdc++.h>

using namespace std;

void fiboSum(long long n) {
    vector<long long> v;
    long long currentSum = 3;
    v.push_back(1);
    v.push_back(2);

    int m = 2;
    while(currentSum < n) {
        currentSum += v[m-1] + v[m-2];
        //cout << currentSum << endl;
        v.push_back(v[m-1] + v[m-2]);
        ++m;
    }

    cout << "currentSum = " << currentSum << endl;
    cout << "mang v: " << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;
    while(currentSum != n && m >= 1) {
        if (currentSum - v[m-1] >= n) {
            currentSum -= v[m-1];
            v[m-1] = -1;
        }
        --m;
    }

    cout << "mang v: " << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;

    vector<long long> res;
    int len = v.size();
    for (int i = 0; i < len; i++) {
        if (v[i] != -1) {
            res.push_back(v[i]);
        }
    }

    if (res.size() == 0) {
        res.push_back(-1);
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}
int main() {
    long long n;
    n = pow(10, 15);
    n = 10000000000;
    n = 25;
    fiboSum(n);
    return 0;
}