#include <bits/stdc++.h>

using namespace std;

//A->Z: 65 -> 90
//a->z: 97 -> 122
void listSubString(string str) {
    int len = str.size();
    int f = 0;
    int cnt = 0;
    string ans;
    string currentAns;
    string cpStr = "";
    for (int i = 0; i < len; i++) {
        int x = str[i];
        if (str[i] >= 65 && str[i] <= 90) {
            cpStr += '1';
        }
        else {
            cpStr += '0';
        }
    }
    cnt = 1;
    currentAns += str[0];
    for (int i = 1; i <= len; i++) {
        if (cpStr[i] == cpStr[i-1]) {
            currentAns += str[i];
            cnt++;
        }
        else {
            if (cnt > f) {
                f = cnt;
                cout << "f = " << f << endl;
                ans = currentAns;
                
            }
            cnt = 1;
            currentAns = "";
            currentAns += str[i];
        }
        cout << "currentAns = " << currentAns << endl;
        cout << "cnt = " << cnt << endl;
    }

    cout << ans << endl;
}
int main() {
    string str;
    str = "abABC";
    str = "vYAKJAWvMuMYxLjbZaYQeGUQtvNDNXywiHSIrwMksDWaArqDPI";
    listSubString(str);
    return 0;
}