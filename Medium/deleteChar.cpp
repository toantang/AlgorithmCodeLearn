#include <bits/stdc++.h>

using namespace std;

int findIndexMax(int start, int end, string s) {
    int maxValue = 0;
    int index;
    for (int i = start; i <= end; i++) {
        if (s[i] > maxValue) {
            maxValue = s[i];
            index = i;
        }
    }
    return index;
}

void deleteChar(string s, int k) {
    int len = s.size();
    int cnt = 0;

    deque<char> S;
    S.push_back(s[0]);
    for (int i = 1; i < len; i++) {
        char x = S.back();
        //cout << "i: " << i << endl;
        //cout << "   x = " << x << ", s[" << i << "] = " << s[i] << endl;
        if (s[i] > x) {
            while(s[i] > S.back() && cnt < k) {
                S.pop_back();
                cnt++;
                if (S.empty() == true) {
                    //cout << "thaot vong while" << endl;
                    break;
                }
            }
        }
        S.push_back(s[i]);
        //cout << S.back() << endl;
    }

    while(cnt < k) {
        S.pop_back();
        cnt++;
    }
    string ans = "";
    while(!S.empty()) {
        //cout << S.front();
        ans += S.front();
        S.pop_front();
    }
    cout << ans << endl;
}
int main() {
    string s;
    int k;
    //s = "93451", k = 2;
    s = "1234", k = 3;  
    //s = "55387", k = 2;
    //s = "8601269313", k = 4;
    //s = "80668896803173", k = 10;
    //s = "32786621179027480247", k = 10; 
    //s = "2950413010015886477760194", k = 20;
    //s = "785030460484058863589355369673", k = 1; 
    //s = "7777777", k = 2;
    //s = "985447841", k = 5;
    //s = "0", k = 1;
    deleteChar(s, k);
    return 0;
}