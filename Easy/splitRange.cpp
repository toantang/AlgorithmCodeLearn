#include <bits/stdc++.h>

using namespace std;

void splitRange(vector<int> arr) {
    vector<string> ans;
    int start = 0, end = 0;
    int len = arr.size();
    string currentString = "";
    if (len == 1) {
        currentString = to_string(arr[0]);
        ans.push_back(currentString);
    }

    for (int i = 1; i < len; i++) {
        cout << "i: " << i << endl;
        cout << "   start = " << start << ", end = " << end << endl;
        if (arr[i] != arr[i-1] + 1) {
            string x = to_string(arr[start]);
            if (start != end) {
                string y = to_string(arr[end]);
                currentString = x + "->" + y;
            }
            else {
                currentString = x;
            }
            ans.push_back(currentString);
            start = i;
            end = i;
        }
        else {
            end++;
        }
        cout << "   start = " << start << ", end = " << end << endl;
    }

    string x = to_string(arr[start]);
    if (start != end) {
        string y = to_string(arr[end]);
        currentString = x + "->" + y;
    }
    else {
        currentString = x;
    }
    ans.push_back(currentString);
    int size = ans.size();
    for (int i = 0; i < size; i++) {
        cout << ans[i] << endl;
    }
}
int main() {
    vector<int> arr;
    arr = {0,1,2,4,5,7};
    arr = {0,2,3,4,6,8,9};
    splitRange(arr);
    return 0;
}