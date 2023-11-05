#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int a[MAX]; // i lẻ: số xúc xắc bạn A bốc lần thứ i, i chẵn: số xúc xắc bạn B bốc lần thứ i; i=[1, MAX]
int k = 1;
void stoneGames(int n) {
    int x = sqrt(n);
    
    for (int i = x; i >= 2; i--) {
        int m = i*i;
        while(n >= m) {
            a[k] = m;
            n = n - a[k];
            k++;
        }
    }

    while(n != 0) {
        a[k] = 1;
        n--;
        k++;
    }
}

int stoneGames2(int n) {
    vector<int> ans;
    int x = sqrt(n);
    for(int i = x; i >= 2; i--) {
        int s = i*i;
        if (n >= s) {
            ans.push_back(s);
            n = n - s;
        }
    }
}
int main() {
    int n;
    n = 17;
    stoneGames(n);
    for (int i = 1; i < k; i++) {
        cout << a[i] << " ";
    }
    /*if (k%2 == 1) {
        cout << 1 << endl;
    }
    else {
        cout << 2 << endl;
    }*/
    return 0;
}