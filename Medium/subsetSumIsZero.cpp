#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
int sumNegative[N];
int sumPositive[N];
vector<int> positive; // mang chua cac so am
vector<int> negative; // mang chua cac so duong
int f = 0;
bool visited[N];
bool check(int v, int k) {
    if (visited[v] == false) {
        return true;
    }
    return true;
}
void TRY(int k, int n) {
    for (int v = 0; v < n; v++) {
        if (check(v, k)) {
            f += positive[v];
            sumPositive[k] = f;
            k++;
            visited[v] = true;
            cout << f << endl;
            TRY(k, n);
            visited[v] = false;
            k--;
            sumPositive[k] = 0;
            f -= positive[k];
        }
    }
}

void subsetSumIsZero(vector<int> L) {
    int len = L.size();
    
    for (int i = 0; i < len; i++) {
        if (L[i] < 0) {
            negative.push_back(L[i]);
        }
        else {
            positive.push_back(L[i]);
        }
    }

    
}
int main() {
    vector<int> L;
    L = {63, 45, -72, -77, 87, 83, -55};
    L = {87, 48, -54, 70, -56, -65, -95, -90, -43, 20};
    subsetSumIsZero(L);
    int n = positive.size();
    TRY(0, n);
    return 0;
}