#include <bits/stdc++.h>

using namespace std;

int c[5] = {0, 2, 4, 6, 8};
int d[] = {4, 20, 100, 500, 2500, 12500, 62500, 312500, 1562500, 7812500}; //mảng lưu trữ số lượng các số siêu chẵn có n chữ số;
int p[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
const int N = 11;
int a[N];
int cnt = 0;

void divisorNumber(int n) {
    cnt = 0;
    int b[N];
    while(n != 0) {
        b[cnt] = n%10;
        n = n/10;
        cnt++;
    }
    cout << endl;
    for (int i = 1; i <= cnt; i++) {
        a[i] = b[cnt - i];
    }
}

int count(int k, int cntNum) {
    int value = a[k]/2;
    if (k == 1) {
        value -= 1;
    }
    //cout << "value = " << value << endl;
    if (k == cntNum+1) {
        return 1;
    }
    if (value >= 0) {
        return value*pow(5, cntNum - k) + count(k+1, cntNum);
    }
    else {
        return count(k+1, cntNum);
    }
}


int findMaxSuperEven() {
    int i = 1;
    int f = 0;
    if (a[1] == 1) {
        cnt--;
        while(i <= cnt) {
            f += 8 * p[cnt - i];
            a[i] = 8;
            i++;
        }
        return f;
    }
    while(a[i]%2 == 0) {
        f += a[i] * p[cnt - i];
        i++;
    }
    a[i] = a[i] - 1;
    for (int k = i+1; k <= cnt; k++) {
        a[k] = 8;
        f += 8 * p[cnt - k];
    }
    return f;
}
void superEvenNumber(int n) {
    int maxSuperEven = findMaxSuperEven();
    cout << "maxSuperEven = " << maxSuperEven << endl;
    int ans = 0;
    cout << "cnt = " << cnt << endl;
    ans += count(1, cnt);
    cout << "ans = " << ans << endl;
    for (int i = 0; i < cnt - 1; i++) {
        ans += d[i];
    }
    cout << ans << endl;
}
int main() {
    int n;
    //n = 38473;
    //n = 27;
    //n = 7777;
    n = 123;
    //n = 50;
    divisorNumber(n);
    superEvenNumber(n);
    return 0;
}