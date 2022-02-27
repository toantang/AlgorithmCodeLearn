#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;
int a[N]; // mang luu tru value = 0 hoac 1
int c[N];
int f = 0;
int cnt = 1;

void makeArray(int n, int k) {
    int i = 1;
    c[0] = 1;
    while(true) {
        int value = c[i-1] * k;
        if (value >= n) {
            break;
        } 
        cnt++;
        c[i] = value;
        i++;
    }
    for (int j = 0; j < cnt; j++) {
        cout << c[j] << " ";
    }
    cout << endl;
}

bool check(int v, int index, int n) {
    if (f > n) {
        return false;
    }
    return true;
}
void TRY(int n, int index, int num) {
    for (int v = 0; v <= 1; v++) {
        if (check(v, index, n)) {
            a[index] = v;
            f += v * c[index];
            index++;

            if (index == num) {
                if (f >= n) {
                    for (int i = 0; i < index; i++) {
                        cout << a[i] << ", ";
                    }
                    cout << endl;
                }
            }

            else {
                TRY(n, index, num);
            }
            index--;
            f -= a[index] * c[index];
        }
    }
}
void findSpecialNumber(int n, int k) {
    makeArray(n, k);
    TRY(n, 0, 1);
}

int main() {
    int n = 8, k = 3;
    //int n = 20, k = 4;
    findSpecialNumber(n, k);
    
    return 0;
}