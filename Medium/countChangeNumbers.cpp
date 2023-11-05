#include <bits/stdc++.h>

using namespace std;

int maxNumber = 0;
vector<int> ans;
void TRY(int n, int k, int m) {
    if (1) {
        n = n*2;
        //cout << "n = " << n << endl;
        m++;
        if (m == k) {
            ans.push_back(n);
        }
        else {
            TRY(n, k, m);
        }
        m--;
        n = n/2;
    }
    //cout << "n = " << n << endl;
    if (n%3 == 1 && n%6 == 4) {
        n = (n-1)/3;
        
        m++;
        if (m == k) {
            ans.push_back(n);
        }
        else {
            TRY(n, k, m);
        }
        m--;
        n = 3*n + 1;
    }
  
}
void countChangeNumbers(int n, int k) {
    
}
int main() {
    int n, k;
    //n = 10, k = 3;
    //n = 5, k = 2;
    //n = 7, k = 1;
    n = 17, k = 4;
    TRY(n, k, 0);
    int len = ans.size();
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}