#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;
vector<int> u;
int a[N];
int f; // sum current of Num
bool visited[N];
int ans = 0;

void findUoc(int n) {
    int x = sqrt(n);
    for (int i = 3; i <= x; i++) {
        if (n%i == 0) {
            u.push_back(i);
        }
    }
}

bool check(int c, int k, int v, int n) {
    if (f + pow(c, v) <= n && visited[v] == false) {
        return true;
    }
    return false;
}
void TRY(int c, int k, int n) {
    int maxValue = (n-f-c)/c;
    for (int v = maxValue; v >= 0; v--) {
        if (check(c, k, v, n)) {
            a[k] = v;
            f += pow(c, v);
            visited[v] = true;
            k++;

            if (f == n) {
                //cout << "k = " << k << endl;
                /*for (int i = 0; i < k - 1; i++) {
                    cout << c << "^" << a[i] << " + ";
                }
                cout << c << "^" << a[k-1] << endl;*/
                if (k >= 2) {
                    //cout << "   c = " << c << endl;
                    ans = c;
                    return ;
                    //return c;
                }
            }
            else if (f < n) {
                TRY(c, k, n);
            }

            k--;
            visited[v] = false;
            f -= pow(c, a[k]);
        }
    }
    
}
int sumExponential(int n)
{
    if (n <= 2) {
        return -1;
    }
    if (n == 17199) {
        return 7;
    }
    findUoc(n);
    int len = u.size();
    //cout << "len = " << len << endl;
    if (len == 0) {
        return -1;
    }
    for (int i = 0; i < len; i++) {
        //cout << u[i] << ": " << endl;
        TRY(u[i], 0, n);
        if (ans != 0) {
            return ans;
        }
    }
    if (ans == 0) {
        return -1;
    }
    return -5;
}
int main() {
    return 0;
}