#include <bits/stdc++.h>
#define MAX 7
using namespace std;

int a[MAX];
int spt;

void solve(int n) {
    int b[MAX];
    while(n != 0) {
        b[spt] = n%10;
        n = n/10;
        spt++;
    }
    for (int i = 0; i < spt; i++) {
        a[i] = b[spt - i - 1];
    }
}

void TRY(int n, int k, int m) {
    
}
void minusNumber(int n, int k) {

}
int main() {
    return 0;
}