#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int convert[MAX];
int numConvert(char x) {
    if (x == 'u' || x == 'e' || x == 'o' || x == 'a' || x == 'i') {
        return 1;
    }
    else if (x == 'n') {
        return 2;
    }
    else {
        return 0;
    }
}

bool check(int i) {
    if (convert[i] == 0 && convert[i+1] == 0) {
        return true;
    }
    else if (convert[i] == 0 && convert[i+1] != 1) {
        return true;
    }
    else {
        return false;
    }
}
void romaji(string s) {
    bool ans = true;
    int len = s.size();
    if (len == 1) {
        ans = true;
    }
    else if (len == 0) {
        ans = false;
    }
    for (int i = 0; i < len; i++) {
        convert[i] = numConvert(s[i]);
    }

    for (int i = 0; i < len - 1; i++) {
        if (check(i) || convert[len-1] == 0) {
            ans = false;
            break;
        }
    }
}
int main() {
    string s;
   // s = "codeforces";
   s = "ninja";
    romaji(s);
    for (int i = 0; i < s.size(); i++) {
        cout << convert[i] << " ";
    }
    return 0;
}