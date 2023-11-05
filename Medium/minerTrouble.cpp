#include <bits/stdc++.h>

using namespace std;

const int N = 1000000007;

unsigned long long findMax(vector<long long> a) {
    unsigned long long x = -1;
    unsigned long long sum = 0;
    unsigned long long max = 0;
    int len = a.size();
    for (int i = 0; i < len; i++) {
        if (a[i] <= x) {
            sum = 0;
        }
        sum += a[i];
        x = a[i];
        if (sum > max) {
            max = sum;
        }
    }

    return max;
}
int minerTrouble(std::vector<long long> a)
{
    int len = a.size();
    if (len == 0) {
        return 0;
    }
    int max1 = findMax(a)%N;
    
    vector<long long> aReserve;
    for (int i = 0; i < len; i++) {
        aReserve.push_back(a[len - 1 - i]);
    }
    int max2 = findMax(aReserve)%N;
    if (max1 >= max2) {
        return max1;
    }
    return max2;
}
int main() {
    vector<long long> a;
    a = {0,2,3,5,1};
    //a = {1,2,3,4,2,3,4,7,6,3,1,1,8};
    cout << minerTrouble(a) << endl;
    return 0;
}