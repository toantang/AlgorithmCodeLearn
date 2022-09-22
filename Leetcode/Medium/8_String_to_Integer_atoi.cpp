#include <bits/stdc++.h>

using namespace std;

string removeZeroCharacter(string s) {
    int len = s.size();
    string newValue = "";
    if (len == 0) return "";
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '0') continue;
        else {
            index = i;
            break;
        }
    }
    return s.substr(index, len - index + 1);
}

int myAtoi(string s) {
    int len = s.size();
    string newString = "";
    bool sign = true;
    bool isSeeNumber = false;
    for (int i = 0; i < len; i++) {
        if (isSeeNumber) {
            if (s[i] < 48 || s[i] > 57) break;
            newString += s[i];
        }
        else {
            if (s[i] >= 48 && s[i] <= 57) {
                isSeeNumber = true;
                newString += s[i];
            }
            if (i > 0 && s[i-1] == '-') {
                newString = "-" + newString;
            }
        }
    }   
    cout << "newString: " << newString << endl;
    newString = removeZeroCharacter(newString);
    cout << "removeZero: " << newString << endl;
    return stoi(newString);     
}

int main() {
    string s;
    s = "words and 987";
    cout << myAtoi(s) << endl;;
    return 0;
}