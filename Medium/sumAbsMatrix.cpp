#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

long long x[MAX];
long long sumAbsMatrix(int n) {
    
    for (int i = 0; i < n; i++) {
        x[0] = x[0] + i;
    }
    long long sum = x[0];
    int k = n-1;
    for (int i = 1; i < n; i++) {
        x[i] = x[i-1] - k;
        sum = sum + x[i];
        k--;
    }
    /*for (int i = 0; i < n; i++) {
        sum = sum + x[i];
    }*/
    return sum<<1;
}
int main() {
    int n = 7;
    
    cout << sumAbsMatrix(7) << endl;
    for (int i = 0; i < 7; i++) {
        cout << x[i] << " ";
    }
}