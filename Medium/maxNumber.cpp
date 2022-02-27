#include <bits/stdc++.h>
#define MAX 9
using namespace std;

int numA[MAX];
int n1 = 0;
int numB[MAX];
int n2 = 0;

int ans[MAX*2];
int k = 0;
long long answer = 0;
long long c[MAX*2];

void solve() {
    c[0] = 1;
    for (int i = 1; i < 17; i++) {
        c[i] = c[i-1]*10;
    }
}
void divisionNumber(int a, int b) {
    int num[MAX];
    while(a != 0) {
        num[n1] = a%10;
        n1++;
        a = a/10;
    }

    for (int i = 0; i < n1; i++) {
        numA[n1 - 1 - i] = num[i];
        num[i] = 0;
    }

    while(b != 0) {
        num[n2] = b%10;
        n2++;
        b = b/10;
    }
    for (int i = 0; i < n2; i++) {
        numB[n2 - 1 - i] = num[i];
    }
}

long long maxNumber(int a, int b) {
    int i = 0, j = 0;
    while(i < n1 && j < n2) {
        if (numA[i] > numB[j]) {
            ans[k] = numA[i];
            i++;
        }
        else if (numA[i] < numB[j]){
            ans[k] = numB[j];
            j++;
        }
        else {
            int i1 = i;
            int j1 = j;
            int s = numA[i];
            while(j1 < n2) {
                if (numB[j1] > s) {
                    break;
                }
                j1++;
            }
            if (numB[j1] > s) {
                ans[k] = numB[j];
                j++;
            }
            else {
                ans[k] = numA[i];
                i++;
            }
        }
        k++;
    }

    while(i < n1) {
        ans[k] = numA[i];
        i++;
        k++;
    }

    while(j < n2) {
        ans[k] = numB[j];
        j++;
        k++;
    }

    for (int i = 0; i < k; i++) {
        long long x = ans[i]*c[k-i-1];
        answer += x;
    }

    return answer;
}

void printArray(int x[], int n) {
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}
int main() {
    //int a = 123, b = 234;
    //int a = 8642, b = 531;
    //int a = 534, b = 644;
    //int a = 9656, b = 8967; 
    //int a = 87556, b = 7463;
    //int a = 57465, b = 34367; 
    //int a = 457865, b = 65345; 
    //int a = 754454, b = 753523;
    //int a = 977, b = 9779;
    int a= 9779, b = 977;
    //int a = 79, b = 77;
    //int a = 77, b = 79;
    solve();
    divisionNumber(a, b);
    cout << maxNumber(a, b) << endl;
    return 0;
}