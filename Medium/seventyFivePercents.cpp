#include <bits/stdc++.h>

using namespace std;

vector<int> countNumChar(string s) {
    int cntA = 0;
    int cntP = 0;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] == 'A') {
            cntA++;
        }
        else {
            cntP++;
        }
    }

    vector<int> c;
    c.push_back(cntA);
    c.push_back(cntP);
    return c;
}

bool check(int i, string s) {
    if (s[i+1] == 'A' && s[i+2] == 'A') {
        return false;
    }
    if (s[i-1] == 'A' && s[i-2] == 'A') {
        return false;
    }
    return true;
}

void seventyFivePercents(string s) {
    int len = s.size();
    vector<int> c = countNumChar(s);
    int cntA = c[0];
    int cntP = c[1];
    cout << "cntA = " << cntA << ", cntP = " << cntP << endl;
    int a = 0;// số kí tự A cần thay đổi để cntP >= 5*cntA, a >= 5*cntA - cntP
    a = (0.75*cntA - 0.25*cntP);
    int end = cntA;
    int cnt = 0;
    string ans = "";
    ans = ans + s[0] + s[1];
    bool sign = false;

    while(a <= cntA) {
        cnt = 0;
        cout << "a: " << a << endl;
        for (int i = 2; i < len - 2; i++) {
            if (s[i] == 'A') {
                if (check(i, s)) {
                    //ss[i] = 'P';
                    ans += 'P';
                    cnt++;
                }
            }
            else {
                ans += s[i];
            }
            if (cnt == a) {
                float x = (cntP + cnt + 0.0)/len;
                if (x >= 0.75) {
                    sign = true;
                    cout << "   ans = " << ans << endl;
                    break;
                }
                
            }
        }
        if (sign == true) {
            break;
        }
        a++;
    }

}
int main() {;
    string s;
    s = "PAPAPAPAPAPAPAPAPAPAPA";
    //s = "PAAPPAPPP";
    seventyFivePercents(s);
    return 0;
}