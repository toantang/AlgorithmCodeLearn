#include <bits/stdc++.h>
using namespace std;

const int N = 100000009;

unsigned long long a[N];
unsigned long long r[N]; // mảng chứa các phần tử của mảng hiệu
bool visited[N];
unsigned long long pivot;
unsigned long long currentSum = 0; //tổng hiện tại của mảng hiệu
void findNumber(long long n) {
    pivot = 5;
    a[1] = 1;
    a[2] = 3;
    a[3] = 7;
    r[1] = 2;
    r[2] = 4;
    for (int i = 1; i <= 4; i++) {
        visited[i] = true;
    }
    visited[7] = true;
    currentSum = 6;
    for (int i = 4; i <= n+1; i++) {
        if (a[i-1] == 0) {
            i--;
        }
        int val = pivot - a[i-1];
        //cout << "i: " << i << endl;
        //cout << "   pivot = " << pivot << ", val = " << val << endl;
        if (visited[pivot] == false) {
            r[i-1] = pivot;
            currentSum += pivot;
            a[i] = currentSum + 1;
            visited[a[i]] = true;
        }
        //cout << "   " << a[i] << ", currentSum = " << currentSum << endl;
        //cout << visited[a[i]] << endl;
        pivot++;
    }

    /*for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }*/
    //cout << endl;
}
int main() {
    long long n;
    //n = 5;
    n = 10;
    n = 100000;
    findNumber(n);
    cout << a[n] << endl;
    return 0;
}