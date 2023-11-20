#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

bool check(string s1, string s2) {
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] > s2[i]) return false;
    }
    return true;
};

bool checkIfCanBreak(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    return check(s1, s2) || check(s2, s1); 
};

int main() {
    string s1, s2;
    s1 = "abe", s2 = "acd";
    // s1 = "abc", s2 = "xya";
    // s1 = "leetcodee", s2 = "interview";
    bool ans = checkIfCanBreak(s1, s2);
    cout << ans << endl;
    return 0;
}