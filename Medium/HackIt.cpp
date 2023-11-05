#include <bits/stdc++.h>

using namespace std;

string ans = "";

void hackIt(string str) {
    int len = str.size();
    
    for (int i = 0; i < len; i++) {
        int val = str[i];
        if (val >=65 && val <= 90) {
            val = 155 - val;
        }
        else if (val == 32) {

        }
        else {
            val = 219 - val;
        }
        char x = val;
        ans = ans + x;
    }
}
int main() {
    string str;
    str = {""};
    hackIt(str);
    cout << ans << endl;
    string s = ",";
    int val = s[0];
    cout << val << endl;
    return 0;
}