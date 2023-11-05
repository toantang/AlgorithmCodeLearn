#include <bits/stdc++.h>

using namespace std;

const int N = 26;
int c[N];

int sumSquares(long long k) {
    int x = sqrt(k);
    int cnt = 0;
    for (long long i = 1; i <= x; i++) {
        long long a = i * i;
        long long b2 = k - a;
        long long value = sqrt(b2);
        if (value * value == b2) {
            cnt++;
            //cout << "a = " << i << ", b = " << value << endl;
        }
    }
    return cnt;
}
int main() {
    long long k;
    k = 25;
    //k = 0;
    k = pow(2, 50);
    cout << sumSquares(k) << endl;
    unsigned long long m = pow(2, 25);
    cout << m << endl;
    return 0;

}