#include <bits/stdc++.h>

using namespace std;
const int N = 1005;

int x[N]; // mangr lưu trữ số chữ số của mỗi phần tử trong mảng arr
int cntNum = 0; //tổng số chữ số của mảng
int part[N]; // mảng lưu trữ các trường hợp cụ thể, ví dụ số X có 3 chữ số có thể phân tích thành 3 = 1 + 1 + 1 = 2 + 1
int f; //tong so chu so hien tai da phan tich dc
void printArray(int x[], int n) {
    for (int i = 0; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void countNum(vector<int> arr) {
    int len = arr.size();
    for (int i = 0; i < len; i++) {
        int val = arr[i];
        if (val >= 100) {
            x[i] = 3;
        }
        else if (val >= 10) {
            x[i] = 2;
        }
        else {
            x[i] = 1;
        }
        cntNum += x[i];
    }
} 

bool check(int v, int k) {
    if (part[k-1] >= v || k == 0) {
        return true;
    }
    return false;
}

void TRY(int k, int n) {
    for (int v = n; v >= 1; v--) {
        if (check(v, k)) {
            part[k] = v;
            f += v;
            if (f == n) {
                printArray(part, k);
            }
            else if (f < n){
                TRY(k+1, n);
            }

            f -= v;
        }
    }
}
void maximumExpression(vector<int> arr) {
    int y = cntNum/2;
    //cout << "y = " << y << endl;
    for (int n = y; n >= 1; n--) {
        cout << "n: " << n << endl;
        for (int i = n; i >= n-1; i--) {
            cout << "   i = " << i << endl;
            part[0] = i;
            f = i;
            TRY(1, n);
        }
    }
}
int main() {
    vector<int> arr;
    arr = {1,2,11,2,1};
    sort(arr.begin(), arr.end());
    countNum(arr);
    printArray(x, arr.size() - 1);
    maximumExpression(arr);
    return 0;
}