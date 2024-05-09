///done

#include <iostream>
#include <ostream>

using namespace std;

bool isPalindrome(int x) {
    string s = to_string(x);
    int len = s.size();
    
    int max = 0;
    if (len%2 == 0) {
        max = len/2;
    }
    else {
        max = (len-1)/2 - 1;
    }
    for (int i = 0; i <= max; i++) {
        if (s[i] != s[len - i - 1]) return false;
    }        
    return true;
}

int main() {
    int x;
    x = 121;
    x = 10;
    bool ans = isPalindrome(x);
    cout << ans << endl;
    return 0;
}