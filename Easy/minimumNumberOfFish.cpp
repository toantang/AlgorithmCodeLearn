#include <bits/stdc++.h>

using namespace std;

int ans = 0;
void minimumNumberOfFish(vector<int> w, int k) {
    sort(w.begin(), w.end());
    int len = w.size();
    for (int i = 0; i < len - 1; i++) {
        while(k < w[i+1]) {
            k = k + w[i];
            ans++;
        }
    }
}

int main() {
    vector<int> w; int k;
    w = {1,4,6,9,12}, k = ;
    return 0;
}