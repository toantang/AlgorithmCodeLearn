#include <bits/stdc++.h>

using namespace std;

const int N = 14;
const string c[2] = {"+", "-"};
string a[N];
string x[N]; 
int f = 0; //tong hien tai
string d[N][N];

void caculateSum(int i, string dv) {
    int val = atoi(dv.c_str());
    if (i == 1) {
        f += val;
    }
    else {
        f -= val;
    }

}

void backBranch(int k) {
    int val = atoi(x[k].c_str());
    if (x[k] == c[1]) {
        f -= val;
    }
    else {
        f += val;
    }
}


void TRY(int start, int k, string s, int n) {
    for (int v = start; v < n; v++) {
        d[start][v] = d[start][v-1] + s[v];
        for (int i = 1; i >= 0; i--) {
            a[k] = d[start][v];
            start = v;
            caculateSum(i, x[k]);
            k++;

            if (k == n) {
                string s;
                for (int i = 0; i <= k; i++) {
                    s += x[i] + a[i];
                }
                cout << s << endl;
            }
            else {
                TRY(start, k, s, n);
            }

            x[k] = "";
            k--;
            backBranch(k);
        }
    }
}
int main() {
    string s;
    s = "123";
    int val = atoi(s.c_str());
    cout << val << endl;
    return 0;
}