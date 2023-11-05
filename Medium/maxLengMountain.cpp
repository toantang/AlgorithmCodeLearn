#include <bits/stdc++.h>

using namespace std;

vector<int> v;
void maxLengMountain(vector<int> a) {
    int len = a.size();
    int start = 0, end = 0;

    int maxLen = 0, startIndex = 0, endIndex = 0;

    for (int i = 1; i < len - 1; i++) {
        cout << "i: " << i << endl;
        cout << "   (" << a[i-1] << ", " << a[i] << ", " << a[i+1] << endl;
        if (a[i] > a[-1]) {
            if (a[i+1] < a[i]) {
                int val = i - start;
                if (val > maxLen) {
                    maxLen = val;
                    startIndex = start;
                    endIndex = i;
                }
                start = i;
            }
        }
        else if (a[i] < a[i-1]) {
            if (a[i+1] > a[i]) {
                start = i;
            }
        }
        else {
            start = i;
            continue;
        }
        cout << "   start = " << start << endl;
    }

    for (int i = startIndex; i <= endIndex; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    vector<int> a;
    //a = {2,9,54,-7,64,37,22,23,41,-14,59,1,60,18,58}; 
    //a = {6,-1,9,-3,2,2,2,-5,7,-4};
    //a = {1, 3, 2, 4, 0};
    a = {18,2,-2,6,-5,13,15,6};
    maxLengMountain(a);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    return 0;
}