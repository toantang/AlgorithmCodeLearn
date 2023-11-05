#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int ans[MAX];
void countNum(int n, vector<int> a, int Q, vector<std::vector<int>> query) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < Q; j++) {
            vector<int> item = query.at(j);
            if (item[1] <= i && item[2] >= i) {
                if (a[i] == item[0]) {
                    ans[j]++;
                }
            }
        }
    }
}

int main() {
    int n, Q;
    vector<int> a; vector<vector<int>> query;
    n = 7,a = {7,6,2,0,0,6,8}, Q =3,  query = {{2,1,4},{6,1,6},{7,2,4}};
    countNum(n, a, Q, query);
    for (int i = 0; i < Q; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}