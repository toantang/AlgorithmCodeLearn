#include <iostream>
#include <ostream>
#include <vector>
#include <string>

using namespace std;

///Solution
//  x^y= z
//  => (x^y)^y =z^y 
//  => x^(y^y)=z^y (associative)
//  => x^0=z^y
//  => x=z^y

vector<int> findArray(vector<int>& pref) {
    if (pref.empty()) return pref;
    vector<int> ans;
    ans.push_back(pref[0]);
    for (int i = 1; i < pref.size(); i++) {
        cout << "ans[i-1] = " << ans[i-1] << ", pref[i] = " << pref[i] << endl;
        int value = pref[i]^pref[i-1];
        ans.push_back(value);
    }        
    return ans;
}

int main() {
    vector<int> pref;
    pref = {5,2,0,3,1};
    vector<int> ans = findArray(pref);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ", ";
    }
    cout << endl;
    return 0;
}