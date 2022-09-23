#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int answer[MAX];
int k = 0;
int amount[3]; // so luong max co the cua moi loai tui

int ans = -1;
int f;

void sellCandies2(int n) {
    int x = n/6;
    for (int i = x; i >= 0; i--) {
        f = f + i;
        amount[0] = i;
        int S = n - 6*i;
        int y = S/9;
        if (f + y > ans) {
            for (int j = y; j >= 0; j--) {
            f  = f + j;
            int S1 = S - 9*j;
            amount[1] = j;
            if (S1%20 == 0) 
            {
                amount[2] = S1/20;
                cout << "(" << amount[0] << ", " << amount[1] << ", " << amount[2] << ")" << endl;
                //answer[k] = amount[0] + amount[1] + amount[2];
                //k++;
                //break;
                f = f + amount[2];
                //cout << "j = " << j << "f =" << f << endl;
                if (f > ans) {
                    ans = f;
                }
                f = f - amount[2];
            }
                
            f = f - j;
            }
                     
        }  
        f = f - i;
    }
}
int main() {
    int n;
    //n = 77;
    //n = 6;
    //n = 53;
    //n = 88;
    //n = 49;
    //n = 69;
    n = 4;
    sellCandies2(n);
    cout << ans << endl;
    /*for (int i = 0; i < k; i++) {
        cout << answer[i] << " ";
    }*/
    return 0;
}