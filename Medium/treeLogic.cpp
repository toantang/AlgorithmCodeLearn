#include <bits/stdc++.h>

using namespace std;

string treeLogic(int n) {
    int x = n%10;
    string ans = "";
    for (int i = 0; i < n; i++) {
        int m = x%10;
        string s = to_string(m);
        ans = ans + s;
        x++;
    }

    x--;    
    for (int i = 0; i < n; i++) {
        
        int m = x%10;
        string s = to_string(m);
        ans = ans + s;
        x--;
    }
    return ans;
}
int main() {
    return 0;
}