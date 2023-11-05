#include <bits/stdc++.h>

using namespace std;

int edgesNumber(int n) {
    return n*(1<<2 + 1<<1) + 2;
}
int main() {
    int x = 1<<2;
    cout << "x = " << x << endl;
    x = x + 1<<1;
    cout << x << endl;
    cout << edgesNumber(5) << endl;
    return 0;
}