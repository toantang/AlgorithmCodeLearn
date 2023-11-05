#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> ans;
string f = "";
string a[] = {"A", "B"};

void TRY(int i, int n, int k) {
    /// i: so luong ki tu A
    /// n: do dai toi da cua string
    /// k: so ki tu A toi da
    /// len: do dai hien tai cua string
    for (int j = 0; j < 2; j++) {
        
        if (j == 0 && (f.back() == 'A' || f.size() == 0)) i++;
        f += a[j];
        if (i < k) {
            if (f.size() < n) {
                TRY(i, n, k);
            }
        }
        else if (i == k) {
            if (f.size() < n) {
                TRY(i, n, k);
            }
            else {
                cout << "f: " << f << endl;
            }
        }
        
        
        // if (f.size() < n) {
        //     TRY(i, n, k);
        // }
        // else {
        //     cout << "i: " << i << ", k = " << k << endl;
        //     if (i == k) {
        //         cout << "f: " << f << endl;
                // cout << "f: " << f << endl;
                // int num = 0;
                // int max = 0;
                // for (int t = 0; t < f.size(); t++) {
                //     if (f[t] == 'B') {
                //         max = num;
                //         num = 0;
                //     }
                //     else {
                //         num++;
                //     }
                // }
                // if (max == k) {
                //     ans.push_back(f);
                //     break;
                // }
                
        //     }
        // }
        f.pop_back();
        if (j == 0 && (f.back() == 'A' || f.size() == 0)) i--;
        
    }
}

string b[] = {"A", "B", "X"};

void try2(int i, int n, int k, int cnt, int lastIndex) {
    for (int j = 0; j < 3; j++) {
        f+= b[j];
        // cout << "f: " << f << ", j: " << j << endl;
        // if (j == 0) {
        //     if (lastIndex == 2) i++;
        // }
        // else if (j == 2) {
        //     if (lastIndex == 0) i++;
        // }

        if (f.size() < n) {
            try2(i, n, k, cnt, j);
        }
        else {
            // if (i == cnt) {
                cout << "f: " << f << endl;
            // }
        }

        f.pop_back();
        // if (j == 0) {
        //     if (lastIndex == 2) i--;
        // }
        // else if (j == 2) {
        //     if (lastIndex == 0) i--;
        // }
    }
};

int main() {
    // int n = 2, k = 1;
    // int n = 3, k = 2;
    // int n = 4, k = 2;
    // int max = n/k;
    // try2(0, 2, k, 1, -1);
    // for (int i = 1; i <= max; i++) {
    //      n = n - k*i;
    //     try2(0, n, k, i, -1);
    // }
    // TRY(0, n, k);
    // for (int i = 0; i < ans.size(); i++) {
    //     cout << "ans[" << i << "] = " << ans[i] << ", ";
    // }
    // int val = 17000000 + 16 * 40000 + 250000 + 100000;
    int val = 17990000;
    int x = val/10;
    val = val - x;
    cout << val << endl;
    val = val - 2000000 - 7000000 - 2827500;
    cout << val << endl;
    return 0;
}