#include <bits/stdc++.h>

using namespace std;

int ans = 0;
void sortString(string s) {
    vector<string> v;
    string a;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] != ',') {
            a = a + s[i];
        }
        else {
            v.push_back(a);
            a = "";
        }
    }
    sort(v.begin(), v.end());
    
}
int main() {
    return 0;

}