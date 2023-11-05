#include <bits/stdc++.h>

using namespace std;

void nearSquare(int n) {
    vector<int> ans;

    int x = sqrt(n);
    for (int i = x; i >= 1; i--) {
        if (n%i == 0) {
            ans.push_back(i);
            ans.push_back(n/i);
            break;
        }
    }
}
int main() {
    return 0;
}