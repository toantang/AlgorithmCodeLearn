#include <bits/stdc++.h>
#define MAX 10
using namespace std;

int ans[MAX];
int k = 0;

void division(int n) {
    n = abs(n);
    int b[MAX];
    while (n != 0) {
        b[k] = n%10;
        n = n/10;
        k++;
    }
    for (int i = 0; i < k; i++) {
        ans[k-1-i] = b[i];
    }
}
bool smartNumber(int n) {
    if (n >= 0 && n <= 10) {
        return true;
    }
    else {
        for (int i = 0; i < k-1; i++) {
            if (ans[i] < ans[i+1]) {
                return false;
            }
        }

        return true;
    }   
}
int main() {
    int n = 54621;
    division(n);
    cout << smartNumber(n) << endl;
    return 0;
}