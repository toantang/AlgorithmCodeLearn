#include <bits/stdc++.h>

using namespace std;

const int c[] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289, 324, 361, 400, 441, 
            484, 529, 576, 625, 676, 729, 784, 841, 900, 961, 1024, 1089, 1156, 1225, 1296, 1369, 1444, 1521, 1600, 
            1681, 1764, 1849, 1936};

const int N = 2005;
int a[N]; 
bool visited[N];
int f = 0; //tong hien tai da tinh
int ans = 0;

bool check(int v, int n) {
    //cout << "v: " << v << endl;
    if (visited[c[v]] == true) {
        //cout << "vao ham nay" << endl;
        return false;
    }
    if (c[v] + f > n) {
        //cout << "vao ham f" << endl;
        return false;
    }
    return true;
}

int findIndex(int n) {
    for (int i = 0; i < 44; i++) {
        if (c[i] > n) {
            return i-1;
        }
    }
    return 0;
}
void TRY(int k, int n, int end) {
    for (int v = 0; v <= end; v++) {
        if (check(v, n) == true) {
            a[k] = c[v];
            f += a[k];
            visited[a[k]] = true;
            k++;
            cout << "f = " << f << endl;
            if (f == n) {
                for (int i = 0; i < k; i++) {
                    cout << a[i] << " ";
                    visited[c[i]] = true;
                }
                cout << endl;
                ans++;
            }
            else {
                if (f < n) {
                    TRY(k, n, end);
                }
            }
            k--;
            visited[a[k]] = false;
            f -= a[k];
        }
        
    }
}
void countCase(int n) {
    for (int i = 1; i < 44; i++) {
        visited[c[i]] = false;
    }
    int end = findIndex(n);
    cout << "end = " << end << endl;
    TRY(0, n, end);
    cout << "ans = " << ans << endl;
}
int main() {
    int n;
    n = 100;
    countCase(n);
    return 0;
}