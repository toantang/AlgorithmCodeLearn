#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

int cntNumOfLazerBeam(string s) {
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') cnt++;
    }
    return cnt;
}

int numberOfBeams(vector<string>& bank) {
    vector<string> cpBank;
    vector<int> numLazerBeam;

    for (int i = 0; i < bank.size(); i++) {
        int cnt = cntNumOfLazerBeam(bank[i]);
        if (cnt > 0) {
            numLazerBeam.push_back(cnt);
        }
    }
    if (numLazerBeam.size() <= 1) return 0;
    int ans = 0;
    for (int i = 0; i < numLazerBeam.size() - 1; i++) {
        ans += numLazerBeam[i] * numLazerBeam[i+1];
    }
    return ans;
}

int main() {
    vector<string> bank;
    bank = {"011001","000000","010100","001000"};
    cout << numberOfBeams(bank) << endl;
    return 0;
}