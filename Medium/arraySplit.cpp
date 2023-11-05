#include <bits/stdc++.h>
#define MAX 300005
using namespace std;

int ans = 0;
vector<int> x;
void arraySplit(vector<int> a, int k) {
    int len = a.size();
    for (int i = 0; i < len - 1; i++) {
        int m = a[i] - a[i+1];
        x.push_back(m);
    }
    sort(x.begin(), x.end());
    int sum = 0;
    if (k > 1) {
        for (int i = 0; i < k-1; i++) {
            sum = sum + x[i];
        }
        ans = a[len-1] - a[0] + sum;
    }
    else if (k == 1) {
        if (len == 1) {
            ans = 0;
        }
        else {
            ans = a[len-1] - a[1];
        }
    }
    else if (k > len) {
        ans = -1;
    }
    else {
        ans = 0;
    }
}
int main() {
    vector<int> a; 
    int k;
    //a = {2,4,5,5,8,11,19}; k = 3;
    //a = {4, 8, 15, 16, 23, 42}, k = 3;
    //a = {1, 1, 2, 3, 5, 8, 13, 21}, k = 1;
    //a = {3, 3, 4, 5, 6}, k = 2;
    //a = {20}, k = 1;
    a = {99, 101, 103, 105, 107}, k = 3;
    arraySplit(a, k);
    /*int size = x.size();
    for (int i = 0; i < size; i++) {
        cout << x[i] << " ";
    }*/
    cout << ans << endl;
    return 0;
}