#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int a[MAX];

int ans = 0;
int sumNumber(int n) {
    int sum = 0;
    while(n != 0) {
        sum = sum + n%10;
        n = n/10;
    }
    return sum;
}
void discoveryNumber(int A, int B, int X) {
    int end = B/X;
    int start = A/X;
    for (int i = start; i <= end; i++) {
        int number = X*i;
        if (number >= A && number <= B) {
            int sum = sumNumber(number);
            if (sum%X == 0) {
                cout << number << " ";
                ans++;
            }
        }
    }
}
int main() {
    int x[3] = {1,20,2};
    //int x[3] = {5,100,5};
    //int x[3] = {1,1000,4};
    //int x[3] = {14772, 21727,19};
    //int x[3] = {4,4,4};
    //int x[3] = {10,11,1};
    //int x[3] = {1870,19913,18};
    //int x[3] = {17036,26300,85};
    //int x[3] = {23812,28704,3};
    //int x[3] = {17674,30334,75};
    discoveryNumber(x[0], x[1], x[2]);
    cout << ans << endl;
    return 0;
}