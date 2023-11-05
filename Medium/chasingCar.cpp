#include <bits/stdc++.h>

using namespace std;

int chasingCar(int v, int s, int k) {
    double x = 60*v*s;
    cout << "x  = "<< x << endl;
    double y = 60*s -v*k;
    cout << "y = " << y << endl;
    double ans = x/y;
    return roundf(ans);
}
int main() {
    int v, s, k;
    v = 10, s = 100, k = 120;
    cout << chasingCar(v, s, k) << endl;
    return 0;
}