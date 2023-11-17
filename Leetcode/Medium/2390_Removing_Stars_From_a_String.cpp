#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string removeStars(string s) {
    string ans = "";
   for (int i = 0; i < s.size(); i++) {
    if (s[i] == '*') {
        if (!ans.empty()) {
            ans.pop_back();
        }
    }
    else {
        ans += s[i];
    }
   }
   return ans;
}

int main() {
    string s;
    s = "leet**cod*e";
    cout << removeStars(s) << endl;
    return 0;
}