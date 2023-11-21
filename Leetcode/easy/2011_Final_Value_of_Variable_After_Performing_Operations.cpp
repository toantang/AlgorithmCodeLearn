#include <iostream>
#include <ostream>
#include <string>

using namespace std;

const string s1 = "--X";
const string s2 = "X--";
const string s3 = "++X";
const string s4 = "X++";

int finalValueAfterOperations(vector<string>& operations) {
    int ans = 0;
    for (int i = 0; i < operations.size(); i++) {
        string si = operations[i];
        
        if (si == s1 || si == s2) ans--;
        else ans++;
    }
    return ans;
}
int main() {
    vector<string> operations;
    // operations = {"++X","++X","X++"};
    operations = {"--X","X++","X++"};
    cout << finalValueAfterOperations(operations) << endl;
    return 0;
}