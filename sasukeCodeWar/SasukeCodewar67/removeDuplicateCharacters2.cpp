#include <bits/stdc++.h>

using namespace std;

string removeDuplicateCharacters2(string arg3) {
    int a[300];
    int len = arg3.size();
    string s;
    for (int i = 0; i < 300; i++) {
        a[i] = 0;
    }
    for (int i = 0; i < len; i++) {
        a[arg3[i]]++;
    }
    for (int i = 0; i < len; i++) {
        if (a[arg3[i]] == 1) {
            s+= arg3[i];
        }
    }
    return s;
}
int main() {
    string arg3;
    arg3 = "zaabcbd";
    arg3 = "";
    //arg3 = " ";
    cout << removeDuplicateCharacters2(arg3);
    return 0;
}