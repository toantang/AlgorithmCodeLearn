#include <bits/stdc++.h>

using namespace std;

string ans = "";

void caesarian(string message, int n) {
    if (n > 26 || n < -26) {
        n = n%26;
    }
    int len = message.size();
    for (int i = 0; i < len; i++) {
        int val = message[i];
        int value = val + n;
        if (val >= 97 && val <= 122) {
            if (value >= 122) {
                val = value - 25;
            }
            else if (value <= 97) {
                val = value + (25 + n);
            }
            else {
                val = value;
            }
        }
        else if (val >= 65 && val <= 90) {
            if (value > 90) {
                val = value - 35;
            }
            else if (value < 65) {
                val = value + 35 + n;
            }
            else {
                val = value;
            }
        }
        char x = val;
        ans = ans + x;
    }
}

int main() {
    string message; 
    int n;
    message = "A,";
    n = -1013;
    cout << n%26 << endl;
    caesarian(message, n);
    cout << ans << endl;
    return 0;
}