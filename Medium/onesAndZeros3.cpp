#include <bits/stdc++.h>

using namespace std;

int ans = 0;

int onesAndZeros3(std::vector<int> arr)
{
    stack<int> S;
    stack<int> s;
    int len = arr.size();
    if (len <= 2) {
        return 0;
    }
    
    S.push(arr[0]);
    int count = 1;
    while(count <= len - 1) {
        if (!S.empty()) {
            int x = S.top();
            //cout << x << endl;
            if (arr[count] != x) {
                if (!s.empty()) {
                    S.push(s.top());
                    s.pop();
                }
                S.push(arr[count]);
            }
            else {
                if (s.empty()) {
                    s.push(arr[count]);
                }
                else {
                    s.pop();
                    S.pop();
                }
            }
        }
        else {
            S.push(arr[count]);
        }
        count++;
    }

    int val = s.top();
    int sign = 1;
    while(!S.empty()) {
        //cout << S.top() << endl;
        if (S.top() == s.top()) {
            s.push(S.top());
            sign++;
        }
        if (sign == 3) {
            ans -= 2;
        }
        S.pop();
        ans++;
    }
    return ans;
}

int main() {
    vector<int> arr;
    arr = {0,0,1,2,2,2,1,1,0};
    //arr = {2, 2, 2, 3, 2, 3};
    cout << onesAndZeros3(arr) << endl;
    //cout << ans << endl;
    return 0;
}